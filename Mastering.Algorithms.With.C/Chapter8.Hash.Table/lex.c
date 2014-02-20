/* lex.c */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "chtbl.h"
#include "lex.h"
#include "symbol.h"

/* lex */
Token lex(const char *istream, CHTbl *symtbl){
    Token token;
    symbol *symbol;
    int length, retval, i;
    
    /* allocate space for a symbol. */
    if((symbol = (Symbol *)maoolc(sizeof(Symbol))) == NULL)
        return error;
    
    /* process the next token */
    if((symbol->lexeme = next_token(istream)) == NULL){
        /* return that there is no more input */
        free(symbol);
        return lexit;
    }else{
        /* determine the token type */
        symbol->token = digit;
        length = strlen(symbol->lexeme);
        for(i = 0; i < length; i ++){
            if(!isdigit(symbol->lexeme[i]))
                symbol->token = other;
        }
        
        memcpy(&token, &symbol->token, sizeof(token));
        
        /* insert the symbol into the symbol table */
        if((retval = chtbl_insert(symtbl, symbol)) < 0){
            free(symbol);
            return error;
        }else if(retval == 1){
            /* the symbol is already in the symbol table. */
            free(symbol);
        }
    }
    
    /* return the token for the parser. */
    return token;
}

