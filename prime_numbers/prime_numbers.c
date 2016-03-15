#include <stdio.h>
#include <math.h>

int isPrime(long n) {
	if (n <= 3) {
		return n >= 2;
	}
	if ((n % 2 == 0) || (n % 3 == 0)) {
		return 0;
	}
	// TODO: test only if n is divisible by prime numbers lesser than
	// n
	for (int i = 5; i <= sqrt(n); i++) {
		if ((n % i == 0) || (n % (i+2) == 0)) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {

    FILE* file;
    char line[10];

    if (argc != 2) {
        puts("Please provide a single file as an argument.");
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Failed to open file \"%s\"\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, file)) {

        long n, i = 0;
        int j = 0;

        sscanf(line, "%ld", &n);

        // we never find more than n / 2 prime numbers that are < n.
        long primes[n/2];

        while (i < n) {
			if (isPrime(i)) {
                primes[j] = i;
                j++;
            }
            i++;
        }

        for (int i = 0; i < j; i++) {
            printf("%ld", primes[i]);
            if ((i + 1) != j) {
                printf(",");
            }
        }
        printf("\n");
	}
}
