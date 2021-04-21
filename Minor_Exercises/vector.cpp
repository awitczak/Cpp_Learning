#include <iostream>
#include <vector>

using namespace std;

int main() {

    // declarations 
    vector<int> arr1;
    vector<int> arr2 (5, 20);
    vector<int> arr3 = {1,2,3,4,5}; // initializer list
    vector<int> arr4 {1,2,3,4,5}; // uniform initialization

    // accessing elements
    // at(), front() - first element, back() - last element, data()

    // modifiers
    // insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()
    arr2[3] = 10;
    arr2.at(3) = 10;

    cout << arr2[3];


    return 0;
}