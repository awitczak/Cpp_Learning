#include <iostream>
using namespace std;

main() {

    int a;
    int *b;
    a =11;

    cout << "a = " << a;
    cout << endl;

    b = &a;

    cout << " value of a variable pointed by b is equal " << *b;
    cout << endl;
    *b = 14;
    cout << "a = " << a;

    cout << endl;

return 0;
}
