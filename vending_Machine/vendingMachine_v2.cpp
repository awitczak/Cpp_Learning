#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

class fileManagement
{
public:
    int productAmount;

    struct inMachine
    {
        vector<string> item;
        vector<string> ifReplenish;
        vector<int> onStock;
        vector<int> price;
        int cashPool[6];
    } machine;

    void read();
    void write();
};

void fileManagement::read()
{

    string line, temp;
    fstream file;
    file.open("vendingData.txt", ios::in);

    if (file.good() == true)
    {
        cout << "Updating settings..." << endl;
        // initial line for amount of products
        file >> temp;
        file >> temp;
        productAmount = stoi(temp);
        // second line for cash pool inside of the machine
        file >> temp;
        for (int i = 0; i < 6; i++)
        {
            file >> temp;
            machine.cashPool[i] = stoi(temp);
        }

        for (int i = 0; i < productAmount; i++)
        {
            file >> temp;
            machine.item.push_back(temp);
            file >> temp;
            machine.onStock.push_back(stoi(temp));
            file >> temp;
            machine.price.push_back(stoi(temp));
            file >> temp;
            machine.ifReplenish.push_back(temp);
        }
    }
    else
        cout << "File access forbidden!" << endl;

    file.close();
}

void fileManagement::write()
{

    int charAmount;
    string entry1, entry2;
    fstream file;

    file.open("vendingData.txt", ios::in | ios::out);
    if (file.good() == true)
    {
        cout << "\nProceeding to save settings...";
        getline(file, entry1);
        file.seekg((entry1).length() + 2, ios::beg);

        // saving current coin pool
        file << "cash_pool " << machine.cashPool[0] << " " << machine.cashPool[1] << " " << machine.cashPool[2] << " " << machine.cashPool[3] << " " << machine.cashPool[4] << " " << machine.cashPool[5] << endl;

        // proceeding to save product info
        for (int i = 0; i < productAmount; i++)
        {
            file << machine.item[i] << " " << machine.onStock[i] << " " << machine.price[i] << " " << machine.ifReplenish[i];
            if (i != productAmount - 1)
                file << endl;
        }
    }
    else
        cout << "\n\nFile access forbidden!" << endl;
    file.close();
}

class machineManagement
{
public:

    friend class fileManagement;
    float coinNominals[6] = {5, 2, 1, 0.5, 0.2, 0.1};

    void moneyCheck(fileManagement vendingData);
    void refill(fileManagement vendingData);
    void disp_max_cap(fileManagement vendingData);
    void disp_curr_cap(fileManagement vendingData);
    void sortProdAlpha(fileManagement vendingData);
    void disp_coin_pool(fileManagement vendingData);
    void takeCoins(fileManagement vendingData);
    void saveSettings(fileManagement vendingData);
    void shutDown();

    // for sorting
    int alphabeticalProductSorting(int howManyProducts)
    {

        fstream file;
        string sortThis[howManyProducts], entry, entry1, entry2;
        int i, j;
        string temp;

        file.open("vendingData.txt", ios::in | ios::out);
        if (file.good() == true)
        {
            int iter = 0;
            while (getline(file, entry))
            {
                if (iter > 1)
                {
                    sortThis[iter - 2] = entry;
                }

                iter++;
            }
        }
        else
            cout << "\n\nFile access forbidden!" << endl;
        file.close();

        for (i = 0; i < howManyProducts - 1; i++)
        {
            for (j = i + 1; j < howManyProducts; j++)
            {
                if (sortThis[j][0] < sortThis[i][0])
                {
                    temp = sortThis[i];
                    sortThis[i] = sortThis[j];
                    sortThis[j] = temp;
                }
            }
        }

        file.open("vendingData.txt", ios::in | ios::out);
        if (file.good() == true)
        {
            getline(file, entry1); // getline() for each line not referencing a product in the machine
            getline(file, entry2);

            file.seekg((entry1 + entry2).length() + 2, ios::beg); // moves to the end of line 2

            file << endl;

            for (i = 0; i < howManyProducts; i++)
            {
                file << sortThis[i] << endl;
            }
            cout << "Products sorted!";
        }
        else
            cout << "\n\nFile access forbidden!" << endl;
        file.close();

        return 0;
    }
    string localTimeToDataName()
    {
        // current date/time based on current system
        time_t now = time(0);

        // convert now to string form
        char *dt = ctime(&now);

        for (int i = 0; i < strlen(dt); i++)
        {
            if (!isdigit(dt[i]) && !isalpha(dt[i]))
                dt[i] = '#';
            if (i == strlen(dt) - 1)
                dt[i] = '.';
        }

        string timeString(dt);

        return timeString + "txt";
    }
    void timeTxt(string filename, string sortingInfoMessage)
    {

        fstream outfile;
        outfile.open(filename, ios::out);
        if (!outfile)
        {
            cout << "Error in creating file!";
        }
        else
            cout << " File created successfully. ";

        outfile << sortingInfoMessage << endl;

        outfile.close();
    }
};

void machineManagement::moneyCheck(fileManagement vendingData)
{
    int sum = 0;
    for (int i1 = 0; i1 < 6; i1++)
    {
        sum = sum + vendingData.machine.cashPool[i1] * coinNominals[i1];
    }

    cout << "The amount of money in the machine: " << sum << "PLN" << endl;
    cout << endl;
    system("pause");
}

void machineManagement::refill(fileManagement vendingData)
{
    for (int i2 = 0; i2 < vendingData.productAmount; i2++)
    {
        vendingData.machine.onStock[i2] = 20;
        vendingData.machine.ifReplenish[i2] = "yes";
        cout << "\n--" << vendingData.machine.item[i2] << " refilled successfully--";
        Sleep(500);
    }
    vendingData.write();
    cout << endl;
    system("pause");
}

void machineManagement::disp_max_cap(fileManagement vendingData)
{
    cout << "Maximal capacity of the machine:";
    for (int i3 = 0; i3 < vendingData.productAmount; i3++)
    {
        cout << "\n--" << vendingData.machine.item[i3] << ": " << 20 << "--";
        Sleep(250);
    }
    cout << endl;
    system("pause");
}

void machineManagement::disp_curr_cap(fileManagement vendingData)
{
    cout << "Current stock:";
    for (int i4 = 0; i4 < vendingData.productAmount; i4++)
    {
        cout << "\n--" << vendingData.machine.item[i4] << ": " << vendingData.machine.onStock[i4] << "--";
        Sleep(250);
    }
    cout << endl;
    system("pause");
}

void machineManagement::sortProdAlpha(fileManagement vendingData)
{
    system("cls");
    cout << "Sorting the products!" << endl;
    Sleep(500);

    string filename = localTimeToDataName();
    cout << "Filename: " << filename << endl;

    alphabeticalProductSorting(vendingData.productAmount);
    timeTxt(filename, "File sorted alphabetically");

    cout << endl;
    system("pause");
}

void machineManagement::disp_coin_pool(fileManagement vendingData)
{
    system("cls");
    cout << "Amount of coins in the machine: " << endl;
    Sleep(500);
    for (int i6 = 0; i6 < 6; i6++)
    {
        cout << vendingData.machine.cashPool[i6] << " coins of the nominal " << coinNominals[i6] << "PLN" << endl;
        Sleep(500);
    }
    cout << endl;
    system("pause");
}

void machineManagement::takeCoins(fileManagement vendingData)
{
    system("cls");
    cout << "Enter how many coins do you want to leave in the machine: " << endl;
    for (int i7 = 0; i7 < 6; i7++)
    {
        cout << coinNominals[i7] << "PLN coin amount: ";
        cin >> vendingData.machine.cashPool[i7];
        cout << endl;
    }
    cout << "\nYou successfully took out the excess coins!";
    cout << endl;
    system("pause");
}

void machineManagement::saveSettings(fileManagement vendingData)
{
    system("cls");

    system("pause");
}

void machineManagement::shutDown()
{
    system("cls");
    cout << "Shuting down..." << endl;
    Sleep(1000);
    for (int i9 = 0; i9 < 3; i9++)
    {
        cout << "." << endl;
        Sleep(500);
    }
    exit(27);
}

class paymentProcedure
{
public:
    float coinNominals[6] = {5, 2, 1, 0.5, 0.2, 0.1};
    float howMuch, howMuchPaid;
    int *ptr_coinsInMachine;

    void payment();
    void givingChange();
    int mostCoins(int *firstEntry, int *lastEntry);
    float round(float roundThis);
    float checkingMaxChange();
};

void paymentProcedure::payment()
{
    float howMuch_temp;
    int whichCoin;

    howMuchPaid = 0;
    howMuch_temp = howMuch;

    while (howMuch_temp > 0)
    { // loop responsible for asking the user for additional coins up until the point
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

        while (cin.fail())
        { // if not integer, repeat
            cout << "Error! Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> whichCoin;
            system("CLS");
        }
        if (whichCoin > 6 || whichCoin < 1)
        { // if the given answer is not in bounds, exit
            system("CLS");
            cout << "Error!";
            exit(1);
        }

        howMuch_temp = howMuch_temp - coinNominals[whichCoin - 1]; // decreases temp price variable accordingly
        *(ptr_coinsInMachine + whichCoin - 1) += 1;                // increases coin amount inside the machine accordingly

        howMuchPaid = howMuchPaid + coinNominals[whichCoin - 1];
        round(howMuchPaid); // rounds up the float value of the sum paid in order to eliminate errors
    }
    if (howMuchPaid != howMuch)
        givingChange(); // if user inserted more valuable coins than necessary, return change
    else
        cout << "\n\nThank you for your purchase!" << endl;
}

void paymentProcedure::givingChange()
{
    float change = round(howMuchPaid - howMuch);
    float coinsIssued[30]; // storing the coin given to the user in each iteration
    bool ifStop = false;
    int changeGiven;
    cout << "\n\n\nYour change: " << change << "PLN" << endl;

    float maxChange = checkingMaxChange();
    maxChange = round(maxChange);

    system("cls");
    cout << "Max change: " << maxChange << endl;
    cout << "Change: " << change << endl;
    system("pause");

    if (maxChange < change)
    {
        cout << "\n\nWe are sorry, the machine does not have enough change!" << endl;
        changeGiven = 0;
        Sleep(5000);
    }
    else
    {
        changeGiven = 1;
        while (ifStop == false)
        {
            int i = 0;
            change = round(change); // makes sure to avoid trouble with floats
            if (change != 0)
            {
                if (i == 0)
                { // if first iteration, find most amount of coins and keep giving them to the user till he got the change or till amount of coins reaches minimum
                    int baseCoinAmount = 5;
                    int pos = mostCoins(ptr_coinsInMachine, ptr_coinsInMachine + 6); // determining priority
                    if (pos = 0)
                        pos = 1; // eliminating 5 PLN, because these coins are of no use while giving change
                    Sleep(500);
                    if (*(ptr_coinsInMachine + pos) > baseCoinAmount)
                    {
                        int excessCoinAmount = *(ptr_coinsInMachine + pos) - baseCoinAmount;
                        Sleep(500);
                        for (int j = 0; j < excessCoinAmount; j++)
                        {
                            if (change >= coinNominals[pos])
                            {
                                change -= coinNominals[pos];
                                *(ptr_coinsInMachine + pos) -= 1;
                                coinsIssued[pos] = coinNominals[pos];

                                cout << "\nCoin issued: " << coinNominals[pos] << "PLN";
                                Sleep(1000);
                            }
                        }
                    }
                } // when baseCoinAmount is reached, then proceed distributing the coins evenly, from the highest possible nominal to lowest, till change left to give is 0
                i = 1;
                while (i < 6)
                {
                    if (change >= coinNominals[i] && *(ptr_coinsInMachine + i) > 0)
                    {
                        change -= coinNominals[i];
                        *(ptr_coinsInMachine + i) -= 1;
                        coinsIssued[i] = coinNominals[i];

                        cout << "\nCoin issued: " << coinNominals[i] << "PLN";
                    }
                    i++;
                }
            }
            else if (change == 0)
            {
                ifStop = true;
                changeGiven = 1;
            }
        }
    }
    cout << endl;
}

int paymentProcedure::mostCoins(int *firstEntry, int *lastEntry)
{
    int biggestAmount = *firstEntry;
    int pos;
    int i = 0;
    while (firstEntry != lastEntry)
    {
        if (biggestAmount < (*firstEntry))
        {
            biggestAmount = *firstEntry;
            pos = i;
        }
        i++;
        firstEntry++;
    }

    return pos;
}

float paymentProcedure::round(float roundThis)
{
    float rounded = int(roundThis * 10 + .5);
    return (float)rounded / 10;
}

float paymentProcedure::checkingMaxChange()
{
    float maxChange;

    for (int i = 1; i < 6; i++)
    {
        maxChange += *(ptr_coinsInMachine + i) * coinNominals[i];
    }
    return maxChange;
}

void disp_menu(fileManagement vendingData);
void disp_menu_operator();
int getChoice();

int main()
{
    int end_program = 0, back_to_menu = 0;
    int choice_product, choice_amount, choice_operator;

    fileManagement vendingData;
    vendingData.read();

    // main loop
    while (end_program != 1)
    {
        disp_menu(vendingData);
        choice_product = getChoice();
        if (choice_product > 0 && choice_product <= vendingData.productAmount)
        {
            cout << "How many would you like to purchase?" << endl;
            choice_amount = getChoice();
            if (choice_amount == 0)
            {
                cout << "Invalid entry! Amount has to be greater than 0!" << endl;
                Sleep(3000);
                continue;
            }
        }
        else if (choice_product == 0)
        {
            string pswd, pswd_correct = "qwerty123";
            system("cls");
            cout << "Enter the password: ";
            cin >> pswd;

            if (pswd != pswd_correct)
            {
                cout << "\nIncorrect password!";
                Sleep(3000);
                continue;
            }
            else
            {
                back_to_menu = 0;
                while (back_to_menu != 1)
                {
                    machineManagement vendingMachine;
                    disp_menu_operator();
                    choice_operator = getChoice();

                    switch (choice_operator)
                    {
                    case 1: // check money amount
                        vendingMachine.moneyCheck(vendingData);
                        break;
                    case 2: // refill products
                        vendingMachine.refill(vendingData);
                        break;
                    case 3: // maximal capacity
                        vendingMachine.disp_max_cap(vendingData);
                        break;
                    case 4: // current capacity
                        vendingMachine.disp_curr_cap(vendingData);
                        break;
                    case 5: // sort alpha
                        vendingMachine.sortProdAlpha(vendingData);
                        break;
                    case 6: // check coin pool
                        vendingMachine.disp_coin_pool(vendingData);
                        break;
                    case 7: // take out coins and set remaining
                        vendingMachine.takeCoins(vendingData);
                        break;
                    case 8: // save settings
                        vendingData.write();
                        cout << endl
                             << "Goodbye!" << endl;
                        Sleep(2000);
                        back_to_menu = 1;
                        break;
                    case 9: // shut down the machine
                        vendingData.write();
                        end_program = 1;
                        vendingMachine.shutDown();
                    default:
                        break;
                    }
                }
            }
        }
        else
        {
            system("cls");
            cout << "Incorrect entry!" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << "." << endl;
                Sleep(500);
            }
            choice_product = getChoice();
            if (choice_product > 0 && choice_product <= vendingData.productAmount)
            {
                cout << "How many would you like to purchase?" << endl;
                choice_amount = getChoice();
                if (choice_amount == 0)
                {
                    cout << "Invalid entry! Amount has to be greater than 0!" << endl;
                    Sleep(3000);
                    continue;
                }
            }
            else
            {
                cout << "\nYou will have to choose the product again. \n";
                Sleep(3000);
                continue;
            }
        }

        if (back_to_menu != 1)
        {
            while (choice_amount > vendingData.machine.onStock[choice_product - 1])
            {
                cout << "\n\nWe do not have so many " << vendingData.machine.item[choice_product - 1] << " on stock!" << endl
                     << "Current stock: " << vendingData.machine.onStock[choice_product - 1] << endl
                     << "Please choose a correct amount: " << endl;
                cin >> choice_amount;
                cout << "The chosen amount: " << choice_amount;
            }

            // updating the stock
            vendingData.machine.onStock[choice_product - 1] = vendingData.machine.onStock[choice_product - 1] - choice_amount;

            // taking payment
            paymentProcedure payment;
            payment.ptr_coinsInMachine = vendingData.machine.cashPool;
            payment.howMuch = choice_amount * vendingData.machine.price[choice_product - 1];

            payment.payment();

            for (int i = 0; i < vendingData.productAmount; i++)
            {
                if (vendingData.machine.onStock[i] == 0)
                    vendingData.machine.ifReplenish[i] = "no";
                else
                    vendingData.machine.ifReplenish[i] = "yes";
            }
        }
        cout << endl;
        system("pause");
        vendingData.write();
    }
    return 0;
}

void disp_menu(fileManagement vendingData)
{
    system("cls");
    cout << "Number of products in the machine: " << vendingData.productAmount << endl;
    cout << "List of products: " << endl;

    cout << "\tItem:\t\tAmount:\t\tPrice:" << endl;
    for (int i = 0; i < vendingData.productAmount; i++)
    {
        cout << i + 1 << ".\t" << vendingData.machine.item[i] << "\t\t" << vendingData.machine.onStock[i] << "\t\t" << vendingData.machine.price[i] << " PLN" << endl;
    }

    cout << endl;
    cout << "What would you like to purchase?" << endl;
}

void disp_menu_operator()
{
    system("cls");
    cout << "Supervision menu: \n\n";
    cout << "1. Check amount of money" << endl;
    cout << "2. Refill products" << endl;
    cout << "3. Maximal capacity of the machine for each product" << endl;
    cout << "4. Current capacity of the machine for each product" << endl;
    cout << "5. Sort products alphabetically" << endl;
    cout << "6. Check the coin pool in the machine" << endl;
    cout << "7. Take out the coins and set the remaining coin pool" << endl;
    cout << "8. Save settings and exit to customer menu" << endl;
    cout << "9. Save data and shut down the machine" << endl
         << endl;
}

int getChoice()
{
    int choice;
    cout << "Please enter an integer: ";
    cin >> choice;

    // loop for correct entry
    while (cin.fail())
    {
        cout << endl;
        cout << "Error! Please enter an integer: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
        system("CLS");
    }

    return choice;
}
