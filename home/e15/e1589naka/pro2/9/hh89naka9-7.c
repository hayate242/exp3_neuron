#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MEIBO
{
 char name[50];
 char tel[30];
 int height;
};

void printMEIBO(const struct MEIBO *pData);
int main()
{
 int i;
 struct MEIBO data[10];
 struct MEIBO *p;


 printf("name phone height\n");
 for (i=0; i<10; i++)
 {
   p = &data[i];
   scanf(" %s %s %d",p -> name, p -> tel, &p -> height);
   // ここで関数にMEIBO構造体のデータをアドレスで渡す
   //ポインタ初期化

   printMEIBO( p );
 }
 return 0;
}
// ここから関数の実装
void printMEIBO(const struct MEIBO *pData)
{
  printf(" %10s %10s    %3d\n",pData->name,pData->tel,pData->height);
}
