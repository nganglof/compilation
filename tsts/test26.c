/**
* nom : TEST FOR (2)
* elements testes : cas d'erreurs de la boucle for
* resultat attendu : NE COMPILE PAS
**/

int main() {
	
	int a;
    int i;
    int j;
    a=0;
    for(i = 0; i < 10; i++; j++) { //trop d'arguments
        a = a + 1;
    }

	return 0;
}
