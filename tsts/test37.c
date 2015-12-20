/**
* nom : TEST REDUCE (2)
* elements testes : cas d'erreur de fonction reduce
* resultat attendu : NE COMPILE PAS
**/

void foo(int a, int b) {
    return;
}

int bar(int a, float b) {
    return 1;
}

int main() {

    int a;
    int A[10];
    
    a = reduce(foo, A); //probleme de type (foo retourne void)
    
	return 0;
}
