#include <iostream>
#include "../include/httplib.h"

int main() {
    httplib::Server svr;

    // Универсальный обработчик для всех методов
    auto echo_handler = [](const httplib::Request& req, httplib::Response& res) {
        std::string response = "ECHO SERVER\n";
        response += "Method: " + req.method + "\n";
        response += "Path: " + req.path + "\n";
        response += "Body: " + req.body + "\n";
        
        response += "Headers:\n";
        for (const auto& header : req.headers) {
            response += "  " + header.first + ": " + header.second + "\n";
        }
        
        res.set_content(response, "text/plain");
        std::cout << "Processed request: " << req.method << " " << req.path << std::endl;
    };

    // Регистрируем обработчик для основных методов
    svr.Get(".*", echo_handler);
    svr.Post(".*", echo_handler);
    svr.Put(".*", echo_handler);
    svr.Delete(".*", echo_handler);
    svr.Patch(".*", echo_handler);

    std::cout << "Starting Echo server on http://localhost:8080" << std::endl;
    std::cout << "Press Ctrl+C to stop..." << std::endl;
    
    svr.listen("0.0.0.0", 8080);
    return 0;
}