#include <iostream> 
#include "Bank.h"
#include "Account.h"
#include "BSTree.h"

using namespace std;

void test1(bool prt){
    string fileName = "BankTransIn.txt";
    Bank tBank(fileName);
    if (prt){
        tBank.store.Display();
    }
    tBank.checkTrans();
}

int main(){
    //string fileName = "BankTransIn.txt";
    //Bank test(fileName);
    //test.printQueue();
    //test.checkTrans();
    //cout << endl;
    //cout << endl;
    //test.store.Display();
    cout << endl;
    test1(false);

    cout << endl;
    cout << endl;
    cout << "Tests Completed " << endl;
    //Bank b(fileName);
    //b.parseOrder("D 10013 7000");
    //b.parName("O Cash Johnny 1001");
    //Account john
    //Account a(1011, "john", "cash");
    //cout<<a<<endl;

    //BSTree bs;
    
    //cout << bs.Insert(new Account(1011, "john", "cash")) << endl;
    //cout << bs.Retrieve(1011, new Account(1011, "john", "cash")) << endl;
}

