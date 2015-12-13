int main() {
	int x;
  float y;
  y=3.5;
  x=y+2;
}

//%type <g> external_declaration function_definition declaration compound_statement type_name declarator_list statement_list statement declaration_list
//%type <g> expression_statement selection_statement iteration_statement jump_statement expression


//{printf("%s\n",$1.code); }
// {asprintf(&($$.code),"%s\n",($1.code));}


/*
  if(isEmpty(unary)){
    printf("ERREUR : variable non initialisée\n");
  }
  else{
    $$.var = unary.var;
    asprintf(&($$.code), "%s%s%s = load i32* %s\n", $1.code, $3.code,$$.var,$3.var);
  }


$$.var = unary.var;
    asprintf(&($$.code), "%s%s%s = load i32* %s\n", $1.code, $3.code,$$.var,$3.var);
  


*/