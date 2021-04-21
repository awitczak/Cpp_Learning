#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    multimap<char, int> Multimap;
    Multimap.insert(pair<char,int>('a',1)); // different way
    Multimap.insert(make_pair('a',2));
    Multimap.insert(make_pair('a',3));
    Multimap.insert(make_pair('b',4));
    Multimap.insert(make_pair('b',5));
    Multimap.insert(make_pair('b',6));


    // iterates over whole multimap
    for (auto &el: Multimap) {
        cout << el.first << " " << el.second << endl;
    }

    // all pairs of a given key
    auto range = Multimap.equal_range('a');
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->first << " " << it -> second << endl;
    }

    return 0;
}