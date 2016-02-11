# Makefile

FILES	= lexer.c parser.c ast.c
CC	= g++
CFLAGS	= -g -ansi

#test:		$(FILES)
#                $(CC) $(CFLAGS) $(FILES) -o test

lexer.c:	lexicaltokens.l
                flex lexicaltokens.l

parser.c:	grammar.y lexer.c
                bison grammar.y

clean:
                rm -f *.o *~ lexer.c lexer.h parser.c parser.h
