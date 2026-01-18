#include <stdio.h>

int main()
{
	int a,b,prod=1,def=0,sum=0;
	printf("Dwse enan akeraio:");
	scanf("%d",&a);
	
	printf("Dwse allon ena akeraio:");
	scanf("%d",&b);
	
	sum=a+b;
	def=a-b;
	prod=a*b;
	
	printf("To athoirsma tous einai:%d\n",sum);
	printf("H diafora tous einai:%d\n",def);
	printf("To ginomeno tous einai:%d",prod);
	return 0;
}
