#include <iostream>
#include <exception>
#include <string>
#include "../header/invalidAgeException.h"

const char* InvalidAgeException::what() const noexcept {
    return message.c_str();
}
