#include <iostream>

using namespace std;

int k_esimo(int vet[], int n, int k){
	for (int i = 0; i < k; ++i)
		for (int j = i+1; j < n; ++j)
			if(vet[i] >= vet[j])
				std::swap(vet[i], vet[j]);

	return vet[k-1];
}

int main(int argc, char const *argv[])
{
	int vet[11] = {3, 4, 5, 1, 2, 10, 1, 8, 12, 3, 3};
	cout << k_esimo(vet, 11, 11);
	return 0;
}
