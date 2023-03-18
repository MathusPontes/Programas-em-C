#include <stdio.h>

int main (void){
    int num1, num2, num3;
    printf ("Programa somador de numeros\n");
    printf ("Informe o primeiro numero: ");
    scanf ("%d", &num1);
    printf ("Informe o segundo numero: ");
    scanf ("%d", &num2);
    printf ("Informe o terceiro e ultimo numero: ");
    scanf ("%d", &num3);
    printf ("A soma dos numeros e: %d", num1+num2+num3);
    return 0;
}