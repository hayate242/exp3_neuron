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
		for(j = i+1 ; j < 10 ; j++ ){
	
				if(data[i].name[0] == data[j].name[0] && data[i].name[1] == data[j].name[1] ){
					printf(" %10s %10s    %3d\n", data[i].name, data[i].tel, data[i].height );
					printf(" %10s %10s    %3d\n", data[j].name, data[j].tel, data[j].height );
				
			}
		}
	}

	return 0;
}
