#include <iostream>

int main() {
    std::cout << "Let's calculate the area of a square\n"
    << "To do so, we will need the length of the side of a square, \n"
    << "which, unfortunately, is not available for this software yet. \n"
    << "Type in the length of the square's side: "; int length;
    std::cin >> length;
    std::cout << "\n";
    int p;
    p = length * length;
    std::cout << "The area of a square is equal to: " << p << "\n";
return 0;
}