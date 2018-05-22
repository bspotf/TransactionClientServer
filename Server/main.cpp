#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include "deps/asio/asio/include/asio.hpp"
#include "TransactionService.h"
#include "Log.h"



int main(int argc, char* argv[])
{
    using asio::ip::tcp;
    std::shared_ptr<Log> logService(new Log);
    try
    {
        std::shared_ptr<TransactionService> tService(new TransactionService);
        std::vector<std::string> transactions = {"sfsg4d|gdfgw1|354:258|cs|1|",
                                                 "hgfg4d|gdfgff|114:254|cs|2|",
                                                 "qwerty|tyuiop|334:117|cs|3|",
                                                 "abcde|abcdef|123:456|cs|4|",
                                                 "sfsg4d|gdfgw1|154:858|cs|5|",
                                                 "abcde|abcdef|367:128|cs|6|",
                                                 "sfsg4d|gdfgw1|116:213|cs|7|",
                                                 "snnnd|gfds1|314:648|cs|8|",
                                                 "sbbfbf|gggw1|681:222|cs|9|",
                                                 "sfsjjj|gjhgfd|333:224|cs|10|",
                                                };
        std::string message;
        for (int i = 0; i < 10; i++ )
        {
            tService->putTransaction(transactions[i]);
            // Parsing demo begin
            std::array<std::string,5> s = tService->parseTransaction(i);

            for (std::string f : s)
            {
                std::cout << f << " ";
            }
            std::cout << std::endl;
            // Parsing demo end
            message += transactions[i] + "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        asio::io_service io_service;
        tcp::acceptor acceptor(io_service,tcp::endpoint(tcp::v4(),8080));
        while(true)
        {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            const short len  = 128;
            while (message.begin() <= message.end())
            {
                socket.write_some(asio::buffer(message,len));
                message = std::string(message.begin() + len, message.end());
            }
        }
    }
    catch (std::exception &e)
    {
        logService->writeError(e.what());
    }
    return 0;
}
