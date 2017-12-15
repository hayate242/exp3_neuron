#include<stdio.h>
#include<string.h>


int main()
{

 char x[256][256];
 char tX[256][256];
 int i,j,k,a,b,c;
 i=0;a=0;

while(EOF != scanf("%s",x[i])) /* ctrl+Dが押されるまで繰り返し */
 {
   i++;
 }

 for(j=0;j<i;j++){
// printf(" x[%d] = %s\n",j,x[j]);
   for(k=j+1;k<i;k++){
     //2回目に入力されるとtXに入れる
     if(j!=k && !strcmp(x[j],x[k])){
      //  printf(" x[%d] = %s\n",j,x[k]); /* 文字列の表示 */
       strcpy(tX[a],x[j]);

      // printf("a= %d\n",a);
       //すでにtXに入っているかどうか確認，あれば削除
       for(b=0;b<a;b++){
        // printf("check %s\n",tX[b]);
         if(!strcmp(tX[a],tX[b])){
           a--;
          // printf("a deleted! = %d\n",a);
         }
       }
       a++;
       break;
     }

   }
  //  for(k=0;x[j][k]!='\0';k++){ /* 文字列の最後は'\0' */
   //
  //  }
 }

 for(c=0;c<a;c++){
   printf(" x[%d] = %s\n",c,tX[c]);
 }
 return 0;
}
