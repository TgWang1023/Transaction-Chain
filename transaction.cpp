#include <cstdlib>
#include "transaction.h"
#include "picosha2.h"

Transaction::Transaction(int amount, std::string sender, std::string receiver, Transaction* next) {
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;
    this->next = next;
    if (this->next == NULL) {
        this->nonce = '.';
        this->hash = "";
    } else {
        while(1) {
            srand(time(NULL));
            char nonce = char(rand() % 26 + 97);
            std::string src = std::to_string(this->next->amount) + this->next->sender + this->next->receiver + nonce;
            std::string hash;
            picosha2::hash256_hex_string(src, hash);
            char last = hash.back();
            if (last == '0' || last == '1' || last == '2' || last == '3' || last == '4') {
                this->next->nonce = nonce;
                this->hash = hash;
                break;
            }
        }
    }
}

int Transaction::getAmount() {
    return this->amount;
}

std::string Transaction::getSender() {
    return this->sender;
}

std::string Transaction::getReceiver() {
    return this->receiver;
}

char Transaction::getNonce() {
    return this->nonce;
}

std::string Transaction::getHash() {
    return this->hash;
}

Transaction* Transaction::getNext() {
    return this->next;
}

void Transaction::printTransaction() {
    std::cout << "===============" << std::endl;
    std::cout << "Transaction amount: " << this->amount << std::endl;
    std::cout << "Sender: " << this->sender << std::endl;
    std::cout << "Receiver: " << this->receiver << std::endl;
    std::cout << "Previous hash: " << this->hash << std::endl;
    std::cout << "===============" << std::endl;
}