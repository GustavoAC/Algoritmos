#include <iostream>

using namespace std;

void ShiftN(int *n1, int *n2,int *n3,int *n4,int d){
    for (int i = 0; i < d; i++){
        std::swap(*n1, *n2);
        std::swap(*n1, *n3);
        std::swap(*n1, *n4);
    }
}

int main(){
   int n1, n2, n3, n4, d;
   std::cout << "Insira os 4 numeros e o numero de deslocamentos.\n";
   std::cin >> n1 >> n2 >> n3 >> n4 >> d;
   d %= 4;
   ShiftN(&n1, &n2, &n3, &n4, d);

   std::cout << "Resultado final: ( " << n1 << " " << n2 << " " << n3 << " " << n4 << " ).\n";


}

