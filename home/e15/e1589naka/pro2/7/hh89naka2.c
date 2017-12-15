#include<stdio.h>

int cntX(char *pt){
  int i = 0;
  int cnt = 0;

	for(i = 0; *pt != '\0'; i++){
		if( *pt == 'X'){
			cnt++;
		}
		pt++;
	}
	return cnt;
}

int main(){

  char x[256],*pt;
  pt = &x[0]; //初期化
	int cnt = 0;

  scanf("%s",x);

 	cnt = cntX(pt);

  printf("Result = %d\n",cnt);
  


  
  return 0;
}

