#include <stdio.h>

int main(){
  int min,max,stride;
  int i;
  printf("何cmから：");
  scanf("%d", &min);
  printf("何cmまで：");
  scanf("%d", &max);
  printf("何cmごと：");
  scanf("%d", &stride);

  for( i = min; i <= max; i += stride ){
    printf("%5dcm %.2fkg\n", i, (i-100) * 0.9 );
  }

}
