#include <iostream>

using namespace std;

int main() {
    int i=0, hmany=0;
    cout << "Enter the number of subsystems: ";
    cin >> hmany;
    cout << endl;
    cout << "Begin to scan the subsystems" << endl;
    for (i = 1; i <= hmany; i++) {
	cout << "Subsystem " << i << " scanned" << endl;
    }
    cout << "Scan finished. No anomalies found. \n";

return 0;    
}