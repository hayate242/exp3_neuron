#include <stdio.h>

int main(){
  int input;
  int i,j;

  printf("正方形を作ります\n");
  printf("何段ですか：");
  scanf("%d", &input);

  for ( i = 0; i < input; i++ ){
    for (j = 0; j < input; j++ ){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
