/**
* nom : TEST PORTEE
* elements testes : portée des variables
* resultat attendu : erreur : variable non déclarée
**/
int foo(int f){
	f = a;
	return f;
}

int main(int c) {
  int a;
  int b;
  a = 5;
  b=foo(3);

  return a;
}
