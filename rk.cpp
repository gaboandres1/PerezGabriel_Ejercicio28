/*
Basado en el código del laboratorio.
*/
#include <iostream>
#include <cmath>

float f0x(float, float, float);
float f1x(float, float, float);
float f0y(float, float, float);
float f1y(float, float, float);

void rk4(float K, float &x1, float &y1, float &x2, float &y2);
   
const float h = 0.0001;
//const float K = 0.0;
const float G = 9.8;
const int N = 1;

int main(int argc, char **argv){
	int input = atoi(argv[1]);
	float K;
	if(input == 0){
		K = 0.0;
	}else{
		K = 0.7;
	}
	
    float x, y, vx, vy, t;
    x = 0;
    y = 0;
    vx = 10;
    vy = 10;
    for(t = 0; t <= 2; t+= h){
        std::cout << t << "\t" << x << "\t" << vx << "\t" << y << "\t" << vy << std::endl;
        rk4(K, vx, vy, x, y);
     }
   
    return 0;
}

void rk4(float K, float &x1, float &y1, float &x2, float &y2){
    float k10x, k11x, k20x, k21x, k30x, k31x, k40x, k41x;
    float k10y, k11y, k20y, k21y, k30y, k31y, k40y, k41y;
   
    k10x = h*f0x(K, x1, y1);
	k10y = h*f0y(K, x1, y1);
	
	k11x = h*f1x(K, x1, y1);
	k11y = h*f1y(K, x1, y1);
	
    k20x = h*f0x(K, x1 + k10x/2, y1 + k10y/2);
    k20y = h*f0y(K, x1 + k10x/2, y1 + k10y/2);
	
	k21x = h*f1x(K, x1 + k11x/2, y1 + k11y/2);
    k21y = h*f1y(K, x1 + k11x/2, y1 + k11y/2);
	
    k30x = h*f0x(K, x1 + k20x/2, y1 + k20y/2);
	k30y = h*f0y(K, x1 + k20x/2, y1 + k20y/2);
	
    k31x = h*f1x(K, x1 + k21x/2, y1 + k21y/2);
    k31y = h*f1y(K, x1 + k21x/2, y1 + k21y/2);
	
	k40x = h*f0x(K, x1 + k30x, y1 + k30y);
    k40y = h*f0y(K, x1 + k30x, y1 + k30y);
	
	k41x = h*f1x(K, x1 + k31x, y1 + k31y);
    k41y = h*f1y(K, x1 + k31x, y1 + k31y);
   
    //float auxx1, auxx2, auxy1, auxy2; 
    x1 = x1 + (1.0/6.0)*(k10x + 2*k20x + 2*k30x + k40x);
    x2 = x2 + (1.0/6.0)*(k11x + 2*k21x + 2*k31x + k41x);
   
    y1 = y1 + (1.0/6.0)*(k10y + 2*k20y + 2*k30y + k40y);
    y2 = y2 + (1.0/6.0)*(k11y + 2*k21y + 2*k31y + k41y);
   
}

float f0x(float K, float x1, float y1){
    return -K*pow(x1, N)*x1/sqrt( pow(x1,2) + pow(y1,2) );
}

float f1x(float K, float x1, float y1){
    return x1;
}

float f0y(float K, float x1, float y1){
    return -G - K*pow(y1, N)*y1/sqrt( pow(x1,2) + pow(y1,2) );
}

float f1y(float K, float x1, float y1){
    return y1;
}