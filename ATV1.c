// Guilherme Pereira de Souza Del Rio Bertola     RA: 0030481513020

#include <stdlib.h>
#include <stdio.h>
struct regLista
{
    int valor;
    char sexo;
    struct regLista *prox;
};

struct regLista *lista()
{
    int numero;
    char sex;
    struct regLista *inicio, *aux, *ant, *aux2;
/* inicializando a variável inicio com um endereco vazio */
    inicio = NULL;
    while(1)
    {
        printf("Informe o peso e o sexo(peso,m/f): ");
        fflush(stdin);
        scanf("%d,%c", &numero,&sex);
        if( numero < 0 )
            break;
/* criando uma variável struct regLista dinamicamente */
        aux = (struct regLista *) malloc( sizeof(struct regLista) );
/* preenchendo os campos da variável criada dinamicamente */
        aux->valor = numero;
        aux->sexo = sex;
        aux->prox = NULL;
        if( inicio == NULL )
            inicio = aux;
        else    // procura posicao correta para incluir
        {
            //if (inicio->prox == NULL)//se o novo tem que ser incluido no inicio e jogar o inicio para a frente
			   if (inicio->valor > aux->valor)
                {   aux->prox = inicio;
                    inicio = aux;
                }
                //else
                //{
                    //inicio->prox = aux;
                //}


	        else   //começa os testes com os demais
	        {
	            aux2 = inicio->prox;
	            ant = inicio;
	            while ( aux2 != NULL )
	            {
	                if (aux2->valor >= aux->valor)
					{   aux->prox = aux2;
						ant->prox = aux;
						break;
					}
					else
					{   ant = aux2;
						aux2 = aux2->prox;
					}
	            }
	            if (aux2 == NULL)
				{
					ant->prox = aux;
	        	}
        }
    }
}
/* imprimindo os valores da lista */
    printf("\n\n\nConteudo da lista:\n");
    aux = inicio;
    while ( aux != NULL )
    {
        printf("%d - %c\n", aux->valor,aux->sexo);
        aux = aux->prox;
    }
    return inicio;

}
struct regLista *unir(){
    struct regLista *lista1, *lista2,*listafinal,*ultimo;
    ultimo = (struct regLista *) malloc( sizeof(struct regLista) );
    //listafinal = ultimo;
    lista1=lista();// inicializando as listas
    lista2=lista();
    if (lista1 == NULL){
        listafinal=lista2;
        return listafinal;
    }
    else{
        if (lista2==NULL){
            listafinal=lista1;
            return listafinal;
        }
        else{
            if (lista1->prox == NULL && lista2->prox == NULL){
                if (lista1->valor>=lista2->valor){
                    lista2->prox=lista1;
                    listafinal=lista2;
                }
                else{
                    lista1->prox=lista2;
                    listafinal=lista1;
                }
            }
            else{
                for(;;){
                    if (lista1==NULL){
                        ultimo->prox=lista2;
                        return listafinal;
                    }
                    else{
                        if (lista2==NULL){
                            ultimo->prox=lista1;
                            return listafinal;
                        }
                        else{
                            if(lista1->valor>=lista2->valor){
                                ultimo->prox=lista2;
                                ultimo=lista2;
                                lista2=lista2->prox;
                            }
                            else{
                                ultimo->prox=lista1;
                                ultimo=lista1;
                                lista1=lista1->prox;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    struct regLista *fim;
    fim = unir();
    printf("\n\n\nConteudo da lista final:\n");
    while ( fim != NULL )
    {
        printf("%d - %c\n", fim->valor,fim->sexo);
        fim = fim->prox;
    }
    return 0;
}

