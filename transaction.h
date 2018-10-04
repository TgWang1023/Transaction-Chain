#include <string>

class Transaction {
    public:
        Transaction();
        ~Transaction();
    private:
        Transaction* next; //Previous Transaction
        int amount; // Amount of money transferred
        std::string sender; // Money Sender
        std::string receiver; // Money Receiver
        std::string nonce; // Added hashing string
        std::string hash; // Hash of previous transaction
};