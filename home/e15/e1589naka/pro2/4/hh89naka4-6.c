#include<stdio.h>
int main()
{
 char x[10][10];
 int i,j,k;
 i=0;
while(EOF != scanf("%s",x[i])) /* ctrl+Dが押されるまで繰り返し */
 {
   i++;
 }
 for(j=0;j<i;j++){
   printf(" x[%d] = %s\n",j,x[j]); /* 文字列の表示 */
   for(k=0;x[j][k]!='\0';k++){ /* 文字列の最後は'\0' */
    printf(" x[%d][%d] = %c\n",j,k,x[j][k]); /* 一文字ずつ表示 */
   }
 }
 return 0;
}
