#include"header.h"
FILE *fp;
FILE *df;
int main(int argc,char **argv)
{
	fp=fopen(argv[1],"r"),df=fopen(argv[2],"w");
	if(fp==0)
	{
		printf("no file\n");
		return 1;
	}
	head_macro();
	include();
	body();
	fclose(fp);
	fclose(df);
}

