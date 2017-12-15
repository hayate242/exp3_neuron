#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4


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
double getRandom(int min,int max)
{
    double randval = 100;
    while ( randval >= 1.0 || randval <= -1.0 ){
        randval = min + (double)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
        printf("%f\n", randval);
    }
	return randval;
}
//２乗和を再計算
double recalculate_error(double x[4][2], double v[2][3], double w[1][3], double t[4]){
    int p,i,j,k;
    double y = 0;
    double z[2];
    double result_error = 0;

    for( p = 0; p < 4; p++ ){
//z,yの初期化
        init_zy( z, &y );
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

        //yの計算
        for( j = 0; j < 1; j++){
            for( k = 0; k < 3; k++ ){
                if ( k == 2 ){
                    y += w[j][k] * 1;
                }else {
                    y += w[j][k] * z[k];
                }
            }
        }
        //ハッシュ関数
        // printf("x1 = %f, x2 = %f\n", x[p][0], x[p][1]);
        y = hash(y);
        printf("y = %f\n", y);
        // printf("---------------------------\n");


        //教師信号との誤差の計算
        result_error += (t[p] - y)*(t[p] - y);
        // printf("result_error = %f\n", result_error);
    }
     printf("result_error = %f\n", result_error);
    return result_error;
}

int main()
{
     double v[2][3] = {{ 0.921006, -0.653518, -0.679311},
                                       { 0.817634, -0.405443, 0.013433}
                      };
       double w[1][3] = {{ 0.764128, -0.303625, 0.016162 }};
    //double v[2][3] = {{ 0.8, 1.0, -0.3},
    //              { 1.3, 0.6, -1.5}
    //};
     // double v[2][3];

     //double w[1][3] = {{ 0.1, 0.3, -0.5 }};
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

    double t[4] = { 0, 1, 1, 0 };
    double e = -1;
    double alpha = 0.052532;
    double result = -1;
    int cnt = 0;
    /* 乱数の種を初期化 */
    srand((unsigned)time(NULL));

    //Vの初期化
    // for( i = 0; i < 2; i++ ){
    //    for( j = 0; j < 3; j++ ){
    //        v[i][j] = getRandom( -1, 1 );
    //        printf("v[%d][%d] = %f\n", i, j, v[i][j]);
    //     }
    //  }




    while( result != 0.0 ){
        //pの選択
        p = rand() % 4;
        //printf("p = %d\n", p);
        //z,yの初期化
        init_zy( z, &y );
        // Zkの計算
        for( k = 0; k < 2; k++ ){
            for( i = 0; i < 3; i++ ){
                //zの計算
                if ( i == 2 ){
                    z[k] += v[k][i] * 1;
                }else {
                    z[k] += v[k][i] * x[p][i];
                }
            }
            //printf("!");
            //ハッシュ関数
            z[k] = hash(z[k]);
            //printf("z[%d][%d] = %f\n", p, k , z[k]);
        }

        //yの計算
        for( j = 0; j < 1; j++){
            for( k = 0; k < 3; k++ ){
                if ( k == 2 ){
                    y += w[j][k] * 1;
                }else {
                    y += w[j][k] * z[k];
                }
            }
        }
        //ハッシュ関数
        y = hash(y);
        //printf("y = %f\n", y);
        //printf("---------------------------\n");


        //教師信号との誤差の計算
        e = t[p] - y;
        //printf("誤差e = %f\n", e);


        //結合荷重の更新
        for( j = 0; j < 1; j++ ){
            for( k = 0; k < 3; k++ ){
                w[j][k] += alpha*e*z[k];
            }
        }

        //再計算
        result = recalculate_error( x, v, w ,t);

        //結果の表示
        cnt++;
        // printf("------------------------%d\n",cnt);
        // for( j = 0; j < 1; j++ ){
        //     for( k = 0; k < 3; k++ ){
        //         printf("w[%d][%d] = %f  ", j, k, w[j][k]);
        //     }
        //     printf("\n");
        // }

    }

    //結果の表示
    for( j = 0; j < 1; j++ ){
        for( k = 0; k < 3; k++ ){
            printf("w[%d][%d] = %f  ", j, k, w[j][k]);
        }
        printf("\n");
    }

	return 0;

}
