#include <iostream>

extern "C" {
	extern long long plus(int a, int b);
}

int main() {
	int a,b;
	std::cin >> a >> b;
	std::cout << plus(a, b) << std::endl;
	return 0;
}
