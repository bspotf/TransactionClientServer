#include "TransactionService.h"
#include <algorithm>

TransactionService::TransactionService()
{

}

void TransactionService::putTransaction(std::string transaction)
{
    transactionContainer.push_back(transaction);
}

std::string TransactionService::getTransaction(int num)
{
    return transactionContainer[num];
}

std::array<std::string,TransactionService::numOfArgs>
TransactionService::parseTransaction(int num)
{
    std::array<std::string,numOfArgs> parsedTransaction;
    std::string element = transactionContainer[num];
    int counter = 0;
    for (int i = 0; i < numOfArgs; i++)
    {
        auto vertPosition = std::find(element.begin(), element.end(), '|');
        if (vertPosition != element.end())
        {
            counter++;
            parsedTransaction[i] = std::string(element.begin(),vertPosition);
            element = std::string(vertPosition + 1, element.end());
        }
    }
    return parsedTransaction;
}


