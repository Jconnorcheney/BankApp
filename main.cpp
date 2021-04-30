#include <iostream>
#include <fstream>
#include "Application.h"
using namespace std;
int main(int argc, char *argv[]) {
    /* const values for reading clarity */
    const int COMMAND = 1;
    const string ADD_COMMAND = "-a";
    const string WITHDRAW_COMMAND = "-w";
    const string HELP_COMMAND = "-h";
    const string TOTAL_COMMAND = "-t";
    const string LOG_COMMAND = "-log";

    Application app;
    vector<string> bankContents = app.GetContents();
    app.SetBank(bankContents);
    string userCommand = argv[COMMAND];
    int goldTotal = stoi(app.bank[0]);

    if (userCommand == ADD_COMMAND) {
        app.AddGold(goldTotal);
    }else if (userCommand == WITHDRAW_COMMAND) {
        app.TakeGold(goldTotal);
    }else if (userCommand == TOTAL_COMMAND) {
        app.GuildBankTotal(goldTotal);
    }else if (userCommand == LOG_COMMAND) {
        app.DisplayTransactions();
    }else if (userCommand == HELP_COMMAND) {
        app.HelpMessage();
    }else{
        cout<< "Invalid parameter, try GuildBank -h to see all commands." << endl;
    }
    app.UpdateGuildBank();
    return 0;
}