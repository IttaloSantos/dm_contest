# Resposta da Questão 03

## Requisitos

- **Requisito 1**: desenvolver uma máquina de estados de um protocolo de conexão entre dois equipamentos (mestre/escravo).

### Máquina de estados

A figura abaixo foi elaborada com base no entendimento dos eventos, das transições e dos estados descritos na tabela da questão 3.

<img src="./images/State%20Machine.jpg" alt=State%20Machine width=300/>

- **Requisito 2**: desenvolver uma função que receba como parâmetro o estado atual e o novo evento. 

- **Requisito 3**: a função deve retornar o próximo estado, de acordo com as transições descritas acima, e realizar as chamadas das funções que realizam as ações de cada estado.

### Algumas considerações

- Não foi entendido como um requisito desenvolver um módulo *listener*, que recebe continuamente as respostas do escravo e faça a abstração dos eventos para alimentar a função acima. 

    - Espera-se que a aplicação de teste entregue o estado atual e o novo evento já abstraídos para a função.

    - Não foi desenvolvido um sistema multi-thread, com uma thread responsável por ficar escutando os eventos e a outra responsável por enviar novos eventos.

- Para as ações associadas aos eventos, foram criadas funções que simbolicamente retornam na tela *debugs* referentes a cada ação.

- O evento de **não recebeu resposta** foi entendido como um *TIMEOUT*, que a aplicação abstrai para a função.

## Fluxograma do código

Abaixo, encontra-se o fluxograma-macro do código desenvolvido.

<img src="./images/Fluxograma.jpg" alt="fluxograma" width="200"/>

Basicamente, o código tem três módulos de biblioteca e a aplicação.

O módulo de interface **Event Handler** contém um método público, **process_event()**, que é a função definida como requisito da questão. Essa função recebe o estado atual da máquina e o novo evento; e retorna o estado seguinte.

A Máquina de estados foi desenvolvida como uma classe. Ela está presente no módulo **State Machine**, que é instanciado pela função **process_event()**.

O módulo **Action** contém os métodos que simbolicamente simulam as ações associadas a cada evento, retornando um *debug*.

Para a camada de aplicação, foram desenvolvidos 4 casos de teste:

- Normal - Possui o fluxo normal de conexão partindo do evento de SENDING_START;

- Link Down - Possui os casos em que a máquina deve transitar para o estado de LINK_DOWN;

- Package Error - Possui os casos em que uma mensagem de NOK_PACKAGE_RECEIVED é recebida;

- Timeout - Possui os casos em que não há resposta do escravo, sendo simbolizado pelo Evento de TIMEOUT.

## Rodando o programa

O *build* deve ser efetuado dentro de um diretório chamado `build`, utilizando os comandos CMake:

> cmake ../.

> cmake --build .

> ./app/APP_FILE_NAME