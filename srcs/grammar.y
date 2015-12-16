%{
    #include <stdio.h>
    #include "parse.h"
    #include "hachage.h"

    extern int yylineno;
    int yylex ();
    int yyerror ();

    char *newvar() {
      static int i=0;
      char *s = NULL;
      asprintf(&s,"%%x%d",i++);
      return s;
    }

    gen_t EMPTY= {"", INT_T, "" } ;
    base_t base_type;
    int allocation_size;
		char * offset_var;
%}

%token <string> IDENTIFIER
%token <n> CONSTANTI
%token <f> CONSTANTF
%token MAP REDUCE EXTERN DO
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN
%token TYPE_NAME
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR
%type <g> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression
%type <g> declarator declarator_list declaration declaration_list
%type <g> comparison_expression expression
%type <a> assignment_operator
%start program
%union {
  char *string;
  int n;
  float f;
  gen_t g;
  base_t b;
  assign_t a;
}
%%


primary_expression
: IDENTIFIER  {
		if(isPresent($1)) {
			gen_t g = findtab($1);
			$$.var = g.var;
			$$.type = g.type;
			$$.name = g.name;
			$$.code = "";
		} else {
			printf("ERREUR : variable non initialisée\n");
		}
	}
| CONSTANTI {
		$$.var = newvar(); 
		$$.type = INT_T;
		$$.name = "";
		asprintf(&($$.code), "%s = add i32 0, %d\n", $$.var,$1);
	}
| CONSTANTF {
    $$.var = newvar(); 
    $$.type = FLOAT_T;
		$$.name = "";
		asprintf(&($$.code), "%s = fadd float 0.0, %f\n", $$.var,$1);
	}
| '(' expression ')' { $$ = EMPTY; } 
| MAP '(' postfix_expression ',' postfix_expression ')' { $$ = EMPTY; } 
| REDUCE '(' postfix_expression ',' postfix_expression ')' { $$ = EMPTY; } 
| IDENTIFIER '(' ')' { $$ = EMPTY; } 
| IDENTIFIER '(' argument_expression_list ')' { $$ = EMPTY; } 
| IDENTIFIER INC_OP  { $$ = EMPTY; } 
| IDENTIFIER DEC_OP { $$ = EMPTY; }  
;

postfix_expression
: primary_expression  { $$=$1; }
| postfix_expression '[' expression ']' {
		if(!strcmp($1.name, "")) {
			printf("ERREUR : un nombre n'est pas un tableau!\n");
		} else {
			$$.var = newvar();
			$$.name = $1.name;
			$$.type = $1.type;
			asprintf(&($$.code), "%s%s = getelementptr i32* %s, i32 %s\n", $3.code, $$.var, $1.var, $3.var);
		}
	}
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: postfix_expression { $$ = $1; }
| INC_OP unary_expression { $$ = $2; }
| DEC_OP unary_expression { $$ = $2; }
| unary_operator unary_expression {
		$$.var = newvar(); 
		if ($2.type==INT_T) {
			$$.type=INT_T;
			asprintf(&($$.code), "%s%s = sub i32 0, %s\n", $2.code, $$.var,$2.var);
		} else {
			$$.type=FLOAT_T;
			asprintf(&($$.code), "%s%s = fsub float 0, %s\n", $2.code, $$.var,$2.var);
		}
	}
;

unary_operator 
: '-'
;

multiplicative_expression
: unary_expression {
		if(strcmp($1.name, "")) {
			$$.var = newvar();
			$$.name = $1.name;
			$$.type = $1.type;
			if($$.type == INT_T) {
				asprintf(&($$.code), "%s%s = load i32* %s\n", $1.code, $$.var, $1.var);
			} else {
				asprintf(&($$.code), "%s%s = load float* %s\n", $1.code, $$.var, $1.var);
			}
		}
	} 
| multiplicative_expression '*' unary_expression { 
		gen_t g = $3;
		if(strcmp(g.name, "")) {
			g.var = newvar();
			g.type = $3.type;
			if(g.type == INT_T) {
				asprintf(&(g.code), "%s%s = load i32* %s\n", $3.code, g.var, $3.var);
			} else {
				asprintf(&(g.code), "%s%s = load float* %s\n", $3.code, g.var, $3.var);
			}
		}

		$$.var = newvar();
		if ($1.type==INT_T && g.type==INT_T) {
				$$.type=INT_T;
				asprintf(&($$.code), "%s%s%s = mul i32 %s, %s\n", $1.code, g.code, $$.var, $1.var, g.var);
		} else if ($1.type==FLOAT_T && g.type==FLOAT_T) {
				$$.type=FLOAT_T;
				asprintf(&($$.code), "%s%s%s = fmul float %s, %s\n", $1.code, g.code, $$.var, $1.var, g.var);
		} else{
			gen_t conv;
			conv.var = newvar();
			$$.type=FLOAT_T;
			if(g.type==INT_T){
				asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, g.code, conv.var, g.var);
				asprintf(&($$.code),    "%s%s = fmul float %s, %s\n", conv.code, $$.var, $1.var, conv.var);
			} else if($1.type==INT_T){
				asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, g.code, conv.var, $1.var);  
				asprintf(&($$.code),    "%s%s = fmul float %s, %s\n", conv.code, $$.var, conv.var, g.var);
			}                  
		} 
	}
;

additive_expression
: multiplicative_expression { $$ = $1; } 
| additive_expression '+' multiplicative_expression { 
		$$.var = newvar(); 
		if ($1.type==INT_T && $3.type==INT_T) {
			$$.type=INT_T;
			asprintf(&($$.code), "%s%s%s = add i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
		}	else if ($1.type==FLOAT_T && $3.type==FLOAT_T) {
			$$.type=FLOAT_T;
			asprintf(&($$.code), "%s%s%s = fadd float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
		} else {
			gen_t conv;
			conv.var = newvar();
			$$.type=FLOAT_T;
			if($3.type==INT_T) {
				asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code,conv.var,$3.var);
				asprintf(&($$.code),    "%s%s = fadd float %s, %s\n", conv.code,$$.var,$1.var,conv.var);
			}	else if($1.type==INT_T) {
				asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code,conv.var,$1.var);  
				asprintf(&($$.code),    "%s%s = fadd float %s, %s\n", conv.code,$$.var,conv.var,$3.var);
			}                  
		} 
	}
| additive_expression '-' multiplicative_expression { 
	$$.var = newvar(); 
	if ($1.type==INT_T && $3.type==INT_T) {
			$$.type=INT_T;
			asprintf(&($$.code), "%s%s%s = sub i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
	} else if ($1.type==FLOAT_T && $3.type==FLOAT_T) {
			$$.type=FLOAT_T;
			asprintf(&($$.code), "%s%s%s = fsub float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
	} else {
			gen_t conv;
			conv.var = newvar();
			$$.type=FLOAT_T;
			if($3.type==INT_T) {
					asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code,conv.var,$3.var);
					asprintf(&($$.code),    "%s%s = fsub float %s, %s\n", conv.code,$$.var,$1.var,conv.var);
			} else if($1.type==INT_T) {
					asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code,conv.var,$1.var);  
					asprintf(&($$.code),    "%s%s = fsub float %s, %s\n", conv.code,$$.var,conv.var,$3.var);
			}                  
		} 
	}
;

comparison_expression
: additive_expression {$$ = $1; }
| additive_expression '<' additive_expression {printf("TODO COMPARAISON \n");}
| additive_expression '>' additive_expression {printf("TODO COMPARAISON \n");}
| additive_expression LE_OP additive_expression {printf("TODO COMPARAISON \n");}
| additive_expression GE_OP additive_expression {printf("TODO COMPARAISON \n");}
| additive_expression EQ_OP additive_expression {printf("TODO COMPARAISON \n");}
| additive_expression NE_OP additive_expression {printf("TODO COMPARAISON \n");}
;

expression
: unary_expression assignment_operator comparison_expression {
    $$.var = $1.var;

		//asprintf(&($$.code), "%s%s%s = getelementptr i32* %s, i32 %s\n", $1.code, $3.code, $$.var, $1.var, $3.var);

    switch($2) {
      case ASSIGN_T:
        if($1.type == INT_T){
          if(($3.type)==FLOAT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),"%s%s%s = fptosi float %s to i32\n", $1.code, $3.code,conv.var,$3.var);
            asprintf(&($$.code), "%sstore i32 %s, i32* %s\n", conv.code, conv.var, $$.var);
          } else {
            asprintf(&($$.code), "%s%sstore i32 %s, i32* %s\n", $1.code, $3.code, $3.var, $$.var);
          }
        } else if($1.type == FLOAT_T){
          if(($3.type)==INT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code, conv.var, $3.var);
            asprintf(&($$.code), "%sstore float %s, float* %s\n", conv.code, conv.var, $$.var);
          } else {
            asprintf(&($$.code), "%s%sstore float %s, float* %s\n", $1.code, $3.code, $3.var, $$.var);
          }
        }
        break;

      case MUL_ASSIGN_T:
        break;

      case ADD_ASSIGN_T:
        break;

      case SUB_ASSIGN_T:
        break;
    }   
	
		//printf("EXPRESSION: <%s>\n", $$.code);

  }
| comparison_expression {$$ = $1 ;}
;

assignment_operator
: '='         {$$=ASSIGN_T;}    
| MUL_ASSIGN  {$$=MUL_ASSIGN_T;}
| ADD_ASSIGN  {$$=ADD_ASSIGN_T;}
| SUB_ASSIGN  {$$=SUB_ASSIGN_T;}
;

declaration 
: type_name declarator_list ';' {asprintf(&($$.code),"%s\n",($2.code));}
| EXTERN type_name declarator_list ';'
;

declarator_list
: declarator {
    if(base_type == INT_T)
      asprintf(&($$.code), "%s = alloca [%d x i32]", $1.var, allocation_size);
    else
      asprintf(&($$.code), "%s = alloca [%d x float]", $1.var, allocation_size);
  }
| declarator_list ',' declarator  {
    if(base_type == INT_T)
      asprintf(&($$.code), "%s\n%s = alloca [%d x i32]", $1.code, $3.var, allocation_size);
    else
      asprintf(&($$.code), "%s\n%s = alloca [%d x float]", $1.code, $3.var, allocation_size);
  }
;

type_name
: VOID  {base_type = VOID_T;}
| INT   {base_type = INT_T;}
| FLOAT {base_type = FLOAT_T;}
;

declarator
: IDENTIFIER {
    allocation_size = 1;
    $$.var = newvar();
    addtab($1, base_type, $$.var);
  }           
| '(' declarator ')' { $$ = $2; }
| declarator '[' CONSTANTI ']' {
    allocation_size = $3;
    $$.var = $1.var;
  }
| declarator '[' ']' { $$ = $1; }  
| declarator '(' parameter_list ')' { $$ = $1 ;}  
| declarator '(' ')' { $$ = $1 ;}             
;

parameter_list
: parameter_declaration
| parameter_list ',' parameter_declaration
;

parameter_declaration
  : type_name declarator 
;

statement
: compound_statement
| expression_statement 
| selection_statement
| iteration_statement
| jump_statement
;

compound_statement
: '{' '}'
| '{' statement_list '}' 
| '{' declaration_list statement_list '}' { printf("%s\n",$2.code); }
;

declaration_list
: declaration {$$=$1;}
| declaration_list declaration { asprintf(&($$.code),"%s\n%s\n",($1.code),$2.code); }
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';' { printf("\n%s", $1.code);}
;

selection_statement
: IF '(' expression ')' statement
| IF '(' expression ')' statement ELSE statement
| FOR '(' expression_statement expression_statement expression ')' statement
;

iteration_statement
: WHILE '(' expression ')' statement
| DO statement WHILE '(' expression ')'
;

jump_statement
: RETURN ';'
| RETURN expression ';'
;

program 
: external_declaration
| program external_declaration
;

external_declaration
: function_definition
| declaration
;

function_definition
: type_name declarator compound_statement
;

%%
#include <stdio.h>
#include <string.h>
#include "hachage.h"

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {


    FILE *input = NULL;
    
    init();

    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    yyparse ();
    free (file_name);
    return 0;
}
