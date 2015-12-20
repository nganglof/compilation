/**
* nom : TEST DO WHILE (2)
* elements testes : cas d'erreur de la boucle do while
* resultat attendu : NE COMPILE PAS
**/

int main() {
	
	int i,a,b,c;
	
	i=0;
	
	do;
	while();

	do;
	while(1;2);
	
	do
	while(i<10);

	do{
		i--;
	}
	do{
		a=3;
	}
	while(a>i);
	
	do i++;
	
	return 0;
}
