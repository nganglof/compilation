/**
* nom : TEST OPERATIONS && et || SUR DES FLOATS
* elements testés : tests les opérateurs && et || sur des entiers
* 
* resultat attendu : NE COMPILE PAS
* opérateurs && and || ne s'appliquent pas sur des flottants
**/

int main() {
	
	float i,j;
	int r1, r2;
	
	i=0;
	j=7;
	
	r1 = i && j; //erreur opérateur
	r2 = i || j; //erreur opérateur
	
	return 0;
}
