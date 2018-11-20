#include "StackStr.h"
#include <math.h>
#include <stdio.h>

int main(){
    /*****KAMUS*****/
    char Input[MAX_STRLEN];
    boolean IsValid;


    /*****ALGORITMA*****/
    /*BACA STRING INPUT*/
    scanf("%s", Input);

    /*Tes Kevalidan Input, apakah ekspresi matematiknya benar*/
    Verifikasi(Input, &IsValid);

    /*Jika valid, hitung hasil eskpresi matematiknya*/
    if (IsValid){
        printf("\nValid");
    }else{
        printf("\nSYNTAX ERROR");
    }







    /*
    STACK S;
    infotype X;
    infotype Y="12345";

    CreateEmpty(&S);
    Push(&S, "12");
    Push(&S, "-132");
    Push(&S, "162.087632120");
    Push(&S, Y);
    Pop(&S, X);
    printf("%4.8f\n", strtod(X, NULL)+0.812);
    PrintStack(S);
    */

    return 0;
}