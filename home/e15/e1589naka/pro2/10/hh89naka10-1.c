#include <stdio.h>
int main()
{
	struct meibo{
		char name[50],tel[30];
		int height;
	} data[10];

	struct meibo *pt;
	int i;

	for(i=0;i<10;i++)
		scanf(" %s %s %d",data[i].name,data[i].tel,&data[i].height);

	printf("      name       phone height\n");

	pt=&data[0];

	for(i=0;i<10;i++){
		printf(" %10s %12s    %3d\n",pt->name,pt->tel,pt->height);
		pt++;
	}

	return 0;
}
