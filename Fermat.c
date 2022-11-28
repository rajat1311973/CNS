#include <stdio.h>
#include <gmp.h>
#include <time.h>

void main()
{
	mpz_t a, b, c, d;
	mpz_inits(a, b, c, d, NULL);
	printf("Enter the number to test Fermat Primality - ");
	gmp_scanf("%Zd", a);
	
	int k;
	printf("Enter the Number of times to run the test - ");
	scanf("%d", &k);
	int seed = (int)time(NULL);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	gmp_randseed_ui(state, seed);
	mpz_sub_ui(c, a, 4);
	mpz_sub_ui(d, a, 1);
	
	for (int i=0; i<k; ++i) {
		mpz_urandomm(b, state, c);
		mpz_add_ui(b, b, 2);
		mpz_powm(b, b, d, a);
		
		if (mpz_cmp_ui(b, 1) != 0) {
			printf("Its a composite number\n");
			return;
		}
	}
	printf("It is probably prime\n");
	
	return;
}
