#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream file;
    file.open("123.txt", ios::in | ios::out);

    if (file.good() == true) {
        cout << "File access granted!" << endl;
    }
    else cout << "File access forbidden" << endl;
    file.close();

return 0;
}
