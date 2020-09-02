#include "GenTAC.h"

class Parser{
    private:
        bool inner_scope;
        unsigned int pos_ptr;
        std::vector<Token*> m_tokens;
        std::stack<Token*> m_stack;
        std::vector<SymbolTable> symbol_table_list;
        GenTAC IR_gen;

        int brace_count;
 
    public:
        Parser(std::vector<Token*> tokens, std::unordered_map<std::string, int> keywords): m_tokens(tokens), pos_ptr(0), inner_scope(false), brace_count(0), IR_gen(&symbol_table_list){start();}
        std::vector<Quad> getIR(){ return IR_gen.getTable(); }
        std::vector<SymbolTable> getSymbolTable(){return symbol_table_list;}

    private:
        void initSymbolTableList();
        void newScope();
        bool ID_isDefined(std::string);
        void STPrint();

        void start();

        void parseFile();
        void parseStatementBlock();
        void parseStatement();

        void parseInferDecl();
        void parseExplicitDecl();

        void parseFnDecl();
        void parseFnBody();
        void parseRet();

        void parseIfStatement();
        void parseForStatement();
        void parseWhileStatement();

        std::vector<Token*> parseExpr(T_Type);

        unsigned int precedence(OperatorDescriptor);

        Token* nextToken();
        Token* peekNextToken();
        Token* peekTwoTokens();
        Token* currentToken();
};