/*Abhimanyu Kumar HW5 
This file contains all the prototpyes for the bank class
*/

#ifndef BANK_H
#define BANK_H

#include<iostream>
#include <queue>
#include "Account.h"
#include "BSTree.h"

using namespace std;

class Bank {
    public: 

        Bank(string &bankFile);
        //~Bank();
        BSTree store;
        void printQueue();
        void checkTrans();
        vector<string> parName(string str);
        vector<int> parseOrder(string str);

    private:
        queue<string> transaction;
};

#endif 