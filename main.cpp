#include <iostream>
#include "t_chain.h"

using namespace std;

int main() {
    cout << "\n\n\nWelcome to FakeCoin transaction-chain terminal!" << endl;
    cout << "Please select the action that you would like to perform today" << endl;
    Chain* t_chain = new Chain();

    while(1) {
        cout << "-------------------------" << endl;
        cout << "1: Add a new transaction" << endl;
        cout << "2: Find transactions" << endl;
        cout << "3: Verify and print the transaction-chain" << endl;
        cout << "0: Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Choice: ";

        char selected_case;
        cin >> selected_case;

        string amount;
        string sender;
        string receiver;
        string find;

        switch(selected_case) {
            case '1':
                cout << "Please enter the amount you would like to transfer: ";
                cin.ignore();
                getline(cin, amount);
                while (cin.fail() || cin.eof() || amount.find_first_not_of("0123456789") != string::npos) {
                    cout << "Only integer values are allowed. Try again: ";
                    if (amount.find_first_not_of("0123456789") == string::npos) {
                        cin.clear();
                        cin.ignore(256,'\n');
                    }
                    getline(cin, amount);
                }
                cout << "Please enter your name: ";
                getline(cin, sender);
                cout << "Please enter the receiver's name: ";
                getline(cin, receiver);
                t_chain->addTransaction(stoi(amount), sender, receiver);
                cout << "Transaction added.\n\n\n" << endl;
                break;
            case '2':
                cout << "Please enter the sender's name: ";
                cin.ignore();
                getline(cin, find);
                cout << "\n\n\n--------------------------------------" << endl;
                t_chain->findTransaction(find);
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