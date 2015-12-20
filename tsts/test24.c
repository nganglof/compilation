/**
* nom : TEST FOR (1)
* elements testes : boucle for, boucles for imbriquees
* resultat attendu : COMPILE
**/

int main() {
	
	int a; 
	int b; 
	int c; 
	int d; 
    int i;
    int j;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    for(i = 0; i < 10; i++) {
        a = a + 1;
    }
    
    for(i = 0; i < 10; i++)
        b = b + 1;
        
    for(i = 0; i < 10; i++);
    
    
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            c = b + 1;
        }
        c = c * 2;
    }
    
    for(i = 0; i < 100; i = i * 2)
        for(j = 0;  j < i; j = i + j)
            d = d + 1;

	return 0;
}
