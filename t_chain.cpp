#include "t_chain.h"

Chain::Chain() {
    this->head = NULL;
}

void Chain::addTransaction(int amount, std::string sender, std::string receiver) {
    if (this->head == NULL) {
        this->head = new Transaction(amount, sender, receiver, NULL);
    } else {
        this->head = new Transaction(amount, sender, receiver, this->head);
    }
}

void Chain::findTransaction(std::string sender_name) {
    if (head == NULL) {
        std::cout << "There are no transactions in the chain." << std::endl;
    } else {
        bool t_exist = false;
        for (Transaction* runner = head; runner != NULL; runner = runner->getNext()) {
            if (runner->getSender() == sender_name) {
                std::cout << "Transaction found.\n" << std::endl;
                runner->printTransaction();
                t_exist = true;
            }
        }
        if (!t_exist) {
            std::cout << "No transactions with your name found" << std::endl;
        }
    }
}

bool Chain::verifyAndPrint() {
    if (head == NULL) {
        std::cout << "There are no transactions in the chain." << std::endl;
    } else {
        for (Transaction* runner = head; runner != NULL; runner = runner->getNext()) {
            runner->printTransaction();
            std::cout << "       |       " << std::endl;
            std::cout << "       |       " << std::endl;
            std::cout << "       |       " << std::endl;
            std::cout << "       V       " << std::endl;
        }
    }
    return true;
}