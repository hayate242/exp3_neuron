#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 4
#define Max 10000000

//ハッシュ関数
double hash( double z ){
        if( z >= 0){
            return 1.0;
        }else{
            return 0.0;
        }
}
//z初期化
void init_zy( double z[2], double *y ){
    int i,j;
    for( i = 0; i < 2; i++ ){
        z[i] = 0;
    }
    *y = 0;

}
//乱数生成
double getRandom(double min,double max)
{
    double randval = 100;
    while ( randval >= 1.0 || randval <= -1.0 ){
        randval = min + (double)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
    }
	return randval;
}
void calc_Z( double z[2], double v[2][3], double x[4][2], double *y ,int p ){
  int k,i;
  //z,yの初期化
  init_zy( z, y );
  // Zkの計算
  for( k = 0; k < 2; k++ ){
      for( i = 0; i < 3; i++ ){
          //zの計算
          if ( i == 2 ){
              z[k] += v[k][i] * 1;
          }else {
              z[k] += v[k][i] * x[p][i];
              // printf("x[%d][%d] = %f\n", p, i, x[p][i]);
          }
      }
      //printf("!");
      //ハッシュ関数
      z[k] = hash(z[k]);
      //printf("z[%d][%d] = %f\n", p, k , z[k]);
  }
}
void calc_Y( double w[1][3], double z[2], double *y){
  int j,k;
  //yの計算
  for( j = 0; j < 1; j++){
      for( k = 0; k < 3; k++ ){
          if ( k == 2 ){
              *y += w[j][k] * 1;
          }else {
              *y += w[j][k] * z[k];
          }
      }
  }
  //ハッシュ関数
  // printf("x1 = %f, x2 = %f\n", x[p][0], x[p][1]);
  // printf("before y = %f\n", y);
  *y = hash(*y);
  // printf("y = %f\n", y);
  // printf("---------------------------\n");

}
//２乗和を再計算
double recalculate_error(double x[4][2], double v[2][3], double w[1][3], double t[4]){
    int p,i,j,k;
    double y = 0;
    double z[2];
    double result_error = 0;

    for( p = 0; p < 4; p++ ){
        //zの計算
        calc_Z( z, v, x, &y, p);
        //yの計算
        calc_Y( w, z, &y);
        //教師信号との誤差の計算(２乗和)
        // result_error += (t[p] - y)*(t[p] - y);
        result_error += pow((t[p] - y),2.0);
        // result_error += (t[p] - y);

    }
     // printf("result_error = %f\n", result_error);
    return result_error;
}
void print_w(double w[1][3]){
  //結果の表示
  int j,k;
  for( j = 0; j < 1; j++ ){
      for( k = 0; k < 3; k++ ){
          printf("w[%d][%d] = %f  ", j, k, w[j][k]);
      }
      printf("\n");
  }
}

int main()
{
    // double v[2][3] = {{ -1.0, -0.3, -0.5},
    //                                   { 0.3, -0.2, 0.2}
    //                   };
    // // double w[1][3] = {{ 1.0, -1.0, -0.5 }};
    // double v[2][3] = {{ 0.8, 1.0, -0.3},
    //              { 1.0, 0.6, 1.0}
    // };


    double v[2][3];

    // double w[1][3] = {{ 0.1, 0.3, 1.0 }};
    double w[1][3];
    double z[2];

    int i,j,k;
    int p;


    double y = 0;

    double x[4][2] = {
                {0.0, 0.0},
                {0.0, 1.0},
                {1.0, 0.0},
                {1.0, 1.0}
    };
    //教師データt
    double t[4] = { 0, 1, 1, 0 };
    //教師データとの誤差
    double e;
    //学習定数
    double alpha = 0.01;
    double result = -1.0;
    int cnt = 0;
    int is_success = 0;


    /* 乱数の種を初期化 */
    srand((unsigned)time(NULL));

    while(is_success == 0){
      //Vの初期化
      printf("初期値\n");
      // alpha = getRandom( 0, 0.1 );
      printf("alpha = %f\n", alpha);
      for( i = 0; i < 2; i++ ){
          for( j = 0; j < 3; j++ ){
              v[i][j] = getRandom( -1.0, 1.0 );
              printf("v[%d][%d] = %f\n", i, j, v[i][j]);
          }
      }
      for( j = 0; j < 1; j++ ){
          for( k = 0; k < 3; k++ ){
            w[j][k] = getRandom( -1.0, 1.0 );
              printf("w[%d][%d] = %f  ", j, k, w[j][k]);
          }
          printf("\n");
      }


      while( result != 0.0 && cnt <= Max ){//&& cnt <= 10
          //pの選択
          p = rand() % 4;
          // p = cnt % 4;
          // printf("p = %d\n", p);
          //z,yの初期化
          init_zy( z, &y );
          //zの計算
          calc_Z( z, v, x, &y, p);
          //yの計算
          calc_Y( w, z, &y);

          //教師信号との誤差の計算
          e = t[p] - y;
          // printf("誤差e = %f\n", e);

          //結合荷重の更新
          for( j = 0; j < 1; j++ ){
              for( k = 0; k < 3; k++ ){
                  // printf("z[%d]=%f\n", k, z[k]);
                  w[j][k] += alpha*e*z[k];
              }
          }

          //再計算
          result = recalculate_error( x, v, w ,t);

          //結果の表示
          cnt++;
          // printf("------------------------%d\n",cnt);

          // print_w(w);

      }
      //結果の表示
      print_w(w);

      if (cnt == Max+1) {
        printf("cnt = %d\n", cnt);
        printf("failed\n-------------------------\n");
        cnt = 0;
      }else{
        printf("cnt = %d\n", cnt);
        printf("success\n");
        is_success = 1;
      }
  }

	return 0;

}
