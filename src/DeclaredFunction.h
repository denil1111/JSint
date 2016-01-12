#ifndef DECLARED_FUNCTION_H_
#define DECLARED_FUNCTION_H_

#include <string>
#include "Object.h"
#include "ast.h"
#include "varlist.hpp"
#include "utils.h"

class TValue;
class VarStack;

namespace ast {
    class Identifier;
    class Expression;
    class StatementList;
}
typedef std::vector<ast::Identifier*> ParameterList;
typedef std::vector<ast::Expression*> ArgumentList;
typedef ast::StatementList FunctionBody;

extern VarStack nowStack;

class DeclaredFunction {
public:
    ast::Identifier *function_name;
    ParameterList *parameter_list;
    FunctionBody *function_body;
    DeclaredFunction(ast::Identifier* id, ParameterList* parameters, FunctionBody* body) : function_name(id), parameter_list(parameters), function_body(body) { }

    virtual TValue execute(ArgumentList *args);
};


#endif
