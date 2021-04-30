#include "Application.h"
#include <fstream>
#include <iostream>
using namespace std;
//deconstructor
Application::~Application() {

}
//constructor
Application::Application() {

}
/* main function for reading the text file and storing it in a vector. */
vector<string> Application::GetContents() {
    vector<string> bankContents;

    ifstream file;
    while(file) {
        /* opening the file */
        file.open("guildBank.txt");
        if (file) {
            /* read contents */
            try {
                if (file.is_open() && file.good()) {
                    string line;
                    /* append it into the vector */
                    while (getline(file, line)) {
                        bankContents.push_back(line);
                    }
                    /* close the file. */
                    file.close();
                }
            } catch (std::exception const &e) {
                cout << "Error opening guild bank file: " << e.what() << endl;
            }
        } else {
            /* guildBank.txt doesnt exist, so make it and add the first line = 0 */
            std::ofstream outfile("guildBank.txt");
            outfile << "0" << endl;
            outfile.close();
            bankContents.push_back("0");
        }
    }
    return bankContents;
}

/* takes the vector returned from GetContents and sets the class property bank. */
void Application::SetBank(vector<string> bankVector) {
    bank = bankVector;
}
/* -a function, takes the gold input and note from the user and adds them to the
 * text file and updates the guild bank total. */
void Application::AddGold(int goldTotal) {
    string note;
    int goldValue;
    /* get gold value from user. */
    cout << "Enter gold value to add:";
    cin >> goldValue;
    /* int validation, reruns until int is entered. */
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Enter a valid whole number:";
            cin>>goldValue;
        }
        if(!cin.fail()){
            break;
        }
    }
    cout << "Adding " << goldValue << " to the Guild Bank total." << endl;
    cin.ignore();
    cout << "Reason for Gold added:";
    getline(cin,note);

    /* combine the note + the gold value entered, add brackets around added value */
    note + char(goldValue);
    note = note + " (+" + to_string(goldValue) + ")";

    /* new updated bank total (old total + entered value) */
    int newBankTotal = goldTotal + goldValue;
    cout << "Gold successfully added, new total of: " << newBankTotal << endl;
    /* replace the first line of the vector with new bank total */
    bank.at(0) = std::to_string(newBankTotal);
    /* add the note and value added to transaction log */
    bank.push_back(note);
}
/* -w function, takes in two inputs from user, total gold added,
 * and reason for adding */
void Application::TakeGold(int goldTotal) {
    /* This function is very similar to the Add function, comments only added
     * where logic differs */

    string note;
    int goldValue;

    cout << "Enter gold value withdrawn:";
    cin >> goldValue;
    /* int validation, if the cin fails, promps you try again. */
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Enter a valid whole number:";
            cin>>goldValue;
        }
        if(!cin.fail()){
            break;
        }
    }
    /* if the value is higher than the total gold in the bank, withdrawing fails.*/
    if(goldValue > goldTotal){
        cout << "Can't take out more than currently exists. Current total is "
        << goldTotal << "." << endl;
        return;
    }

    cout << "Withdrawing " << goldValue << " from the Guild Bank total." << endl;
    cin.ignore();
    cout << "Reason for Gold withdrawn:";
    getline(cin,note);

    note + char(goldValue);
    note = note + " (-" + to_string(goldValue) + ")";

    int newBankTotal = goldTotal - goldValue;
    cout << "Gold successfully withdrawn, new total of: " << newBankTotal << endl;
    bank.at(0) = std::to_string(newBankTotal);
    bank.push_back(note);
}
/* -t function, very simple. shows guild bank total gold. */
void Application::GuildBankTotal(int totalGold) {
    cout << "Guild Bank Total: " << totalGold << "." << endl;
}
/* -log function, displays all the contents of the bank vector. */
void Application::DisplayTransactions() {
    for(int i = 0; i < bank.size();i++){
        if(i != 0){
            cout << bank[i] << endl;
        }else{
            /* if it's the first loop (aka the total gold data)
             * format that line to look nicer for the end user */
            cout << "Guild Bank Total: " + bank[i] << endl;
        }

    }
}
/* -h Command functions. shows all the possible arguments for the program.*/
void Application::HelpMessage() {
    cout << " -_-_-_-_- GuildBank Commands -_-_-_-_-" << endl;
    cout << "GuildBank -a (add gold to the guild bank)." << endl;
    cout << "GuildBank -w (withdraw gold from the guild bank)." << endl;
    cout << "GuildBank -h (help, display all commands)." << endl;
    cout << "GuildBank -t (total, display guild bank total)." << endl;
    cout << "GuildBank -log (display all transactions)." << endl;
    cout << "GuildBank -d (delete logged transactions, doesn't modify total gold).";
}
/* Function for updating the text file with the current bank vector */
void Application::UpdateGuildBank() {
    try{
        string bankFile = "guildBank.txt";
        ofstream file(bankFile);
        for(int i = 0; i < bank.size(); i++){
            file << bank[i]+"\n";
            }
        file.close();
    }catch(std::exception const& e){
        cout << "Error writing results to file: " << e.what() << endl;
    }
}
/* -d function, removes the transaction data from the text file
 *  by deleting old text file and replacing it with a new one, same name
 *  with the first line being the passed in totalGold parameter */
void Application::RemovedLoggedEvents(string totalGold) {
    try{
        if( remove("guildBank.txt") != 0){
            cout << "Error Deleting contents." << endl;
        }else{
            cout << "Successfully reset Guild Bank transactions." << endl;
        }

        string bankFile = "guildBank.txt";
        ofstream file(bankFile);
        file << totalGold;
        file.close();

    }catch(std::exception const& e){
        cout << "Error writing results to file: " << e.what() << endl;
    }
}