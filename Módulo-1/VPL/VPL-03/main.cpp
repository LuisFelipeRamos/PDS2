#include <iostream>

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '5'.

    int q1 = 5;

    // 2) Declare um vetor de inteiro5s e inicialize com valores de 0 a 9.

    int q2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 3) Declare um ponteiro para inteiros e inicialize com valor nulo.

    int *q3 = NULL;

    // 4) Imprima o ENDEREÇO da variável declarada em (1)

    std::cout << &q1 << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)

    std::cout << q1 << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)

    std::cout << &q2 << std::endl;

    // 7) Imprima o ENDEREÇO da variável declarada em (3)

    std::cout << &q3 << std::endl;

    // 8) Imprima o VALOR da variável declarada em (3)

    std::cout << q3 << std::endl;

    // 9) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (3)

    q3 = &q1;

    // 10) Imprima o VALOR da variável declarada em (3)

    std::cout << q3 << std::endl;

    // 11) Imprima o VALOR guardado no ENDEREÇO apontado por (3)

    std::cout << *q3 << std::endl;

    // 12) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (3)

    bool c = &q1 == q3;
    std::cout << c << std::endl;

    // 13) Coloque o VALOR '10' no ENDEREÇO apontado por (3)

    *q3 = 10;

    // 14) Imprima o VALOR da variável declarada em (1)

    std::cout << q1 << std::endl;

    // 15) Atribua o ENDEREÇO da variável (2) à variável declarada em (3)

    q3 = &q2[0];

    // 16) Imprima o VALOR da variável declarada em (3)

    std::cout << q3 << std::endl;

    // 17) Imprima o VALOR guardado no ENDEREÇO apontado por (3)

    std::cout << *q3 << std::endl;
    // 18) Atribua o ENDEREÇO da primeira posição de (2) à variável declarada em (3)

    q3 = &q2[0];

    // 19) Imprima o VALOR da variável declarada em (3)

    std::cout << q3 << std::endl;

    // 20) Imprima o VALOR guardado no ENDEREÇO apontado por (3)

    std::cout << *q3 << std::endl;

    // 21) Multiplique todos os valores do vetor declarado em (2) por '10', porém manipulando apenas a variável (3)

    for (int i = 0; i < 10; i++){
        *(q3 + i) = *(q3 + i) * 10;
    }

    // 22) Imprima os elementos de (2) a partir variável do vetor utilizando a notação [] (colchetes)

    for (int i = 0; i < 10; i++){
        std::cout << q2[i] << " ";   
    }
    std::cout << std::endl;

    // 23) Imprima os elementos de (2) a partir variável do vetor utilizando a notação ponteiro/deslocamento

    for (int i = 0; i < 10; i++){
         std::cout << *(q2 + i) << " ";
    }
    std::cout << std::endl;

    // 24) Imprima os elementos de (2) manipulando apenas a variável (3)

    for (int i = 0; i < 10; i++){
        std::cout << *(q3 + i) << " ";
    }
    std::cout << std::endl;

    // 25) Imprima o resultado da comparação do VALORES armazenado na quinta posição de (2) e no ponteiro (3) incrementado de 4

    std::cout << (q2[4] == *(q3 + 4)) << std::endl;

    // 26) Atribua o ENDEREÇO da quinta posição de (2) à variável declarada em (3)

    q3 = &q2[4];

    // 27) Imprima o VALOR guardado no ENDEREÇO apontado por (3)

    std::cout << *q3 << std::endl;

    // 28) Imprima o VALOR guardado no ENDEREÇO do ponteiro (3) decrementado de 4

    std::cout << *(q3 - 4) << std::endl;

    return 0;
}