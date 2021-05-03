#ifndef BANKAPP_APPLICATION_H
#define BANKAPP_APPLICATION_H
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
class Application {
public:
    vector<string> bank;

    Application();
    virtual ~Application();
    void SetBank(vector<string> bankVector);
    vector<string> GetContents();
    void AddGold(int totalGold);
    void TakeGold(int totalGold);
    void GuildBankTotal(int totalGold);
    void DisplayTransactions();
    void HelpMessage();
    void UpdateGuildBank();
    void RemovedLoggedEvents(string totalGold);
    static string GetDDMMYY();

};


#endif //BANKAPP_APPLICATION_H
