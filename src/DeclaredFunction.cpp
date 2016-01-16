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
    debugOut<<"run func now!"<<std::endl;
    if (function_body) {
        if (function_body->getChildren().size() > 0) {
            for (auto i : function_body->getChildren()) {
                traverse(i);
            }
        }
        debugOut<<"run func now!"<<std::endl;
        function_body->run();
    }
    return TValue::undefined();
}

void DeclaredFunction::traverse(ast::Node* statement) {
    if (!statement) return;
    ast::VarDecl* varDecl = dynamic_cast<ast::VarDecl*>(statement);
    std::vector<ast::Node *> children = statement->getChildren();
    if (varDecl) {
        varDecl->usedFlag = false;
        ast::Statement* statement = new ast::VarDecl(varDecl->name);
        function_body->list.insert(function_body->list.begin(), statement);
    } else if (children.size() > 0) {
        for (auto i : children) {
            DeclaredFunction::traverse(i);
        }
    }
}
