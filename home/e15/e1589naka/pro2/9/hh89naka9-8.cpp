#include <stdio.h>

struct MEIBO
{
 char name[50];
 char tel[30];
 int height;
 void print(); // メンバ関数
};

int main()
{
 int i;
 MEIBO data[10]; // C++の場合は頭にstructをつけなくてもよい
 printf(" name phone height\n");
 for (i=0; i<10; i++)
 {
 scanf(" %s %s %d", data[i].name, data[i].tel, &data[i].height);
 // ここでメンバ関数を呼び出す
 data[i].print();
 }
 return 0;
}
// ここからメンバ関数の実装
void MEIBO::print(){
  printf(" %10s %10s    %3d\n",name,tel,height);
}
