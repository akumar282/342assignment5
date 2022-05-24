/*Abhimanyu Kumar HW5 
This file contains all the implementaions for the BinaryTree class
*/


#include <iostream> 
#include "BSTree.h"
#include "Account.h"

using namespace std;

BSTree::BSTree(){
    root = NULL;
}

BSTree::~BSTree(){
    Empty(root);
}

bool BSTree::Insert(Account *acc){
    
    return InsertRecHelp(root, acc);
}

bool BSTree::Retrieve(const int &accNum, Account *&acc) const {
            acc = recRet(root, accNum);
            return acc != nullptr;
        }

Account* BSTree::recRet(Node* pRoot, int AccNum) const {
            if (pRoot == nullptr) {
                return nullptr;
            }
            else if (pRoot->pAcct->getAccNum() == AccNum) {
                return pRoot->pAcct;
            }
            else if (AccNum < pRoot->pAcct->getAccNum()) {
                return recRet(pRoot->left, AccNum);
            }
            else {
                return recRet(pRoot->right, AccNum);
            }
        }

bool BSTree::InsertRecHelp(Node* curr, Account* acc){
    if(isEmpty()){
        root = new Node;
        root->pAcct = acc;
        root->left= NULL;
        root->right= NULL;
        return true;
    } 
    if(acc->getAccNum() > curr->pAcct->getAccNum()){
        if(curr->right == NULL){
            Node *intree = new Node();
            intree->pAcct = acc;
            intree->left  = NULL;
            intree->right = NULL;
            curr->right = intree;
            return true;
        } else { 
            return InsertRecHelp(curr->right, acc);
        }
    } else if(acc->getAccNum() < curr->pAcct->getAccNum()){
        if(curr->left == NULL){
            Node *intree = new Node();
            intree->pAcct = acc;
            intree->left  = NULL;
            intree->right = NULL;
            curr->left = intree;
            return true;
        } else { 
            return InsertRecHelp(curr->left, acc);
        }
    }
    return false;
}

bool BSTree::isEmpty() const{
    return root == nullptr;
}

void BSTree::Empty(Node *node){
    if(node != NULL){
        Empty(node->left);
        Empty(node->right);
        delete node;
    }
}

void BSTree::Display() const{
    recDis(root);
}

void BSTree::recDis(Node *pR) const {
            if (pR != nullptr) {
                recDis(pR->left);
                
                std::cout << pR->pAcct->getFName() << " " << pR->pAcct->getLName() 
                << " Account ID: " <<
                pR->pAcct->getAccNum() << std::endl;

                for (int i = 0; i < 10; i++) {
                    std::cout << "       " << pR->pAcct->getFundName(i) << ": $" <<
                 pR->pAcct->getFundBal(i) << std::endl;
                }
            std::cout << std::endl;
            recDis(pR->right);
            }
        }




