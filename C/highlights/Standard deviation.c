#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void init_array(int *p,int n,int a,int b);
double average (int *p,int n);
double stdev(int *p,int n,double av);
double percent(int *p,int n,double a,double b);

int main()
{
	int *a;
	int n;
	double right1=0,left1=0,right2=0,left2=0,p1,p2,av;
	do{
	printf("Type number of  array's contents:");
	scanf("%d",&n);
	}while(n<=1);
	a=(int *)malloc(sizeof(int)*n);
	if(!a)
	{
		fprintf(stderr,"Error occured while allocating needed memory!");
		exit(0);
	}
	init_array(a,n,25,50);
	printf("\nArray's contents initialised");
	av=average(a,n);
	printf("\nThe standard deviation is:%lf",stdev(a,n,av));
	right1=stdev(a,n,av)+av;
	left1=av-stdev(a,n,av);
	right2=av+2*stdev(a,n,av);
	left2=av-2*stdev(a,n,av);
	printf("\naverage+-stdev:%.2lf%%|avrage+-2*stdev:%.2lf%%",p1=percent(a,n,right1,left1),p2=percent(a,n,right2,left2));
	
	FILE *fp;
	fp=fopen("percent.dat","a");
	if(!fp)
	{
		fprintf(stderr,"Error opening file!");
		exit(0);
	}
	fprintf(fp,"%d %.2lf %.2lf\n",n,p1,p2);
	fclose(fp);
	
	int records=0;
	
	fp=fopen("percent.dat","r");
	if(!fp)
	{
		fprintf(stderr,"Error openinig file!");
		exit(0);
		}	
	while(fscanf(fp, "%d %lf %lf\n",&n,&p1,&p2)==3)
	{
		records++;	
		               }
	fclose(fp);	
	printf("\nNumber of records is:%d",records);	
	free(a);
	return  0;
}
void init_array(int *p,int n,int a,int b)
{
	srand(time(NULL));
	int i;
	for(i=0;i<n;i++)
		*(p+i)=b+rand() % (b-a+1);
}

double average (int *p,int n)
{
	int i,sum=0;
	double av=0;
	for(i=0;i<n;i++)
		sum+=p[i];
	av=(double)sum/n;
	return av;	
}
double stdev(int *p,int n,double av)
{
	int i;
	double s=0;
	for(i=0;i<n;i++)
		s+=pow(p[i]-av,2);
	 return sqrt(s/(n-1));
}
double percent(int *p,int n,double a,double b)
{
	int i,cnt=0;
	for(i=0;i<n;i++)
	{
		if(p[i]<=a && p[i]>=b)
			cnt++;
	}
	return (double)100*cnt/n;

}
