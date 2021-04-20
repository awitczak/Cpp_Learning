#include <iostream>

using namespace std;

class number {
    static int i;
    public:
    number() {
        cout << i-- << endl;
    }
};

int number::i = 100;
int main() {
    number numbers[100];
    return 0;
}