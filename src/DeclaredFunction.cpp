#include "DeclaredFunction.h"

TValue DeclaredFunction::execute(ArgumentList *args) {
    TValue val;
    if (args) {
        int index = 0;

        if (parameter_list->size() != args->size()) {
            runerror("wrong number of arguments");
        }
        for (auto arg : *args) {
            arg->run();
        }
        debugOut << "with arguments: ";
        for (auto arg : *args) {
            switch (arg->value.type) {
                case TValue::TType::Tstring: {
                    debugOut << arg->value.sValue.str << " ";
                    break;
                }
                case TValue::TType::Tdouble: {
                    debugOut << arg->value.sValue.dou << " ";
                    break;
                }
            }
            nowStack.assignAndNew(parameter_list->at(index)->name, arg->value);
            index++;
        }
        debugOut << std::endl;
    }
    try{
        val = function_body->run();
    }catch(ast::ReturnException e){
        val = e.value;
    }
    
    nowStack.pop();
    return val;
}
