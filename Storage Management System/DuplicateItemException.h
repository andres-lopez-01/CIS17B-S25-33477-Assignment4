#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class DuplicateItemException : public runtime_error {
public:
    DuplicateItemException(const string& msg) : runtime_error(msg) {} //throws error
};
