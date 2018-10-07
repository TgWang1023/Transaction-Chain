#include "transaction.h"

Transaction::Transaction(int amount, std::string sender, std::string receiver, Transaction* next) {
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;
    this->next = next;
}

std::string Transaction::getSender() {
    return this->sender;
}

Transaction* Transaction::getNext() {
    return this->next;
}

void Transaction::printTransaction() {
    std::cout << "-------------" << std::endl;
    std::cout << "Transaction amount: " << this->amount << std::endl;
    std::cout << "Sender: " << this->sender << std::endl;
    std::cout << "Receiver: " << this->receiver << std::endl;
}