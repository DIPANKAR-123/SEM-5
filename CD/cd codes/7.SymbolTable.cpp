#include <stdio.h>
#include <string.h>
#define MAX_SYMBOLS 100
typedef struct
{
    char name[20];
    int value;
} Symbol;
Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;
void addSymbol(const char *name, int value)
{
    if (symbolCount < MAX_SYMBOLS)
    {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].value = value;
        symbolCount++;
    }
    else
        printf("Error: Symbol table is full.\n");
}
void displaySymbolTable()
{
    printf("Symbol Table:\n");
    printf("%-10s%-10s\n", "Name", "Value");
    for (int i = 0; i < symbolCount; i++)
        
                 printf("%-10s%-10d\n", symbolTable[i].name,
                        symbolTable[i].value);
}
int main()
{
    addSymbol("x", 42);
    addSymbol("y", 100);
    addSymbol("z", 75);
    displaySymbolTable();
    return 0;
}