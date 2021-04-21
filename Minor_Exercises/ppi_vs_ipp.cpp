#include <iostream>

using namespace std;

int main() {

    // i++ increments value of i, but returns original value, that i held before incrementation
    // ++i inctrements value of i and returns incremented value

    int i = 1;
    cout << "Using i++, while i = 1: " << i++ << endl;
    i = 1;
    cout << "Using ++i, while i = 1: " << ++i << endl;


    return 0;
}