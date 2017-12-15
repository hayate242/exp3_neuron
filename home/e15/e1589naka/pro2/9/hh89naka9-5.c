#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define sqr(n) ((n) * (n))

typedef struct {
	double x;
	double y;
} Point;


typedef struct {
	Point pt;
	double fuel;
} Car;

double distance_of( Point pa, Point pb ){
	return sqrt(sqr(pa.x - pb.x) + sqr(pa.y -pb.y));
	//return 0.0;
}
double distance_from_here( Point pa ){
	return sqrt(sqr(pa.x) + sqr(pa.y));
	//return 0.0;
}

void put_info(Car c){
	printf("現在位置：(%.2f, %2f)\n", c.pt.x, c.pt.y);
	printf("残り燃料：%.2fリットル\n", c.fuel);
}

int move(Car *c, Point dest, int selectWay){
  double d;
  if( selectWay == 0 ){
    d = distance_of(c->pt,dest);
    if (d > c->fuel){
  		return 0;
  	}
  	c->pt = dest;
  	c->fuel -= d;
  	return 1;
  }
  else if ( selectWay == 1){
    d = distance_from_here(dest);
    if (d > c->fuel){
  		return 0;
  	}
  	c->pt.x += dest.x;
    c->pt.y += dest.y;
  	c->fuel -= d;
  	return 1;
  }
  else {
    return 0;
  }


}

int main()
{

	Car mycar = {{ 0.0 , 0.0 }, 90.0};

	while(1) {
		int select;
    int selectWay;
		Point dest;

		put_info(mycar);
		printf("移動しますか 【Yes・・・1/No・・・0】 : ");
		scanf("%d", &select);
		if (select != 1) break;

    printf("目的地の座標を入力しますか？目的地からの移動距離を入力しますか？ 【座標・・・0/移動距離・・・1】 : ");
    scanf("%d", &selectWay);

    if( selectWay == 0 ){
      printf("目的地のX座標："); scanf("%lf", &dest.x);
  		printf("　　　　Y座標："); scanf("%lf", &dest.y);
    }
    else if( selectWay == 1 ){
      printf("目的地からのX方向の移動距離："); scanf("%lf", &dest.x);
  		printf("　　　　　　Y方向の移動距離："); scanf("%lf", &dest.y);
    }
    else {
      break;
    }


		if (!move(&mycar, dest,selectWay))
			puts("\a燃料不足で移動できません");
	}

	return 0;
}
