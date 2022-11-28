#include<iostream>
#include<time.h>
using namespace std;

int fast_exponent(int a, int b, int n){
	string binary = "";
	int i = 0;
	while(b > 0){
		if(b%2 == 0) binary = "0" + binary;
		else binary = "1" + binary;
		
		b = b / 2;
		i++;
	}
	
	int c = 0, f = 1;
	for(int i=binary.size() - 1;i>=0;i--){
		f = (f*f)%n;
		c = 2*c;
		
		if(binary[i] == '1'){
			c = c + 1;
			f = (f*a)%n;
		}
	}
	return f;
	
}

int multiplicative_inverse(int a, int n){
	for(int i=1;i<=n;i++){
		if((i*a)%n == 1) return i;
	}
	return 0;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){

	srand(time(0));
	
	int q, alpha;
	
	cout<<"enter the prime number: "<<endl;
	cin>>q;
	
	cout<<"Enter the primitive root: "<<endl;
	cin>>alpha;
	
	
	// user A selects a random integer Xa < q - 1
	int Xa = rand()%(q);
	
	int Ya = fast_exponent(alpha, Xa, q);
	
	// private = {Xa}
	// public = {q, alpha. Ya}
	
	cout<<"Enter message: "<<endl;
	int message;
	cin>>message;
	
	// choose random k
	int k;
	
	for(int i=1;i<q;i++){
		if(gcd(i, q-1) == 1){
			k = i;
			break;
		}
	}
	
	int S1 = fast_exponent(alpha, k, q);
	
	int k_inv = multiplicative_inverse(k, q-1);
	int S2 = (k_inv*(message - (Xa * S1)))%(q-1);
	while(S2 < 0) S2 = S2 + q-1;
	
	cout<<"Signature pair: "<<endl<<"S1: "<<S1<<endl<<"S2: "<<S2<<endl;
	
}
