#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



typedef struct{
	int x;
	int y;
	float dist;
	double r;
	double theta;
}point;
void getData ( point *p , int n, int min , int max , float * max_dist, int *max_x, int *max_y);
void cart2polar(double *r, double *theta , int x, int y);


int main()
{
	srand(time(NULL));
	float max_dist;
	point *p;
	int i,N,max_x,max_y;
	do{
		printf("Dwse plithos shmeiwn(>2)");
		scanf("%d",&N);
	}while(N<2);
	
	p=(point *)malloc(N*sizeof(point));
	if(!p)
	{
		perror("Error");
		exit(1);
	}

	getData(p,N,1, 10,&max_dist,&max_x, &max_y);
	
	printf("Point with maximum distance is ( %d, %d):%f",max_x,max_y,max_dist);
	
	FILE *fp;
	if(!(fp=fopen("max.dat","a")))
	{
		perror("Error");
		exit(1);
	}
	fprintf(fp,"Point with maximum distance is ( %d, %d):%.2f\n",max_x,max_y,max_dist);
	fclose(fp);
	
	free(p);
	return 0;
}
void getData ( point *p , int n, int min, int max, float * max_dist,int * max_x, int *max_y)
{
	float temp=-1;
	int i,max_a=0, max_b=0;

	for(i=0;i<n;i++)
	{
	
		
		p[i].x=min+rand()%(max-min+1);
		p[i].y=min+rand()%(max-min+1);
		p[i].dist=sqrt(pow(p[i].x,2)+pow(p[i].y,2));
		cart2polar(&p[i].r,&p[i].theta,p[i].x,p[i].y);
		if(p[i].dist>temp){
			max_a=p[i].x;
			temp=p[i].dist;
			max_b=p[i].y;
			}	
	}
	*max_dist=temp;
	*max_x=max_a;
	*max_y=max_b;
	
}

void cart2polar (double *r, double *theta, int x, int y)
{
	*r=sqrt(pow(x+y,2));
	*theta=atan2(x,y);
}
