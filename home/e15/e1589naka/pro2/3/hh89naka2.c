#include<stdio.h>

int main(){
  int nums[10];
  int i = 0;
  int max = 0;
  
  for(i=0;i<10;i++){
    scanf("%d",&nums[i]);
    // printf("num%d=%d\n",i,nums[i]);
     if(nums[i] > max){
        max = nums[i];
      }
  }
  printf("Maximum = %d\n",max);
  return 0;
}

