#ifndef __UTILS_H__
#define __UTILS_H__

typedef struct YYLTYPE {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
    char *filename;
} YYLTYPE;

#define YYLTYPE_is_declared

extern int yylex();
// extern int yyparse();
extern int yylineno;
extern char *yytext;

void yyerror(char *s, ...);

typedef struct ast_struct ast_tree;
typedef ast_tree ast_node;

struct ast_struct {
	ast_node** ch;		// children
	char* debug;		// debug info
	int val;
};

#define NDEBUG

#ifdef NDEBUG
#define DEBUG_TEST_COND 0
#else
#define DEBUG_TEST_COND 1
#endif

/* get only filename */
#include <cstring>
#define __FILENAME__ \
    (std::strrchr(__FILE__, '/') ? std::strrchr(__FILE__, '/') + 1 : __FILE__)

/* show more precise infomartion */
#ifdef DBINFO_POS
#define __DB_POS__ \
    "[" << __FILENAME__ << ":" << __LINE__ << "] " <<
#else
#define __DB_POS__ "" <<
#endif

/* define print macros */
#include <iostream>
#define DBVAR(var) \
    do { \
        if (DEBUG_TEST_COND) \
        std::cout << "[DEBUG] " << __DB_POS__ \
        #var << "\t"  << (var) << \
        std::endl; \
    } while (0)

#define DBMSG(msg) \
    do { \
        if (DEBUG_TEST_COND) \
        std::cout << "[DEBUG] " << __DB_POS__ \
        msg << \
        std::endl;\
    } while (0)

#define LOG(msg) \
    do { \
        if (DEBUG_TEST_COND) \
        std::cout << "[LOG] " << __DB_POS__ \
        msg << \
        std::endl; \
    } while (0)

#include <iostream>

void ast_travel(ast_node* node);
ast_node* ast_dbg(char* debug);
ast_node* ast_newNode1(ast_node* c1);
ast_node* ast_newNode2(ast_node* c1, ast_node* c2);
ast_node* ast_newNode3(ast_node* c1, ast_node* c2, ast_node* c3);
ast_node* ast_newNode4(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4);
ast_node* ast_newNode5(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5);
ast_node* ast_newNode6(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6);
ast_node* ast_newNode7(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7);
ast_node* ast_newNode8(ast_node* c1, ast_node* c2, ast_node* c3, ast_node* c4, ast_node* c5, ast_node* c6, ast_node* c7, ast_node* c8);

extern int debugFlag;
struct MyStream
{
    template <typename T>
    MyStream& operator<<(const T& x)
    {
        
        if (debugFlag)
            std::cout << x;

        return *this;
    }


    // function that takes a custom stream, and returns it
    typedef MyStream& (*MyStreamManipulator)(MyStream&);

    // take in a function with the custom signature
    MyStream& operator<<(MyStreamManipulator manip)
    {
        // call the function, and return it's value
        return manip(*this);
    }

    // define the custom endl for this stream.
    // note how it matches the `MyStreamManipulator`
    // function signature
    static MyStream& endl(MyStream& stream)
    {
        // print a new line
        if (debugFlag)
        {
            std::cout << std::endl;

            // do other stuff with the stream
            // std::cout, for example, will flush the stream
            stream << "Called MyStream::endl!" << std::endl;
        }
        return stream;
    }

    // this is the type of std::cout
    typedef std::basic_ostream<char, std::char_traits<char> > CoutType;

    // this is the function signature of std::endl
    typedef CoutType& (*StandardEndLine)(CoutType&);

    // define an operator<< to take in std::endl
    MyStream& operator<<(StandardEndLine manip)
    {
        // call the function, but we cannot return it's value
        if (debugFlag)
            manip(std::cout);

        return *this;
    }
};
extern MyStream debugOut;

// DebugOut wrap(std::ostream& os)
// {
//   return DebugOut(os);
// }

#endif
