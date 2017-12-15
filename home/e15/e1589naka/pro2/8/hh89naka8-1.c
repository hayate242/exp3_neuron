#include <stdio.h>
int main()
{

	struct {
	char name[50],tel[30];
	int height;

	} data[3];

	int i;


	for(i=0;i<3;i++)
		scanf(" %s %s %d",data[i].name,data[i].tel,&data[i].height);

	printf("      name      phone height\n");

	for(i=0;i<3;i++)
		printf(" %10s %10s    %3d\n",data[i].name,data[i].tel,data[i].height);

	return 0;
}
