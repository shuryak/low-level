#ifndef _LEX_ANALYZER_H_
#define _LEX_ANALYZER_H_

#include <stdlib.h>
#include <string.h>

enum TOKENS { EOI = 0, NUM = 1, PLUS = 2, STAR = 3, LP = 4, RP = 5, UNKNOWN = 6 };

typedef struct token_lexeme {
    enum TOKENS token;
    char lexeme;
} token_lexeme;

void set_input_stream(char *input);
token_lexeme get_next_token(void);
void set_token_index(uint index);
uint get_token_index(void);

#endif
