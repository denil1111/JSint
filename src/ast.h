#ifndef __AST_H__
#define __AST_H__

#include <string>
#include <map>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <sstream>
#include "varlist.hpp"
#include "Object.h"

//used forward-declaration to deal with cross-reference issue
class TValue;
// namespace ast start
namespace ast {
// forward declaration
class LabelDecl;
class ConstDecl;
class TypeDecl;
class VarDecl;
class Statement;
class Identifier;
class Routine;
class Expression;
class StatementList;
class IntegerType;
class RealType;
class CharType;
class BooleanType;
class RangeType;
class ArrayType;
class ConstValue;
class FieldDecl;
class RecordType;
class TypeConst;
class CaseStmt;
class Block;
class CatchStmt;
class ThrowStmt;
class FinallyStmt;
class TryStmt;
class BreakException;
class ContinueException;
class LabeledStmt;
class MemberName;
class myException;

typedef std::string PropertyName;
typedef std::vector<MemberName*> MemberNameList;
typedef std::vector<Identifier*> ParameterList;
typedef std::vector<Expression*> ArgumentList;
//typedef std::vector<Expression*> ElementList;
typedef StatementList FunctionBody;
typedef std::vector<VarDecl *>      VarDeclList;
typedef std::vector<Identifier *>   IdentifierList;
typedef std::vector<Routine *>      RoutineList;
typedef std::vector<std::string>    NameList;
typedef std::vector<Expression *>   ExpressionList;
typedef std::vector<ConstDecl *>    ConstDeclList;
typedef std::vector<FieldDecl *>    FieldDeclList;
typedef std::vector<TypeConst *>    TypeDeclList;
typedef std::vector<CaseStmt *>     CaseList;
typedef std::map<std::string,Statement*> LabelMap;

class ReturnException:public std::exception{
public:
    TValue value;
    ReturnException(TValue v):value(v){};
};
class runerrorException:public std::exception{
public:
    runerrorException(){};
};
class BreakException:public std::exception{
public:
    std::string label;
    BreakException(std::string label):label(label){}
};

class ContinueException:public std::exception{
public:
    std::string label;
    ContinueException(std::string label):label(label){}
};

class MyException:public std::exception{
public:
    TValue myex;
    MyException(TValue myex):myex(myex){}
};


// pure virtual class for all ast noxdes
class Node {
public:
    std::string     debug;
    // TValue value;
    void print_node(std::string prefix, bool tail, bool root) {
        std::string tailStr = "└── ";
        std::string branchStr = "├── ";
        std::string ch_tailStr = "    ";
        std::string ch_branchStr = "|   ";
        std::cout << (root ? prefix : (prefix + (tail ? tailStr : branchStr))) << (this->toString()) << std::endl;
        auto children_list = this->getChildren();
        auto ch_prefix = tail ? prefix + ch_tailStr : prefix + ch_branchStr;
        for(size_t i = 0; i < children_list.size(); i++) {
            children_list[i] ? children_list[i]->print_node(ch_prefix, i == children_list.size() - 1, false) : []() {std::cout << "nullptr in tree\n";}();
        }
    }

    virtual std::vector<Node *> getChildren() { return *(new std::vector<Node *>()); }
    virtual ~Node() {}
    virtual std::string toString(){
        return "node";
    };
    virtual TValue run() = 0;
	virtual void assign(TValue value) { runerror("Assignment not supported!"); }
};
class Statement : public Node {
public:
    Statement() {};
    virtual TValue run()
    {
        return TValue::undefined();
    }
    virtual std::vector<Statement*> *getlist(){}
	virtual std::string toString() { return "Statement"; }
};

class StatementList : public Statement{
public:
    std::vector<Statement*> list;
	StatementList() {}
	StatementList(Statement* stmt) {
		list = std::vector<Statement*>{stmt};
	}
	StatementList(Statement* stmt, StatementList* stmtList) {
		list = std::vector<Statement*>{stmt};
		for (auto stmt : stmtList->list) {
			list.push_back(stmt);
		}
	}
    virtual TValue run();
    virtual std::string toString(){ return "StatementList";}
    virtual std::vector<Statement*> *getlist(){ return &list;}
	virtual std::vector<Node *> getChildren() {
		std::vector<Node *> rlist;
		for(auto i : list) rlist.push_back((Node *)i);
		return rlist;
 	}
};

class Program : public Node {
public:
    LabelDecl*      lable_part;
    ConstDeclList*  const_part;
    TypeDeclList*   type_part;
    VarDeclList*    var_part;
    RoutineList*    routine_part;
    StatementList*  routine_body;

    Program() {}
    Program(LabelDecl* lp, ConstDeclList* cp, TypeDeclList* tp, VarDeclList* vp, RoutineList* rp, StatementList* rb) :
        lable_part(lp),
        const_part(cp),
        type_part(tp),
        var_part(vp),
        routine_part(rp),
        routine_body(rb) {}
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        for(auto i : *(const_part))         list.push_back((Node *)i);
        for(auto i : *(type_part))          list.push_back((Node *)i);
        for(auto i : *(var_part))           list.push_back((Node *)i);
        for(auto i : *(routine_part))       list.push_back((Node *)i);
        for(auto i : *(routine_body->getlist())) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "Program start"; }
    virtual TValue run();
};

class Routine : public Program {
public:
    enum class RoutineType { function, procedure, error };
    Identifier*     routine_name;
    TypeDecl*       return_type;
    VarDeclList*    argument_list;
    RoutineType     routine_type; // function or procedure
    Routine(RoutineType rt, Identifier* rn, VarDeclList* vdl, TypeDecl* td) :
        Program(),
        routine_name(rn),
        return_type(td),
        argument_list(vdl),
        // routine_list(nullptr),
        routine_type(rt) {}
    Routine(Routine* r, Program* p) :
        Program(*p),
        routine_name(r->routine_name),
        return_type(r->return_type),
        argument_list(r->argument_list),
        // routine_list(r->routine_list),
        routine_type(r->routine_type) {
        }

    bool isFunction() { return routine_type == RoutineType::function; }
    bool isProcedure() { return routine_type == RoutineType::procedure; }

    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)routine_name);
        list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        for(auto i : *(const_part)) list.push_back((Node *)i);
        for(auto i : *(var_part)) list.push_back((Node *)i);
        for(auto i : *(routine_part)) list.push_back((Node *)i);
            // std::cout<<"hahaha"<<this<<";"<<var_part<<"\n";
        for(auto i : *(routine_body->getlist())) list.push_back((Node *)i);

        return list;
    }
    virtual std::string toString() { return routine_type == RoutineType::function ? "Function" : "Procedure"; }
    virtual TValue run();
};

class Expression : public Statement {
public:
    virtual TValue run();
};

class CallExpression : public Expression {
public:
    Expression* funcExp;
    ArgumentList* argument_list;
    CallExpression(Expression* funcExp, ArgumentList* args) : funcExp(funcExp), argument_list(args) {}
    virtual std::string toString(){ return "function_called"; }
    virtual TValue run();
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back(funcExp);
        if (argument_list) {
            for (auto i : *argument_list) {
                list.push_back(i);
            }
        }
        return list;
    }
};

class LabelDecl : public Statement {

};
class TypeDecl : public Statement {
public:
    enum class TypeName : int{
        error,
        integer,
        real,
        character,
        boolean,
        range,
        array,
        record,
        user_defined,
		string
    };

    std::string     raw_name = "";
    TypeName        sys_name = TypeName::error;
    RangeType*      range_type = nullptr;
    ArrayType*      array_type = nullptr;
    RecordType*     record_type = nullptr;

    TypeDecl(ArrayType* atp) : array_type(atp) {init();}
    TypeDecl(RecordType* rtp) :  record_type(rtp) {init();}
    TypeDecl(RangeType* rtp) : range_type(rtp) {init();}
    TypeDecl(TypeName tpname) : sys_name(tpname) { std::cout << "comment: used in const def" << std::endl; init();}
    TypeDecl(const std::string &str) : raw_name(str){init();}
    TypeDecl(const char * ptr_c) : raw_name(*(new std::string(ptr_c))) {init();}

    void init() {
        // std::cout << this << std::endl;
        if (sys_name != TypeName::error)
            return;
        if (raw_name == "integer")          sys_name = TypeName::integer;
        else if (raw_name == "real")        sys_name = TypeName::real;
        else if (raw_name == "char")        sys_name = TypeName::character;
        else if (raw_name == "boolean")     sys_name = TypeName::boolean;
        else if (raw_name.size() > 0)       sys_name = TypeName::user_defined;
        else if (range_type)                sys_name = TypeName::range;
        else if (array_type)                sys_name = TypeName::array;
        //else if (record_type)               sys_name = TypeName::record;
        else                                throw std::logic_error("Unimplemented type");
    }

    virtual std::string toString() { return raw_name; }
    virtual TValue run();
};

// class ArrayType: public Statement {
// public:
//     TypeDecl*   subscript = nullptr;
//     TypeDecl*   array_type = nullptr;

//     ArrayType(TypeDecl* ss, TypeDecl* at) : subscript(ss), array_type(at) {}
//     virtual std::string toString() { return "Array of " + (array_type ? array_type->raw_name : "#error"); }
//     virtual TValue run();
// };

class FieldDecl: public Statement {
public:
    Identifier* first;
    TypeDecl*   second;
    FieldDecl(Identifier* first, TypeDecl* second) : first(first), second(second) {}
    virtual std::string toString() { return "FieldDecl"; }
    virtual TValue run() {}
};

class RecordType: public Statement {
public:
    FieldDeclList*      field_list;

    RecordType(FieldDeclList* list) : field_list(list)  {}
    virtual std::string toString() { return "RecordType"; }
    virtual TValue run() {}
};


class Identifier : public Expression {
public:
    std::string         name;

    Identifier(const std::string& name) : name(name) {}
    Identifier(const char * ptr_s) : name(*(new std::string(ptr_s))) {}
    virtual std::string toString() { return "Identifier: " + name; }
    virtual TValue run();
};


class FunctionDeclaration : public Expression {
public:
    Identifier* function_name;
    ParameterList* parameter_list;
    FunctionBody* function_body;
    FunctionDeclaration(Identifier* id, ParameterList* args, FunctionBody* body) : function_name(id), parameter_list(args), function_body(body) {}
    virtual std::string toString(){ return "function_declaration"; }
    virtual TValue run();
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back(function_name);
        for (auto i : *parameter_list) {
            list.push_back(i);
        }
        for (auto i : function_body->getChildren()) {
            list.push_back(i);
        }
        return list;
    }
};

class ArrayRef : public Expression {
public:
    Identifier*     array = nullptr;
    Expression*     index = nullptr;

    ArrayRef(Identifier* array, Expression* index) : array(array), index(index) {}
    virtual std::string toString() { return "ArrayRef: " + array->name; }
    virtual TValue run();
};

class RecordRef : public Expression {
public:
    Identifier*     record = nullptr;
    Identifier*     field = nullptr;

    RecordRef(Identifier* record, Identifier* field) : record(record), field(field) {}
    virtual std::string toString() { return "RecordRef"; }
    virtual TValue run() {}
};



class ConstValue : public Expression {
public:
    virtual TypeDecl::TypeName getConstType() = 0;
    virtual int toRange() = 0;
    /* canRange : bool, if subclass can not be a range, overwrite it and return true  */
    virtual bool notRange() { return false; }
};


class TypeConst : public Statement {
public:
    Identifier*     name = nullptr;
    TypeDecl*       type = nullptr;

    TypeConst(Identifier* name, TypeDecl* td) : name(name), type(td) {}
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back(name);
        list.push_back(type);
        return list;
    }
    virtual std::string toString() { return "TypeConst"; }
    virtual TValue run() {}
};


class ConstDecl : public Statement {
public:
    Identifier*     name = nullptr;
    ConstValue*     val = nullptr;
    TypeDecl*       type = nullptr;

    ConstDecl(Identifier* name, ConstValue* cv)     : name(name), val(cv), type(new TypeDecl(val->getConstType())) {}
//
//    ConstDecl(Identifier* name, IntegerType* it)    : name(name), val((ConstValue *)it), type(new TypeDecl("integer")) {}
//    ConstDecl(Identifier* name, RealType* it)       : name(name), val((ConstValue *)it), type(new TypeDecl("real"))    {}
//    ConstDecl(Identifier* name, CharType* it)       : name(name), val((ConstValue *)it), type(new TypeDecl("char"))    {}
//    ConstDecl(Identifier* name, BooleanType* it)    : name(name), val((ConstValue *)it), type(new TypeDecl("boolean")) {}
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back(name);
        list.push_back(val);
        list.push_back(type);
        return list;
    }
    virtual std::string toString() { std::stringstream oss; oss << "Const " << name->name << ":" << val->toRange(); return oss.str(); }
    virtual TValue run();
};


class VarDecl : public Statement {
public:
    Identifier*     name;
    Expression*     initial;
    bool            usedFlag = true;
    VarDecl(Identifier* name, Expression* initial) : name(name), initial(initial) {}
    VarDecl(Identifier* name) : name(name), initial(nullptr) {}
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)name);
        list.push_back((Node *)initial);
        return list;
    }
    std::string toString() { return "VarDecl"; }
    virtual TValue run();
};
class IntegerType : public ConstValue {
public:
    int val;

    IntegerType(int val): val(val) {}
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::integer; }
    virtual int toRange() { return val; }
    virtual std::string toString() { return [=]() {std::stringstream oss; oss << val; return oss.str(); }(); }
    virtual TValue run();
};

class RealType : public ConstValue {
public:
    double val;

    RealType(double val) : val(val) {}

    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::real; }
    virtual int toRange() { return 0; }
    virtual bool notRange() { return true; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual TValue run();
};

class CharType : public ConstValue {
public:
    char val;

    CharType(const char * p_str) : val(*(p_str)) {}
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::character; }
    virtual int toRange() { return (int)val; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual TValue run();
};

class StringType : public ConstValue {
public:
    std::string val;

    StringType(const std::string& name) : val(name) {}
    StringType(const char * ptr_s) : val(*(new std::string(ptr_s))) {}
	virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::string; }
	virtual int toRange() { return 0; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual TValue run();
};

class BooleanType : public ConstValue {
public:
    bool val;

    BooleanType(const char * str) : val(std::string(str) == "true" ? true : false) {}
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::boolean; }
    virtual int toRange() { return val; }
    virtual std::string toString() { std::stringstream oss; oss << val; return oss.str(); }
    virtual TValue run();
};

class RangeType : public Expression {
public:
    //TypeDecl*       base_type; //TODO: distinguish int range, char range, boolean range
    int             low, high;
    std::string     low_s, high_s;
    bool            isNameRange = false;

    RangeType(int low, int high) : low(low), high(high) {}
    RangeType(std::string low_s, std::string high_s) : low_s(low_s), high_s(high_s), isNameRange(true) {}
    size_t size() { return high - low + 1; }
    virtual std::string toString() { std::stringstream oss; oss << "[" << low << "," << high << "]"; return oss.str(); }
    virtual TValue run();
};

class FuncCall : public Expression{
public:
    Identifier* id;
    ExpressionList* argument_list;

    FuncCall(Identifier* id) : id(id), argument_list(nullptr) {}
    FuncCall(Identifier* id, ExpressionList* argument_list) : id(id), argument_list(argument_list) {}

    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)id);
        // list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        // for(auto i : *(var_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "FuncCall " + id->name; }
    virtual TValue run();
};

class ProcCall : public Statement {
public:
    Identifier* id;
    ExpressionList* argument_list;

    ProcCall(Identifier* id) : id(id), argument_list(new ExpressionList) {}
    ProcCall(Identifier* id, ExpressionList* argument_list) : id(id), argument_list(argument_list) {}

    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)id);
        // list.push_back((Node *)return_type);
        for(auto i : *(argument_list)) list.push_back((Node *)i);
        // for(auto i : *(var_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_part)) list.push_back((Node *)i);
        // for(auto i : *(routine_body)) list.push_back((Node *)i);
        return list;
    }
    virtual std::string toString() { return "ProcCall " + id->name; }
    virtual TValue run();
};

class SysProcCall : public ProcCall {
public:
    SysProcCall(Identifier* id) : ProcCall(id) {}
    SysProcCall(Identifier* id, ExpressionList* al) : ProcCall(id, al) {}


    virtual std::string toString() { return "System Porcedure Call " + id->name; }
    virtual TValue run();
};

class SysFuncCall : public FuncCall {
public:
    SysFuncCall(Identifier* id) : FuncCall(id) {}
    SysFuncCall(Identifier* id, ExpressionList* al) : FuncCall(id, al) {}

    virtual std::string toString() { return "System Function Call " + id->name; }
    virtual TValue run();
};

class Operator : public Expression {
public:
    enum class OpType : int {
        //binary
        plus,
        minus,
        mul,
        div,
        mod,
        bit_and,
        bit_or,
        bit_xor,
		land,
		lor,
        eq,
        ne,
        lt,
        gt,
        le,
        ge,
		assign,
		comma,
		aeq,
		ane,
		iof,
		iin,
		lsh,
		rsh,
		lrsh,
		plus_assign,
		minus_assign,
		mul_assign,
		div_assign,
		mod_assign,
		bit_and_assign,
		bit_or_assign,
		bit_xor_assign,
		lsh_assign,
		rsh_assign,
		lrsh_assign,
        unary_label,
        bit_not,
        lnot,
        positive,
        negtive,
        pplus,
        mminus,
        rpplus,
        rmminus,
        voido,
        type,
        del,
        condition

    };

    Expression *op1, *op2, *op3;
    OpType op;

    Operator(Expression* op1, OpType op, Expression* op2) :
        op1(op1),
        op(op),
        op2(op2)
    {}
    Operator(Expression* op1, Expression* op2, Expression* op3) :
        op1(op1),
        op2(op2),
        op3(op3),
        op(OpType::condition)
    {}
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)op1);
        if (op<OpType::unary_label)
            list.push_back((Node *)op2);
        return list;
    }
    virtual std::string toString() {
        return "op: " + (std::map<OpType, std::string>){
            { OpType::plus, "plus" },
            { OpType::minus, "minus" },
            { OpType::mul, "mul" },
            { OpType::div, "div" },
            { OpType::mod, "mod" },
            { OpType::bit_and, "bit_and" },
            { OpType::bit_or, "bit_or" },
            { OpType::bit_xor, "bit_xor" },
            { OpType::eq, "eq" },
            { OpType::ne, "ne" },
            { OpType::lt, "lt" },
            { OpType::gt, "gt" },
            { OpType::le, "le" },
            { OpType::ge, "ge" },
			{ OpType::comma, "comma"},
			{ OpType::assign, "assign"},
			{ OpType::land, "logic_and"},
			{ OpType::lor, "logic_or"},
			{ OpType::land, "logic_and"},
			{ OpType::aeq, "all_eq"},
			{ OpType::ane, "all_ne"},
			{ OpType::iof, "of"},
			{ OpType::iin, "in"},
			{ OpType::lsh, "left_shift"},
			{ OpType::rsh, "right_shift"},
			{ OpType::lrsh, "lrshift"},
			{ OpType::plus_assign,"plus_assign"},
			{ OpType::minus_assign,"minus_assign"},
			{ OpType::mul_assign,"mul_assign"},
			{ OpType::div_assign,"div_assign"},
			{ OpType::mod_assign,"mod_assign"},
			{ OpType::bit_and_assign,"bit_and_assign"},
			{ OpType::bit_or_assign,"bit_or_assign"},
			{ OpType::bit_xor_assign,"bit_xor_assign"},
			{ OpType::lsh_assign,"lsh_assign"},
			{ OpType::rsh_assign,"rsh_assign"},
			{ OpType::lrsh_assign,"lrsh_assign"},
            { OpType::bit_not, "bit_not" },
            { OpType::positive, "positive"},
            { OpType::negtive, "negtive"},
            { OpType::pplus, "plus_plus_left"},
            { OpType::mminus, "minus_minus_left"},
            { OpType::rpplus, "plus_plus_right"},
            { OpType::rmminus, "minus_minus_right"},
            { OpType::voido, "void"},
            { OpType::type, "type"},
            { OpType::del, "delete"},
            { OpType::condition, "condition"}
        }[op];
    }
    virtual TValue run();
};

class AssignmentStmt : public Statement {
public:
    Identifier* lhs = nullptr; // left-hand side
    Expression* rhs = nullptr;
    bool  complex_assign = false;
    AssignmentStmt(Identifier* lhs, Expression* rhs) : lhs(lhs), rhs(rhs) {}
    AssignmentStmt(ArrayRef* lhs, Expression* rhs) : lhs((Identifier *)lhs), rhs(rhs), complex_assign(true) {}
    AssignmentStmt(RecordRef* lhs, Expression* rhs) : lhs((Identifier *)lhs), rhs(rhs), complex_assign(true) {}

    std::string getlhsName() {
        return complex_assign ? ((ast::ArrayRef*) this->lhs)->array->name : this->lhs->name;
    }

    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> list;
        list.push_back((Node *)lhs);
        list.push_back((Node *)rhs);
        return list;
    }
    virtual std::string toString() { return "Assignment"; }
    virtual TValue run();
};

class IfStmt : public Statement {
private:
    int instanceCount;
public:
    Expression* condition;
    Statement* thenStmt;
    Statement* elseStmt;
    IfStmt(Expression* condition,Statement* thenStmt,Statement* elseStmt) : condition(condition),thenStmt(thenStmt),elseStmt(elseStmt) {};
    virtual TValue run();
    virtual std::string toString() { return "If"; }
};
class WhileStmt : public Statement {
public:
    Expression* condition;
    Statement* loopStmt;
    bool ifDo;
    WhileStmt(Expression* condition,Statement* loopStmt,bool ifDo):condition(condition),loopStmt(loopStmt),ifDo(ifDo){}
    virtual TValue run();
    virtual std::string toString() { return "while"; }
};

// namespace ast end
class ForStmt : public Statement {
public:
    Expression* loopVar;
    Expression* startExp;
    Expression* endExp;
    // int direction;
    Statement* loopStmt;
    ForStmt(Expression* loopVar, Expression* startExp, Expression* endExp,Statement* loopStmt):
        loopVar(loopVar),
        startExp(startExp),
        endExp(endExp),
        loopStmt(loopStmt){}
    virtual TValue run();
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> rList;
        rList.push_back(loopVar);
        rList.push_back(startExp);
        rList.push_back(endExp);
        rList.push_back(loopStmt);
        return rList;
    }

    virtual std::string toString() { return "for"; }
};

class CaseStmt : public Statement {
public:
    Expression* condition;
    Statement* thenStmt;
    bool isDefault;
    CaseStmt(Expression* condition,Statement* thenStmt,bool isDefault):condition(condition),thenStmt(thenStmt),isDefault(isDefault){}
    virtual TValue run();
    virtual std::string toString() { return "case/default statement"; }
};

class SwitchStmt : public Statement {
public:
    Expression* exp;
    CaseList* list;
    SwitchStmt(Expression* exp,CaseList* list):exp(exp),list(list){}
    virtual TValue run();
    virtual std::string toString() { return "switch statement"; }
};

class ReturnStmt : public Statement {
public:
    Expression* exp;
    ReturnStmt(Expression* exp):exp(exp){}
    virtual TValue run();
    virtual std::string toString() { return "return statement"; }
};

class BreakStmt : public Statement {
public:
    Identifier * label;
    BreakStmt(Identifier * label):label(label){}
    virtual TValue run();
    virtual std::string toString() { return "break statement"; }
};

class ContinueStmt : public Statement {
public:
    Identifier * label;
    ContinueStmt(Identifier * label):label(label){}
    virtual TValue run();
    virtual std::string toString() { return "continue statement"; }
};

class LabeledStmt : public Statement {
public:
    Identifier * label;
    Statement * stmt;
    LabeledStmt(Identifier * label,Statement* stmt):label(label),stmt(stmt){}
    virtual TValue run();
    virtual std::vector<Node *> getChildren() {
        std::vector<Node *> rList;
        rList.push_back(label);
        rList.push_back(stmt);
        return rList;
    }
    virtual std::string toString() { return "LabeledStmt statement"; }
};

class TryStmt : public Statement {
public:
    Block*blockstmt;
    CatchStmt*catchstmt;
    FinallyStmt*finallystmt;
    TryStmt(CatchStmt*catchstmt,FinallyStmt*finallystmt):catchstmt(catchstmt),finallystmt(finallystmt){}
    virtual TValue run();
    virtual std::string toString() { return "try statement"; }
};

class ThrowStmt : public Statement {
public:
    Expression* exp;
    ThrowStmt(Expression* exp):exp(exp){}
    virtual TValue run();
    virtual std::string toString() { return "throw statement"; }
};

class FinallyStmt : public Statement{
public:
    Block * stmt;
    FinallyStmt(Block * stmt):stmt(stmt){}
    virtual TValue run();
    virtual std::string toString() { return "finally statement"; }
};

class CatchStmt : public Statement {
public:
    Identifier * identifier;
    Block * stmt;
    CatchStmt(Identifier * identifier,Block * stmt):identifier(identifier),stmt(stmt){}
    virtual TValue run();
    virtual std::string toString() { return "catch statement"; }
};

class PropertyNameAndValue: public Statement {
public:
	std::string name;
	ast::Expression* valueExp;
	PropertyNameAndValue() {}
    PropertyNameAndValue(std::string* name, ast::Expression* valueExp) : name(*name), valueExp(valueExp) {}
	virtual std::string toString() { return "Property"; }
	virtual std::vector<Node *> getChildren() { return std::vector<Node*>{valueExp}; }
	virtual TValue run();
};

class PropertyNameAndValueList : public StatementList {
public:
	PropertyNameAndValueList() {}
    PropertyNameAndValueList(PropertyNameAndValue* property): StatementList(property) {}
	PropertyNameAndValueList(PropertyNameAndValue* property,
							 PropertyNameAndValueList* propertyList):
	StatementList(property, propertyList) {}

	virtual std::string toString() { return "PropertyList"; }
	virtual std::vector<Node *> getChildren() {
		std::vector<Node *> rlist;
		for(auto el : list) rlist.push_back((Node *)el);
		return rlist;
	}
	virtual TValue run();
};

class ElementList : public StatementList {
public:
	ElementList() {}
ElementList(Expression* el): StatementList(el) {}
ElementList(Expression* el, ElementList* elList): StatementList(el, elList) {}

	virtual std::string toString() { return "ElementList"; }
	virtual std::vector<Node *> getChildren() { return StatementList::getChildren(); }
	virtual TValue run();
};

class ArrayType: public ConstValue {
private:
	ElementList* elList;
public:
    ArrayType() : elList(new ElementList()){}
ArrayType(ElementList* elList): elList(elList) {}
    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::array; }
	virtual int toRange() { return 1; }

    virtual std::string toString() { return "Array"; }
    virtual std::vector<Node *> getChildren() {
		return std::vector<Node *>{elList};
	}
    virtual TValue run();
};

class ObjectType : public ConstValue {
private:
	PropertyNameAndValueList* propList;
public:
    ObjectType(): propList(new PropertyNameAndValueList()) {}
    ObjectType(PropertyNameAndValueList* pList): propList(pList) {}

    virtual TypeDecl::TypeName getConstType() { return TypeDecl::TypeName::array; }
	virtual int toRange() { return 1; }

	virtual std::string toString() { return "Object"; }
	virtual std::vector<Node*> getChildren() { return std::vector<Node*>{propList}; }
	virtual TValue run();
};


class MemberPropertyExpression : public Expression {
private:
	Expression* leftExp;
	MemberNameList* rightExpList;
public:
	MemberPropertyExpression() {}
    MemberPropertyExpression(Expression* exp): leftExp(exp), rightExpList(nullptr) {}
    MemberPropertyExpression(Expression* exp, MemberNameList* expList):
	leftExp(exp), rightExpList(expList) {}

	virtual std::string toString() { return "MemberPropertyExpression"; }
	virtual std::vector<Node*> getChildren() {
		if (rightExpList != nullptr) {
			std::vector<Node*> rList = std::vector<Node*>{(Node*)leftExp};
			for (MemberNameList::iterator iter=rightExpList->begin();
				 iter != rightExpList->end(); iter++) {
				rList.push_back((Node*)*iter);
			}
			return rList;
		} else return std::vector<Node*>{leftExp};
	}
	std::pair<Object*, ast::MemberName*>* simplify();
	virtual TValue run();
	virtual void assign(TValue value);
};

class MemberName : public Expression {
private:
	bool isIdentifier;
	Expression* exp;
public:
	MemberName() {}
    MemberName(Expression* exp, bool isIdentifier): exp(exp), isIdentifier(isIdentifier) {}

	virtual std::string toString() { return "MemberName"; }
	virtual std::vector<Node*> getChildren() {
		return std::vector<Node*>{exp};
	}
	virtual TValue run();
};

/*class MemberExpressionList : public StatementList {
private:
public:
	MemberExpressionList() {}
MemberExpressionList(Expression* exp): StatementList(exp) {}
MemberExpressionList(Expression* exp, ExpressionList* expList):
	StatementList(exp, expList) {}

	virtual std::string toString() { return "MemberExpressionList"; }
	virtual std::vector<Node *> getChildren()
	}*/

class Block : public Statement {
	StatementList* stmtList;
public:
    Block() : stmtList(new StatementList) {}
    Block(StatementList* stmtList) : stmtList(stmtList) {}
	virtual std::string toString() { return "block"; }
    virtual std::vector<Node *> getChildren() { return std::vector<Node* >{stmtList}; }
	virtual TValue run();
};

}
#endif
