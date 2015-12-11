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

float mystere(float x){
	
	int i,j;
	float res;
	
	i=0;
	res=0;
	do{
	 res += x*i;
	 for(j=0;j<i;j++){
		 if((j+i)%2==0){
			 res+=j;
		 }
		 else{
			 res-=j;
		 }
	 }
	}
	while(i<10);
	return res;
}

int main() {

	int i,a,b,res;
	int *t1;
	int t2[10];
	float *t3;
	float t4[20];
	
	a = 8;
	
	for (i=0;i<10;i++){
		t2[i]=power(a,i);
	}
	
	while(i>=0){
		if(t2[i]*4>=a+12)
			t1[i]=t2[i];
		else
			t1[i]=power(t2[i],3);
		i--;
	}
	
	if(a%2==0)
		t3=map(power,t4);
	else
		t3=reduce(mystere,t4);

	
	return a;
}
