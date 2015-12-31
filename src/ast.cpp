#include "ast.h"

#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "utils.h"
using namespace std;

void ast::Identifier::run() {
    std::cout << "Creating identifier: " << name << std::endl;
    
}

void ast::IntegerType::run() {
    std::cout << "Creating integer: " << val << std::endl;
}
void ast::RealType::run() {
    std::cout << "Creating real: " << val << std::endl;
}
void ast::CharType::run() {
    std::cout << "Creating char: " << val << std::endl;
}
void ast::BooleanType::run() {
    std::cout << "Creating boolean: " << val << std::endl;
}
void ast::RangeType::run() {
    std::cout << "Creating subscript range from " << this->low << " to " << this->high << std::endl;
}
void ast::BinaryOperator::run() {
//    llvm::Instruction::BinaryOps instr;
//    auto op1_val = op1->CodeGen(context);
//    auto op2_val = op2->CodeGen(context);
//
//    if (op1_val->getType()->isDoubleTy() || op2_val->getType()->isDoubleTy()) {
//        switch (op) {
//        // Arithmetic Operations
//        case OpType::plus:    return llvm::BinaryOperator::Create( llvm::Instruction::FAdd,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::minus:   return llvm::BinaryOperator::Create( llvm::Instruction::FSub,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::mul:     return llvm::BinaryOperator::Create( llvm::Instruction::FMul,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::div:     return llvm::BinaryOperator::Create( llvm::Instruction::SDiv,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::mod:     return llvm::BinaryOperator::Create( llvm::Instruction::SRem,
//                op1_val, op2_val, "", context.currentBlock());    
//        case OpType::bit_and:     return llvm::BinaryOperator::Create( llvm::Instruction::And,
//                op1_val, op2_val, "", context.currentBlock());  
//        case OpType::bit_or:     return llvm::BinaryOperator::Create( llvm::Instruction::Or,
//                op1_val, op2_val, "", context.currentBlock()); 
//        case OpType::bit_xor:     return llvm::BinaryOperator::Create( llvm::Instruction::Xor,
//                op1_val, op2_val, "", context.currentBlock()); 
//        // Logical Operations
//        
//        case OpType::eq:  {auto ret = llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_EQ,
//                op1_val, op2_val, "", context.currentBlock()); 
//                          std::cout << "boolean value is int1 " << ret->getType()->isIntegerTy() << std::endl;
//                          return ret;}
//        case OpType::ne:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_NE,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::lt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLT,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::gt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGT,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::le:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLE,
//                op1_val, op2_val, "", context.currentBlock());
//        case OpType::ge:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGE,
//                op1_val, op2_val, "", context.currentBlock());
//        //case OpType::and: return  llvm::cmp
//        }
//    } else 
//    switch (op) {
//    // Arithmetic Operations
//    case OpType::plus:    return llvm::BinaryOperator::Create( llvm::Instruction::Add,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::minus:   return llvm::BinaryOperator::Create( llvm::Instruction::Sub,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::mul:     return llvm::BinaryOperator::Create( llvm::Instruction::Mul,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::div:     return llvm::BinaryOperator::Create( llvm::Instruction::SDiv,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::mod:     return llvm::BinaryOperator::Create( llvm::Instruction::SRem,
//            op1_val, op2_val, "", context.currentBlock());    
//    case OpType::bit_and:     return llvm::BinaryOperator::Create( llvm::Instruction::And,
//            op1_val, op2_val, "", context.currentBlock());  
//    case OpType::bit_or:     return llvm::BinaryOperator::Create( llvm::Instruction::Or,
//            op1_val, op2_val, "", context.currentBlock()); 
//    case OpType::bit_xor:     return llvm::BinaryOperator::Create( llvm::Instruction::Xor,
//            op1_val, op2_val, "", context.currentBlock()); 
//    // Logical Operations
//    
//    case OpType::eq:  {auto ret = llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_EQ,
//            op1_val, op2_val, "", context.currentBlock()); 
//                      std::cout << "boolean value is int1 " << ret->getType()->isIntegerTy() << std::endl;
//                      return ret;}
//    case OpType::ne:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_NE,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::lt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLT,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::gt:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGT,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::le:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SLE,
//            op1_val, op2_val, "", context.currentBlock());
//    case OpType::ge:  return  llvm::CmpInst::Create( llvm::Instruction::ICmp, llvm::CmpInst::ICMP_SGE,
//            op1_val, op2_val, "", context.currentBlock());
//    //case OpType::and: return  llvm::cmp
//    }
}

void ast::AssignmentStmt::run() {
    
}

void ast::ConstDecl::run() {
    
}


void ast::VarDecl::run() {
    
}

void ast::Program::run() {
    
}

void ast::Routine::run() {
   
}
void ast::FuncCall::run() {
   
}

void ast::ProcCall::run() {
   
}

void ast::SysFuncCall::run() {}



void ast::SysProcCall::run() {
    
}

void ast::TypeDecl::run() {}

void ast::Expression::run() {}

void ast::IfStmt::run() {
    
}
void ast::WhileStmt::run() {
   
}
void ast::RepeatStmt::run() {
    
}
void ast::ForStmt::run() {
    
}
void ast::CaseStmt::run() {
    
}
void ast::SwitchStmt::run() {
   
}
void ast::GotoStmt::run(){
   
}
void ast::LabelStmt::run(){
    
}

void ast::ArrayType::run() {
}

void ast::ArrayRef::run() {
    
}


