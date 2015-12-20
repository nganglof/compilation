/**
* nom : TEST WHILE (1)
* elements testes : boucles while, boucles while imbriquees
* resultat attendu : COMPILE
**/

int main() {
	
	int a; 
    int i;
    int j;
	a = 0;  
    i = 0;
    
    while(i < 10) {
        a = a + 1;
        i++;
    }
    
    i = 0;
    while(i < 10)
        i++;
        
    while(i < 10);
    
    i = 0;
    while(i < 10) {
        j = 0;
        while(j < 10) {
            a = a + 1;
            j++;
        }
        i++;
    }

	return 0;
}
