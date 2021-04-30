#ifndef BANKAPP_APPLICATION_H
#define BANKAPP_APPLICATION_H
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class Application {
public:
    vector<string> bank;

    Application();
    virtual ~Application();
    void SetBank(vector<string> bankVector);
    vector<string> GetContents();
    int AddGold(int totalGold);
    int TakeGold(int totalGold);
    void GuildBankTotal(int totalGold);
    void DisplayTransactions();
    void HelpMessage();
    void UpdateGuildBank();

};


#endif //BANKAPP_APPLICATION_H
