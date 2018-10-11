#include "t_chain.h"
#include "picosha2.h"

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
            std::cout << "No transactions with this sender's name found" << std::endl;
        }
    }
}

bool Chain::verifyAndPrint() {
    if (head == NULL) {
        std::cout << "There are no transactions in the chain." << std::endl;
    } else {
        // VERIFICATION
        for (Transaction* runner = head; runner != NULL; runner = runner->getNext()) {
            if (runner->getNext() != NULL) {
                std::string src = std::to_string(runner->getNext()->getAmount()) + runner->getNext()->getSender() + runner->getNext()->getReceiver() + runner->getNext()->getNonce();
                std::string hash;
                picosha2::hash256_hex_string(src, hash);
                if (runner->getHash() != hash) {     
                    std::cout << "Verification Error" << std::endl;
                    runner->printTransaction();
                    runner->getNext()->printTransaction();
                    return false;
                }
            }
        }

        // PRINT
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