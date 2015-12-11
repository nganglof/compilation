/**
* nom : TEST VARIABLES NON INITIALISEES
* elements testés : empeche l'utilisation de variables nom initialisées
* 
* resultat attendu : NE COMPILE PAS
* erreur: erreur: ‘a’ undeclared
**/

int main() {
	
	int i,j;
	
	i= 2;
	j = 3;
	a = i+j;
	
	return 0;
}
