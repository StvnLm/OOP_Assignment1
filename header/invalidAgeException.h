#include <iostream>
#include <exception>
#include <string>

#ifndef INVALIDAGEEXCEPTION_H
#define INVALIDAGEEXCEPTION_H

class InvalidAgeException : public std::exception {
public:
    InvalidAgeException(const char* msg) : message(msg) {}

    const char* what() const noexcept override;

private:
    std::string message;
};

#endif
