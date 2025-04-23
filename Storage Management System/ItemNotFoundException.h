#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class ItemNotFoundException : public runtime_error {
public:
    ItemNotFoundException(const string& msg) : runtime_error(msg) {}//trow error
};
