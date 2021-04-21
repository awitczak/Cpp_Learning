#include <iostream>
#include <vector>

using namespace std;

class Point {
    public: 
        int x,y;
        Point() {
            x = 0;
            y = 0;
        }
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
    
    void displayPoint();
};

void Point::displayPoint() {
    cout << "The x-coordinate is equal to: " << x << endl;
    cout << "THe y-coordinate is equal to: " << y << endl;
}

int main() {

    // creating a vector of a class Point and displaying the information stored

    vector<Point> positions;
    positions.push_back(Point(1,2));
    positions.push_back(Point(1,3));

    // positions[0].displayPoint(); 

    // size() returns the number of elements in the vector
    // (actual number of objects held in vector, not necessarily equal to its storage capacity)
    for (int i = 0; i < positions.size(); i++) {
        positions[i].displayPoint();
    }


    vector<int> number;
    number.push_back(1);
    number.push_back(4);
    number.push_back(5);
    number.push_back(6);
    number.push_back(2);

    // or passing array
    // this breaks the loop below, the 1,4,5,6,2 entries are correctly placed, however the loop does not stop there
    int arr[] = {1,4,5,6,2};
    vector<int> number_arr(arr,arr+5); 

    // other option in C++11
    // works fine
    vector<int> number_otherOpt{1,4,5,6,2};

    // loop for displaying the information of a vector with single size
    for (vector<int>::const_iterator i = number_otherOpt.begin(); i != number_otherOpt.end(); ++i) {
        cout << *i << ' ';
    }
    

    return 0;
}