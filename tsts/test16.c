/**
* nom : TEST TABLEAUX
* elements testes : instanciations et affectations illegales de tableaux
* resultat attendu : NE COMPILE PAS
**/

int main() {

    int A[10];
    
    A[20] = 1; // Affectation illegal en dehors du tableau A
    A[5.5] = 1; // Erreur d'index

    return 0;
}
