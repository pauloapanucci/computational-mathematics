#include <math.h>

double PI = 3.1415926535897932;
double FA = 0.017453292519943295;

double SA = 0.166666666666666666;
double SB = 0.008333333333333333;
double SC = 0.000198412698412698;
double SD = 0.000002755731922398;
double SE = 0.000000025052108385;
double SF = 0.000000000160590438;

double CA = 0.500000000000000000;
double CB = 0.041666666666666666;
double CC = 0.001388888888888888;
double CD = 0.000024801587301587;
double CE = 0.000000275573192239;
double CF = 0.000000002087675698;

double fsin(double deg);
double fcos(double deg);

double fsin(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
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
    if (deg > 45){
      return fcos(90 - deg);
    }
    else {
      double sqr = x * x;
      return x + (x * (sqr *( sqr*( sqr*( sqr*( sqr*(sqr*SF - SE) + SD) - SC) + SB) - SA)));
    }
  } else if (deg == 0) {
    return 0;
  }
}

double fcos(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
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
      return 1 + ( sqr*( sqr*( sqr*( sqr*( sqr*(CF*sqr - CE) + CD) - CC) + CB) - CA));
    }
  } else if (deg == 0) {
    return 1;
  }
}
