#include <stdio.h>
#include <math.h>

int main(){
  int x;
  int i = 1.0;
  printf("正の整数を入力してください:");
  scanf("%d", &x);

  while ( pow( 2.0, i ) <= x){
    printf("%d ", (int)pow( 2.0, i ));
    i++;
  }
  printf("\n");

  return 0;
}
