#include "ErrorHandler.h"

class Lexer{

    #define CASE_DIGIT case '0': case '1': case '2': case '3': case '4': case '5': \
                       case '6': case '7': case '8': case '9'

    #define CASE_ID case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':case 'H':case 'I': \
                    case 'J':case 'K':case 'L':case 'M':case 'N':case 'O':case 'P':case 'Q':case 'R': \
                    case 'S':case 'T':case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':case 'a': \
                    case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j': \
                    case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':case 'q':case 'r':case 's': \
                    case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':case '_'

    public:
        Lexer(const std::string&);
        void lex();
        char currentChar();
        char nextChar();
        char peekNextChar();

    private:
        const std::string& data;
        std::vector<Token*> tokens;
        u32 index;
        u32 line;
        u32 col;
        ErrorHandler error;

        Token* number_lit();
        Token* identifier();

        Token* createToken(std::string&, TokenKind, u32);

        void printTokens(bool verbose);

        constexpr static inline bool isDigit(char c) noexcept {
            return c >= 48 && c <= 57;
        }

        constexpr static inline bool isAlpha(char c) noexcept {
            return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95;
        }

};
