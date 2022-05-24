#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <queue>
#include <iostream>

using namespace std;

class Account{
    private:
        struct Fund{
            string fName;
            int fNum;
            int funds;
            queue<string> accHist;
        };

        int AccNum;
        string FName;
        string LName;
        string fNames[10] = {"Money Market", "Prime Money Market", "Long-Term Bond", "Short-Term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"};
        Fund storeFund[10];

        void setFund(int fund, int amount);

    public: 
        Account();
        Account(int AccNum, string LName, string FName);
        void setName(string ln, string fn);
        void setnum(int num);
        ~Account();
        Account getAccount(int &AccNum);
        int getAccNum();
        int getFundBal(int &fNum);
        string getLName();
        string getFName();
        string getFundName(int ind);

        void AddFund(int f, int amm);
        void SubFund(int f, int amm);
        bool depositFunds(const int &fund, const int &amount);
        bool transFunds(const int &fund, int &amount, const int &fund2);
        bool withdrawFunds(const int &fund, int &ammount);

        void printHistoryFund(int fund);
    
        friend ostream &operator<<(ostream &out, Account &acc);

};




#endif
