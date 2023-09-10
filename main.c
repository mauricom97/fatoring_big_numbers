#include <stdio.h>
#include <gmp.h>

void calcularFatorial(int n) {
    mpz_t resultado;
    mpz_init_set_ui(resultado, 1);

    for(int i = 2; i <= n; i++) {
        mpz_mul_ui(resultado, resultado, i);
    }

    gmp_printf("O fatorial de %d é %Zd\n", n, resultado);

    mpz_clear(resultado);
}

int main() {
    int numero;
    printf("Digite um número inteiro para calcular o fatorial: ");
    scanf("%d", &numero);

    if (numero >= 0) {
        calcularFatorial(numero);
    } else {
        printf("Não é possível calcular o fatorial de um número negativo.\n");
    }

    return 0;
}
