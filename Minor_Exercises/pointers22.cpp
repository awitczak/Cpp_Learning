#include <iostream>
using namespace std;

float average(float a, float tab[]);

main() {
    int size = 0, i;
    float *ptr, result;
    cout << "The software will calculate the arithmetic average of a few numbers\n ";
    cout << "Type in how many numbers you like to use to calculate the average: ";
    cin >> size;
    ptr = new float[size];

    for (i = 0; i < size; i++) {
        cout << "Type in the value for the " << i+1 << " element: ";
        cin >> ptr[i];
        cout << endl;
    }
    cout << "I will calculate the average of the following numbers: ";
    for (i = 0; i < size; i++) {
        cout << ptr[i] << ", ";
    }
    cout << endl;
    result = average(size,ptr);
    cout << "The average of the above numbers is: " << result << endl;

    delete ptr;
    ptr = NULL;

return 0;
}

float average(float a, float tab[]) {
    int b;
    float avg;
    for (b = 0; b < a; b++) {
        avg += tab[b];
    }
    avg /= a;
    return avg;
}
