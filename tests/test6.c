/**
* nom : TEST FLOAT
* elements testés : declaration, affectation, operations, et retour de flottant
* 
* resultat attendu : COMPILE
**/

int main() {
	
	float a,b;
	float r1,r2,r3,r4;
	
	a=7.6;
	b=3.2;

	r1=a-b;
	r2=a+b;
	r3=a/b;
	r4=a*b;
	
	return r1+r2*(r3/r4);
}
