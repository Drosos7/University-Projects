// Time Calculator: Converts a given number of seconds into hours, minutes, and seconds.
#include <stdio.h>
int main(void)
{
	int t,hours,mod1,min,mod2,seconds;
	printf("Type wanted seconds:");
	scanf("%d",&t);
	hours=t/3600;
	mod1=t%3600;
	min=mod1/60;
	seconds=mod1%60;
	printf(" %d hours,%d minutes,%d seconds",hours,min,seconds);
	
	return 0;
}
