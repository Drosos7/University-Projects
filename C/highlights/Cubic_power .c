//Prints the cubes of the first N natural numbers, where N is an integer input by the user.
#include <stdio.h>
main()
{
   int i,N,y;
   
   printf("Give number of natural numbers to be cubed :");
   scanf("%d",&N);
   
   
   for (i=1;i<=N;i++)
   {
      y= i*i*i;
	  printf("\n%d cube's is: %d ",i,y);
   }

   
   printf("\n\n Thank you for using this program.");
}
   	
	
	
	
	
	
	








