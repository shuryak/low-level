#include "parser.h"

void parse_input(char* input_str) {
    token_lexeme token;
    int result = 0;

    set_input_stream(input_str);

    token = get_next_token();
    result = stmt(token);

    // No error handler
    printf("Result: %d\n", result);

    return;
}

static int stmt(token_lexeme token) {
    int result = 0;

    switch (token.token) {
        case LP:
        case NUM:
            result = expr(token);
            break;

        default:
            break;
    }

    return result;
}

static int expr(token_lexeme token) {
    token_lexeme tmp_token = token;
    int result = 0;

    switch (tmp_token.token) {
        case LP:
        case NUM:
            result = term(tmp_token);

            tmp_token = get_next_token();

            switch (tmp_token.token) {
                case PLUS:
                    tmp_token = get_next_token();
                    result += expr(tmp_token);
                    break;
                case RP:
                    set_token_index(get_token_index() - 1);
                    break;
                
                default:
                    break;
            }

            break;

        default:
            break;
    }

    return result;
}

static int term(token_lexeme token) {
    token_lexeme tmp_token = token;
    int result = 0;

    switch (tmp_token.token) {
        case LP:
        case NUM:
            result = fact(tmp_token);

            tmp_token = get_next_token();

            switch (tmp_token.token) {
                case STAR:
                    tmp_token = get_next_token();
                    result *= term(tmp_token);
                    break;
                case PLUS:
                case RP:
                    set_token_index(get_token_index() - 1);
                    break;

                default:
                    break;
            }
        
        default:
            break;
    }

    return result;
}

static int fact(token_lexeme token) {
    token_lexeme tmp_token = token;
    int result = 0;

    switch (tmp_token.token) {
        case LP:
            tmp_token = get_next_token();
            result = expr(tmp_token);
            tmp_token = get_next_token();
            break;
        case NUM:
            result = atoi(&tmp_token.lexeme);
            break;

        default:
            break;
    }

    return result;
}
