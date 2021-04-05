#include <iostream>
using namespace std;

char *createobject(void);

main() {

    char *ptr1, *ptr2, *ptr3;

    cout << "Now we will see a creation!\n";

    ptr1 = createobject();
    ptr2 = createobject();
    ptr2 = createobject();

    *ptr1 = 'a';
    *ptr2 = 'b';

    cout << "\nWe created three new objects.\n"
    << "Two of them have values: " << *ptr1 << ptr2 << endl
    << "From the third we can see only junk: " << *ptr3 << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

return 0;
}

char *createobject(void) {
    char *w;
    cout << endl << "We create an object!" << endl;
    w = new char;
    return w;
}
