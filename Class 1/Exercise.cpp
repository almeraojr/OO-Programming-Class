
#include <iostream>
#include <string>

using namespace std;

struct Client{
    string name;
    int code;
    double balance;
};

bool debit(Client &client, double debitValue)
{
    double bal = client.balance;

    bal -= debitValue;

    if (bal <=0)
    {
        cout << "Not possible! Client does not have sufficient funds for operation!" << endl;

        return false;
    }else
    {
        client.balance = bal;
        cout << "Value = " << debitValue << " debited." << endl;
        return true;
    }
    
}

bool credit(Client &client, double creditValue)
{
    double bal = client.balance;

    bal += creditValue;

    client.balance = bal;

    cout << "Value = " << creditValue << " credited to account." << endl;

    return true;
    
}

int main()
{
    struct Client client1, client2;

    client1.name = "Junin";
    client1.code = 1;
    client1.balance = 900;

    client2.name = "drezin";
    client2.code = 2;
    client2.balance = 450;

    debit(client2, 50);
  
    credit(client1, 6489.77);

    cout << "new balance = " << client1.balance << " for client" << client1.name << endl;

    cout << "new balance = " << client2.balance << " for client" << client2.name << endl;

}