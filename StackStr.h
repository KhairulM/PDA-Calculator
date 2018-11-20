#include "boolean.h"

#define MAX_STRLEN 256
#define MAX_STACK 100
#define Nil 0
#define Base 'Z'
#define NDef 'Q'



typedef char infotype;
typedef struct{
    infotype Mem[MAX_STACK+1];              
    int TOP;
}STACK;

#define Top(S) (S).TOP
#define InfoTop(S) (S).Mem[Top(S)]




void CreateEmpty(STACK *S);

boolean IsEmpty(STACK S);

boolean IsFull(STACK S);

void Pop(STACK *S, infotype *X);

void Push(STACK *S, infotype X);

void PrintStack(STACK S);

boolean IsOperator(infotype X);
 
boolean IsKoma(infotype X);

boolean IsParanthesis(infotype X);

boolean IsNumber(infotype X);
   
boolean IsBase(infotype X);

void Verifikasi(char Input[MAX_STRLEN], boolean *IsValid);