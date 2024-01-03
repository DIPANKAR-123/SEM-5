#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool hasUnterminatedComment(const char *code)
{
    bool inComment = false;
    int length = strlen(code);
    for (int i = 0; i < length - 1; i++)
    {
        if (code[i] == '/' && code[i + 1] == '*')
        {
            /* /* */
            inComment = true;
            i++;
        }
        else if (code[i] == '*' && code[i + 1] == '/')
        {
            inComment = false;
            i++;
        }
    }
    return inComment;
}
int main()
{
    char code[1000];
printf("Enter your C code (terminate input with a period '.' on a line by itself):\n ");
while(1) {
        char line[100];
        fgets(line, sizeof(line), stdin);
        if (line[0] == '.' && line[1] == '\n')
        {
            break;
        }
        strcat(code, line);
}
if(hasUnterminatedComment(code)) {
        printf("Error: Unterminated multi-line comment found.\n");
}
else {
        printf("No unterminated multi-line comments found.\n");
}
return 0;
}