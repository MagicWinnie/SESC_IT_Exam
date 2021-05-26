#include <string.h>
#include "stack.h"

#define N 1000

int compute_RPN(char* input){
    Stack* S = create();
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '+'){
            int buf = pop(S) + pop(S);
            push(S, buf);
        }
        else if(input[i] == '-'){
            int buf = pop(S) - pop(S);
            push(S, buf);
        }
        else if(input[i] == '*'){
            int buf = pop(S) * pop(S);
            push(S, buf);
        }
        else if(input[i] != ' '){
            push(S, input[i] - '0');
        }
    }
    return pop(S);
}

int main(){
    char* input = "1 2 + 4 * 3 +\0";
    printf("%d\n", compute_RPN(input));
}