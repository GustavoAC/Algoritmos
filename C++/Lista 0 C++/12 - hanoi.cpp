#include <iostream>

using namespace std;

void hanoi(int h, char O, char D, char T){
	if(h > 0){
		hanoi(h - 1, O, T, D);
		std::cout << "Movido de " << O << " para " << D << endl;
		hanoi(h - 1, T, D, O);
	}
}

int main(){
	int h;
	std::cout << "Insira o tamanho da torre.\n";
	std::cin >> h;

	hanoi(h, 'A', 'C', 'B');
	return 0;
}