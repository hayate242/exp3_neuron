#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int ans = 0;
  int flag = 0;
  int n = 100;
  int yourFuckingfortune;
  srand((unsigned)time(NULL));
  

    yourFuckingfortune = rand()%n;
 // printf("%d\n",yourFuckingfortune);

while(flag == 0){
  printf("数字を当ててください : ");
   scanf("%d", &ans);
  printf("%d",ans);
  if(ans == yourFuckingfortune){
    printf("当たりです。\n");
    flag =1;
  }  
  if(ans > yourFuckingfortune){
    printf("それより小さいです。\n");
  }  
  if(ans < yourFuckingfortune){
    printf("それより大きいです。\n");
  }  
}

  
  return 0;
}

