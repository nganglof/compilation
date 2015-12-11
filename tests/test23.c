/**
* nom : TEST DO wHILE (1)
* elements testes : tests de la boucle do while
* resultat attendu : COMPILE
**/

int main() {
	
	int i;
	int a,b,c,d;
	
	i=0;
	
	do;
	while(1);

	do{
	}
	while(0);
	
	do
		i++;
	while(i<20);
	
	do{
		a=+b;
		c--;
	}
	while( a != b && c>d);
	
	return 0;
}
