%{
    #include <stdio.h>
    #include "parse.h"
    #include <string.h>
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

    char *newlabel() {
      static int i=0;
      char *s = NULL;
      asprintf(&s,"label%d",i++);
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
%type <g> comparison_expression expression argument_expression_list
%type <g> statement_list statement compound_statement jump_statement selection_statement expression_statement iteration_statement


%type <g> program external_declaration function_definition
%type <g> parameter_list parameter_declaration

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
		/*if(isPresent($1)) {
			gen_t g = findtab($1);
			$$.var = g.var;
			$$.type = g.type;
			$$.name = g.name;
			$$.code = "";
		} else {
			printf("ERREUR : variable non initialisée\n");
		}*/
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
: expression { $$ = $1; }
| argument_expression_list ',' expression {
	$$.var = newvar(); 
	asprintf(&($$.code), "%s%s\n",$1.code,$3.code);
}
;

unary_expression
: postfix_expression { $$ = $1; }
| INC_OP unary_expression {

	//bug et si pas present ?
    gen_t unary = findtab($2.name);
    $$.var = unary.var;


	if($2.type == INT_T){

		// bug plus de code dans unary...
		//gen_t load;
		//load.var = newvar();
		gen_t inc;
		inc.var = newvar();
		//asprintf(&($$.code), "%s = load i32* %s\n%s = add i32 %s, 1\nstore i32 %s, i32* %s", load.var,$2.var,inc.var,load.var,inc.var,$$.var);
		asprintf(&($$.code), "%s%s = add i32 %s, 1\nstore i32 %s, i32* %s",$2.code,inc.var,$2.var,inc.var,$$.var);
		
		$$.name = $2.name;

	}
	else if($2.type==FLOAT_T){

		// bug plus de code dans unary...
		//gen_t load;
		//load.var = newvar();
		gen_t inc;
		inc.var = newvar();
		//asprintf(&($$.code), "%s = load float* %s\n%s = fadd float %s, 1.0\nstore float %s, float* %s", load.var,$2.var,inc.var,load.var,inc.var,$$.var);
		asprintf(&($$.code), "%s%s = fadd float %s, 1.0\nstore float %s, float* %s",$2.code, inc.var,$2.var,inc.var,$$.var);
		
		$$.name = $2.name;

	}
	else
		printf("operation interdite sur ce type\n");
}
| DEC_OP unary_expression {	
	if($2.type == INT_T){

		// bug plus de code dans unary...
		gen_t load;
		load.var = newvar();
		gen_t inc;
		inc.var = newvar();
		asprintf(&($$.code), "%s = load i32* %s\n%s = sub i32 %s, 1\nstore i32 %s, i32* %s", load.var,$2.var,inc.var,load.var,inc.var,$$.var);
		$$.name = $2.name;

	}
	else if($2.type==FLOAT_T){

		// bug plus de code dans unary...
		gen_t load;
		load.var = newvar();
		gen_t inc;
		inc.var = newvar();
		asprintf(&($$.code), "%s = load float* %s\n%s = fsub float %s, 1.0\nstore float %s, float* %s", load.var,$2.var,inc.var,load.var,inc.var,$$.var);
		$$.name = $2.name;

	}
	else
		printf("operation interdite sur ce type\n");
}
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
		/*if(strcmp($1.name, "")) {
			$$.var = newvar();
			$$.name = $1.name;
			$$.type = $1.type;
			if($$.type == INT_T) {
				asprintf(&($$.code), "%s%s = load i32* %s\n", $1.code, $$.var, $1.var);
			} else {
				asprintf(&($$.code), "%s%s = load float* %s\n", $1.code, $$.var, $1.var);
			}

		}*/
		$$ = $1;
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
| additive_expression '<' additive_expression {
  $$.var = newvar();

  //bug plus de load* :(
  if($$.type == INT_T) {
  	asprintf(&($$.code), "%s%s = load i32* %s\n", $1.code, $$.var, $1.var);
  } else {
  	asprintf(&($$.code), "%s%s = load float* %s\n", $1.code, $$.var, $1.var);
  }

  asprintf(&($$.code),"%s%s%s = icmp slt i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
| additive_expression '>' additive_expression {
  $$.var = newvar();
  asprintf(&($$.code),"%s%s%s = icmp sgt i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
| additive_expression LE_OP additive_expression {
  $$.var = newvar();
  asprintf(&($$.code),"%s%s%s = icmp use i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
| additive_expression GE_OP additive_expression {
  $$.var = newvar();
  asprintf(&($$.code),"%s%s%s = icmp sge i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
| additive_expression EQ_OP additive_expression {
  $$.var = newvar();
  asprintf(&($$.code),"%s%s%s = icmp eq i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
| additive_expression NE_OP additive_expression {
  $$.var = newvar();
  asprintf(&($$.code),"%s%s%s = icmp ne i32 %s, %s\n",$1.code, $3.code,$$.var,$1.var,$3.var);
}
;

expression
: unary_expression assignment_operator comparison_expression {
    gen_t unary = findtab($1.name);
    $$.var = unary.var;
    	//bug attention $$.var -> $1;var
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
      
      //BUG : faire conversion apres multiplication

        if($1.type == INT_T){
          if(($3.type)==FLOAT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),"%s%s%s = fptosi float %s to i32\n", $1.code, $3.code,conv.var,$3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load i32* %s\n%s = mul i32 %s, %s\nstore i32 %s, i32* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s%s = load i32* %s\n%s = mul i32 %s, %s\nstore i32 %s, i32* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        } else if($1.type == FLOAT_T){
          if(($3.type)==INT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code, conv.var, $3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load float* %s\n%s = fmul float %s, %s\nstore float %s, float* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

 			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();
			         	
            asprintf(&($$.code), "%s%s%s = load float* %s\n%s = fmul float %s, %s\nstore float %s, float* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        }      
        break;

      case ADD_ASSIGN_T:
      
      //BUG : faire conversion apres multiplication

        if($1.type == INT_T){
          if(($3.type)==FLOAT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),"%s%s%s = fptosi float %s to i32\n", $1.code, $3.code,conv.var,$3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load i32* %s\n%s = add i32 %s, %s\nstore i32 %s, i32* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s%s = load i32* %s\n%s = add i32 %s, %s\nstore i32 %s, i32* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        } else if($1.type == FLOAT_T){
          if(($3.type)==INT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code, conv.var, $3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load float* %s\n%s = fadd float %s, %s\nstore float %s, float* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

 			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();
			         	
            asprintf(&($$.code), "%s%s%s = load float* %s\n%s = fadd float %s, %s\nstore float %s, float* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        }        
        break;

      case SUB_ASSIGN_T:
      
      //BUG : faire conversion apres multiplication

        if($1.type == INT_T){
          if(($3.type)==FLOAT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),"%s%s%s = fptosi float %s to i32\n", $1.code, $3.code,conv.var,$3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load i32* %s\n%s = sub i32 %s, %s\nstore i32 %s, i32* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s%s = load i32* %s\n%s = sub i32 %s, %s\nstore i32 %s, i32* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        } else if($1.type == FLOAT_T){
          if(($3.type)==INT_T){
            gen_t conv;
            conv.var = newvar();
            asprintf(&(conv.code),  "%s%s%s = sitofp i32 %s to float\n", $1.code, $3.code, conv.var, $3.var);

			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();

            asprintf(&($$.code), "%s%s = load float* %s\n%s = fsub float %s, %s\nstore float %s, float* %s\n", conv.code, step1.var,$$.var,step2.var,step1.var,conv.var,step2.var, $$.var);
          } else {

 			gen_t step1;
			gen_t step2;
			step1.var = newvar();
			step2.var = newvar();
			         	
            asprintf(&($$.code), "%s%s%s = load float* %s\n%s = fsub float %s, %s\nstore float %s, float* %s\n", $1.code, $3.code, step1.var,$$.var,step2.var,step1.var,$3.var,step2.var, $$.var);
          }
        }        
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
| EXTERN type_name declarator_list ';' {asprintf(&($$.code),"%s\n",($3.code));}
//bug extern on en fait quoi ?
;

declarator_list
: declarator {
    if(base_type == INT_T){
    	if(allocation_size==1)
     		asprintf(&($$.code), "%s = alloca i32", $1.var);
  		else
  			asprintf(&($$.code), "%s = alloca [%d x i32]", $1.var, allocation_size);
  	}
    else{
    	if(allocation_size==1)
     		asprintf(&($$.code), "%s = alloca float", $1.var);
  		else
  			asprintf(&($$.code), "%s = alloca [%d x float]", $1.var, allocation_size);
  	}
  }
| declarator_list ',' declarator  {
    if(base_type == INT_T)
      asprintf(&($$.code), "%s%s = alloca [%d x i32]", $1.code, $3.var, allocation_size);
    else
      asprintf(&($$.code), "%s%s = alloca [%d x float]", $1.code, $3.var, allocation_size);
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
    $$.name = $1;
    addtab($1, base_type, $$.var);
  }           
| '(' declarator ')' { $$ = $2; }
| declarator '[' CONSTANTI ']' {
    allocation_size = $3;
    $$.var = $1.var;
  }
| declarator '[' ']' { $$ = $1; }  
| declarator '(' parameter_list ')' {
	$$ = $1;
	asprintf(&($$.code), "(%s)",$3.code);
}  
| declarator '(' ')' {
	$$ = $1;
	asprintf(&($$.code), "()");
}             
;

parameter_list
: parameter_declaration { $$ = $1;}
| parameter_list ',' parameter_declaration {
	asprintf(&($$.code), "%s%s\n",$1.code,$3.code);
}
;

parameter_declaration
  : type_name declarator {
  	char * typeparam;
  	if(base_type==INT_T)
  		typeparam = "i32";
  	else if (base_type == FLOAT_T)
  		typeparam = "float";
  	else
  		printf("type de parametre de fonction non reconnu\n");
  	asprintf(&($$.code),"%s %s",typeparam,$2.var);
  }
;

statement
: compound_statement { $$ = $1; }  
| expression_statement { $$ = $1; }  
| selection_statement { $$ = $1; }  
| iteration_statement { $$ = $1; }  
| jump_statement { $$ = $1; }  
;

compound_statement
: '{' '}' {
	asprintf(&($$.code), "\n");
}
| '{' statement_list '}' {
	asprintf(&($$.code), "%s\n",$2.code);
}
| '{' declaration_list statement_list '}' {
	asprintf(&($$.code), "%s%s\n",$2.code,$3.code);
}
;

declaration_list
: declaration {$$=$1;}
| declaration_list declaration { asprintf(&($$.code),"%s%s\n",($1.code),$2.code); }
;

statement_list
: statement {$$=$1; }
| statement_list statement {
	asprintf(&($$.code),"%s%s\n",($1.code),$2.code);
}
;

expression_statement
: ';' {$$=EMPTY;}
| expression ';' {$$=$1;}
;

selection_statement
: IF '(' expression ')' statement{
    char* thenif = newlabel();	
    char* endif = newlabel();

    asprintf(&($$.code),"%sbr i1 %s, label %%%s, label %%%s\n%s:\n%sbr label %%%s\n%s:\n",$3.code,$3.var,thenif,endif,thenif,$5.code,endif,endif);	
}
| IF '(' expression ')' statement ELSE statement{
    char* thenif = newlabel();
    char* elseif = newlabel();
    char* endif = newlabel();

    asprintf(&($$.code),"%sbr i1 %s, label %%%s, label %%%s\n%s:\n%sbr label %%%s\n%s:\n%sbr label %%%s\n%s:\n",$3.code,$3.var,thenif,elseif,thenif,$5.code,endif,elseif,$7.code,endif,endif);
}
| FOR '(' expression_statement expression_statement expression ')' statement{

	char* cond = newlabel();
	char* body = newlabel();
	char* inc = newlabel();
	char* end = newlabel();

    asprintf(&($$.code),"%sbr label %%%s\n%s:\n%sbr i1 %s, label %%%s, label %%%s\n%s:\n%s\nbr label %%%s\n%s:\n%s\nbr label %%%s\n%s:\n",$3.code,cond,cond,$4.code,$4.var,body,end,body,$7.code,inc,inc,$5.code,cond,end);

}
;


iteration_statement
: WHILE '(' expression ')' statement {
	char* cond = newlabel();
	char* body = newlabel();
	char* end = newlabel();

	asprintf(&($$.code),"br label %%%s\n%s:%sbr i1 %s, label %%%s, label %%%s\n%s:\n%sbr label %%%s\n%s:\n",cond,cond,$3.code,$3.var,body,end,body,$5.code,cond,end);

}
| DO statement WHILE '(' expression ')' {
	char* cond = newlabel();
	char* body = newlabel();
	char* end = newlabel();

	asprintf(&($$.code),"br label %%%s\n%s:%sbr label %%%s\n%s:\n%sbr i1 %s, label %%%s, label %%%s\n%s:\n",body,body,$2.code,cond,cond, $5.code, $5.var,body,end,end);
}


jump_statement
: RETURN ';' { asprintf(&($$.code),"ret i1 0\n");} 
| RETURN expression ';' {
	//gen_t res;
	//res.var = newvar();
	//bug float*
	if($2.type == INT_T){
		asprintf(&($$.code),"%sret i32 %s",$2.code,$2.var);		
		//asprintf(&($$.code),"%s%s = load i32* %s\nret i32 %s",$2.code,res.var,$2.var,res.var);
	}
	else{
		asprintf(&($$.code),"%sret float %s",$2.code,$2.var);		
		//asprintf(&($$.code),"%s%s = load float* %s\nret float %s",$2.code,res.var,$2.var,res.var);
	}
}
;

program 
: external_declaration {printf("%s",$1.code);}
| program external_declaration {printf("%s",$2.code);}
;

external_declaration
: function_definition {$$=$1;}
| declaration {$$=$1;}
;

function_definition
: type_name declarator compound_statement {
	$$.var = newvar();
	char* typefonction;
	if(base_type==INT_T) typefonction="i32";
	else if (base_type==FLOAT_T) typefonction="float";
	else typefonction = "void";
	asprintf(&($$.code),"define %s @%s%s{\n%s\n}\n",typefonction,$2.name,$2.code,$3.code);
}
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
