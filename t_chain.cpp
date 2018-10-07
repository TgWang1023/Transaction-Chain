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
    std::cout << "stub" << std::endl;
}

bool Chain::verifyAndPrint() {
    for (Transaction* runner = head; runner != NULL; runner = runner->getNext()) {
        runner->printTransaction();
    }
    return true;
}