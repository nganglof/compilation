/**
* nom : TEST MAP (1)
* elements testes : fonction map
* resultat attendu : COMPILE
**/

int incremente(int i) {
    return i++;
}

float settohalf(int i) {
    return 0.5;
}

int main() {
	
    int A[];
    int B[10];
    float C[10];
    
    A = map(incremente, B); //map avec fonction avec parametre et retour de meme type
    A = map(incremente, map(incremente, B))
    C = map(settohalf, A); //map avec fonction avec parametre et retour de type different
    
	return 0;
}
