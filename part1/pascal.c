// Pascals triangle - By Andreas Fredlund
#include <stdio.h>
#include <stdlib.h>
 
long fakultet(int);

long fakultet(int n){    //calculateas factorial.  
 long product = 1;
 for  (int i=1; i<= n; i++){
   product = product*i;
 }
 return product;
}      

int main(int argc, char const *argv[])
{

	int n,i,k;

	if (argc != 2)    // if there is no parameter or more than 1.
   {
      printf("Use one parameter \n");
      return -1;
   }

   else {
   n = atoi(argv[1]);          // sets n to the value of the parameter              
   for (i=0; i < n; i++){     // rows
   	for (k=0 ; k <= i; k++){  //columns
            printf("%ld ",fakultet(i)/(fakultet(k)*fakultet(i-k)));
           
         }
          printf("\n");
      }
      return 0;
   }
}





