#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>

#define CASE_VALID_NAME_CHARACTERS case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':case 'H':case 'I': \
                                   case 'J':case 'K':case 'L':case 'M':case 'N':case 'O':case 'P':case 'Q':case 'R': \
                                   case 'S':case 'T':case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':case 'a': \
                                   case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j': \
                                   case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':case 'q':case 'r':case 's': \
                                   case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':case '_':
#define CASE_DIGITS case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':

#ifdef DEBUG_BUILD
    #define DEBUG_PRINT_TOKENS std::cout << "\n"; printTokens()
#else
    #define DEBUG_PRINT_TOKENS
#endif

enum ExprType{E_UNARY, E_BINARY, E_TERNARY, E_INTEGER, E_FLOAT, E_STRING, E_INDEX, E_FIELD};
enum Type{T_INT, T_FLOAT, T_STR, T_ARR};


enum TokenType{OPERATOR, NUMBER, FLOAT, STRING, PAREN, COMMA, NAME, COMPARISON, NOT, OP_EQUAL, DOT};
    
struct Token{
    TokenType type;
    std::string data;
};

struct Decl{
    Type type;
    std::string name;
    struct {

    } d_int;
    struct {

    } d_float;
    struct {

    } d_string;
    struct {

    } d_array;
};

struct Expr {
    ExprType type;
    union{
        struct {
            unsigned long long int val;
        } e_integer;
        struct {
            double val;
        } e_float;
        struct {
            std::string val;
        } e_string;
        struct {
            Type type;
            Expr* index;
        } e_index;
        struct {
            Expr* expr;
            char op;
        } e_unary;
        struct {
            Expr* left;
            Expr* right;
            char op;
        } e_binary;
        struct {
            Expr* eval;
            Expr* left;
            Expr* right;
        } e_ternary;
    };
};

typedef uint_fast64_t uint;