#include <iostream>
#include "t_chain.h"

using namespace std;

int main() {
    cout << "Welcome to FakeCoin transaction-chain terminal!" << endl;
    cout << "Please select the action that you would like to perform today" << endl;
    Chain* t_chain = new Chain();

    while(1) {
        cout << "-------------------------" << endl;
        cout << "1: Add a new transaction" << endl;
        cout << "2: Find a transaction" << endl;
        cout << "3: Verify and print the transaction-chain" << endl;
        cout << "0: Exit" << endl;
        cout << "-------------------------" << endl;

        char selected_case;
        cin >> selected_case;

        switch(selected_case) {
            case '1':
                cout << "This is case 1" << endl;
                break;
            case '2':
                cout << "This is case 2" << endl;
                break;
            case '3':
                cout << "This is case 3" << endl;
                break;
            case '0':
                cout << "Goodbye" << endl;
                exit(0);
            default:
                cout << "Please enter 1, 2 or 3 to perform an action or 0 to quit" << endl;
        }
    }

    return 0;
}