%{
    //#include "ast.h"
    #include "parser.h"
    #include "lexer.h"

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %sn", s); }
%}

%union {

}

%output  "parser.cpp"
%defines "parser.h"

/* Define terminal symbols.
 */
%token <string> TIDENTIFIER TINTEGER TDOUBLE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token <token> TPLUS TMINUS TMUL TDIV

/* Define the type of node nonterminal symbols represent
 */
//%type <ident> ident

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

// Inicial state
%start program

%%

program : stmts { }
        ;

stmts : stmt { }
      | stmts stmt { }
      ;

stmt : var_decl | func_decl
     | expr { }
     ;

block : TLBRACE stmts TRBRACE { }
      | TLBRACE TRBRACE { }
      ;

var_decl : ident ident { }
         | ident ident TEQUAL expr { }
         ;

func_decl : ident ident TLPAREN func_decl_args TRPAREN block
            { }
          ;

func_decl_args : /*blank*/  { }
          | var_decl { }
          | func_decl_args TCOMMA var_decl { }
          ;

ident : TIDENTIFIER { }
      ;

numeric : TINTEGER { }
        | TDOUBLE { }
        ;

expr : ident TEQUAL expr { }
     | ident TLPAREN call_args TRPAREN { }
     | ident { }
     | numeric
     | expr comparison expr { }
     | TLPAREN expr TRPAREN { }
     ;

call_args : /*blank*/  { }
          | expr { }
          | call_args TCOMMA expr  { }
          ;

comparison : TCEQ | TCNE | TCLT | TCLE | TCGT | TCGE
           | TPLUS | TMINUS | TMUL | TDIV
           ;

%%
