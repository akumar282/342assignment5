#ifndef BSTREE_H
#define BSTREE_H

#include "Account.h"

class BSTree { 
    private:
        struct Node {
            Account *pAcct;
            Node *right;
            Node *left;

        };
        Node *root;
    
    public: 
        BSTree();
        ~BSTree();

        bool Insert(Account *acc);
        bool InsertRecHelp(Node* curr, Account* acc);
        bool Retrieve(const int &Accnum, Account *&acc) const;
        Account* recRet(Node* pRoot, int AccNum) const;
        void recDis(Node *pR) const;
        bool isEmpty() const;

        void Display() const;
        void Empty(Node *node);
        
};

#endif