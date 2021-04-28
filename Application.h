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
    Application();
    virtual ~Application();
    static vector<string> GetContents();
    void AddGold(int goldValue);
    void TakeGold(int goldValue);
    int GuildBankTotal();
    void DisplayTransactions();
    void HelpMessage();
    void UpdateGuildBank();
};


#endif //BANKAPP_APPLICATION_H
