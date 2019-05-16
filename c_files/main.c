#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <libgen.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <string.h>

#define SetBitLinear(A,k)		( A[(k/32)] |= (1 << (k%32)) )
#define TestBitLinear(A,k)		( A[(k/32)] & (1 << (k%32)) )
#define ClearBitLinear(A,k)		( A[(k/32)] &= ~(1 << (k%32)) )

void fibonacci(int n);
void primes(int n);

int *SieveofErotosthenes(int num);

int main(int argc, char **argv){
	int fib_flag = 0;
	int prime_flag = 0;
	int n = 0;
	char c;
	while((c = getopt(argc, argv, "f:p:h")) != -1){
		switch (c){
			case 'f':
				fib_flag = 1;
				n = atoi(optarg);
			break;
			case 'p':
				prime_flag = 1;
				n = atoi(optarg);
			break;
			case 'h':
				fprintf(stderr, "use: ./sequ <-f: n fibonacci numbers> <-p: list primes up to n> \n" );
			break;
		}
	}

	if(fib_flag > 0 && prime_flag > 0){
		fprintf(stderr, "error: too many command line arguments -- run with -h for help display\n");
		exit(0);
	} else if (fib_flag > 0){
		fibonacci(n);
	} else if (prime_flag > 0){
		primes(n);
	}

	return 0;
}

void primes(int n){
	SieveofErotosthenes(n);
}

void fibonacci(int n){
	int *a = calloc(n, sizeof(int));
	int i = 2;

	a[0] = 1;

	a[1] = 1;

	while(i < n){
		a[i] = a[i-1] + a[i-2];

		i++;
	}
	for(i = 0; i < n-1; i++){

		fprintf(stderr, "%d, ", a[i]);
		
	}
	fprintf(stderr, "%d\n", a[i]);

	free(a);
}

int *SieveofErotosthenes(int num){
	int i = 0;
	int j = 0;
	int *primes = (int *)calloc(1+(num / 32), sizeof(int));

	SetBitLinear(primes, 1);

	for(i = 2; i <= num; i++){
		for(j = i+i; j <= num; j += i){
			//fprintf(stderr, "setting %d\n", j);
			SetBitLinear(primes, j);
		}
	}

	fprintf(stdout, "%d\n", 2);
	for(i = 1; i <= num; i+=2){
		if(!TestBitLinear(primes, i)){
			fprintf(stdout, "%d\n", i);
		}
	}
	
	return primes;
}