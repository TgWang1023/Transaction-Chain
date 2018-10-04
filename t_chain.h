#include "transaction.h"

class Chain {
    public:
        Chain();
        ~Chain();
        void addTransaction(Transaction new_transaction);
        Transaction findTransaction(std::string sender_name);
        bool verifyAndPrint();
    private:
        Transaction* head;
};