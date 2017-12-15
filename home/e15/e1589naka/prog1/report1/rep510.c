#include <stdio.h>

int main(){
  int i,j,k;
  int a[4][3], b[3][4];
  int c[4][4];

  //aの初期化
  for( i = 0; i < 4; i++ ){
    for( j = 0; j < 3; j++ ){
      printf("a[%d][%d] = ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
  //bの初期化
  for( i = 0; i < 3; i++ ){
    for( j = 0; j < 4; j++ ){
      printf("b[%d][%d] = ", i, j);
      scanf("%d", &b[i][j]);
    }
  }
  //cの初期化
  for( i = 0; i < 4; i++ ){
    for( j = 0; j < 4; j++ ){
      c[i][j] = 0;
    }
  }
  // c = a * b
  for( i = 0; i < 4; i++ ){
    for( j = 0; j < 4; j++ ){
      for( k = 0; k < 3; k++ ){
        c[i][j] += a[j][k] * b[k][j];
      }
    }
  }

  //c 出力
  printf("A*B = \n");
  for( i = 0; i < 4; i++ ){
    for( j = 0; j < 4; j++ ){
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

}
