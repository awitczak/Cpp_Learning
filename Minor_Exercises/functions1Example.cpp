#include <iostream>
using namespace std;

float rect_area(float side1, float side2);


int main() {
    float a,b,area;
    cout << "Enter the length of the first side: ";
    cin >> a;
    cout << endl << "Enter the length of the second side: ";
    cin >> b;
    cout << endl;
    cout << "Your rectangle has sides of lengths equal to: a = " << a;
    cout << ", b = " << b;
    cout << endl;
    area = rect_area(a,b);
    cout << "The area of your rectangle is: " << area << endl;
return 0;
}


float rect_area(float side1, float side2) {
    float result;
    result = side1*side2;
    cout << "Calculating the area... \n\n";
    
return result;
}