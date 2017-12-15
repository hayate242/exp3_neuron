#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

	struct {
	char name[50],tel[30];
	int height;

	} data[10];

	int i,j;
	int nameLen;

	FILE *fp;	/* (1)ファイルポインタの宣言 */
	/* (2)ファイルのオープン */
	/*  ここで、ファイルポインタを取得する */
	if ((fp = fopen("kadai8.txt", "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}
	/* (4)ファイルの読み（書き）*/
	for(i=0;i<10;i++)
			fscanf(fp," %s %s %d",data[i].name,data[i].tel,&data[i].height);
	
	fclose(fp);	/* (5)ファイルのクローズ */



	printf("      name      phone height\n");

	for(i=0;i<10;i++){
		for(j = 0 ; data[i].name[j] != '\0' ; j++ ){
			nameLen++;
			//printf("%d\n",nameLen);
		}
		if( nameLen <= 6 ){
			printf(" %10s %10s    %3d\n",data[i].name,data[i].tel,data[i].height);
		}
			nameLen = 0;
	}

	return 0;
}
