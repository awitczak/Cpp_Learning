#include <iostream>
using namespace std;

int main() {
int age=0, years=0;
    cout << "How old are you? \n";
    cin >> age;
    cout << endl;
    
while (age < 24) {
    age++;
    years++;
}

if (age < 25) {
    cout << "Theoretically in " << years;
    if (years == 1) cout << " years";
    else if (years > 1 && years < 5) cout << " years";
    else if (years >= 5|| years == 0) cout << " years";
    cout << " you will graduate. \n";
}

else cout << "So old and still studying at the University... \n";

return 0;
}
