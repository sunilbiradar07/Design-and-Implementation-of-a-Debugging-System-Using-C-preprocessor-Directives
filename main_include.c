#include"header.h"
extern char **head_path;
extern int head;
extern FILE *df;
void include()
{
	int i;
for(i=0;i<head;i++)
        {
        FILE *sf=fopen(head_path[i],"r");
        char cha;
        while((cha=fgetc(sf))!=-1)
                fputc(cha,df);
        fclose(sf);
        }

}

