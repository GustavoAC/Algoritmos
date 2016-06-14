#include <iostream>// Basic I/O.

using namespace std;

int maiores(const int* const vet, const int n, const int x){
    int num(0);
    for (int i = 0; i < n; i++){
        if(vet[i] > x)
            num++;
    }

    return num;
}

int main(){
   const int vet[10] = {1, 4, 12, 3, 6, 3, 5, 8, 9, 10};
   const int n = 10, x(7);
   int num = maiores(vet, n, x);
   std::cout << "Existem " << num << " numeros maiores que " << x << " no vetor.\n";

}

