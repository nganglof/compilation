/**
* nom : TEST TABLEAUX
* elements testes : instanciations et affectations illegales de tableaux
* resultat attendu : NE COMPILE PAS
**/

int main() {

    int C[100];
    float D[100];
    
    int E[200];
    float F[200];
    
    E = C; //affectation illégale
    F = D; //affectation illégale
    

    return 0;
}
