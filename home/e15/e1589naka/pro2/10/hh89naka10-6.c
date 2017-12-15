#include <stdio.h>
#include <string.h>

struct meibo{
  char name[50],tel[30];
  int height;
};

void check_number( struct meibo *pt, struct meibo *pt1 ){
  int j,k;
  int cnt = 0;
  int a = 1;


  // printf(" %10s %12s    %3d, %10s %12s   %3d\n",pt->name,pt->tel,pt->height,pt1->name,pt1->tel,pt1->height);
  for( j = strlen(pt -> tel)-1; j > strlen(pt -> tel)-5 ; j--){
    k = strlen(pt1 -> tel)-a;
    // printf("pt = %c\n", pt -> tel[j]);
    // printf("pt1 = %c\n", pt1 -> tel[k]);

    if( pt -> tel[j] == pt1 -> tel[k]){
      cnt++;
    }
    a++;
  }
  if( cnt == 4){
    printf(" %10s %12s    %3d, %10s %12s    %3d\n",pt->name,pt->tel,pt->height,pt1->name,pt1->tel,pt1->height);

  }


}

int main()
{

  struct meibo data[10];
	struct meibo *pt,*pt1;

	int i,j;

	for(i=0;i<10;i++)
		scanf(" %s %s %d",data[i].name,data[i].tel,&data[i].height);

	printf("      name       phone height\n");

	pt=&data[0];
  pt1 = pt+1;

  for(i=0;i<10;i++){
    for( j = i+1; j < 10; j++){
      check_number(pt, pt1);
      pt1++;
		}
    pt++;
    pt1 = pt+1;
	}

	return 0;
}
