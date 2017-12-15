#include<stdio.h>

int main(){
  char x[256];
  char tmp;
  int i = 0;
  int cntX = 0;
  while((tmp=getchar())!= '\n'){
    x[i] = tmp;
    if(tmp == 'X'){
      cntX++;
      i--;
    }
      

    i++;
  }

  if(cntX > i){
    printf("X ga ooi\n");
  }
  else if(cntX < i){
    printf("X igai ga ooi\n");
  }
  else{
    printf("Onaji kazu\n");
  }
  
  return 0;
}

