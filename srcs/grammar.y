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
    base basetype;
    int assignement;

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

%start program
%union {
  char *string;
  int n;
  float f;
  gen_t g;
}
%%


primary_expression
: IDENTIFIER  {

  //si coté gauche du egal, pas besoin d'afficher !

  gen_t g = findtab($1);
  char *nv= newvar();
  $$.var = nv;
  if ( g.type == INT_T){
    $$.type = INT_T;

    asprintf(&($$.code), "%s = load i32* %s\n", nv,g.var);
  }
  else{
    $$.type = FLOAT_T;
    asprintf(&($$.code), "%s = load float* %s\n", nv,g.var);
  }
    $$.name = $1;

 } 
| CONSTANTI   {
  $$.var=newvar(); 
  $$.type=INT_T;
  asprintf(&($$.code), "%s = add i32 0, %d\n", $$.var,$1);
 }
| CONSTANTF    {
  $$.var=newvar(); 
  $$.type=FLOAT_T;
  asprintf(&($$.code), "%s = fadd float 0, %f\n", $$.var,$1);
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
  : primary_expression  {$$=$1;}
   | postfix_expression '[' expression ']' { $$ = $1; }
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
 } }
;

unary_operator 
: '-'
;

multiplicative_expression
: unary_expression { $$ = $1; } 
| multiplicative_expression '*' unary_expression { 
  $$.var = newvar(); 
  if ($1.type==INT_T && $3.type==INT_T) {
  $$.type=INT_T;
    asprintf(&($$.code), "%s%s%s = mul i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } else {
  $$.type=FLOAT_T;
    asprintf(&($$.code), "%s%s%s = fmul float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } }
| multiplicative_expression '/' unary_expression { 
  $$.var = newvar(); 
  if ($1.type==INT_T && $3.type==INT_T) {
  $$.type=INT_T;
    asprintf(&($$.code), "%s%s%s = sdiv i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } else {
  $$.type=FLOAT_T;
    asprintf(&($$.code), "%s%s%s = fdiv float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } }
;

additive_expression
  : multiplicative_expression { $$ = $1; } 
     | additive_expression '+' multiplicative_expression { 
  $$.var = newvar(); 
  if ($1.type==INT_T && $3.type==INT_T) {
  $$.type=INT_T;
    asprintf(&($$.code), "%s%s%s = add i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } else {
  $$.type=FLOAT_T;
    asprintf(&($$.code), "%s%s%s = fadd float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } 
 }
| additive_expression '-' multiplicative_expression { 
  $$.var = newvar(); 
  if ($1.type==INT_T && $3.type==INT_T) {
    asprintf(&($$.code), "%s%s%s = sub i32 %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } else {
    asprintf(&($$.code), "%s%s%s = fsub float %s, %s\n", $1.code, $3.code,$$.var,$1.var,$3.var);
 } }
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
  //printf("CODE UNARY : %s\n",$1.code);
  if(!isPresent($1.name)){
    printf("ERREUR : variable non initialisée\n");
  }
  else{

    gen_t unary = findtab($1.name);
    $$.var = unary.var;

    switch(assignement){
      case 0:
        //assignement =
        //selon type /!\
        asprintf(&($$.code), "%s%sstore i32 %s, i32* %s\n", $1.code, $3.code,$3.var,$$.var);
        break;


      case 1:
        //assignement MUL_ASSIGN
        break;

      case 2:
        //assignement ADD_ASSIGN
        break;

      case 3:
        //assignement Sub_ASSIGN
        break;
    }   
  }
}
| comparison_expression {$$ = $1 ;}
;

assignment_operator
: '='         {assignement=0;}    
| MUL_ASSIGN  {assignement=1;}
| ADD_ASSIGN  {assignement=2;}
| SUB_ASSIGN  {assignement=3;}
;

declaration 
: type_name declarator_list ';' {asprintf(&($$.code),"%s\n",($2.code));}
| EXTERN type_name declarator_list ';'
;

declarator_list
: declarator {$$ = $1;}
| declarator_list ',' declarator  {asprintf(&($$.code),"%s \n%s \n",($1.code),($3.code));}
;

type_name
  : VOID {basetype = VOID_T;}
   | INT  {basetype = INT_T;}
   | FLOAT {basetype = FLOAT;}
;

declarator
  : IDENTIFIER  {
    $$.var = newvar();
    addtab($1,basetype,$$.var);
    if ( basetype == INT_T){
      asprintf(&($$.code),"%s = alloca i32\n",$$.var);
    }
    else{
      asprintf(&($$.code),"%s = alloca float\n",$$.var);      
    }
  }           
   | '(' declarator ')'  { $$ = $2; }  
   | declarator '[' CONSTANTI ']' { $$ = $1; }  
   | declarator '[' ']' { $$ = $1; }            
   | declarator '(' parameter_list ')' { $$ = $1 ;}  
   | declarator '(' ')'  { $$ = $1 ;}             
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
| '{' declaration_list statement_list '}' {printf("%s\n",$2.code);}
;

declaration_list
: declaration {$$=$1;}
| declaration_list declaration {asprintf(&($$.code),"%s\n%s\n",($1.code),$2.code);}
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';' {printf("code :\n%s" , $1.code) ;}
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
