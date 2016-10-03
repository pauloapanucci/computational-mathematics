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

// rearranged
double rsin5(double deg);
double rcos5(double deg);
double rsin6(double deg);
double rcos6(double deg);
double rsin7(double deg);
double rcos7(double deg);

// original
double osin5(double deg);
double ocos5(double deg);
double osin6(double deg);
double ocos6(double deg);
double osin7(double deg);
double ocos7(double deg);

double rsin5(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rsin5(deg - 180);
  } else if (deg == 270) {
    return -1;
  } else if (deg > 180) {
    return -1 * rsin5(deg - 180);
  } else if (deg == 180) {
    return 0;
  } else if (deg > 90) {
    return rcos5(deg - 90);
  } else if (deg == 90) {
    return 1;
  } else if (deg > 0) {
    if (deg > 45){
      return rcos5(90 - deg);
    }
    else {
      double sqr = x * x;
      return x + (x * (sqr * (sqr * (sqr * (sqr * SD) - SC) + SB) - SA));
    }
  } else if (deg == 0) {
    return 0;
  }
}

double rcos5(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rcos5(deg - 180);
  } else if (deg == 270) {
    return 0;
  } else if (deg > 180) {
    return -1 * rcos5(deg - 180);
  } else if (deg == 180) {
    return -1;
  } else if (deg > 90) {
    return -1 * rsin5(deg - 90);
  } else if (deg == 90) {
    return 0;
  } else if (deg > 0) {
    if (deg > 45) return rsin5(90 - deg);
    else {
      double sqr = x * x;
      return 1 + (sqr * (sqr * (sqr * (sqr * CD) - CC) + CB) - CA);
    }
  } else if (deg == 0) {
    return 1;
  }
}

double rsin6(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rsin6(deg - 180);
  } else if (deg == 270) {
    return -1;
  } else if (deg > 180) {
    return -1 * rsin6(deg - 180);
  } else if (deg == 180) {
    return 0;
  } else if (deg > 90) {
    return rcos6(deg - 90);
  } else if (deg == 90) {
    return 1;
  } else if (deg > 0) {
    if (deg > 45){
      return rcos6(90 - deg);
    }
    else {
      double sqr = x * x;
      return x + (x * (sqr * (sqr * (sqr * (sqr * (sqr * (-SE) + SD) - SC) + SB) - SA)));
    }
  } else if (deg == 0) {
    return 0;
  }
}

double rcos6(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rcos6(deg - 180);
  } else if (deg == 270) {
    return 0;
  } else if (deg > 180) {
    return -1 * rcos6(deg - 180);
  } else if (deg == 180) {
    return -1;
  } else if (deg > 90) {
    return -1 * rsin6(deg - 90);
  } else if (deg == 90) {
    return 0;
  } else if (deg > 0) {
    if (deg > 45) return rsin6(90 - deg);
    else {
      double sqr = x * x;
      return 1 + (sqr * (sqr * (sqr * (sqr * (sqr * (-CE) + CD) - CC) + CB) - CA));
    }
  } else if (deg == 0) {
    return 1;
  }
}

double rsin7(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rsin7(deg - 180);
  } else if (deg == 270) {
    return -1;
  } else if (deg > 180) {
    return -1 * rsin7(deg - 180);
  } else if (deg == 180) {
    return 0;
  } else if (deg > 90) {
    return rcos7(deg - 90);
  } else if (deg == 90) {
    return 1;
  } else if (deg > 0) {
    if (deg > 45){
      return rcos7(90 - deg);
    }
    else {
      double sqr = x * x;
      return x + (x * (sqr * (sqr * (sqr * (sqr * (sqr * (sqr * SF - SE) + SD) - SC) + SB) - SA)));
    }
  } else if (deg == 0) {
    return 0;
  }
}

double rcos7(double deg){
  deg = fmod(deg, 360.0);
  double x = deg * FA;
  if (deg > 270) {
    return -1 * rcos7(deg - 180);
  } else if (deg == 270) {
    return 0;
  } else if (deg > 180) {
    return -1 * rcos7(deg - 180);
  } else if (deg == 180) {
    return -1;
  } else if (deg > 90) {
    return -1 * rsin7(deg - 90);
  } else if (deg == 90) {
    return 0;
  } else if (deg > 0) {
    if (deg > 45) return rsin7(90 - deg);
    else {
      double sqr = x * x;
      return 1 + (sqr * (sqr * (sqr * (sqr * (sqr * (sqr * CF - CE) + CD) - CC) + CB) - CA));
    }
  } else if (deg == 0) {
    return 1;
  }
}

double osin5(double deg){
  double x = deg * FA;
  return x
      - (x * x * x                         / (                         3 * 2 ) )
      + (x * x * x * x * x                 / (                 5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x         / (         7 * 6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x * x / ( 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}

double ocos5(double deg){
  double x = deg * FA;
  return 1
      - (x * x                         / (                         2 ) )
      + (x * x * x * x                 / (                 4 * 3 * 2 ) )
      - (x * x * x * x * x * x         / (         6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x / ( 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}

double osin6(double deg){
  double x = deg * FA;
  return x
      - (x * x * x                                 / (                                   3 * 2 ) )
      + (x * x * x * x * x                         / (                           5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x                 / (                   7 * 6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x * x         / (           9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x * x * x * x * x / ( 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}

double ocos6(double deg){
  double x = deg * FA;
  return 1
      - (x * x                                 / (                                  2 ) )
      + (x * x * x * x                         / (                          4 * 3 * 2 ) )
      - (x * x * x * x * x * x                 / (                  6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x         / (          8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x * x * x * x / ( 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}

double osin7(double deg){
  double x = deg * FA;
  return x
      - (x * x * x                                         / (                                             3 * 2 ) )
      + (x * x * x * x * x                                 / (                                     5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x                         / (                             7 * 6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x * x                 / (                     9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x * x * x * x * x         / (           11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x * x * x * x * x * x / ( 13 * 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}

double ocos7(double deg){
  double x = deg * FA;
  return 1
      - (x * x                                         / (                                            2 ) )
      + (x * x * x * x                                 / (                                    4 * 3 * 2 ) )
      - (x * x * x * x * x * x                         / (                            6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x                 / (                    8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      - (x * x * x * x * x * x * x * x * x * x         / (           10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) )
      + (x * x * x * x * x * x * x * x * x * x * x * x / ( 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 ) );
}
