#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

// ANSI Escape Codes Colors
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

// ANSI Escape Codes Style Text
#define BOLD "\033[1m"

int requestRpc(std::string url, std::string method, std::string param)
{
    nlohmann::json requestJson = {
        {"jsonrpc", "2.0"},
        {"method", method},
        {"params", {param}},
        {"id", 0}};

    std::cout << std::setfill('-') << std::setw(40) << "-" << std::setfill(' ') << "\n";
    std::cout << "Select RPC Server -> " << GREEN << BOLD << url << RESET << std::endl;
    std::cout << "Select Method -> " << YELLOW << BOLD << method << RESET << std::endl;

    if (!param.empty())
    {
        std::cout << "Parameters -> " << BLUE << BOLD << param << RESET << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::setfill(' ') << "\n";

    try
    {
        auto response = cpr::Post(
            cpr::Url{url},
            cpr::Body{requestJson.dump()},
            cpr::Header{{"Content-Type", "application/json"}, {"Origin", url}});

        if (response.status_code != 200)
        {
            std::cerr << "Error sending RPC request. Status code: " << response.status_code << std::endl;
            if (response.error)
            {
                std::cerr << "Error details: " << response.error.message << std::endl;
            }
            return 1;
        }

        nlohmann::json responseJson = nlohmann::json::parse(response.text);
        if (responseJson.contains("result"))
        {
            std::cout << "RPC Status code: " << response.status_code << std::endl;
            std::cout << "RPC Response: " << responseJson["result"] << std::endl;
        }
        else if (responseJson.contains("error"))
        {
            std::cerr << "Error in RPC response: " << responseJson["error"] << std::endl;
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::string url = "";
    std::string method = "";
    std::string param = "";

    if (argc >= 3 && (argc % 2 == 1))
    {
        for (int i = 1; i < argc; i += 2)
        {
            if ((std::string(argv[i]).length() >= 2 ? std::string(argv[i]).substr(0, 2) : std::string(argv[i])) == "-u")

            {
                url = argv[i + 1];
            }
            else if ((std::string(argv[i]).length() >= 2 ? std::string(argv[i]).substr(0, 2) : std::string(argv[i])) == "-m")
            {
                method = argv[i + 1];
            }
            else if ((std::string(argv[i]).length() >= 2 ? std::string(argv[i]).substr(0, 2) : std::string(argv[i])) == "-p")
            {
                param = argv[i + 1];
            }
            else
            {
                std::cerr << "Unknown argument: " << argv[i] << std::endl;
            }
        }
    }

    if (url.empty())
    {
        std::cerr << "Specify the RPC address you want to test" << std::endl;
        return 1;
    }
    if (method.empty())
    {
        std::cerr << "Specify the required method for testing" << std::endl;
        return 1;
    }

    return requestRpc(url, method, param);
}
