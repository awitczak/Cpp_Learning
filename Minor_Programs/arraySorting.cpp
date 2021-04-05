#include <iostream>

using namespace std;

void arraySorting(int sortThis[], int s);

int main() {
    int i;
    int sortThis[] = {1,4,5,6,2,2,9,2,7,3};
    int s = sizeof(sortThis)/sizeof(sortThis[0]);

    cout << "Not sorted: " << endl;
    for (i = 0; i < s; i++){
        cout << sortThis[i] <<" ";
    }
    cout << endl;

    arraySorting(sortThis, s);

    cout << "Sorted: " << endl;
    for (i = 0; i < s; i++) {
        cout<< sortThis[i] <<" ";
    }
return 0;
}

void arraySorting(int sortThis[],int s) {
    int i,j,temp;
    int *ptr_sortThis;

    ptr_sortThis = sortThis;

    for (i = 0; i < s - 1; i++) {
        for (j = i + 1; j < s; j++) {
            if (*(ptr_sortThis + j) < *(ptr_sortThis + i)) {
                temp = *(ptr_sortThis + i);
                *(ptr_sortThis + i) = *(ptr_sortThis + j);
                *(ptr_sortThis + j) = temp;
            }
        }
    }

}
