#include <iostream>

using namespace std;

int fib(int a){
	if(a <= 1) return a;
	else return fib(a-1) + fib(a-2);
}

int main()
{
	int input;
	std::cin >> input;

	for (int i = 1; fib(i) < input; i++)
	{
		std::cout << fib(i) << " ";
	}
}

