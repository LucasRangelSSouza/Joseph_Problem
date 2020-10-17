/*
 * C Program to Solve Josephus Problem using Linked List 
 */
#include <stdio.h>
#include <stdlib.h>
 
struct no
{
    int num;
    struct no *proximo;
};
 
void criar(struct no **);
void imprimir(struct no *);
int sobrevivente(struct no **, int);
 
int main()
{
    struct no *chave = NULL;
    int vencedor, proximo;
 
    criar(&chave);
    printf("The persons in circular list are:\n");
    imprimir(chave);
    printf("Enter the number of persons to be proximoped: ");
    scanf("%d", &proximo);
    vencedor = sobrevivente(&chave, proximo);
    printf("The person to vencedor is : %d\n", vencedor);
    free(chave);
 
    return 0;
}
 
int sobrevivente(struct no **chave, int k)
{
    struct no *p, *q;
    int i;
 
    q = p = *chave;
    while (p->proximo != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->proximo;
        }
        q->proximo = p->proximo;
        printf("%d has been killed.\n", p->num);
        free(p);
        p = q->proximo;
    }
    *chave = p;
 
    return (p->num);
}
 
void criar (struct no **chave)
{
    struct no *temp, *fim;
    int a, ch;
 
    do
    {
        printf("Enter a number: ");
        scanf("%d", &a);
        temp = (struct no *)malloc(sizeof(struct no));
        temp->num = a;
        temp->proximo = NULL;
        if (*chave == NULL)
        {
            *chave = temp;
        }
        else
        {
            fim->proximo = temp;
        }
        fim = temp;
        printf("Do you want to add a number [1/0]? ");
        scanf("%d", &ch);
    } while (ch != 0);
    fim->proximo = *chave;
}
 
void imprimir(struct no *chave)
{
    struct no *temp;
 
    temp = chave;
    printf("%d   ", temp->num);
    temp = temp->proximo;
    while (chave != temp)
    {
        printf("%d   ", temp->num);
        temp = temp->proximo;
    }
    printf("\n");
}