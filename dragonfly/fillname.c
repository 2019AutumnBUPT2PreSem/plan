#include <stdio.h>
#define STRLENLIMIT 16

typedef struct char16
{
    char c[STRLENLIMIT];
} nam;

void display_nam(nam name)
{
    for(int j = 0; j < STRLENLIMIT; j++)
        if(name.c[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", name.c[j]);
}

nam fillname(char *p)
{
	int i;
	nam newnam;
	newnam.c[STRLENLIMIT];
	for(i=0;i<=STRLENLIMIT-1;i++)
	{
		if(p[i] == '\0')
		{
			newnam.c[i] = '\0';
			break;
		}
		if(newnam.c[i] == '\0')
		{
			newnam.c[i+1] = '\0';
		}
		if(p[i] != '\0')
		{
			newnam.c[i] = p[i];
		}
	}
	for(i=0;i<=STRLENLIMIT-1;i++)
	{
		if(newnam.c[i] == '\0')
		{
			newnam.c[i+1] = '\0';
		}
	}
	return newnam;
}

int main()
{
	int i;
	nam p;
	p= fillname("table1");
	
	display_nam(p);

	return 0;
} 
