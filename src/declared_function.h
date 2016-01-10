#ifndef DECLARED_FUNCTION_H_
#define DECLARED_FUNCTION_H_
#include <string>
#include <vector>

class DeclaredFunction {
public:
    std::string name;
    std::vector<std::string> *parameters;
    void callWithArguments() {}
};

#endif
