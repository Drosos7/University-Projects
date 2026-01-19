#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 2048

int replaceChar(char * line , char c);
char *createOutputName(char c);

int main(int argc, char *argv[])
{
	char *outfilename;
	int replaced=0,cnt_line=0;	
	char line[N];
	char c;
	
	//Elegxos orismatwn
	if(argc<2)
	{
		fprintf(stderr,"Not enough arguments!");
		return 1;
	}
	//anoigma arxeiwn
	FILE *fin,*fout;
	if(!(fin=fopen(argv[1],"r")))
	{
		perror("Error");
		exit(1);
	}
		
	do{
	printf("Dwse enan xarakthra pou na afairesw:");
	scanf(" %c",&c);
	}while(c<20 );
	
	outfilename=createOutputName(c);
	
	if(!(fout=fopen(outfilename,"w")))
	{
		perror("Error");
		exit(1);
	}
	//Epejergaia 
	while(fgets(line , N , fin)!=NULL)
	{	
		cnt_line++;
		replaced+=replaceChar(line , c);
		fputs(line,fout);
	}
	//Emfaniseis
	printf("\nTotal replaced %d",replaced);
	//Apodesmeuseis
	fclose(fin);
	fclose(fout);
	free(outfilename);
	
	return 0;
}

int replaceChar(char * line , char c)
{
	int cnt=0,i=0;
	
	while(line[i]!='\0')
	{
		if(line[i]==c){
			line[i]='-';
			cnt++;
			}
			i++;
	}	
	return cnt;
}
char *createOutputName(char c)
{
	char *Fname;
	Fname=(char *)malloc(30*sizeof(char));
	if(!Fname)
	{
		perror("Error");
		exit(1);
	}
	sprintf(Fname,"output_%c.txt",c);
	return Fname;
}
