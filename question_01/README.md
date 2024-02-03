# Resposta da questão 1

## A função possui erros de compilação

- A função espera retornar um ponteiro de *char*, mas o código tenta retornar um ponteiro de inteiro. O compilador não consegue converter naturalmente, isto é, sem fazer um *cast*. Além disso, não há necessidade de retornar a variável **packet**, pois como esta é um ponteiro, o valor alterado na posição de memória para onde ela aponta já está sendo acessado pela variável passada como parâmetro na função.

- "Narrowing conversion". Durante a inicialização do ponteiro de *char* **header**, o compilador tenta converter um valor inteiro (*128*) que ultrapassa a capacidade de armazenamento do tipo *char*, que permite atribuições de valores entre *-127* e *127*.

## A função possui erros de lógica

```
for (i=0; i < *length; i++)
    packet[i+3] = packet[i];

for (i=0; i < 12; i++)
    packet[i] = header[i];
```

- O primeiro *loop* desloca erroneamente os elementos de **packet**. Os elementos de posição *i+3* serão perdidos, pois serão substituídos pelos elementos de posição *i*.

- Os *9* primeiros elementos de **packet** serão sobrepostos pelos elementos de **header**, pois apenas *3* posições foram deslocadas no primeiro ponteiro, deixando espaço insuficiente para receber os *12* elementos do segundo ponteiro.

## Sugestões de melhoria

A função descrita na questão 01 foi refatorada. Foram realizadas as correções dos *bugs* identificados, além de sugestões de boas práticas e códigos desnecessários.

O código refatorado está disponível no arquivo `src/correct_function/correct_function.cpp`.

O código original está disponível no arquivo `src/original_function/original_function.cpp`. Este foi comentado, para que o *build* fosse efetuado com sucesso.

## Rodando o código exemplo

A função foi transformada em uma aplicação, a fim de validar as alterações sugeridas. O *build* deve ser efetuado dentro de um diretório chamado *build*, utilizando os comandos CMake:

> cmake ../.

> cmake --build .

> ./app/app

A aplicação contém apenas *01* caso de teste.