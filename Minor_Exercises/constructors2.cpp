#include <iostream>
using namespace std;

class processor {
    int n_thr, n_cores;
        public: 
            processor(int, int); // this is the constructor
            void disp_param();
};

processor::processor(int a, int b) {
    n_thr = a;
    n_cores = b;
}

void processor::disp_param() {
    cout << "\nProcessor has " << n_thr << " threads";
    cout << "\nProcessor has " << n_cores << " cores";
}

main() {
    processor i5(4,4);
    processor i7(8,4);

    cout << "This software stores and displays the information about processors" << endl;
    cout << "\n\ti5\n";
    i5.disp_param();

    cout << endl;

    cout << "\n\ti7\n";
    i7.disp_param();

    cout << endl;

    return 0;
}