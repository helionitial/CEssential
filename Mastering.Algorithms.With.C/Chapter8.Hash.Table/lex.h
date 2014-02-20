/* lex.h 
 * sample use
 */

#ifndef LEX_H
#define LEX_H

#include "chtbl.h"

/* define the token types recognized by the lexical analyzer */
typedef enum Token_{lexit, error, digit, other}Token;

/* public interface */
Token lex(const char *istream, CHTbl *symtbl);

#endif

