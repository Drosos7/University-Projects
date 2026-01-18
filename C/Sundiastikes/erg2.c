#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delCharacter(char *line ,char symb);
char *changeFileName(char *oldname ,char symb);

int main()
{
	//Dhlosh metablhtwn 
	FILE *ffrom,*fto;
	char target;
	char srcname[]="plato-parmenides.txt";
	char *newfilename;
	char line[2048];
	int del=0;
	 
	//1.Ανοιγουμε πρωτα το source arxeio gia diabasma
	ffrom=fopen(srcname,"r");
	if(!ffrom)
	{
		fprintf(stderr,"An error occured while opening the source file!");
		exit(0);
	}
	
	//2.Zhtaw apo ton xrhsth  pio sumbolo apo thelei na diagrawv tis empaniseis tou//
	fprintf(stdout,"Which character do you wish to remove?\n");
	fscanf(stdin,  "%c",&target);
	
	//3.Kalw thn sunarthsh pou mou epistefei to onoma tou deuterou arxeiou
	newfilename=changeFileName(srcname,target);
	
	fto=fopen(newfilename,"w");
	if(!fto)
	{
		fprintf(stderr,"Error opening new file!");
		exit(0);
	}
	//4. brogxos epejergasias
	while(fgets(line,sizeof(line),ffrom ))
	{
		del+=delCharacter(line,target);
		fputs(line,fto);
	}
	
	//5.Ektyposeis
	printf("Newfilename is:");
	puts(newfilename);
	
	printf("Total deletions:%d", del );
	
	//free/kleisimo arxeiwn
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



