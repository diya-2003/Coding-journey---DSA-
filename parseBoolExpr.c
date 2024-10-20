
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 20000

typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;
void init(Stack* s) {
    s->top = -1;
}
void push(Stack* s, char value) {
    if (s->top < MAX_STACK_SIZE - 1)
        s->items[++(s->top)] = value;
}
char pop(Stack* s) {
    if (s->top >= 0) 
        return s->items[(s->top)--];
    return '\0';
}
char peek(Stack* s) {
    if (s->top >= 0)
        return s->items[s->top];
    return '\0';
}
bool parseBoolExpr(char* expression) {
    Stack st;
    init(&st);
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        char currChar = expression[i];
        if (currChar == ',' || currChar == '(')
            continue;
        if (currChar == 't' || currChar == 'f' || currChar == '!' || currChar == '&' || currChar == '|')
            push(&st, currChar);
        else if (currChar == ')')
            bool hasTrue = false, hasFalse = false;
            while (peek(&st) != '!' && peek(&st) != '&' && peek(&st) != '|') {
                char topValue = pop(&st);
                if (topValue == 't')
                    hasTrue = true;
                else if (topValue == 'f')
                    hasFalse = true;
            }
            char op = pop(&st);
            if (op == '!')
                push(&st, hasTrue ? 'f' : 't');  // NOT operation
            else if (op == '&')
                push(&st, hasFalse ? 'f' : 't');  // AND operation
            else if (op == '|')
                push(&st, hasTrue ? 't' : 'f');   // OR operation
        }
    }
    return peek(&st) == 't';
}
int main() {
    char expression1[] = "&(|(f))";
    char expression2[] = "|(f,f,f,t)";
    char expression3[] = "!(&(f,t))";

    printf("%s => %s\n", expression1, parseBoolExpr(expression1) ? "true" : "false");
    printf("%s => %s\n", expression2, parseBoolExpr(expression2) ? "true" : "false");
    printf("%s => %s\n", expression3, parseBoolExpr(expression3) ? "true" : "false");

    return 0;
}
