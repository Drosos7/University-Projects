#include <stdio.h>

main() 
{
	int p,flag,i,min_thesh;
	float N,min,A[20];
	flag=0;
	p=0;
	printf("Dose ena arithmo N 2-20:");	
	 do{
	 	  if(p==0)
	 	   scanf("%f",&N);
	  	  else if(p>0)
	      {		
	  	   printf("Edoses timh ektos orion,janadose:");
	  	   scanf("%f",&N);
          }
		   flag=(N<2||N>20);
		   if(flag)
		    p++;
	   }while(flag);
	   
	//Arxikopoihsh tou pinaka me max diastaseis=20 me mhden//
	  
	   for(i=0;i<20;i++)
	   { 
	   A[i]=0;
	   }
	    
         for(i=0;i<(int)N;i++)
		 {
          printf("Dose arithmo pou thes gia thn %d thesh tou pinaka:\n",i+1);
		  scanf("%f",&A[i]);
		  if(i==0)
		   min=A[i];
	  	  else
			 if(min>A[i])
			 min=A[i];   
        }
	   	printf("O elaxistos arithmos ton stoixeion tou pinaka A, einai o: %.2f , %d ",min,(int)A[(int)N+1]);//blepo an ekane thn arxikopoihsh me 0//
}
	
	
	
	
	
	
	
	
	
	
	
	
	

