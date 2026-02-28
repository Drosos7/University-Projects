#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main (void)
{
	int hidden,x,p;
	srand(time(NULL));
	hidden=rand()%101;
	p=0;
	printf("Guess the number (1-100):");
	scanf("%d",&x);
	p++;
	
	 while(x!=hidden)
	 {
	    if(x<hidden)
	   { 	
	    printf("Aim higher than %d\n",x);
	    scanf("%d",&x);
        }
	   else 
	   {
	   	printf("Aim lower than %d\n",x);
	   	scanf("%d",&x);
	   }
	    p++;
	 } 	 
	  if(x==hidden)
       printf("Congratulations! You guessed the number in %d attempts.\n",p); 	
	
	
	return 0;
}


