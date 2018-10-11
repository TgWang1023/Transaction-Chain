#include <string>
#include <iostream>

class Transaction {
    public:
        Transaction(int amount, std::string sender, std::string receiver, Transaction* next);
        int getAmount();
        std::string getSender();
        std::string getReceiver();
        char getNonce();
        std::string getHash();
        Transaction* getNext();
        void printTransaction();
    private:
        Transaction* next; // Previous Transaction
        int amount; // Amount of money transferred
        std::string sender; // Money Sender
        std::string receiver; // Money Receiver
        char nonce; // Added hashing string
        std::string hash; // Hash of previous transaction
};