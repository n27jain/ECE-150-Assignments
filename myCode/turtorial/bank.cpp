#include <stdlib.h>
#include <iostream>
using namespace std;

const int count = 2;
int account_number[count];
float balance[count];

int main(const int argc, const char *argv[])
{
    // input error checking goes here...
    int withdraw_account = atoi(argv[1]);
    float amount = atof(argv[2]);

    // setting up accounts
    account_number[0] = 5767230;
    balance[0] = 7500.00;
    account_number[1] = 5767451;
    balance[1] = 5805.50;

    // find the account in database
    int account_position = -1;
    for (int i = 0; i < count; ++i) {
        if (account_number[i] == withdraw_account)
            account_position = i;
    }

    if (account_position == -1) {
        cerr << "Account does not exist." << endl;
    } else {
        // check balance
        if (balance[account_position] >= amount) {
            cout << "Withdrawal successful." << endl;
            balance[account_position] = balance[account_position] - amount;
        } else {
            cout << "Withdrawal failed." << endl;
        }
    }
    
    return 0;
}
