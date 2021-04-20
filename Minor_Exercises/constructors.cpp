// constructor is a special class member function, which has the same name as the class. In the constructor body, instructions used to set the initial values of the object elements are placed.

#include <iostream>
using namespace std;

class number {
    int value;
        public: 
            number(int l) { value = l; } // this is the constructor
            void disp() { cout << value << endl; }
};

main() {
    number f = number(5);
    number s(7);

    cout << "five = ";
    f.disp();

    cout << "seven = ";
    s.disp();
}