#include<stdio.h>

int main(){
  int nums[10];
  int i = 0;
  int min;
  
  for(i=0;i<10;i++){
    scanf("%d",&nums[i]);
    // printf("num%d=%d\n",i,nums[i]);
     if(i == 0)
        min = nums[0];
     if(nums[i] < min){
        min = nums[i];
      }
  }
  printf("Minimum = %d\n",min);
  return 0;
}

