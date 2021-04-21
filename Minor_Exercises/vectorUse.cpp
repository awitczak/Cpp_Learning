#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> Vec;

    Vec.reserve(16); // reserving initial amount helps to reduce the time needed for the program to run, as there is less copying

    for (int i = 0; i < 18; ++i) {
        Vec.push_back(i);
        cout << Vec.size() << " " << Vec.capacity() << endl;
    }
    return 0;
}