//need to implement threads (idk I'm lost, so I just created a functioning C prgm for a base)
/*============================================================================
   Description : Takes user-input integer to find and output all prime numbers
                  up to user input. 
  ============================================================================ */
#include <stdio.h>
#include <math.h>

int isPrime(unsigned n) {
   unsigned s, i;
  
   // Check for special cases.
   if(n <= 1)
      return 0;
   if(n == 2)
      return 1;
   // Check that given int is not even.
   if(n % 2 == 0) 
      return 0;
  
   // Check if prime.
   s = (unsigned)sqrt(n);
   for(i=3; i<=s; i+=2) {
        if (n % i == 0)
            return 0;
   }
   return 1;
}

// Check all numbers if n is prime.
void printPrimeThreadCalculation(void* threadId) {

  for(n=0; n < max; n++) { 
      if (isprime(n)) {
          printf("%-4d", n);
      }
  }
}

//Receive user input and move to create threads.
int main(void) {
  unsigned n;
  int max;
  
  // Receive user input.
  printf("Enter the number up to which you wish to check: ");
  scanf ("%d", max);
  
  printf("\nThe prime numbers are:\n");
   
  /* Thread Prime Checker */
  primeCheckerThread(max);
  /* Exits the threads */
  pthread_exit(NULL);
  
  printf("\n");
  return 0;
}

//Create threads.
void primeCheckerThread(int numOfThreads) {

    pthread_t threads[numOfThreads];
    int rc;
    long t;
    for (t = 0; t < numOfThreads; t++) {
        /* Creates threads */
        rc = pthread_create(&threads[t], NULL, printPrimeThreadCalculation, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }  pthread_join(threads[t],NULL);

    }

}
