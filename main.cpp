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
        cout << "2: Find transactions" << endl;
        cout << "3: Verify and print the transaction-chain" << endl;
        cout << "0: Exit" << endl;
        cout << "-------------------------" << endl;

        char selected_case;
        cin >> selected_case;

        int amount;
        string sender;
        string receiver;

        switch(selected_case) {
            case '1':
                cout << "Please enter the amount you would like to transfer:" << endl;
                cin >> amount;
                cout << "Please enter your name:" << endl;
                cin >> sender;
                cout << "Please enter the receiver's name:" << endl;
                cin >> receiver;
                t_chain->addTransaction(amount, sender, receiver);
                cout << "Transaction added." << endl;
                break;
            case '2':
                cout << "Please enter your name:" << endl;
                cin >> sender;
                cout << "\n\n\n--------------------------------------" << endl;
                t_chain->findTransaction(sender);
                cout << "--------------------------------------\n\n\n" << endl;    
                break;
            case '3':
                cout << "\n\n\n-------------END OF CHAIN-------------" << endl;
                t_chain->verifyAndPrint();
                cout << "----------BEGINNING OF CHAIN----------\n\n\n" << endl;         
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