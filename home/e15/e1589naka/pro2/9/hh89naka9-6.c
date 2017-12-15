#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	int i,j,k;
	int telLen1,telLen2;
  int flag = 0;

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
    telLen1 = len(data[i].tel);

    for(j = i+1 ; j < 10 ; j++ ){
      telLen2 = len(data[j].tel);
      for( k = 1; k <= 4; k++){
        if( data[i].tel[telLen1-k] != data[j].tel[telLen2-k] ){
          flag = 0;
          break;
        }else {
          flag = 1;
        }
      }
      if( flag ){
        printf(" %10s %10s    %3d\n",data[i].name,data[i].tel,data[i].height);
        printf(" %10s %10s    %3d\n",data[j].name,data[j].tel,data[j].height);
        flag = 0;
      }
    }
	}

	return 0;
}
