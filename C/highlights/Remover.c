#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delCharacter(char *line ,char symb);
char *changeFileName(char *oldname ,char symb);

int main()
{
	//Variable declarations
	FILE *ffrom,*fto;
	char target;
	char srcname[]="plato-parmenides.txt";
	char *newfilename;
	char line[2048];
	int del=0;
	 
	//1.
	ffrom=fopen(srcname,"r");
	if(!ffrom)
	{
		fprintf(stderr,"An error occured while opening the source file!");
		exit(0);
	}
	
	//2.asking user which character to remove
	fprintf(stdout,"Which character do you wish to remove?\n");
	fscanf(stdin,  "%c",&target);
	
	//3.function call to change the file name
	newfilename=changeFileName(srcname,target);
	
	fto=fopen(newfilename,"w");
	if(!fto)
	{
		fprintf(stderr,"Error opening new file!");
		exit(0);
	}
	//4. calling function into a loop to read each line, remove the character and write to new file
	while(fgets(line,sizeof(line),ffrom ))
	{
		del+=delCharacter(line,target);
		fputs(line,fto);
	}
	
	//5. printing results
	printf("Newfilename is:");
	puts(newfilename);
	
	printf("Total deletions:%d", del );
	
	//6. free allocated memory and close files
	free(newfilename);
	fclose(ffrom);
	fclose(fto);
	
	return 0;
}

char *changeFileName(char *oldname,char symb)
{
char *dot;
char *newfilename = malloc(strlen(oldname) + 20);
    if (!newfilename) 
		return NULL;
    strcpy(newfilename, oldname);
    dot=strchr(newfilename,'.');
    if(dot!=NULL)
    *dot='\0';
		
    strcat(newfilename, "-without-");
    strncat(newfilename, &symb, 1);
    strcat(newfilename, ".txt");

    return newfilename;
}

int delCharacter(char line[], char symb)
{
	int i, j = 0, del = 0;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] != symb) {
            line[j] = line[i];
            j++;
        } else {
            del++;
        }
    }

    line[j] = '\0';
    return del;
}



