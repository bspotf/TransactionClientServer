#include <iostream>
#include <array>
#include <deps/asio/asio/include/asio.hpp>

using asio::ip::tcp;

int main(int argc, char* argv[])
{
    try
    {
        asio::io_service io_service;
        tcp::endpoint ep( asio::ip::address::from_string("127.0.0.1"), 8080);
        tcp::socket socket(io_service);
        socket.connect(ep);
        while (true) {
            std::array<char,128> buf;
            asio::error_code error;
            size_t len = socket.read_some(asio::buffer(buf), error);
            if (error == asio::error::eof)
                break;
            else if (error)
                throw asio::system_error(error);
            std::cout.write(buf.data(), len);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
