#include"header.h"
extern char **macro_name;
extern char **macro_body;
extern int mac_count;
extern FILE *fp;
extern FILE *df;
void body()
{
	int a,l,c,i=0,j=0;
	char s[100],main[100],ch,temp,m[100],b;
a:      while(fgets(m,sizeof(m),fp))
        {
                if(m[0]=='#')
                {
                        goto a;
                }
                else
                {
                        fseek(fp,-strlen(m),SEEK_CUR);
l:      while((ch=fgetc(fp))!=-1)
        {
                temp=ch;
                if(ch=='/')
                {
                        ch=fgetc(fp);
                        if(ch=='/' ||ch=='*')
                        {
                        if(ch=='/')
                        {
                                while((ch=fgetc(fp))!='\n');
                                  fputc(' ',df);
                                fputc('\n',df);
                        }
                        if(ch=='*')
                        {
                                while(((ch=fgetc(fp))!='*') || ((ch=fgetc(fp))!='/'))
                                {
                                        if(ch!='\n')
                                                fputc(' ',df);
                                        else
                                                fputc('\n',df);
                                }
                        }
                        }
                        else
                        {
                                fputc('/',df);
                                fputc(ch,df);
                        }
                }
                for(i=0;i<mac_count;i++)
 {
                        ch=temp;
                        c=0;
                        for(j=0;;j++)
                        {
                                if(macro_name[i][j]=='\0')
                                {
                                        fprintf(df,"%s",macro_body[i]);
                                        fseek(fp,-1,SEEK_CUR);
                                        goto l;
                                }
                                if(ch==macro_name[i][j])
                                {
                                        c++;
                                        ch=fgetc(fp);
                                }
                                else
                                        break;
                        }
                        if(c>0)
                                fseek(fp,-c,SEEK_CUR);
                }
                if(ch!='/')
                fputc(temp,df);
        }
		}
	}
}

