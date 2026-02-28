#include <stdio.h>
#include <stdlib.h>

char * read_string();
int mystrlen(char *str);
int strcmp(char * s1, char * s2);
int main()
{
	printf("Type a string:");
	char *s1=read_string();
	printf("Type another string:");
	char * s2=read_string();
	if(s1!=NULL)
		printf("\nThe string you typed is %d characters long\n\n",mystrlen(s1));
	
	if(s2!=NULL)
	{
		if(strcmp(s1,s2)==0)
		 	printf("%s<>%s",s1,s2);
		else 
			printf("%s=%s",s1,s2); 
		}
		
		free(s1);
		free(s2);	
		
	return 0;
}

int mystrlen (char *str)
{
	int l=0;
	while(str[l]!='\0')
	 l++;
	 return l;
}

char * read_string()
{
	//Read a string of arbitrary length from the user and return a pointer to it
	char *str=NULL;
	char*temp;
	char c;
	int l=0;
	while((c=getchar())!='\n' &&  c!=EOF)
	{
		temp= realloc(str,l+2);//+1 for new char and +1 for null terminator
		if(temp==NULL){
		 return NULL;
		}
		str=temp;
		str[l]=c;
		l++;
		str[l]='\0';}
	
	return str;
}

int strcmp(char * s1, char * s2)
{
	//an attempt to implement the strcmp function from the string.h library using counter first and then alphabetical comparison if the strings are of equal length
	int i=0,cnt1=0,cnt2=0;
	
	while(s1[i]!='\0' && s2[i]!='\0'){
	 cnt1++;
	 cnt2++;
	 i++;
    }
	if(cnt1<cnt2 || cnt1>cnt2)
	 	return 0;
	else{
		for(i=0;i<cnt1;i++){
		  if(s1[i]<s2[i] || s1[i]>s2[i])
		   return 0;
		   }
		  return 1; 
	}
	
		 	
}
