#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isValidIfStatement(const char *line)
{
    int length = strlen(line);
    bool foundIfKeyword = false;
    bool foundOpeningBrace = false;
    bool foundClosingBrace = false;
    for (int i = 0; i < length; i++)
    {
        char c = line[i];
        if (c == ' ' || c == '\t')
        {
            continue;
        }
        if (!foundIfKeyword)
        {
            if (c == 'i' && line[i + 1] == 'f' && (line[i + 2] == ' ' || line[i + 2] == '('))
            {
                foundIfKeyword = true;
                i += 1;
                continue;
            }
            else
            {
                return false;
            }
        }
        if (foundIfKeyword && !foundOpeningBrace)
        {
            if (c == '(')
            {
                foundOpeningBrace = true;
                continue;
            }
            else
            {
                return false;
            }
        }
        if (foundIfKeyword && foundOpeningBrace && !foundClosingBrace)
        {
            if (c == ')')
            {
                foundClosingBrace = true;
                continue;
            }
        }
    }
    return foundIfKeyword && foundOpeningBrace && foundClosingBrace;
}
int main()
{
    char line[100];
    printf("Enter a line of C code: ");
    fgets(line, sizeof(line), stdin);
    if (isValidIfStatement(line))
    {
        printf("Valid if statement.\n");
    }
    else
    {
        printf("Invalid if statement.\n");
    }
    return 0;
}