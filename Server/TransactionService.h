#ifndef TS_H
#define TS_H

#include <vector>
#include <string>
#include <array>


class TransactionService
{
private:
    std::vector<std::string> transactionContainer;
    const static unsigned short numOfArgs = 5;
public:
    TransactionService();
    void putTransaction(std::string transaction);
    std::string getTransaction(int num);
    std::array<std::string,numOfArgs> parseTransaction(int num);

};

#endif //TS_H
