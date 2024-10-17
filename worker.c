#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main(int argc, char *argv[]) {
    // check if the user has provided exactly 2 arguments.
    // If not, we give them an error message.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <lower_bound> <upper_bound>\n", argv[0]);
        return 1;  // Exit with an error code arguments are wrong.
    }

    // Convert the command-line arguments from strings to integers.
    int lower_bound = atoi(argv[1]);  // The starting number for checking primes.
    int upper_bound = atoi(argv[2]);  // The ending number for checking primes.
				      
    char primes[] = "Primes : "; 
    char newline[] = " ";     

    printf("%s", primes);

    //looping through the numbers lower_bound and upper_bound.
    for (int i = lower_bound; i <= upper_bound; i++) {

        if (i <= 1) continue;  // Skip numbers <= 1 since they're not prime.

        int is_prime = 1;  // Flag that indicates if the number is prime.
			   
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {  // If i is divisible by j, it's not prime.
                is_prime = 0;  // Mark it as not prime and break out of the loop.
                break;
            }
        }

        if (is_prime) {		//print prime numbers
            printf("%d ", i);
        }
    }

    printf("%s\n", newline);

    return 0;
}
