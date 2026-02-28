// This is a simple calculator program that performs basic arithmetic operations based on user input.

#include <stdio.h>
main()
{
	int x,y,z;
	int operator;
	
	printf("First number:");
	scanf("%d",&x);
	printf("Second number:");
	scanf("%d",&y);
	printf(" 1 for addition (+),\n 2 for subtraction (-) ,\n 3 for division (/) ,\n 4 for multiplication (*) ,\n 5 for modulo (%%) ,\n");
	scanf("%d",&operator);
	if (operator==1)
	{
		z=x+y;
		printf("%d+%d=%d",x,y,z);
    }
    else if (operator==2)
	{
		z=x-y;
		printf("%d-%d=%d",x,y,z);
    }
	else if(operator==3)
	{
		z=x/y;
		printf("%d/%d=%d",x,y,z);
	}
	else if(operator==4)
	{
		z=x*y;
		printf("%d*%d=%d",x,y,z);
	}
	else if(operator==5)
	{
		z=(int)x%(int)y;
		printf("%d%%%d=%d",x,y,z);
		
	}
	
  
}
