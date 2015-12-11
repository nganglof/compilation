/**
* nom : TEST TYPE VARIABLES (2)
* elements testés : types de variable non acceptées : short, long, double, pointeurs, char
* 
* resultat attendu : NE COMPILE PAS
* erreur: unknown type name
**/

int main() {
	
	short a;
	double b;
	long c;
	
	int *i1;
	int* i2;
	int*i3;
	
	void *v;
	
	unsigned int d;
	
	return 0;
}
