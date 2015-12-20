/**
* nom : TEST GENERAL
* elements testes : tests de boucles et fonctions complexes, en utlisant tous les types implémentés
* resultat attendu : COMPILE
**/

int power(int a, int b){
	int i,res;
	res=1;
	for( i=0 ; i<b; i++){
		res = a*res;
	}
	return res;
}

int main() {

	int i,a,b,res;

	
	a = 8;
	
	for (i=0;i<10;i++){
		b=power(a,i);
	}
	
	while(i>=0){
		if(a*4>=a+12)
			b=a;
		else
			b=power(a,3);
		i--;
	}

	
	return a;
}
