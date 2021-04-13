#include <iostream>


// possible labels for classes: public, private, protected
class processor {
    public:
        int n_cores;
        float clk_spd;
        int n_thr;
        char name[80];
};

// class with functions as elements
class phone {
    public:
        void call(int num);
        void vibrate(bool vib);
        int phone_num;
        bool vibration;
        char cont_name[80];
        char disp_call_name(char cont[]);
};

int main() {

    processor i5;    // definition of object specimen
    processor *ptr;  // definition of pointer
    // processor &ifive; // definition of reference

    // associating values of elements
    i5.n_cores = 4;

    ptr = &i5;
    ptr -> n_cores = 4;
    
    // ifive.n_cores = 4;

    return 0;
}