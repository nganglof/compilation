/**
* nom : TEST COMPARAISONS INT/FLOAT
* elements testés : comparaisons entre un entier et un float (<,<=,>,>=,==,!=)
* 
* resultat attendu : COMPILE
**/

int main() {
	
	int i;
	float f;
	
	int r1, r2, r3, r4, r5, r6, r7;
	
	i=7;
	f=7.3;
	
	r1 = i < f;		// r1 = 1
	r2 = i <= f;	// r2 = 1
	r3 = i > f;		// r3 = 0
	r4 = i >= f;	// r4 = 0
	r5 = i == f;	// r5 = 0
	r6 = i != f;	// r6 = 1
	
	i=3;
	f=3.0;

	r1 = i < f;		// r1 = 0
	r2 = i <= f;	// r2 = 1
	r3 = i > f;		// r3 = 0
	r4 = i >= f;	// r4 = 1
	r5 = i == f;	// r5 = 1
	r6 = i != f;	// r6 = 0
	
	return 0;
}
