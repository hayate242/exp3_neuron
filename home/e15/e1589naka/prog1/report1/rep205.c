#include <stdio.h>

int main(){
  int x,y;
  double tmp;
  printf("二つの整数を入力してください\n");
  printf("整数x：");
  scanf("%d", &x);
  printf("整数y：");
  scanf("%d", &y);

  tmp = (double)x/(double)y*100;
  printf("xの値はyの%f％です\n", tmp);
  return 0;
}
