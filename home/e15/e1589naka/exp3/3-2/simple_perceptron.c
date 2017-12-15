#include <stdio.h>
#define N 4

double hash(double z){
//ハッシュ関数
        if( z >= 0){
            return 1;
        }else{
            return 0;
        }
}

int main()
{
    double v[2][3] = {{ 0.8, 1.0, -0.3},
                    { 1.3, 0.6, -1.5}
    };
    double w[1][3] = {{ 1.1, -1.2, -0.5 }};
    double z[2];
    double x1[4],x2[4];
    int i,j,k;
    int p = 0;
    double x[2];

    double y = 0;
    
    // x1[0] = 0;x2[0] = 0;
    //x1[1] = 0;x2[1] = 1;
    // x1[2] = 1;x2[2] = 0;
    //x1[3] = 1;x2[3] = 1;

    x[0] = 0;
    x[1] = 0;

    
    scanf("%lf %lf", &x[0], &x[1]);
   

    //z初期化
    for( i = 0; i < 2; i++ ){
         z[i] = 0;
    }

   
    
    // Zkの計算
    for( k = 0; k < 2; k++ ){
        for( i = 0; i < 3; i++ ){
            //zの計算
            if ( i == 2 ){
                z[k] += v[k][i] * 1;
            }else {
                z[k] += v[k][i] * x[i];
            }
        }
        //ハッシュ関数
        z[k] = hash(z[k]);
        printf("z[%d] = %f\n", k , z[k]);
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
        //ハッシュ関数
        y = hash(y);
        printf("y[j] = %f\n", j , y);
    }

   
    
    
	return 0;

}

