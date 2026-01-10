//ginomeno me pinaka
#include <stdio.h>
#define N 5
main()
{
   int A[N],i,gin;
   	gin=1;	
	for (i=0;i<N;i++)
	{
		printf("Dose akeraio gia thn %d thesi tou pinaka 1-8 :",i+1);
		scanf("%d",&A[i]);
		if(A[i]<1||A[i]>8){
		
       	   do{   
		    printf("Lathos dose timh 1-8,janadose :");
       		scanf("%d",&A[i]);
             
		   }while(A[i]<1||A[i]>8);     
	     }
		   gin*=A[i];
     }
     printf("To ginomeno einai:%d",gin);
}
