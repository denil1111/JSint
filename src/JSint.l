%option noyywrap yylineno
%{
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ast.h"
#include "utils.h"

#include "parser.hpp"
#include "ccalc.h"

#define YY_INPUT(buf,result,max_size)  {\
    result = GetNextChar(buf, max_size); \
    if (  result <= 0  ) \
      result = YY_NULL; \
    }
#define YYLVAL_DEBUG yylval.debug = strdup(yytext);
extern YYLTYPE yylloc;
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;\
	yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
%}
DecimalDigit [0-9]
DecimalDigits [0-9]+
NonZeroDigit [1-9]
DecimalIntegerLiteral [0]|({NonZeroDigit}{DecimalDigits}*)
ExponentIndicator [eE]
SignedInteger [+-]?[0-9]+
ExponentPart {ExponentIndicator}{SignedInteger}
HexDigit [0-9a-fA-F]
SingleEscapeCharacter [\'\"\\bfnrtv]
NonEscapeCharacter [^\'\"\\bfnrtv0-9xu]
CharacterEscapeSequence {SingleEscapeCharacter}|{NonEscapeCharacter}
EscapeSequence {CharacterEscapeSequence}
DoubleStringCharacter ([^\"\\\n\r]+)|(\\{EscapeSequence})
SingleStringCharacter ([^\'\\\n\r]+)|(\\{EscapeSequence})
IdentifierStart [$_a-zA-Z]
IdentifierPart {IdentifierStart}|[0-9]

%%
({DecimalIntegerLiteral}\.{DecimalDigits}*{ExponentPart}?)|(\.{DecimalDigits}{ExponentPart}?)|({DecimalIntegerLiteral}{ExponentPart}?) { BeginToken(yytext);YYLVAL_DEBUG return DECIMAL_LITERAL; }
[0][xX]{HexDigit}+ { BeginToken(yytext);YYLVAL_DEBUG return HEX_INTEGER_LITERAL; }
(\"{DoubleStringCharacter}*\")|(\'{SingleStringCharacter}*\') { BeginToken(yytext);YYLVAL_DEBUG return STRING_LITERAL; }
"true"|"false" { BeginToken(yytext);YYLVAL_DEBUG return BOOLEAN_LITERAL; }
"null" { BeginToken(yytext);YYLVAL_DEBUG return NULL_LITERAL; }
"this" { BeginToken(yytext);YYLVAL_DEBUG return THIS; }
"new" { BeginToken(yytext);YYLVAL_DEBUG return NEW; }
"delete" { BeginToken(yytext);YYLVAL_DEBUG return DELETE; }
"void" { BeginToken(yytext);YYLVAL_DEBUG return VOID; }
"typeof" { BeginToken(yytext);YYLVAL_DEBUG return TYPEOF; }
"instanceof" { BeginToken(yytext);YYLVAL_DEBUG return INSTANCEOF; }
"in" { BeginToken(yytext);YYLVAL_DEBUG return IN; }
"var" { BeginToken(yytext);YYLVAL_DEBUG return VAR; }
"if" { BeginToken(yytext);YYLVAL_DEBUG return IF; }
"else" { BeginToken(yytext);YYLVAL_DEBUG return ELSE; }
"do" { BeginToken(yytext);YYLVAL_DEBUG return DO; }
"while" { BeginToken(yytext);YYLVAL_DEBUG return WHILE; }
"for" { BeginToken(yytext);YYLVAL_DEBUG return FOR; }
"continue" { BeginToken(yytext);YYLVAL_DEBUG return CONTINUE; }
"break" { BeginToken(yytext);YYLVAL_DEBUG return BREAK; }
"return" { BeginToken(yytext);YYLVAL_DEBUG return RETURN; }
"with" { BeginToken(yytext);YYLVAL_DEBUG return WITH; }
"switch" { BeginToken(yytext);YYLVAL_DEBUG return SWITCH; }
"case" { BeginToken(yytext);YYLVAL_DEBUG return CASE; }
"default" { BeginToken(yytext);YYLVAL_DEBUG return DEFAULT; }
"throw" { BeginToken(yytext);YYLVAL_DEBUG return THROW; }
"try" { BeginToken(yytext);YYLVAL_DEBUG return TRY; }
"catch" { BeginToken(yytext);YYLVAL_DEBUG return CATCH; }
"finally" { BeginToken(yytext);YYLVAL_DEBUG return FINALLY; }
"function" { BeginToken(yytext);YYLVAL_DEBUG return FUNCTION; }
"import" { BeginToken(yytext);YYLVAL_DEBUG return IMPORT; }
"[" { BeginToken(yytext);YYLVAL_DEBUG return LEFT_BRACKET; }
"]" { BeginToken(yytext);YYLVAL_DEBUG return RIGHT_BRACKET; }
"(" { BeginToken(yytext);YYLVAL_DEBUG return LEFT_PARE; }
")" { BeginToken(yytext);YYLVAL_DEBUG return RIGHT_PARE; }
"{" { BeginToken(yytext);YYLVAL_DEBUG return LEFT_BRACE; }
"}" { BeginToken(yytext);YYLVAL_DEBUG return RIGHT_BRACE; }
"," { BeginToken(yytext);YYLVAL_DEBUG return COMMA; }
"." { BeginToken(yytext);YYLVAL_DEBUG return DOT; }
":" { BeginToken(yytext);YYLVAL_DEBUG return COLON; }
";" { BeginToken(yytext);YYLVAL_DEBUG return SEMICOLON; }
"*=" { BeginToken(yytext);YYLVAL_DEBUG return MULTI_ASG; }
"%=" { BeginToken(yytext);YYLVAL_DEBUG return MOD_ASG; }
"+=" { BeginToken(yytext);YYLVAL_DEBUG return PLUS_ASG; }
"-=" { BeginToken(yytext);YYLVAL_DEBUG return MINUS_ASG; }
"<<=" { BeginToken(yytext);YYLVAL_DEBUG return LSHIFT_ASG; }
">>=" { BeginToken(yytext);YYLVAL_DEBUG return RSHIFT_ASG; }
">>>=" { BeginToken(yytext);YYLVAL_DEBUG return LLSHIFT_ASG; }
"&=" { BeginToken(yytext);YYLVAL_DEBUG return BIT_AND_ASG; }
"^=" { BeginToken(yytext);YYLVAL_DEBUG return BIT_NOT_ASG; }
"|=" { BeginToken(yytext);YYLVAL_DEBUG return BIT_OR_ASG; }
"/=" { BeginToken(yytext);YYLVAL_DEBUG return SLASHASSIGN; }
"+" { BeginToken(yytext);YYLVAL_DEBUG return PLUS; }
"-" { BeginToken(yytext);YYLVAL_DEBUG return MINUS; }
"*" { BeginToken(yytext);YYLVAL_DEBUG return MULTI; }
"/" { BeginToken(yytext);YYLVAL_DEBUG return SLASH; }
"=" { BeginToken(yytext);YYLVAL_DEBUG return ASSIGN; }
"++" { BeginToken(yytext);YYLVAL_DEBUG return PLUS_PLUS; }
"--" { BeginToken(yytext);YYLVAL_DEBUG return MINUS_MINUS; }
"~" { BeginToken(yytext);YYLVAL_DEBUG return TILDE; }
"?" { BeginToken(yytext);YYLVAL_DEBUG return QUES; }
"!" { BeginToken(yytext);YYLVAL_DEBUG return EXCLAM; }
"%" { BeginToken(yytext);YYLVAL_DEBUG return PERCENT; }
"<" { BeginToken(yytext);YYLVAL_DEBUG return LESS; }
">" { BeginToken(yytext);YYLVAL_DEBUG return GREATER; }
"==" { BeginToken(yytext);YYLVAL_DEBUG return EQUAL; }
"<<" { BeginToken(yytext);YYLVAL_DEBUG return LSHIFT; }
">>" { BeginToken(yytext);YYLVAL_DEBUG return RSHIFT; }
">>>" { BeginToken(yytext);YYLVAL_DEBUG return RRSHIFT; }
"<=" { BeginToken(yytext);YYLVAL_DEBUG return LESS_EQ; }
">=" { BeginToken(yytext);YYLVAL_DEBUG return GREATER_EQ; }
"!=" { BeginToken(yytext);YYLVAL_DEBUG return NOT_EQUAL; }
"===" { BeginToken(yytext);YYLVAL_DEBUG return ALWAYS_EQ; }
"!==" { BeginToken(yytext);YYLVAL_DEBUG return ALWAYS_NEQ; }
"&" { BeginToken(yytext);YYLVAL_DEBUG return BIT_AND; }
"|" { BeginToken(yytext);YYLVAL_DEBUG return BIT_OR; }
"^" { BeginToken(yytext);YYLVAL_DEBUG return BIT_NOT; }
"&&" { BeginToken(yytext);YYLVAL_DEBUG return AND; }
"||" { BeginToken(yytext);YYLVAL_DEBUG return OR; }
<<EOF>> { BeginToken(yytext);YYLVAL_DEBUG return JEOF; }
{IdentifierStart}{IdentifierPart}*  { BeginToken(yytext);YYLVAL_DEBUG return IDENTIFIER_NAME; }

[ \n\t]+ { BeginToken(yytext); }
.		{ printf("Invalid character\n"); }
%%
