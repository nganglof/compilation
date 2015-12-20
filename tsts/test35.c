/**
* nom : TEST MAP (2)
* elements testes : cas d'erreurs de la fonction map
* resultat attendu : NE COMPILE PAS
**/

void foo(int i) {
    return i++;
}

int bar(int i) {
    return i++;
}

int foobar(int i) {
    
}

int main() {
	
    int A[];
    int B[10];
    float C[10];
    int D[20];
    
    D = map(foobar, B); //Erreur d'affectation de tableau (taille de D > taille de B)
    
	return 0;
}
