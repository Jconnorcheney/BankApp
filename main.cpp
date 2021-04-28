#include <iostream>
#include <fstream>
#include "Application.h"
using namespace std;
int main(int argc, char *argv[]) {
    /* const values for reading clarity */
    const int COMMAND = 0;
    const int GOLD_VALUE = 1;
    const string ADD_COMMAND = "-a";
    const string WITHDRAW_COMMAND = "-w";
    const string HELP_COMMAND = "-h";
    const string TOTAL_COMMAND = "-t";
    const string LOG_COMMAND = "-log";

    int goldInput;
    string userCommand = argv[COMMAND];
    if (argc > 1) {
        try {
            goldInput = int(argv[GOLD_VALUE]);
        }catch (exception const &e) {

            cout << e.what() << "You must enter a whole number as your gold value,"
                       " try 'guildBank -h' for more help." << endl;
            return 0;
        }

    }
    Application app;
    vector<string> bank = app.GetContents();
    if (userCommand == ADD_COMMAND) {
        cout << "Withdrawing " << goldInput << " from the guild bank total";
        app.AddGold(goldInput);
    }
    if (userCommand == WITHDRAW_COMMAND) {
        cout << "Adding " << goldInput << " to the guild bank total";
        app.TakeGold(goldInput);
    }
    if (userCommand == TOTAL_COMMAND) {
        app.GuildBankTotal();
    }
    if (userCommand == LOG_COMMAND) {
        app.DisplayTransactions();
    }
    if (userCommand == HELP_COMMAND) {
        app.HelpMessage();
    }

    return 0;
}