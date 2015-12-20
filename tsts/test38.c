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
    
    a = reduce(bar, A); //probleme de type (bar admet un float en parametre)
    
	return 0;
}
