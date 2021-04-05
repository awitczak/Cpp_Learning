#include <iostream>
using namespace std;

void pizza(int *lpi, float *money);

main() {

    int pizza_no = 0;
    float pln = 134.28;
    cout << "You currently have " << pizza_no << " pizza.\n";
    cout << "And you have " << pln << " PLN." << endl;
    cout << "It is time to order some pizza!" << endl;

    pizza(&pizza_no, &pln);

    cout << "Your delivery just arrived\n";
    cout << "Now, you have " << pizza_no << " pizza. \n";
    cout << "And have left " << pln << " PLN." << endl;


return 0;
}

void pizza(int *lpi, float *money) {
    *lpi = 2;
    *money = 62.47;
}
