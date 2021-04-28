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
void Application::AddGold(int goldValue) {
    cout << "Adding " << goldValue << " to the guild bank total";
}
void Application::TakeGold(int goldValue) {

}
int Application::GuildBankTotal() {

}
void Application::DisplayTransactions() {

}
void Application::UpdateGuildBank() {

}