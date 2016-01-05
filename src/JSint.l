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
"/=" { BeginToken(yytext);YYLVAL_DEBUG return SLASHASSIGN; }
"/" { BeginToken(yytext);YYLVAL_DEBUG return SLASH; }
<<EOF>> { BeginToken(yytext);YYLVAL_DEBUG return JEOF; }
{IdentifierStart}{IdentifierPart}  { BeginToken(yytext);printf("haha\n");YYLVAL_DEBUG return IDENTIFIER_NAME; }



[ \n\t]+ { BeginToken(yytext); }
.		{ printf("Invalid character\n"); }
%%
