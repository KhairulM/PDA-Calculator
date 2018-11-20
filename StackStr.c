#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackStr.h"
   

void CreateEmpty(STACK *S){
    Top(*S)=Nil;
}

boolean IsEmpty(STACK S){
    return (Top(S)==Nil);
}

boolean IsFull(STACK S){
    return (Top(S)==MAX_STACK);
}

void Pop(STACK *S, infotype *X){
    if (!IsEmpty(*S)){
        *X=InfoTop(*S);
        if (Top(*S)==1){
            Top(*S)=Nil;
        }else{
            Top(*S)--;
        } 
    }
    else{
        *X=NDef;
    }    
}

void Push(STACK *S, infotype X){
    if (!IsFull(*S)){
        Top(*S)++;
        InfoTop(*S)=X;
    }
}

void PrintStack(STACK S){
    int Top=Top(S);

    printf("\n[");
    while (Top!=Nil){
        if (Top==Top(S)){
            printf("%c", S.Mem[Top]);
        }
        else{
            printf(", %c", S.Mem[Top]);
        }
        Top--;
    }
    printf("]");
}

boolean IsOperator(infotype X){
    return (X=='+' || X=='-' || X=='*' || X=='/' || X=='^');
}

boolean IsKoma(infotype X){
    return (X=='.');
}

boolean IsParanthesis(infotype X){
    return (X=='(' || X==')');
}

boolean IsNumber(infotype X){
    return (X>='0' && X<='9');
}

boolean IsBase(infotype X){
    return (X==Base);
}

void Verifikasi(char Input[MAX_STRLEN], boolean *IsValid){
    STACK Verif;
    infotype X, Y;


    CreateEmpty(&Verif);
    Push(&Verif, Base);
    *IsValid=true;

    PrintStack(Verif);


    if (strlen(Input)!=0){
        for (int i=0;Input[i]!='\0' && *IsValid;i++){
            if (IsOperator(Input[i])){
                if (IsOperator(InfoTop(Verif))){
                    *IsValid=false;
                }else if (IsNumber(InfoTop(Verif))){
                    Pop(&Verif, &X);
                    Push(&Verif, Input[i]);
                }else if (IsBase(InfoTop(Verif))){
                    if (Input[i]=='-'){
                        Push(&Verif, Input[i]);
                    }else{
                        *IsValid=false;
                    }
                }else if (IsParanthesis(InfoTop(Verif))){
                    if (Input[i]=='-'){
                        Push(&Verif, Input[i]);
                    }else{
                        *IsValid=false;
                    }
                }

            }else if(IsNumber(Input[i])){
                if (IsOperator(InfoTop(Verif))){
                    Pop(&Verif, &X);
                    Push(&Verif, Input[i]);
                }else if (IsBase(InfoTop(Verif))){
                    Push(&Verif, Input[i]);
                }else if (IsParanthesis(InfoTop(Verif))){
                    if (InfoTop(Verif)=='('){
                       Push(&Verif, Input[i]); 
                    }
                }

            }else if(IsParanthesis(Input[i])){
                if (Input[i]=='('){
                    if (IsOperator(InfoTop(Verif))){
                        Pop(&Verif, &X);
                        Push(&Verif, Input[i]);
                    }else if (IsNumber(InfoTop(Verif))){
                        *IsValid=false;
                    }else if (IsBase(InfoTop(Verif))){
                        Push(&Verif, Input[i]);
                    }else if (InfoTop(Verif)=='('){
                        Push(&Verif, Input[i]);
                    }
                }else{
                    if (IsOperator(InfoTop(Verif))){
                        *IsValid=false;
                    }else if (IsNumber(InfoTop(Verif))){
                        while (!(InfoTop(Verif)=='(') && !(IsBase(InfoTop(Verif)))){
                            Pop(&Verif, &X);
                        }
                        if (IsBase(InfoTop(Verif))){
                            *IsValid=false;
                        }else{
                            Pop(&Verif, &Y);
                            Push(&Verif, X);
                        }
                    }else if (IsBase(InfoTop(Verif))){
                        *IsValid=false;
                    }else if (InfoTop(Verif)=='('){
                        *IsValid=false;
                    }
                }
            }else if(IsKoma(Input[i])){
                if (IsOperator(InfoTop(Verif))){
                    *IsValid=false;
                }else if (IsBase(InfoTop(Verif))){
                    *IsValid=false;
                }else if (InfoTop(Verif)=='('){
                    *IsValid=false;
                }
            }
            PrintStack(Verif);
        }
        if (*IsValid){
            while (InfoTop(Verif)!=Base){
                Pop(&Verif, &X);
            }
            if (!IsNumber(X)){
                *IsValid=false;
            }
            
        }
        PrintStack(Verif);
    }else{
        *IsValid=false;
    }
    
}