#include <stdio.h>

int main(void){
    int x, y, z;

    printf("長さ 3 の数列を入力してください：");
    scanf("%d %d %d", &x, &y, &z);

    if ( x - y == y - z ){
        printf("等間隔です");
        if ( x - y > 0 ){
            printf("（間隔 = %d）\n", x-y);
        }
        else{
            printf("（間隔 = %d）\n", y-x);
        }
    }
    else{
        printf("等間隔ではありません\n");
    }

    return 0;
}
