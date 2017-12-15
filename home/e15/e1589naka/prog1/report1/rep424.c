#include <stdio.h>

int main(){
  int i,j,num;

  printf("ピラミッドを作ります\n");
  printf("何段ですか：");
  scanf("%d", &num);

  for( i = 1; i <= num; i++ ){
    for( j = 1; j <= (num-i) ; j++ ){
      printf(" ");
    }
    for( j = 1; j <= (i-1)*2+1; j++ ){
      printf("*");
    }
    printf("\n");
  }

}
