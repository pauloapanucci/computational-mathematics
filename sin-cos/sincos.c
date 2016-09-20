#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double PI = 3.1415926535897932;
double factor;

double SA = 0.1666666666666666;
double SB = 0.0083333333333333;
double SC = 0.0001984126984126;
double SD = 0.0000027557319223;
double SE = 0.0000000250521083;
double SF = 0.0000000001605904;

double CA = 0.5;
double CB = 0.0416666666666666;
double CC = 0.0013888888888888;
double CD = 0.0000248015873015;
double CE = 0.0000002755731922;
double CF = 0.0000000020876756;

double fsin(double deg);
double fcos(double deg);

double fsin(double deg){
  deg = remainder(deg, 360);
  double x = deg * factor;
  if (deg > 270) {
    return -1 * fsin(deg - 180);
  } else if (deg == 270) {
    return -1;
  } else if (deg > 180) {
    return -1 * fsin(deg - 180);
  } else if (deg == 180) {
    return 0;
  } else if (deg > 90) {
    return fcos(deg - 90);
  } else if (deg == 90) {
    return 1;
  } else if (deg > 0) {
    if (deg > 45) return fcos(90 - deg);
    else {
      double sqr = x * x;
      double res;
      res = SF * sqr;
      res += SE;
      res *= sqr;
      res = SD - res;
      res *= sqr;
      res += SC;
      res *= sqr;
      res = SB - res;
      res *= sqr;
      res += SA;
      res *= sqr;
      res = 1 - res;
      res *= x;
      return res;
    }
  } else if (deg == 0) {
    printf("era cilada!\n");
    return 0;
  }
}

double fcos(double deg){
  deg = remainder(deg, 360);
  double x = deg * factor;
  if (deg > 270) {
    return -1 * fcos(deg - 180);
  } else if (deg == 270) {
    return 0;
  } else if (deg > 180) {
    return -1 * fcos(deg - 180);
  } else if (deg == 180) {
    return -1;
  } else if (deg > 90) {
    return -1 * fsin(deg - 90);
  } else if (deg == 90) {
    return 0;
  } else if (deg > 0) {
    if (deg > 45) return fsin(90 - deg);
    else {
      double sqr = x * x;
      double res;
      res = CF * sqr;
      res += CE;
      res *= sqr;
      res = CD - res;
      res *= sqr;
      res += CC;
      res *= sqr;
      res = CB - res;
      res *= sqr;
      res += CA;
      res *= sqr;
      res = 1 - res;
      return res;
    }
  } else if (deg == 0) {
    return 1;
  }
}

int main(){
  printf("PI = %ld\n", PI);
  factor = PI / 180;
  printf("FACTOR = %ld\n", factor);
  FILE * data = fopen("sincos.dat", "w");
  for (size_t i = 0; i < 540; i++) {
    double nsin = fsin(i);
    double ncos = fcos(i);
    double realsin = sin(i * factor);
    double realcos = cos(i * factor);
    printf("ANGLE %3d; SIN = %.12lf; RSIN = %.12lf; ERR = %.12lf\n", i, nsin, realsin, realsin - nsin);
    fprintf(data, "%i\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", i, nsin, realsin, ncos, realcos);
  }
  fclose(data);
  return 0;
}
