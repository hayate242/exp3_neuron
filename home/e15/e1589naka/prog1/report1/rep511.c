#include <stdio.h>
#define StudentNum 6


int main(){
  int i;
  int Japanese[StudentNum];
  int Math[StudentNum];
  int sum = 0;


  printf("学生の点数を入力してください：\n");
  for( i = 0; i < StudentNum; i++ ){
    printf("学生%d\n", (i+1) );
    printf("国語：");
    scanf("%d", &Japanese[i]);
    printf("数学：");
    scanf("%d", &Math[i]);
  }

  for( i = 0; i < StudentNum; i++ ){
    printf("学生%dの平均点 = %f\n", i, (double)(Japanese[i]+Math[i])/2);
  }

  for( i = 0; i < StudentNum; i++ ){
    sum += Japanese[i];
  }
  printf("国語の平均点 = %f\n", (double)sum/StudentNum);

  sum = 0;
  for( i = 0; i < StudentNum; i++ ){
    sum += Math[i];
  }
  printf("数学の平均点 = %f\n", (double)sum/StudentNum);


}
