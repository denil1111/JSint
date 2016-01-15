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
            nowStack.assignAndNew(parameter_list->at(index)->name, arg);
            index++;
        }
        debugOut << std::endl;
    }
    try{
        if (function_body) {
            val = function_body->run();
        } else {
            val = TValue::undefined();
        }
    }catch(ast::ReturnException e){
        val = e.value;
    }
    return val;
}
