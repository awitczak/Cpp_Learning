#include <iostream>
# define M_PI           3.14159265358979323846  /* pi */
#include<windows.h>


using namespace std;

float areaTriangle();
float areaCircle();
float areaSquare();
float areaParallelogram();
float areaRhombus();
int menu();

int main() {
    float result;
    int choice;
    int quit = 0;

    while (quit == 0) {
        system("CLS");
        choice = menu();
        cout << "\n\nYou want to calculate the area of a " << choice << ".";

        switch(choice) {
            case 1:
                system("CLS");
                result = areaTriangle();
                break;
            case 2:
                system("CLS");
                result = areaCircle();
                break;
            case 3:
                system("CLS");
                result = areaSquare();
                break;
            case 4:
                system("CLS");
                result = areaParallelogram();
                break;
            case 5:
                system("CLS");
                result = areaRhombus();
                break;
            case 6:
                system("CLS");
                quit = 1;
                exit(6);
            default:
                system("CLS");
                cout << "Invalid entry!\n";
                for (int i = 0; i < 3; i++) {
                    cout << ".\n";
                    Sleep(500);
                }
                continue;
        }
        cout << "\n----------------------------------------------";
        cout << "\n\n\nThe area of this figure is equal to: " << result;
        Sleep(5000);
    }

    return 0;
}

int menu() {
    int choice;
    cout << "   --- Online area calculator ---";
    cout << "\n1. triangle";
    cout << "\n2. circle";
    cout << "\n3. square";
    cout << "\n4. Parallelogram";
    cout << "\n5. Rhombus";
    cout << "\nChoose the integer representing your figure: ";

    cin >> choice;

    while(cin.fail()) {
        cout << "Error! Please enter an integer: " << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
        system("CLS");
    }

    return choice;
}

float areaTriangle() {
    float a;
    float h;
    cout << "Please enter the base length of your triangle: ";
    cin >> a;
    cout << "\nPlease enter the height of your triangle: ";
    cin >> h;
    float A = a*h/2;

    return A;
}

float areaCircle() {
    float r;
    cout << "Please enter the radius: ";
    cin >> r;
    float A = r*r*M_PI;

    return A;
}

float areaSquare() {
    float a;
    cout << "Please enter the base length of your square: ";
    cin >> a;
    float A = a*a;

    return A;
}

float areaParallelogram() {
    float a, h;
    cout << "Please enter the base length: ";
    cin >> a;
    cout << "\nPlease enter the height: ";
    cin >> h;
    float A = a*h;

    return A;
}

float areaRhombus() {
    float e, f;
    cout << "Please enter e: ";
    cin >> e;
    cout << "\nPlease enter f: ";
    cin >> f;
    float A = e*f/2;

    return A;
}
