#include <iostream>

using namespace std;

class processor {
    int n_thread;
    int n_core;
        public:
            int proc_param(int thr, int cores) {
                n_thread = thr;
                n_core = cores;
                
                return 0;
            }
        void disp_param();
};

void processor::disp_param() {
    cout << "Processor has " << n_thread << " threads" << endl;
    cout << "Processor has " << n_core << " cores" << endl;
}

int main () {
    processor i5, i7;

    cout << "Program stores and displays the processors data" << endl;

    i5.proc_param(4,4);
    i7.proc_param(8,4);

    cout << "i5: " << endl;
    i5.disp_param();

    cout << endl;

    cout << "i7: " << endl;
    i7.disp_param();

    return 0;
}