#include <stdio.h>
#include <stdlib.h>

int len(char x[256]){
  int i = 0;
  int cnt = 0;

	for(i = 0; x[i] != '\0'; i++){
		cnt++;
	}
	return cnt;
}


int main()
{

	struct {
	char name[50],tel[30];
	int height;

	} data[10];

	int i;
	int maxlen = 0;
	int index = 0;


	for(i=0;i<10;i++)
		scanf(" %s %s %d",data[i].name,data[i].tel,&data[i].height);

	printf("      name      phone height\n");

	for(i=0;i<10;i++)
		if( len(data[i].name) > maxlen ){
			maxlen = len(data[i].name);
			index = i;
		}
	printf(" %10s %10s    %3d\n",data[index].name,data[index].tel,data[index].height);


	return 0;
}
