#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // American Express; 34 ou 37; 15 digitos

    // Visa; 4; 13 digitos e 16 digitos

    // MasterCard; 51,52,53,54,55; 16 digitos

    long long int numero_do_cartao;
    int contador = 0;
    int soma = 0;

    do
    {
        numero_do_cartao = get_long_long("Numero do cartao: ");
    } 
    
    while (numero_do_cartao < 0);

    int american_express = numero_do_cartao / pow(10, 13);
    int mastercard = numero_do_cartao / pow(10, 14);
    int visa[2];
    visa[0] = numero_do_cartao / pow(10, 12);
    visa[1] = numero_do_cartao / pow(10, 15);
    int elo = numero_do_cartao / pow(10, 15);

    while (numero_do_cartao > 0)
    {
        int r = numero_do_cartao % 10;
        numero_do_cartao /= 10;
        contador++;

        if (contador % 2 == 0)
        {
            r *= 2;
            if (r > 9)
            {
                r -= 9;
            }
        }

        soma += r;
    }

    if (soma % 10 == 0)
    {
        if (american_express == 34 || american_express == 37)
        {
            printf("American Express\n");
        }

        else if (visa[0] == 4 || visa[1] == 4)
        {
            printf("Visa\n");
        }

        else if (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55)
        {
            printf("MasterCard\n");
        }

        else if (elo == 5 || elo == 6)
        {
            printf("Elo\n");
        }
        
        else
        {
            printf("Invalido\n");
        }
    }

    else
    {
        printf("Invalido\n");
    }

    return 0;
}