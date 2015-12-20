/**
* nom : TEST TABLEAUX
* elements testes : instanciations et affectations legales de tableaux
* resultat attendu : COMPILE
**/

int main() {

    int A[];
    float B[];

    int C[100];
    float D[100];
    
    int E[200];
    float F[200];
    
    C = E;
    D = F;
    A = C;
    B = D;

    return 0;
}
