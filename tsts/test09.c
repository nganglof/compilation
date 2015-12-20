/**
* nom : TEST OPERATIONS INT/FLOAT
* elements testés : operations entre un entier et un float
* 
* resultat attendu : COMPILE
**/

int main() {
	
	int x,i;
	float y,f;
	
	x=4;
	y=4.5;

	x=y;	//x=4
	y=x;	//y=4.0

	i=2;
	f=3.5;
	
	x=i+f;	//x=5
	y=i+f;	//y=5.2
	
	x=i-f;	//x=-1
	y=i-f;	//y=-1.2	

	x=i*f;	//x=6
	y=i*f;	//y=6.4

	x=i/f;	//x=0
	y=i/f;	//y=0.625
		
	return 0;
}
