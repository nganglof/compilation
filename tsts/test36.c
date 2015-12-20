/**
* nom : TEST REDUCE (1)
* elements testes : fonction reduce
* resultat attendu : COMPILE
**/

int additionne(int i, int j) {
    return i + j;
}

float mult(float i, float j) {
    return i + j;
}

int main() {

    int a;
    float b;
    
    int A[10];
    float B[10];
    
    a = reduce(additionne, A);
    b = reduce(mult, B);
    
	return 0;
}
