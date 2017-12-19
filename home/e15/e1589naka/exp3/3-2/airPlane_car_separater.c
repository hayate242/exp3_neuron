#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 50
#define Max 100000
#define matrixSize 8
#define OutPutNum 2

// FILE openFile(FILE *fp, char *fname){
//   fp = fopen( fname, "r" );
//   if( fp == NULL ){
//     printf( "%sファイルが開けません¥n", fname );
//     return fp;
//   }
//   return fp;
// }

void read_data_set_info( FILE *fp, int *dataNum, int *testDataNum, int *dataSize, int *outputSize){
  fscanf(fp, "%d\n", dataNum);
  fscanf(fp, "%d\n", testDataNum);
  fscanf(fp, "%d\n", dataSize);
  fscanf(fp, "%d\n", outputSize);
}
void read_learning_data_set( FILE *fp, const int dataNum, const int testDataNum,
   double learningData[6][matrixSize][matrixSize] , double teacherOutput[6][2],
    double testData[3][matrixSize][matrixSize] ){

  int i,j,k;
  int tmp;
  for( i = 0; i < dataNum; i++ ){
    for( j = 0; j < matrixSize; j++ ){
      for( k = 0; k < matrixSize; k++ ){
        fscanf(fp, "%d,\n", &tmp);
        learningData[i][j][k] = (double)tmp;
        // printf("%d,", (int)learningData[i][j][k]);
        printf("%d,", tmp);
      }
      printf("\n");
    }
    printf("\n\n");
  }
  for( i = 0; i < dataNum; i++ ){
    for( j = 0; j < 2; j++ ){
      fscanf(fp, "%d,\n", &tmp);
      teacherOutput[i][j] = (double)tmp;
      printf("%d,", tmp);
    }
    printf("\n");
  }
  for( k = 0; k < testDataNum; k++ ){
    for( i = 0; i < matrixSize; i++ ){
      for( j = 0; j < matrixSize; j++ ){
        fscanf(fp, "%d,\n", &tmp);
        testData[k][i][j] = (double)tmp;
        printf("%d,", tmp);
      }
      printf("\n");
    }
    printf("\n\n");
  }
}
//ハッシュ関数
double hash( double z ){
        if( z >= 0){
            return 1.0;
        }else{
            return 0.0;
        }
}
//z初期化
void init_zy( double z[N], double y[OutPutNum] ){
    int i;
    for( i = 0; i < N; i++ ){
        z[i] = 0;
    }
    for( i = 0; i < OutPutNum; i++ ){
        y[i] = 0;
    }
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
void calc_Z( double z[N], double v[N][N+1], double learningData[matrixSize][matrixSize], double y[OutPutNum] ){
  int k,i,j;
  //z,yの初期化
  init_zy( z, y );
  // Zkの計算
  for( k = 0; k < N; k++ ){
      for( i = 0; i < matrixSize; i++ ){
        for( j = 0; j < matrixSize; j++ ){

          //zの計算
          if ( i == matrixSize - 1 ){
              z[k] += v[k][i] * 1;
          }else {
              z[k] += v[k][i] * learningData[i][j];
              // printf("x[%d][%d] = %f\n", p, i, x[p][i]);
          }
        }
      }
      //printf("!");
      //ハッシュ関数
      z[k] = hash(z[k]);
      //printf("z[%d][%d] = %f\n", p, k , z[k]);
  }
}
void calc_Y( double w[1][N+1], double z[N], double y[OutPutNum]){
  int j,k;
  //yの計算
  for( j = 0; j < OutPutNum; j++){
      for( k = 0; k < N+1; k++ ){
          if ( k == N ){
              y[j] += w[j][k] * 1;
          }else {
              y[j] += w[j][k] * z[k];
          }
      }
  }
  //ハッシュ関数
  // printf("x1 = %f, x2 = %f\n", x[p][0], x[p][1]);
  // printf("before y = %f\n", y);
  for ( j = 0; j < OutPutNum; j++) {
    y[j] = hash(y[j]);
  }
  // *y = hash(*y);
  // printf("y = %f\n", y);
  // printf("---------------------------\n");

}
//２乗和を再計算
double recalculate_error(double learningData[6][matrixSize][matrixSize], double v[N][N+1], double w[1][N+1], double t[6][2], int dataNum ,int outputSize){
    int p,i,j,k;
    double y[outputSize];
    double z[N];
    double result_error = 0;

    for( p = 0; p < dataNum; p++ ){
        //zの計算
        calc_Z( z, v, learningData[p], y );
        //yの計算
        calc_Y( w, z, y);
        //教師信号との誤差の計算(２乗和)
        // result_error += (t[p] - y)*(t[p] - y);
        // printf("%d (", p);
        for( i = 0; i < OutPutNum; i++ ){
          result_error += pow((t[p][i] - y[i]),2.0);
          //結果の出力
          // printf("%f ,", y[i]);
        }
        // printf(")\n");

    }
     // printf("result_error = %f\n", result_error);
    return result_error;
}
void print_w(double w[OutPutNum][N+1]){
  //結果の表示
  int j,k;
  for( j = 0; j < OutPutNum; j++ ){
      for( k = 0; k < N+1; k++ ){
          printf("w[%d][%d] = %f;  ", j, k, w[j][k]);
      }
      printf("\n");
  }
  printf("----------------------\n"); 
}
double recalculate_error_print(double learningData[6][matrixSize][matrixSize], double v[N][N+1], double w[1][N+1], double t[6][2], int dataNum ,int outputSize){
    int p,i,j,k;
    double y[outputSize];
    double z[N];
    double result_error = 0;

    for( p = 0; p < dataNum; p++ ){
        //zの計算
        calc_Z( z, v, learningData[p], y );
        //yの計算
        calc_Y( w, z, y);
        //教師信号との誤差の計算(２乗和)
        // result_error += (t[p] - y)*(t[p] - y);
        printf("%d (", p);
        for( i = 0; i < OutPutNum; i++ ){
          result_error += pow((t[p][i] - y[i]),2.0);
          //結果の出力
          printf("%f ,", y[i]);
        }
        printf(")\n");

    }
     // printf("result_error = %f\n", result_error);
    return result_error;
}

int main(){
  FILE *fp;
  int a;
  char fname[] = "data_set.dat";
  int dataNum,testDataNum,dataSize,outputSize;
  // fp = openFile( fp, "data_set.dat" );
  fp = fopen( fname, "r" );
  if( fp == NULL ){
    printf( "%sファイルが開けません¥n", fname );
    return -1;
  }

  read_data_set_info(fp, &dataNum, &testDataNum, &dataSize, &outputSize);
  printf("%d\n",dataNum);
  printf("%d\n",testDataNum);
  printf("%d\n",dataSize);
  printf("%d\n",outputSize);

  double learningData[6][matrixSize][matrixSize];
  double teacherOutput[6][2];
  double testData[testDataNum][matrixSize][matrixSize];
  double v[N][N+1];
  double w[outputSize][N+1];
  double z[N];
  read_learning_data_set(fp, dataNum, testDataNum, learningData, teacherOutput, testData);

  int i,j,k;
  int p;


  double y[outputSize];

  //教師データとの誤差
  double e[OutPutNum];
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
    for( i = 0; i < N; i++ ){
        for( j = 0; j < N+1; j++ ){
            v[i][j] = getRandom( -1.0, 1.0 );
            printf("v[%d][%d] = %f;  ", i, j, v[i][j]);
        }
    }
    for( j = 0; j < outputSize; j++ ){
        for( k = 0; k < N+1; k++ ){
          w[j][k] = getRandom( -1.0, 1.0 );
          printf("w[%d][%d] = %f;  ", j, k, w[j][k]);
        }
        printf("\n");
    }


    while( result != 0.0 && cnt <= Max ){//&& cnt <= 10
        //pの選択
        p = rand() % dataNum;
        // p = cnt % 4;
        // printf("p = %d\n", p);
        //zの計算
        calc_Z( z, v, learningData[p], y );
        //yの計算
        calc_Y( w, z, y);

        //教師信号との誤差の計算
        for( i = 0; i < OutPutNum; i++ ){
          e[i] = teacherOutput[p][i] - y[i];
        }

        // printf("誤差e = %f\n", e);

        //結合荷重の更新
        for( j = 0; j < OutPutNum; j++ ){
            for( k = 0; k < N+1; k++ ){
                // printf("z[%d]=%f\n", k, z[k]);
                w[j][k] += alpha*e[j]*z[k];
            }
        }

        //再計算
        result = recalculate_error( learningData, v, w ,teacherOutput, dataNum, outputSize );

        //結果の表示
        cnt++;
        // printf("------------------------%d\n",cnt);

        // print_w(w);

    }
    //結果の表示
    print_w(w);
    recalculate_error_print( learningData, v, w ,teacherOutput, dataNum, outputSize );

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
