#include "transaction.h"

class Chain {
    public:
        Chain();
        void addTransaction(int amount, std::string sender, std::string receiver);
        void findTransaction(std::string sender_name);
        bool verifyAndPrint();
    private:
        Transaction* head;
};