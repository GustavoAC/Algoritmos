#include <iostream>

using namespace std;

void inverteVetor(int *piVet, const int tam){
	for (int i = 0; i < tam/2; ++i)
        std::swap(*(piVet+i),*(piVet+tam-i-1));
}

int main(int argc, char const *argv[]){
	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, tam(10);
	inverteVetor(vet, tam);
	for (int i = 0; i < tam; ++i){
		std::cout << vet[i] << "\n";
	}

	return 0;
}
