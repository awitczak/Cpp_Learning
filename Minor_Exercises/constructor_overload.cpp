#include <iostream>
using namespace std;

class processor {
    int n_thr, n_cores;
    public:
        processor(); // no argument constructor
        processor(int, int); // two argument constructor
        processor(int); // one argument constructor
        void disp_param();
};

processor::processor(int a, int b) {
    n_thr = a;
    n_cores = b;
}

processor::processor() {
    n_thr = 1;
    n_cores = 1;
}

processor::processor(int a) {
    n_thr = 1;
    n_cores = a;
}

void processor::disp_param() {
    cout << "\nProcessor has " << n_thr << " threads";
    cout << "\nProcessor has " << n_cores << " cores";
}

main() {
    processor i5(4,4);
    processor i7(8,4);
    processor p3;
    processor c2d(2);

    cout << "This software stores and displays the information about processors" << endl;

    cout << "\n\ti7\n";
    i7.disp_param();

    cout << endl;

    cout << "\n\ti5\n";
    i5.disp_param();

    cout << endl;

    cout << "\n\tp3\n";
    p3.disp_param();

    cout << endl;

    cout << "\n\tc2d\n";
    c2d.disp_param();

    cout << endl;

    return 0;
}