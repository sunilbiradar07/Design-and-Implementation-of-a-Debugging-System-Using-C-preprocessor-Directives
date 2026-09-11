
#include"header.h"
extern FILE *fp;
extern FILE *df;
char **macro_name,**macro_body,**head_name,**head_path;
int mac_count=0,head=0,h=0,i;
void head_macro()
{
	char s[100],main[100],ch,temp,m[100],b;
	while(fscanf(fp,"%s",s)!=-1)
	if(strcmp(s,"#define")==0)
		mac_count++;
	rewind(fp);
	while(fscanf(fp,"%s",s)!=-1)
	{
		s[8]='\0';
		if(strcmp(s,"#include")==0)
			head++;
	}
	rewind(fp);
	macro_name=malloc(sizeof(char *)*mac_count);
	macro_body=malloc(sizeof(char *)*mac_count);
	head_name=malloc(sizeof(char *)*head);
	head_path=malloc(sizeof(char *)*head);
	////////////////////////////collecting macro(name & body)/////////////

	while(fscanf(fp,"%s",s)!=-1)
	{
		strcpy(main,s);
		main[4]='\0';
		if(strcmp(main,"main")==0)
			break;
		if(strcmp(s,"#define")==0)
		{
			fscanf(fp,"%s",s);
			macro_name[i]=malloc(strlen(s)+1);
			strcpy(macro_name[i],s);
			macro_name[i][strlen(s)]='\0';
			fscanf(fp,"%s",s);
			macro_body[i]=malloc(strlen(s)+1);
			strcpy(macro_body[i],s);
			macro_body[i][strlen(s)]='\0';
			i++;
		}
	}
	rewind(fp);
	i=0;
	int len,q=0;
	//////////////////////collect headerfile names/////////////////////////
	while(fscanf(fp,"%s",s)!=-1)
	{
		b=s[8];
		s[8]='\0';
		if(strcmp(s,"#include")==0)
		{
			s[8]=b;
			head_name[i]=malloc(strlen(s)-8+1);
			strcpy(head_name[i],s+9);
			len=strlen(head_name[i])-1;
			if(head_name[i][len]=='>')
			{
				h=1;
				head_path[i]=malloc(len+13+1);
			}
			head_name[i][strlen(head_name[i])-1]='\0';
			if(h)
			{
				strcat(head_path[i],"/usr/include/");
				strcat(head_path[i],head_name[i]);
			}
			else
			{
				head_path[i]=malloc(strlen(head_name[i]));
				strcpy(head_path[i],head_name[i]);
			}
			i++;
			h=0;
		}
	}
	rewind(fp);
}

