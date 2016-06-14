#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1, x2, y2, d;
	std::cout << "Insira o X e o Y do ponto 1.\n";
	std::cin >> x1;
	std::cin >> y1;
	std::cout << "Insira o X e o Y do ponto 2.\n";
	std::cin >> x2;
	std::cin >> y2;

	d = std::sqrt(std::pow(x2-x1, 2) + std::pow(y2 - y1, 2));

	std::cout << "A distancia entre os pontos eh " << d << ".\n";

	return 0;
}
