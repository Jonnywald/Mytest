#include <stdio.h>
struct regLista
{
    int valor;
    struct regLista *prox;
};

int main()
{
    int numero;
    struct regLista *inicio, *aux, *ant, *aux2;
/* inicializando a variável inicio com um endereco vazio */
    inicio = NULL;
    while(1)
    {
        printf("Informe o numero:\n");
        scanf("%d", &numero);
        if( numero < 0 )
            break;
/* criando uma variável struct regLista dinamicamente */
        aux = (struct regLista *) malloc( sizeof(struct regLista) );
/* preenchendo os campos da variável criada dinamicamente */
        aux->valor = numero;
        //aux->prox = NULL;
        if( inicio == NULL ){ /* caso seja o primeiro numero */
            inicio = aux;
            inicio->prox = NULL;
        }
        else    /* procura posicao correta para incluir */
        {
            ant = inicio;
            aux2 = ant->prox;
            if (ant->prox != NULL){ /* existe mais de um item na lista */

                while ( aux2->prox != NULL )
                {
                    if (aux2->valor < aux->valor){ /* caso o item seja menor que o a inserir*/
                        if((aux2->prox->valor > aux->valor)&& (aux2->prox != NULL)){ /* caso o valor do proximo ao ant seja maior que o a inserir*/
                            aux->prox = aux2->prox; /* inserindo o valor no local certo*/
                            aux2->prox = aux;
                            //break;
                        }
                        else{
                            if (aux2->prox == NULL){
                                if (aux2->valor < aux->valor){ /* caso o item seja menor que o a inserir*/
                                    aux2->prox = aux;
                                    aux->prox = NULL;
                                }
                                else{ /* caso o item seja maior que o a inserir*/
                                    aux->prox = aux2;
                                    ant->prox = aux;
                                }
                            }
                        }
                        aux2 = aux2->prox;
                        ant = ant->prox; /* anda um item para frente*/
                    }
                    else{ /* caso o item seja maior que o a inserir*/
                        aux->prox = aux2;
                        ant->prox = aux;
                    }
                }
            }
            else{ /* existe apenas um item na lista */
                if (ant->valor < aux->valor){ /* caso o item seja menor que o a inserir*/
                    ant->prox = aux;
                    aux->prox = NULL;
                }
                else{ /* caso o item seja maior que o a inserir*/
                    aux->prox = ant;
                    inicio = aux;
                }
            }
        }
    }
/* imprimindo os valores da lista */
    printf("\n\n\nConteudo da lista:\n");
    aux = inicio;
    while ( aux != NULL )
    {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    return 0;
}
