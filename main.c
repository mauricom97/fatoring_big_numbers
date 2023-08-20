#include <stdio.h>
#include <gmp.h>

void pollard_rho_factorization(mpz_t n) {
    mpz_t x, y, d;
    mpz_init(x);
    mpz_init(y);
    mpz_init(d);
    
    mpz_set_ui(x, 2);
    mpz_set_ui(y, 2);
    mpz_set_ui(d, 1);
    
    while (mpz_cmp_ui(d, 1) == 0) {
        mpz_mul(x, x, x);
        mpz_add_ui(x, x, 1);
        mpz_mod(x, x, n);
        
        mpz_mul(y, y, y);
        mpz_add_ui(y, y, 1);
        mpz_mod(y, y, n);
        mpz_mul(y, y, y);
        mpz_add_ui(y, y, 1);
        mpz_mod(y, y, n);
        
        mpz_sub(d, x, y);
        mpz_abs(d, d);
        mpz_gcd(d, d, n);
    }
    
    if (mpz_cmp(d, n) == 0) {
        gmp_printf("N�o foi poss�vel fatorar %Zd\n", n);
    } else {
        mpz_t factor2;
        mpz_init(factor2);
        mpz_divexact(factor2, n, d);
        
        gmp_printf("Fatores de %Zd: %Zd e %Zd\n", n, d, factor2);
        
        mpz_clear(factor2);
    }
    
    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(d);
}

int main() {
    mpz_t number;
    mpz_init(number);
    
    gmp_printf("Digite um n�mero inteiro para fatorar: ");
    gmp_scanf("%Zd", number);
    
    pollard_rho_factorization(number);
    
    mpz_clear(number);
    
    return 0;
}
