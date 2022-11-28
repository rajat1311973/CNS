#include <stdio.h>
#include <gmp.h>
#include<iostream>
using namespace std;

int main() {
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	unsigned long seed = time(NULL);
	gmp_randseed_ui(state, seed);
	
	int bits = 1024;
	mpz_t a, prob_prime;
	mpz_inits(a, prob_prime, NULL);
	
	int n = 500;  // No. of Interations
	while(n--) {
		// printf("temp\n");
		mpz_rrandomb(a, state, bits);
		mpz_t B;
		mpz_inits(B,NULL);
		mpz_nextprime(B,a);   // next prime number greater than a is B 
		int res = mpz_probab_prime_p(B, 25);
		if(res == 1) {
			// gmp_printf("The generated random number %Zd is probably prime\n", a);
			mpz_set(prob_prime, a);
		}else if(res == 2) {
			gmp_printf("The generated random Prime number of 1024 bits is :- %Zd \n", a);
			return 0;
		}
	}
	gmp_printf("The generated random Probably Prime number of 1024 bits is :- %Zd\n", prob_prime);
	cout<<endl;
	return 0;
}
