#include <iostream>
using namespace std;

void zer (int &valu, int &ref);
void nzer (int valu, int ref);

int main () {
     int a = 44, b = 77;
     cout << "Before executing function nzer: \n";
     cout << "a = " << a << ",b = " << b << endl;
     nzer ( a,b);
     cout << "After the execution of function nzer: \n";
     cout << "a = " << a << ",b b = " << b << endl;
     cout << "Before executing function zer: \n";
     cout << "a = " << a << ", b = " << b << endl;
     zer (a,b);
     cout << "After the execution of function zer:\n";
     cout << "a = " << a << ", b = " << b << endl;
    
return 0;
}

void zer(int &valu, int &ref)
{
    cout << "\tIn function zer before zeroing: \n";
    cout << "\tvalu = " << valu << ", ref = "
    << ref << endl;
    valu = 0;
    ref = 0;
    cout << "\tIn function zer after zeroing: \n";
    cout << "\tvalu = " << valu << ", ref = "
    << ref << endl;
}

void nzer (int valu, int ref)
{
     cout << "\tIn function nzer before zeroing: \n";
     cout <<"\tvalu = " << valu << ", ref = "
     << ref << endl;
     valu = 0;
     ref = 0;
     cout << "\tIn function nzer after zeroing: \n";
     cout << "\tvalu = " << valu << ", ref = "
     << ref << endl;
}
    

    