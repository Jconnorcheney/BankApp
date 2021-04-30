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
vector<string> Application::GetContents() {
    vector<string> bankContents;

    ifstream file;
    while(file) {
        //opening the file
        file.open("guildBank.txt");
        if (file) {
            /* read contents */
            try {
                if (file.is_open() && file.good()) {
                    string line;
                    //append it into the vector
                    while (getline(file, line)) {
                        bankContents.push_back(line);
                    }
                    //close the file.
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
        }
    }
    return bankContents;
}
void Application::SetBank(vector<string> bankVector) {
    bank = bankVector;
}
int Application::AddGold(int goldTotal) {
    string note;

    int goldValue;

    cout << "Enter gold value:";
    cin >> goldValue;

    while(!(cin >> goldValue)){
        cout << "Please enter a valid gold value (whole number):";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    char goldValueChar = char(goldValue);
    cout << "Adding " << goldValue << " from the guild bank total." << endl;
    cin.ignore();
    cout << "Reason for Gold added:";
    getline(cin,note);
    note + goldValueChar;
    int newBankTotal = goldTotal + goldValue;
    note = note + " || +" + to_string(goldValue);
    bank.at(0) = std::to_string(newBankTotal);
    bank.push_back(note);
    return goldValue;

}

int Application::TakeGold(int goldTotal) {
    string note;

    int goldValue;

    cout << "Enter gold value:";
    cin >> goldValue;
    while(!(cin >> goldValue)){
        cout << "Please enter a valid gold value (whole number):";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    char goldValueChar = char(goldValue);
    cout << "Withdrawing " << goldValue << " from the guild bank total." << endl;
    cin.ignore();
    cout << "Reason for Gold withdrawn:";
    getline(cin,note);
    note + goldValueChar;
    int newBankTotal = goldTotal - goldValue;
    note = note + " || -" + to_string(goldValue);
    bank.at(0) = std::to_string(newBankTotal);
    bank.push_back(note);
    return goldValue;
}

void Application::GuildBankTotal(int totalGold) {
    cout << "Guild Bank Total: " << totalGold << "." << endl;
}

void Application::DisplayTransactions() {
    for(int i = 0; i < bank.size();i++){
        if(i != 0){
            cout << bank[i] << endl;
        }else{
            cout << "Guild Bank Total: " + bank[i] << endl;
        }

    }
}

void Application::HelpMessage() {
    cout << "GuildBank Commands" << endl;
    cout << "GuildBank -a (add gold to the guild bank)." << endl;
    cout << "GuildBank -w (withdraw gold from the guild bank)." << endl;
    cout << "GuildBank -h (display all commands)." << endl;
    cout << "GuildBank -t (display guild bank total)." << endl;
    cout << "GuildBank -log (display all the)." << endl;

}

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