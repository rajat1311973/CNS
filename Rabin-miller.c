#include <stdio.h>
#include <gmp.h>
#include <time.h>

void main()
{
	mpz_t a, b, c, d, e, s, f;
	mpz_inits(a, b, c, d, e, s, f, NULL);
	printf("Enter the number to perform Rabin Miller Primality test - ");
	gmp_scanf("%Zd", a);
	
	if (mpz_mod_ui(e, a, 2) == 0) {
		printf("It's an even composite number\n");
		return;
	}
	
	int k;
	printf("Enter the Number of times to run the test - ");
	scanf("%d", &k);
	
	// using random
	int seed = (int)time(NULL);
	gmp_randstate_t state;
	gmp_randinit_default(state);
	gmp_randseed_ui(state, seed);
	mpz_sub_ui(c, a, 3);
	
	mpz_set(d, a);
	mpz_set_ui(s, 0);
	mpz_sub_ui(d, d, 1);
	while (mpz_mod_ui(e, d, 2) == 0) {
		mpz_cdiv_q_ui(d, d, 2);
		mpz_add_ui(s, s, 1);
	}
	
	mpz_sub_ui(e, a, 1);
	
	for (int i=0; i<k; ++i) {
		mpz_urandomm(b, state, c);
		mpz_add_ui(b, b, 2);
		
		// b = [2, n-2]
		mpz_powm(b, b, d, a);
		
		if (mpz_cmp_ui(b, 1) == 0 || mpz_cmp(b, e) == 0) {
			continue;
		}
		
		mpz_set(f, s);
		int flag = 1;
		while (mpz_cmp_ui(f, 1) != 0) {
			mpz_powm_ui(b, b, 2, a);
			if (mpz_cmp(b, e) == 0) {
				flag = 0;
				continue;
			}
			mpz_sub_ui(f, f, 1);
		}
		if (flag){
			printf("It's a composite number\n");
			return;	
		}
	}
	printf("It is probably prime number\n");
	
	return;
}

