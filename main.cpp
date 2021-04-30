#include <iostream>
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
    const string DELETE_COMMAND = "-d";

    Application app;
    vector<string> bankContents = app.GetContents();
    app.SetBank(bankContents);
    string userCommand;
    /* if there is an argument set the userCommand variable = the argument*/
    if(argc > 1){
        userCommand = argv[COMMAND];
    }else{
        /* else keep it bank */
        userCommand = "";
    }
    /* convert the total in index 0 to an int to be used later in the program */
    int goldTotal = stoi(app.bank[0]);
    /* if/else block that covers all input arguments
     * with add and withdraw also running the update guild bank function */
    if (userCommand == ADD_COMMAND) {
        app.AddGold(goldTotal);
        app.UpdateGuildBank();
    }else if (userCommand == WITHDRAW_COMMAND) {
        app.TakeGold(goldTotal);
        app.UpdateGuildBank();
    }else if (userCommand == TOTAL_COMMAND) {
        app.GuildBankTotal(goldTotal);
    }else if (userCommand == LOG_COMMAND) {
        app.DisplayTransactions();
    }else if (userCommand == HELP_COMMAND) {
        app.HelpMessage();
    }else if (userCommand == DELETE_COMMAND){
        app.RemovedLoggedEvents(app.bank[0]);
    }else{
        /* invalid or no argument, point user in the right direction to use app */
        cout << "Invalid argument, use GuildBank -h to see all arguments." << endl;
    }

    return 0;
}