#include <stdio.h>

int main(){
  int n,i;
  int sum = 0;
  printf("nの値：");
  scanf("%d", &n);

  for( i = 1; i <= n; i++ ){
    sum += i;
  }
  printf("1から%dまでの和は%dです\n", n, sum);
}
