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
	
	//1. Check for command line argument
	if(argc<2)
	{
		fprintf(stderr,"Not enough arguments!");
		return 1;
	}
	//2. Open the input file
	FILE *fin,*fout;
	if(!(fin=fopen(argv[1],"r")))
	{
		perror("Error");
		exit(1);
	}
		
	do{
	printf("Which character do you want to replace:");
	scanf(" %c",&c);
	}while(c<20 );
	
	outfilename=createOutputName(c);
	
	if(!(fout=fopen(outfilename,"w")))
	{
		perror("Error");
		exit(1);
	}
	//3. Read each line, replace the character and write to output file
	while(fgets(line , N , fin)!=NULL)
	{	
		cnt_line++;
		replaced+=replaceChar(line , c);
		fputs(line,fout);
	}
	//4. Print results
	printf("\nTotal replaced %d",replaced);
	//5. Free allocated memory and close files
	fclose(fin);
	fclose(fout);
	free(outfilename);
	
	return 0;
}

int replaceChar(char * line , char c)
{
	int cnt=0,i=0;
	//Replace all occurrences of c with '-' and count replacements,serial scanning of the line
	while(line[i]!='\0')
	{
		if(line[i]==c){
			line[i]='-';
			cnt++;
			}
			i++;
	}	
	//Return the count of replacements for this line
	return cnt;
}
char *createOutputName(char c)
{
	//Create a new filename based on the character to be replaced, e.g., "output_a.txt" for character 'a'
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
