#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largura, altura;
    int i, j;
    char formato[4];
    char aux[100];
    int valor_maximo;

    FILE *arq1;
    arq1 = fopen("C:/Exercicio2-PDI/lena256.pgm", "r");
    if (arq1 == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    
    fscanf(arq1, "%[^\n]\n", formato);
    printf("%s\n",formato);
    fscanf(arq1, "%[^\n]\n", aux );
    fscanf(arq1, "%d %d\n", &largura, &altura);
    printf("%d %d\n",largura, altura);
    fscanf(arq1, "%d\n", &valor_maximo);
    printf("Lido");

    // Alocar memória para a imagem
    int **imagem = malloc(largura * sizeof(int *));
    for (i = 0; i < largura; i++)
    {
        imagem[i] = malloc(altura * sizeof(int));
    }

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            int pixel_valor;
            fscanf(arq1, "%d\n", &pixel_valor);
            imagem[j][i] = pixel_valor; // alterando a ordem de leitura dos pixels
        }
    }

    // Salvar a imagem resultante em um novo arquivo
    FILE *arq2;
    arq2 = fopen("C:/Exercicio2-PDI/lena256Girar90.pgm", "w");
    fprintf(arq2, "%s\n", formato);
    fprintf(arq2, "%d %d\n", altura, largura); // trocando a ordem da altura e largura
    fprintf(arq2, "%d\n", valor_maximo);
    for (i = 0; i < largura; i++) // invertendo a ordem da leitura dos pixels na escrita
    {
        for (j = altura-1; j >= 0; j--)
        {
            fprintf(arq2, "%d\n", imagem[i][j]);
        }
    }
    fclose(arq2);

    // Liberar a memória alocada
    for (i = 0; i < largura; i++)
    {
        free(imagem[i]);
    }
    free(imagem);

    fclose(arq1);
    return 0;
}
