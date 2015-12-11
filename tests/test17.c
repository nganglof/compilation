/**
* nom : TEST IF (1)
* elements testes : boucles if, tests conditions, if imbriqués
* resultat attendu : COMPILE
**/

int main() {
	
	int i;
	int a,b,c,d;
	
	a = 2;
	b = 0;
	c = 100;
	c = 50;
	
	if(1);
	
	if(a>0)
		a++;
	
	if(a++<c){
		b = b +1;
	}
	
	if(a==b){
		c=10;
	}
	else{
		b=3;
	}
	
	if(a==b && c>0){
		b+=6;
		if(d<=c){
			d--;
		}
		else{
			d++;
		}
	}
	else{
		c = b && c;
		if(1)
			c--;
	}

	return 0;
	
	
}
