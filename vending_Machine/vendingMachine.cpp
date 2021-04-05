#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstring>

#define MAX_PRODUCTS 50

using namespace std;

struct machineData {
    string items[MAX_PRODUCTS];
    int onStock[MAX_PRODUCTS];
    int price[MAX_PRODUCTS];
    string ifReplenish[MAX_PRODUCTS];
    int cashPool[6];
};

int howManyProducts;

int menu(machineData dataInfo);
int menuSupervision();
void amountQuestion (int choiceF, machineData dataInfo);
machineData dataRead();
void dataWrite(machineData dataInfo, int changeGiven);
void replenishTenOnStart(machineData dataInfo);
void maximalCapacityBreached();
int payment(float howMuch, int *ptr_coinsInMachine);
int givingChange(float howMuch, float howMuchPaid, int *ptr_coinsInMachine, float coins[]);
float round(float roundThis);
int mostCoins(int *firstEntry, int *lastEntry);
float checkingMaxChange(int *ptr_coinsInMachine, float coins[]);
int alphabeticalProductSorting();
string localTimeToDataName();
void timeTxt(string filename, string sortingInfoMessage);


int main() {

    machineData data;
    float sum = 0;
    int howMuchSold;
    int quit = 0, skip;
    int choice;
    int choiceOperator;
    float amount = 0;
    //int maxStock[howManyProducts] = {500,500,500,500,500,10,10,500};
    float coinNominals[6] = {5,2,1,0.5,0.2,0.1};
    string pswd = "blank";
    string pswdCorrect = "qwerty123";
    string filename;

    data = dataRead();
    maximalCapacityBreached();
    replenishTenOnStart(data);

    while (TRUE) {
        skip = 0;
        data = dataRead();
        Sleep(250);

        int choice = menu(data);

        if (choice > 0 && choice <= howManyProducts) {
            amountQuestion(choice,data);
                cin >> amount;
        }
        else if (choice == 100) {
            quit = 0;
            system("CLS");
            cout << "Enter the password: ";
            cin >> pswd;
            if (pswd != pswdCorrect) {
                cout << "\nIncorrect password!";
                Sleep(2000);
                continue;
            }
            else {
                while (quit == 0) {
                    choiceOperator = menuSupervision();

                    while(cin.fail()) {
                        cout << "Error! Please enter an integer: " << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> choiceOperator;
                        system("CLS");
                    }

                    switch(choiceOperator) {
                        case 1:
                            sum = 0;
                            for (int i1 = 0; i1 < 6; i1++){
                                sum = sum + data.cashPool[i1] * coinNominals[i1];
                            }

                            cout << "The amount of money in the machine: " << sum << "PLN" << endl;
                            cout << endl;
                            system("pause");
                            continue;
                        case 2:
                            for (int i2 = 0; i2 < howManyProducts; i2++) {
                                data.onStock[i2] = 20;
                                data.ifReplenish[i2] = "yes";
                                cout << "\n--" << data.items[i2] << " refilled successfully--";
                                Sleep(500);
                            }
                            cout << endl;
                            system("pause");
                            continue;
                        case 3:
                            cout << "Maximal capacity of the machine:";
                            for (int i3 = 0; i3 < howManyProducts; i3++){
                                cout << "\n--" << data.items[i3] << ": " << 20 << "--";
                                Sleep(250);
                            }
                            cout << endl;
                            system("pause");
                            continue;
                        case 4:
                            cout << "Current stock:";
                            for (int i4 = 0; i4 < howManyProducts; i4++){
                                cout << "\n--" << data.items[i4] << ": " << data.onStock[i4] << "--";
                                Sleep(250);
                            }
                            cout << endl;
                            system("pause");
                            continue;
                        case 5:
                            system("CLS");
                            cout << "Sorting the products!" << endl;
                            Sleep(500);

                            filename = localTimeToDataName();
                            cout << "Filename: " << filename << endl;

                            alphabeticalProductSorting();
                            timeTxt(filename,"File sorted alphabetically");

                            data = dataRead();

                            cout << endl;
                            system("pause");
                            break;
                        case 6:
                            system("CLS");
                            cout << "Amount of coins in the machine: " << endl;
                            Sleep(500);
                            for (int i5 = 0; i5 < 6; i5++) {
                                cout << data.cashPool[i5] << " coins of the nominal " << coinNominals[i5] <<  "PLN" << endl;
                                Sleep(500);
                            }
                            cout << endl;
                            system("pause");
                            break;
                        case 7:
                            system("CLS");
                            cout << "Enter how many coins do you want to leave in the machine: " << endl;

                            for (int i6 = 0; i6 < 6; i6++) {
                                cout << coinNominals[i6] <<  "PLN coin amount: ";
                                cin >> data.cashPool[i6];
                                cout << endl;
                            }

                            cout << "\nYou successfully took out the excess coins!";
                            cout << endl;
                            cout << endl;
                            system("pause");
                            break;
                        case 8:
                            dataWrite(data,1);
                            cout << "\n\nGoodbye!";
                            Sleep(2000);
                            quit = 1;
                            skip = 1;
                            break;
                        case 9:
                            system("CLS");
                            cout << "Shuting down...\n";
                            Sleep(1000);
                            for (int i8 = 0; i8 < 3; i8++) {
                                cout << ".\n";
                                Sleep(500);
                            }
                            quit = 1;
                            dataWrite(data,1);
                            exit(27);
                        default:
                            continue;
                    }
                }
            }
        }
        else {
            system("CLS");
            cout << "Incorrect entry!\n";
            Sleep(2000);
            for (int i = 0; i < 3; i++) {
                cout << ".\n";
                Sleep(500);
            }
            cout << "Choose a viable option: ";
            cin >> choice;
            if (choice > 0 && choice < 8) {
                amountQuestion(choice,data);
                cin >> amount;
            }
            else {
                    cout << "\nYou will have to choose the product again. \n";
            Sleep(2000);
            }
        }

        if (skip == 1) continue;

        if (amount == 0) {
            for (int i = 0; i < 3; i++) {
                cout << ".\n";
                Sleep(500);
            }
            system("CLS");
            continue;
        }

        system("CLS");
        cout << "The chosen amount: " << amount;

        int j = 0;
        int cantDecide = 0;
        while (amount > data.onStock[choice-1] && cantDecide != 1) {
            j++;
            cout << "\n\nWe do not have so many " << data.items[choice-1] << " on stock!" << " \nPlease choose a correct amount: \n";
            cin >> amount;
            cout << "The chosen amount: " << amount;

            if (j > 1) {
                cout << "\nDo you still want to buy " << data.items[choice-1] << "?";
                cout << "\nIf you have changed your mind, please enter 1: ";
                cin >> cantDecide;
                if (cantDecide != 1) {
                    cout << "\nIn that case, focus on entering a correct amount.\n";
                    j = 0;
                }
            }
        }

        if (cantDecide == 1) {
            system("CLS");
            cout << "Please wait.\n";
            for (int i = 0; i < 3; i++) {
                cout << ".\n";
                Sleep(500);
            }
            continue;
        }

        data.onStock[choice-1] = data.onStock[choice-1] - amount;

        int *ptr_coinsInMachine;
        float moneyToPay = amount * data.price[choice-1];

        ptr_coinsInMachine = data.cashPool;
        int changeGiven = payment(moneyToPay,ptr_coinsInMachine);

        for (int i = 0; i < *(&data.onStock + 1) - data.onStock; i++) {
            if (data.onStock[i] == 0) data.ifReplenish[i] = "no";
            else data.ifReplenish[i] = "yes";
        }

        dataWrite(data,changeGiven);

        Sleep(3000);
        system("CLS");
    }



return 0;
}

int menu(machineData dataInfo) {
    int choice;
    system("CLS");
    cout << "Welcome to our vending machine! Which product would you like to purchase?";
    cout << "\n\n";
    cout << "Items:                                    Stock:                               Price:" << endl;
    for (int i = 0; i < howManyProducts; i++) {
        cout << i+1 << ". " << dataInfo.items[i] << "                                    | " << dataInfo.onStock[i] << "                                | " << dataInfo.price[i] << "PLN" << endl;
    }

    cout << "\n\nEnter an integer: ";
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

int menuSupervision() {
    int choiceOperator;
    system("CLS");
    cout << "Supervision menu: \n\n";
    cout << "1. Check amount of money\n";
    cout << "2. Refill products\n";
    cout << "3. Maximal capacity of the machine for each product\n";
    cout << "4. Current capacity of the machine for each product\n";
    cout << "5. Sort products alphabetically\n";
    cout << "6. Check the coin pool in the machine\n";
    cout << "7. Take out the coins and set the remaining coin pool\n";
    cout << "8. Save settings and exit to customer menu\n";
    cout << "9. Shut down the machine\n";


    cout << "\nEnter an integer: ";
    cin >> choiceOperator;
return choiceOperator;
};

void amountQuestion (int choiceF, machineData dataInfo) {

    cout << "How many " << dataInfo.items[choiceF-1] << " would you like to buy? Enter: ";

}

machineData dataRead() {

    machineData dataF;

    string entry;
    string temp_string[7];
    fstream file;
    file.open("vendingData.txt", ios::in | ios::out );

    if(file.good()==true) {
        cout << "Updating settings...";

        file >> entry;
        file >> entry;

        howManyProducts = std::stoi(entry);

        int j = 0;
        for (int i = 0; i < 7; i++) {
            file >> temp_string[i];
            if (i > 0) {
                dataF.cashPool[j] = std::stoi(temp_string[i]);
                j++;
            }
        }

        for (int i = 0; i < howManyProducts; i++) {
            file >> dataF.items[i];
            file >> dataF.onStock[i];
            file >> dataF.price[i];
            file >> dataF.ifReplenish[i];
        }

    }
    else cout << "\n\nFile access forbidden!" << endl;

    file.close();

return dataF;
}

void dataWrite(machineData dataInfo, int changeGiven) {

    int charAmount;
    string entry1,entry2;
    fstream file;

    file.open("vendingData.txt", ios::in | ios::out );
    if(file.good()==true) {
        cout << "\nProceeding to save settings...";
        getline(file,entry1);

        if (changeGiven == 1) {
            file.seekg(entry1.length(),ios::beg);
            file << endl;
            file << "cash_pool ";
            for (int i = 0; i < 6; i++) {
                file << dataInfo.cashPool[i] << " ";
            }
        }

        else {
            getline(file,entry2);
            file.seekg((entry1+entry2).length() + 2,ios::beg);
        }

        file << endl;

        for (int i = 0; i < howManyProducts; i++) {
            file << dataInfo.items[i] << " " << dataInfo.onStock[i] << " " << dataInfo.price[i] << " " << dataInfo.ifReplenish[i];
            if ( i != howManyProducts - 1) file << endl;
        }

    }
    else cout << "\n\nFile access forbidden!" << endl;
    file.close();
}


void replenishTenOnStart(machineData dataInfo) {
    for (int i = 0; i < *(&dataInfo.onStock + 1) - dataInfo.onStock; i++) {
            if (dataInfo.ifReplenish[i] == "no") {
                dataInfo.onStock[i] = 10;
                dataInfo.ifReplenish[i] = "yes";
                dataWrite(dataInfo,0);
            }
    }
}

void maximalCapacityBreached() {
    if (howManyProducts > 50) {
        cout << "The maximal capacity has been breached! Fatal error! Machine is going to shut down immediately!";
        exit(404);
    }
}

int payment(float howMuch, int *ptr_coinsInMachine) {
    float howMuch_temp;
    float howMuchPaid = 0;
    int whichCoin;
    int changeGiven = 0;
    float coins[6] = {5, 2, 1, 0.5, 0.2, 0.1};

    howMuch_temp = howMuch;

    while (howMuch_temp > 0) {  // loop responsible for asking the user for additional coins up until the point
                                // when the sum of the inserted coins equals or is greater than the price

        system("CLS");
        cout << "The remaining amount: " << round(howMuch_temp) << "PLN.\nWhich coins do you want to use?" << endl
        << "1. 5   PLN" << endl
        << "2. 2   PLN" << endl
        << "3. 1   PLN" << endl
        << "4. 0.5 PLN" << endl
        << "5. 0.2 PLN" << endl
        << "6. 0.1 PLN" << endl
        << "Choose: ";

        cin >> whichCoin;

        while(cin.fail()) { // if not integer, repeat
            cout << "Error! Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> whichCoin;
            system("CLS");
        }
        if (whichCoin > 6 || whichCoin < 1) { // is the given answer is not in bounds, exit
            system("CLS");
            cout << "Error!";
            exit(1);
        }

        howMuch_temp = howMuch_temp - coins[whichCoin-1]; // decreases temp price variable accordingly
        *(ptr_coinsInMachine + whichCoin - 1) += 1;       // increases coin amount inside the machine accordingly

        howMuchPaid = howMuchPaid + coins[whichCoin-1];
        round(howMuchPaid);                               // rounds up the float value of the sum paid in order to eliminate errors
    }
    if (howMuchPaid != howMuch) changeGiven = givingChange(howMuch, howMuchPaid, ptr_coinsInMachine, coins); // if user inserted more valuable coins than necessary, return change
    else cout << "\n\nThank you for your purchase!" << endl;
return changeGiven;
}

int givingChange(float howMuch, float howMuchPaid, int *ptr_coinsInMachine, float coins[]) {
    float change = round(howMuchPaid - howMuch);
    float coinsIssued[30]; // storing the coin given to the user in each iteration
    bool ifStop = false;
    int changeGiven;
    cout << "\n\n\nYour change: " << change << "PLN" << endl;

    float maxChange = checkingMaxChange(ptr_coinsInMachine, coins);
    maxChange = round(maxChange);

    system("CLS");
    cout << "first moneta: " << *ptr_coinsInMachine << endl;
    cout << "max change: " << maxChange << endl;
    cout << "change: " << change << endl;
    system("pause");

    if (maxChange < change) {
        cout << "\n\nWe are sorry, the machine does not have enough change!" << endl;
        changeGiven = 0;
        Sleep(5000);
    }
    else {
        changeGiven = 1;
        while (ifStop == false) {
            int i = 0;
            change = round(change); // makes sure to avoid trouble with floats
            if (change != 0) {
                if (i == 0) {       // if first iteration, find most amount of coins and keep giving them to the user till he got the change or till amount of coins reaches minimum
                    int baseCoinAmount = 5;
                    int pos = mostCoins(ptr_coinsInMachine, ptr_coinsInMachine + 6); // determining priority
                    if (pos = 0) pos = 1; // eliminating 5 PLN, because these coins are of no use while giving change
                    Sleep(500);
                    if (*(ptr_coinsInMachine + pos) > baseCoinAmount) {
                        int excessCoinAmount = *(ptr_coinsInMachine + pos) - baseCoinAmount;
                        Sleep(500);
                        for (int j = 0; j < excessCoinAmount; j++) {
                            if (change >= coins[pos]) {
                                change -= coins[pos];
                                *(ptr_coinsInMachine + pos) -= 1;
                                coinsIssued[pos] = coins[pos];

                                cout << "\nCoin issued: " << coins[pos] << "PLN";
                            }
                        }
                    }
                }   // when baseCoinAmount is reached, then proceed distributing the coins evenly, from the highest possible nominal to lowest, till change left to give is 0
                i = 1;
                while (i < 6) {
                    if (change >= coins[i] && *(ptr_coinsInMachine + i) > 0) {
                        change -= coins[i];
                        *(ptr_coinsInMachine + i) -= 1;
                        coinsIssued[i] = coins[i];

                        cout << "\nCoin issued: " << coins[i] << "PLN";
                    }
                    i++;
                }
            }
            else if (change == 0) {
                ifStop = true;
                changeGiven = 1;
            }
        }
    }
    cout << endl;
return changeGiven;
}

float round(float roundThis)
{
    float rounded = int(roundThis * 10 + .5);
    return (float)rounded / 10;
}

int mostCoins(int *firstEntry , int *lastEntry) {

    int biggestAmount = *firstEntry;
    int pos;
    int i = 0;
    while (firstEntry != lastEntry) {
        if (biggestAmount < (*firstEntry)) {
            biggestAmount = *firstEntry;
            pos = i;
        }
        i++;
        firstEntry++;
    }

return pos;
}

float checkingMaxChange(int *ptr_coinsInMachine, float coins[]) {
    float maxChange;

    for (int i = 1; i < 6; i++) {
        maxChange += *(ptr_coinsInMachine + i) * coins[i];
    }
return maxChange;
}

int alphabeticalProductSorting() {

    fstream file;
    string sortThis[howManyProducts],entry,entry1,entry2;
    int i,j;
    string temp;

    file.open("vendingData.txt", ios::in | ios::out );
    if(file.good()==true) {
        int iter = 0;
        while (getline(file,entry)) {
            if (iter > 1) {
                sortThis[iter-2] = entry;
            }

            iter++;
        }
    }
    else cout << "\n\nFile access forbidden!" << endl;
    file.close();


    for (i = 0; i < howManyProducts - 1; i++) {
        for (j = i + 1; j < howManyProducts; j++) {
            if (sortThis[j][0] < sortThis[i][0]) {
                temp = sortThis[i];
                sortThis[i] = sortThis[j];
                sortThis[j] = temp;
            }
        }
    }


    file.open("vendingData.txt", ios::in | ios::out );
    if(file.good()==true) {
        getline(file,entry1); // getline() for each line not referencing a product in the machine
        getline(file,entry2);

        file.seekg((entry1+entry2).length() + 2,ios::beg); // moves to the end of line 2

        file << endl;

        for (i = 0; i < howManyProducts; i++) {
            file << sortThis[i] << endl;
        }
        cout << "Products sorted!";
    }
    else cout << "\n\nFile access forbidden!" << endl;
    file.close();

return 0;
}

string localTimeToDataName() {
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    for (int i = 0; i < strlen(dt); i++) {
        if (!isdigit(dt[i]) && !isalpha(dt[i])) dt[i] = '#';
        if (i == strlen(dt)-1) dt[i] = '.';
    }

    string timeString(dt);

return timeString + "txt";
}

void timeTxt(string filename, string sortingInfoMessage) {

    fstream outfile;
    outfile.open(filename,ios::out);
    if(!outfile) {
       cout<<"Error in creating file!";
    }
    else cout<<" File created successfully. ";

    outfile << sortingInfoMessage << endl;

    outfile.close();
}
