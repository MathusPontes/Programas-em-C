#include <stdio.h>

int main (void){
    float num;
    printf ("Programa quadrado de um numero\n");
    printf ("Gentileza informe o numero real que gostaria de saber o resultado: ");
    scanf ("%f", &num);
    printf ("O resultado é: %f", num*num);
    return 0;
}