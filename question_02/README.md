# Resposta da questão 2

## O que a função faz?

Assumindo que a variável **List_head** é um ponteiro global que aponta para o primeiro elemento de uma lista duplamente encadeada, a função `void removeEntry(int key)` se propõe a remover o primeiro nó dessa lista cujo o valor seja diferente do valor de **key** (argumento da função).

Seguindo o fluxo comum de remoção de um nó X de uma lista duplamente encadeada descrita abaixo:

```
typedef struct node
{
    int key;
    node *next;
    node *previous;
};

typedef struct list
{
    node *head;
};
```

- Se X for um nó intermediário, a função faz com que o nó anterior a X aponte para o nó seguinte a X, enquanto que o nó seguinte tem seu ponteiro "previous" apontado para o nó anterior a X, eliminando este da lista;

- Se X for o próprio **List_head** e não houver mais nós na lista, a função faz com que **List_head** aponte para NULL;

- Se X for o próprio **List_head** e houver nós subsequentes, a função faz com que **List_head** aponte para o nó seguinte a X.

## A função funciona?

Não, a função não funciona por dois motivos:

- Ocorre um erro de segmentação ao tentar acessar o ponteiro **entry** após realizar o *free* no fim da função;

- O método comum de remoção de um nó da lista é remover o nó que possuir o valor igual a **key**;

- É necessário que, dentro da última condição, ```else if(noPrev)```, o ponteiro **entry->next->previous** seja apontado para NULL, a fim de realizar a remoção do nó com sucesso.

## A função é reentrante? Por quê?

Não é reentrante, pois a variável global **List_head** mantém seu estado após a finalização da função. 

Uma função reentrante, geralmente, não utiliza variáveis globais, pois as diferentes chamadas dessa função (por diferentes threads, por exemplo), compartilhariam o estado da variável global, sendo o comportamento atual da função influenciado por comportamentos anteriores.

## Melhorias e sugestões

Corrigindo os *bugs* identificados:

```
void removeEntry(int key)
{
    int noPrev = 1, noNext = 1;
    list_entry *entry;

    for(entry = List_head; entry != NULL; entry = entry->next)
    {
        if(entry->key == key) break;
    }
    
    if(entry == NULL) return;
    
    if(entry->previous != NULL)
    {
        entry->previous->next = entry->next;
        noPrev = 0;
    }

    if(entry->next != NULL)
    {
        entry->next->previous = entry->previous;
        noNext = 0;
    }

    if((noPrev) && (noNext)) List_head = NULL;
    else if(noPrev)
    {
        List_head = entry->next;
        entry->next->previous = NULL;
    }

    free(entry);
}
```