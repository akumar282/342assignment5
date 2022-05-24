/*Abhimanyu Kumar HW5 
This file contains all the implementaions for the Account class
*/

#include "Account.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

Account::Account(){
    
}

Account::Account(int AccNum, string LName, string FName){
    this->AccNum = AccNum;
    //cout << "AccNum: " << AccNum << endl;
    this->LName = LName;
    this->FName = FName; 
    for(int i = 0; i < 10; i++){
        Fund f;
        f.fName = fNames[i];
        f.fNum = i;
        f.funds = 0;
        storeFund[i] = f;
    }
}
//
Account::~Account(){

}
//
string Account::getLName(){
    return LName;
}

void Account::setName(string ln, string fn){
    LName = ln;
    FName = fn; 
}

void Account::setnum(int num){
    AccNum = num;
}

string Account::getFName(){
    return FName;
}

string Account::getFundName(int ind){
    return fNames[ind];
}

int Account::getAccNum(){
    //cout << "getAccNum: AccNum: " << AccNum << endl;
    return AccNum;
}

int Account::getFundBal(int &fNum){
    return storeFund[fNum-1].funds;
}
/*
void Account::AddFund(int f, int amm){
    Fund f1 = storeFund[f];
    f1.funds += amm;
    cout<< f1.funds <<" it worked " << endl;
    storeFund[f] = f1;
    
}

void Account::SubFund(int f, int amm){
    Fund f1 = storeFund[f];
    f1.funds -= amm;
    cout<< f1.funds <<" it worked " << endl;
    storeFund[f] = f1;
    
}
*/
bool Account::depositFunds(const int &fund, const int &amount){
    if(fund < 0 || fund > 9){
        return false;
    } else {
        //cout << fund << endl;
        //AddFund(fund, amount);
        /*
        cout << "getAccNum: " << getAccNum() << endl;
        cout << storeFund[0].funds << endl;
        */
        storeFund[fund].funds += amount;
        storeFund[fund].accHist.push("D "+to_string(getAccNum())+to_string(storeFund[fund].fNum)+" "+to_string(amount));
        return true;
    }
    return false;
}

bool Account::transFunds(const int &fund, int &amount, const int &fund2){
    if(fund < 0 || fund > 9 || fund2 < 0 || fund2 > 9 ){
        return false;
    } else {
        //cout << " happen" << endl;
        storeFund[fund].funds -= amount;
        storeFund[fund2].funds += amount;
        storeFund[fund2].accHist.push("T "+to_string(getAccNum())+to_string(storeFund[fund].fNum)+" "+to_string(amount)+" "+to_string(getAccNum())+to_string(storeFund[fund2].fNum));
        storeFund[fund].accHist.push("T "+to_string(getAccNum())+to_string(storeFund[fund].fNum)+" "+to_string(amount)+" "+to_string(getAccNum())+to_string(storeFund[fund2].fNum));
        return true;
    }
    return false;
}

bool Account::withdrawFunds(const int &fund, int &amount){
    if(fund < 0 || fund > 9){
        return false;
    } else { 
        if(storeFund[fund].funds - amount < 0){
            switch (fund){
            case 0: {
                if(((storeFund[0].funds + storeFund[1].funds) - amount ) < 0){
                    cout<< "No funds available" << endl;
                    storeFund[1].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount)+" (Failed)");
                } else { 
                    amount -= storeFund[0].funds;
                    storeFund[0].funds = 0;
                    storeFund[1].funds -= amount;
                    storeFund[1].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount));
                    return true; 
                }
                break;
            }
            case 1: {
                if(((storeFund[0].funds + storeFund[1].funds) - amount ) < 0){
                    cout<< "No funds available" << endl;
                    storeFund[0].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount)+" (Failed)"); 
                } else { 
                    amount -= storeFund[1].funds;
                    storeFund[1].funds = 0;
                    storeFund[0].funds -= amount;
                    storeFund[0].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount));
                    return true; 
                }
                break;
            }
            case 2: 
                if(((storeFund[2].funds + storeFund[3].funds) - amount ) < 0){
                    cout<< "No funds available" << endl;
                    storeFund[3].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount)+" (Failed)"); 
                } else { 
                    amount -= storeFund[2].funds;
                    storeFund[2].funds = 0;
                    storeFund[3].funds -= amount;
                    storeFund[3].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount));
                    return true; 
                }
                break;
            case 3: {
                if(((storeFund[2].funds + storeFund[3].funds) - amount ) < 0){
                    cout<< "No funds available" << endl;
                    storeFund[2].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount)+" (Failed)"); 
                } else { 
                    amount -= storeFund[3].funds;
                    storeFund[3].funds = 0;
                    storeFund[2].funds -= amount;
                    storeFund[2].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[1].fNum)+" "+to_string(amount));
                    return true; 
                }
                break;
            }
            default: {
                    cout<<"No funds available"<<endl;
                return false; 
                break;
                }
            }
        } else { 
            storeFund[fund].funds -= amount;
            storeFund[fund].accHist.push("W "+to_string(getAccNum())+to_string(storeFund[fund].fNum)+" "+to_string(amount));
            return true;
        }

    }
    return false;
}
void Account::printHistoryFund(int fund) {
    cout << getFundName(fund) << ": $" << storeFund[fund].funds << endl;
    while(!storeFund[fund].accHist.empty()){
        cout<<"  "<<storeFund[fund].accHist.front() << endl;
        storeFund[fund].accHist.pop();
    }
}

ostream &operator<<(ostream &out, Account &acc){
    out << "Name: " << acc.getFName() << " " << acc.getLName() << "  ID: " << acc.AccNum << endl;
    for(int i = 0; i<10; i++){
        out<<"   "<<acc.storeFund[i].fName<<" $"<<acc.storeFund[i].funds << endl;
    }
    return out; 
}

