#include <stdio.h>

int main(){
  int i,j;


  for( i = 0; i <= 9; i++ ){
    if( i == 0){
      printf("    |");
    }else if (i == 1) {
      printf("----+----------------------------\n");
    }
    if( i > 0 ){
      printf("  %d |", i );
    }
    for( j = 1; j <= 9; j++ ){
      if( i == 0){
        printf("%3d", j);
      }else{
          printf("%3d", i*j);
      }
    }
    printf("\n");
  }

}
