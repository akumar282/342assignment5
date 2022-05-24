/*Abhimanyu Kumar HW5 
This file contains all the implementaions for the bank class
*/

#include<iostream> 
#include<fstream>
#include<sstream>
#include "Bank.h"
#include "Account.h"
#include "BSTree.h"
#include <queue>

using namespace std;

Bank::Bank(string &bankFile){
    try{
        ifstream inFile;
        inFile.open(bankFile);
        string transLine;
        //getline(inFile, transLine);
        while(getline(inFile, transLine)){
            transaction.push(transLine);
        }
        inFile.close();
    } catch (out_of_range const&) {
        cerr << "File was not opened..." << endl;
        exit(-1);
    }
}

void Bank::printQueue(){ 
    cout << transaction.size() << endl;
    while(!transaction.empty()){
        cout<<transaction.front() <<endl;
        transaction.pop();
    }
}

void Bank::checkTrans(){

    vector<int> nums;
    vector<string> names;
    string action = "";
    while(!transaction.empty()){
        action.append(transaction.front());
        transaction.pop();
        
        switch (action[0]){
            case 'D':{

                nums = parseOrder(action);
                Account *accPtr = nullptr;
                store.Retrieve(nums[0]/10, accPtr);
                //cout << "nums[0]%10: " << nums[0]%10 << endl;
                accPtr->depositFunds(nums[0] % 10, nums[1]);
                //cout << "Deposit" <<endl;

                break;
            }
            case 'W': {
                nums = parseOrder(action);
                Account *accPtr = nullptr;
                store.Retrieve(nums[0]/10, accPtr);
                accPtr->withdrawFunds(nums[0] % 10, nums[1]);
                //cout << "Withdraw" << endl;
                break;
            }
            case 'T': {
                nums = parseOrder(action);
                Account *accPtr = nullptr;
                //cout << "nums[0]: " << nums[0] << endl;
                store.Retrieve(nums[0] / 10, accPtr);
                //cout << nums[0] % 10 << endl;

                //cout << nums[2] % 10 << endl;
                accPtr->transFunds(nums[0] % 10, nums[1], nums[2] % 10);
                //cout << "Transfer" << endl;
                break;
            }
            case 'O': {
                
                string accnumber = action.substr(action.size()-5, action.size());
                vector<string> name2 = parName(action);
                
                auto *newAcc = new Account(stoi(accnumber), name2[0], name2[1]);
                
                
                if(!store.Insert(newAcc)){
                    delete newAcc;
                }
                
                
                break;
            }
            case 'H': {
                string acNum = action.substr(2, 4);
                
                Account *accPtr = nullptr;
                store.Retrieve(stoi(acNum), accPtr);
                cout << endl;
                cout <<"Transaction History for: " <<accPtr->getFName() << " " << accPtr->getLName() << " " << acNum << endl;
                for(int i = 0; i<10; i++){
                    accPtr->printHistoryFund(i);
                }
                break;
            }
            default: {
                //cout << "Nothing else left" << endl;
                break;
            }
        }  

        action = "";
    }
}

vector<int> Bank::parseOrder(string str){
    string temp = str.substr(2, str.size());
    //cout << temp << endl;
    stringstream in(temp);
    vector<int> vec;
    int tem;
    while(in >> tem){
        vec.push_back(tem);
    }
    /*
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    */
    return vec;
}

vector<string> Bank::parName(string str){
    vector<string> names;
    string temp = str.substr(2, str.size());
    //cout << temp << endl;
    stringstream in(temp);
    string tem;
    while(in >> tem){
        names.push_back(tem);
    }
    /*
    cout << names[0] << endl;
    cout << names[1] << endl;
    */
    return names;
}

