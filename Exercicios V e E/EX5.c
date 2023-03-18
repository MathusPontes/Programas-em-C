#include <stdio.h>

int main (void){
    float num;
    printf ("Programa divisor por 5\n");
    printf ("Gentileza informe o numero real que deseja dividir: ");
    scanf ("%f", &num);
    printf ("O resultado é: %f", num/5);
    return 0;
}