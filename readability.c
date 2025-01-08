#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

float letras(string texto);

int palavras(string texto);

float frases(string texto);

int main()
{
    string texto = get_string("Texto: ");

    float nota = 0.0588 * (letras(texto) / palavras(texto) * 100) - 0.296 * (frases(texto) / palavras(texto) * 100) - 15.8;

    if (nota >= 16)
    {
        printf("\nNivel: 16+");
    }

    else if (nota < 1)
    {
        printf("\nAbaixo do Nivel: 1");
    }

    else
    {
        printf("\nNivel: %.f", nota);
    }
    
    return 0;
}

float letras(string texto)
{
    float total = 0;
    int numero;

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        char c = texto[i];

        if (tolower(c) >= 'a' && tolower(c) <= 'z')
        {
            numero = 1;
        }

        else
        {
            numero = 0;
        }
        
        total += numero;
    }
  return total;  
}

int palavras(string texto)
{
    int total = 1;
    int numero;

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        char c = texto[i];

        if (c == ' ')
        {
            numero = 1;
        }

        else
        {
            numero = 0;
        }

        total += numero;
    }
    return total;
}

float frases(string texto)
{
    float total = 0;
    int numero;

    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        char c = texto[i];

        if (c == '.')
        {
            numero = 1;
        }

        else if (c == '?')
        {
            numero = 1;
        }

        else if (c == '!')
        {
            numero = 1;
        }

        else
        {
            numero = 0;
        }

        total += numero;
    }
    return total;
}