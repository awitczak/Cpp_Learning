#include <iostream>

// friend function has access to all members of a class (also private and protected) 

using namespace std;

class door; // declaration of the class
class home {
    private:
        bool flowerHydr;

    public: 
        home(bool v) {flowerHydr = v;}

        void dayPassed() {
            flowerHydr = 0;
            cout << "day has passed, flower needs water" << endl;
        }
        void ownerHydFlower() {
            flowerHydr = 1;
            cout << "flower has been hydrated by the house" << endl;
        }

        friend void gardener(home &h, door &d);
};

class door {
    bool lock;

    public: 
    door (bool v) {lock = v;}

    void openDoor() {
        lock = 0;
        cout << "door has been opened" << endl;
    }
    void closeDoor() {
        lock = 1;
        cout << "door has been closed" << endl;
    }

    friend void gardener(home &h, door &d);
};

void gardener(home &h, door &d) {
    d.openDoor();
    h.flowerHydr = 1;
    cout << "flower has been hydrated by gardener" << endl;
    d.closeDoor();
}

main() {
    home h1(0);
    door d1(1);

    h1.ownerHydFlower();
    cout << "Owner: It is time for adventure! Gardener will take care of my flower!" << endl;
    d1.openDoor();
    cout << "Owner left" << endl;
    d1.closeDoor();
    h1.dayPassed();
    gardener(h1,d1);

    return 0;
}