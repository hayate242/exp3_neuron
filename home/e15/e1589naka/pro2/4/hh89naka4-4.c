#include<stdio.h>
#include <string.h>

int main(){
  char x[256];
  int i = 0;
  int j = 0;
  int cntX = 0;
  int cntO = 0;
  

  while(scanf("%s",x) != EOF){

 // printf("sizeof(x) = %d",strlen(x));

  for(j = 0;j<strlen(x);j++){
     if(x[j] == 'X'){
        cntX ++;
      }
     else{
        cntO++;
      }
  }
    
     i++;
  }

 // printf("cntO = %d: cntX = %d\n",cntO,cntX);

  if(cntX > cntO){
    printf("X ga ooi\n");
  }
  else if(cntX < cntO){
    printf("X igai ga ooi\n");
  }
  else{
    printf("Onaji kazu\n");
  }
  
  return 0;
}

