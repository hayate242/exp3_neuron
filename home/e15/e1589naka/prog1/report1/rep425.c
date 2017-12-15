#include <stdio.h>

int main(){
  int i,j,num;

  printf("下向き数字ピラミッドを作ります\n");
  printf("何段ですか：");
  scanf("%d", &num);

  for( i = 1; i <= num; i++ ){
    for( j = 1; j < i ; j++ ){
      printf(" ");
    }
    for( j = 1; j <= (num-i)*2+1; j++ ){
      printf( "%d", (i%10) );
    }
    printf("\n");
  }

}
