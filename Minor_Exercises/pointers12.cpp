#include <iostream>
using namespace std;

main() {

    float tab[4] = {7.23, 12.46, 16.12, 23.28};
    float *ptr;
    ptr = tab;

    cout << "The earlies train from Krakow to "
    << "Milk & Honey land departures at: "
    << *ptr << endl;
    ptr = ptr + 1;
    cout << "Next train departures at: " << *ptr << endl;
    ptr++;
    cout << "Next train departures at: " << *ptr << endl;
    ptr += 1;
    cout << "The last train departures at: " << *ptr << endl;

return 0;
}
