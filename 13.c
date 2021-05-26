#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 1000

bool is_balanced_brackets(char* input){
    int br[3] = {0, 0, 0};
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '(') br[0]++;
        else if (input[i] == ')') br[0]--;
        else if (input[i] == '[') br[1]++;
        else if (input[i] == ']') br[1]--;
        else if (input[i] == '{') br[2]++;
        else if (input[i] == '}') br[2]--;
        if(br[0] < 0 || br[1] < 0 || br[2] < 0)
            return false;
    }
    if(br[0] == 0 && br[1] == 0 && br[2] == 0)
        return true;
    return false;
}

int main(){
    char* input = "((({(([){)]}})\0";
    printf("%d", is_balanced_brackets(input));
    return 0;
}