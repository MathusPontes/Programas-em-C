#include <stdio.h>

int main (void){
    float num; // Declaração de variavel em real ou ponto flutuante
    printf ("Gentileza informe um numero real: ");
    scanf ("%f", &num);
    printf ("O numero informado foi: %f", num); // %f vai mostrar somente em numero real
    return 0;
}