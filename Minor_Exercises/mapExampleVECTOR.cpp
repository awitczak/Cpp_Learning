#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    map<string, vector<int>> Map; // greater<> or less<> to sort the map
    
    Map["Adam"].push_back(121093);
    Map["Kasia"].push_back(2193);

    // possible to get multiple numbers for each keyword
    Map["Adam"].push_back(100);

    // looping through map
    for (auto &el1: Map) {
        cout << el1.first << " ";
        for (auto &el2: el1.second) {
            cout << el2 << " ";
        }
        cout << endl;
    }

    // possible to print also as:
    // cout << Map["Adam"] << endl;

    return 0;
}