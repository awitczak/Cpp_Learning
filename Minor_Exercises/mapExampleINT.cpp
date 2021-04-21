#include <iostream>
#include <map>

using namespace std;

int main() {
    // <key,value>
    map<string, int> Map; // after int: greater<> or less<> to sort the map
    
    Map["Adam"] = 121093;
    Map["Kasia"] = 2193;
    Map.insert(make_pair("Beboki",7888292));

    // looping through map
    for (auto &el: Map) {
        cout << el.first << " " << el.second << endl;
    }

    // possible to print also as:
    // cout << Map["Adam"] << endl;

    return 0;
}