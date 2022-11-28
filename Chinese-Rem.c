#include <stdio.h>
#include <gmp.h>
#include <time.h>

int main() {
    int n;
    printf("Enter number of relations\n");
    scanf("%d", &n);

    mpz_t a[n], m[n], M1[n], x1[n], x, M, temp;
    for(int i=0;i<n;i++) {
        mpz_inits(a[i], m[i], M1[i], x1[i], NULL);
    }
    mpz_inits(M, x, temp, NULL);
    mpz_set_ui(M, 1);

    for(int i=0;i<n;i++) {
        printf("Enter a%d and m%d\n", i+1, i+1);
        gmp_scanf("%Zd %Zd", a[i], m[i]);
        mpz_mul(M, M, m[i]);
    }

    gmp_printf("M = %Zd\n", M);

    for(int i=0; i<n ;i++) {
        mpz_cdiv_q(M1[i], M, m[i]);
        gmp_printf("M%d = %Zd\n", i+1, M1[i]);
    }

    // find multiplicative inverses
    for(int i=0;i<n;i++) {
        mpz_invert(x1[i], M1[i], m[i]);
        gmp_printf("x%d = %Zd\n", i+1, x1[i]);

    }

    mpz_set_ui(x, 0);
    for(int i=0;i<n;i++) {
        mpz_set_ui(temp, 1);
        mpz_mul(temp, temp, a[i]);
        mpz_mul(temp, temp, x1[i]);
        mpz_mul(temp, temp, M1[i]);

        mpz_add(x, x, temp);
    }
    mpz_fdiv_r(x, x, M);

    gmp_printf("x = %Zd\n", x);

    return 0;
}
