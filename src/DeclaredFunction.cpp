#include "DeclaredFunction.h"
TValue DeclaredFunction::execute(ArgumentList *args) {
    TValue val;
    if (args) {
        int index = 0;

        if (parameter_list->size() != args->size()) {
            runerror("wrong number of arguments");
        }
        debugOut << "with arguments: ";
        for (auto arg : *args) {
            switch (arg.type) {
                case TValue::TType::Tstring: {
                    debugOut << arg.sValue.str << " ";
                    break;
                }
                case TValue::TType::Tdouble: {
                    debugOut << arg.sValue.dou << " ";
                    break;
                }
            }
            nowStack.newVar(parameter_list->at(index)->name, arg);
            index++;
        }
        debugOut << std::endl;
    }
    if (function_body) {
        for (auto i : function_body->getChildren()) {
            traverse(i);
        }
        function_body->run();
    }
    return TValue::undefined();
}

void DeclaredFunction::traverse(ast::Node* statement) {
    ast::VarDecl* varDecl = dynamic_cast<ast::VarDecl*>(statement);
    std::vector<ast::Node *> children = statement->getChildren();
    if (varDecl) {
        if (varDecl->initial) {
            varDecl->usedFlag = false;
        }
        ast::Statement* statement = new ast::VarDecl(varDecl->name);
        function_body->list.insert(function_body->list.begin(), statement);
    }
    if (children.size() > 0) {
        for (auto i : children) {
            DeclaredFunction::traverse(i);
        }
    }
}
