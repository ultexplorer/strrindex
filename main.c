#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);
int strrindex(char s[], char t[]);
char pattern[]="hro";

int main()
{
    char str[MAXLINE]=" ";
    int N=0;
    while (my_getline(str,MAXLINE)>0)
    {
        if((N=strrindex(str, pattern))>=0){
           printf("%d %s\n", N, str);
        }        
    }    

    return 0;
}

int my_getline(char s[], int lim)
{
    int i, c;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF &&  c!='\n')
    {
        s[i++]=c;
    }
    if(c=='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';

    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k;
    int found=-1;
    for(i=0; s[i]!='\0'; ++i)
    {
        for(j=i, k=0; t[k]!='\0' && t[k]==s[j]; k++, j++){
           ; 
        }
        if(k>0 && t[k]=='\0') found=i;
    }
    return found;
}