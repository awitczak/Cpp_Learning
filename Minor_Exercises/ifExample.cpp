#include <iostream>

int main() {
    int a = 1, b = 2, c = 3;
    
    if (a) std::cout << "Variable a is not equal to 0 and its value"
	<< " is: " << a << "\n";
	
    if (a > b)std::cout << "it will not display\n";
    else std::cout << a << " is smaller than " << b << "\n";
    if (c < b) std::cout << "it will not display\n";
    else if (b = 2) {
	b++;
	std::cout<< "b = " << b << "\n";
    }
return 0;
}