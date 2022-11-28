#include<stdio.h>
#include<gmp.h>
int main()
{
  mpz_t P,G;
  mpz_inits(P,G,NULL);
  gmp_printf("enter the values of Prime and G(primitive root of P\n");
  gmp_scanf("%Zd",P);gmp_scanf("%Zd",G);
  int a,b;
  printf("enter the secret values of both parties\n");
  scanf("%d",&a);scanf("%d",&b);
  gmp_printf("alice and bob will do following\n");
  mpz_t alice,bob;
  mpz_inits(alice,bob,NULL);
  mpz_powm_ui(alice, G, a,P);
  mpz_powm_ui(bob,G,b,P);
  gmp_printf("alice and bob will get following secret forms %d %d \n",alice,bob);
  mpz_swap(alice,bob);
  mpz_t fin_alice,fin_bob;
  mpz_inits(fin_alice,fin_bob,NULL);
  mpz_powm_ui(fin_alice,alice, a,P);
  mpz_powm_ui(fin_bob,bob,b,P); 
  gmp_printf("final alice and bob will get following secret forms %d %d \n",fin_alice,fin_bob);
 } 
