//need to implement threads (idk I'm lost, so I just created a functioning C prgm for a base)

#include <stdio.h>
#include <math.h>

int isprime(unsigned n) {
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

int main(void) {
  unsigned n;
  int max;
  
  // Receive user input.
  printf("Enter the number up to which you wish to check: ");
  scanf ("%d", max);
  
  // Check all numbers if n is prime.
  printf("Prime numbers are:\n");
  for(n=0; n < max; n++) { 
      if (isprime(n)) {
          printf("%-4d", n);
      }
  }
  printf("\n");
  return 0;
}
