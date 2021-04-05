#include <iostream>
using namespace std;

main() {

    int mass = 135, *weig, choic = 0;
    float km = 14.96, *power;
    void *poit;
    power = &km;
    weig = &mass;
    cout << "Choose a motorbike with the engine capacity up to 125 cm^3\n"
    << "Which parameter is the most important for you?\n"
    << "\t1. Mass\n"
    << "\t2. Engine power\n"
    << "Type down your choice: ";

    cin >> choic;

    if (choic == 1) {
        poit = weig;
        cout << "Motorbike for you: Yamaha Virago 125\n"
        << "Its mass is: " << *(int*)poit << "kg" << endl;
    }

    if (choic == 2) {
        poit = power;
        cout << "Motorbike for you: Honda VT Shadow 125\n"
        << "Its power is: " << *(float*)poit << "KM" << endl;
    }

return 0;}
