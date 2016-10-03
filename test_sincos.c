#include <stdio.h>
#include <float.h>
#include "sincos/sincos.h"

int main(){

  printf("\nTESTING SINCOS\n");

  double egsin[3] = { DBL_MIN, DBL_MIN, DBL_MIN };
  int aegsin[3] = { 0, 0, 0 };
  double egcos[3] = { DBL_MIN, DBL_MIN, DBL_MIN };
  int aegcos[3] = { 0, 0, 0 };

  double egosin[3] = { DBL_MIN, DBL_MIN, DBL_MIN };
  int aegosin[3] = { 0, 0, 0 };
  double egocos[3] = { DBL_MIN, DBL_MIN, DBL_MIN };
  int aegocos[3] = { 0, 0, 0 };

  FILE * data = fopen("sincos.dat", "w");
  for (int i = 0; i < 540; i++) {
    double realsin = sin(i * FA);
    double realcos = cos(i * FA);

    double rsin[3] = { rsin5(i), rsin6(i), rsin7(i) };
    double ersin[3] = { rsin[0] - realsin , rsin[1] - realsin , rsin[2] - realsin };

    double rcos[3] = { rcos5(i), rcos6(i), rcos7(i) };
    double ercos[3] = { rcos[0] - realcos , rcos[1] - realcos , rcos[2] - realcos };

    double osin[3] = { osin5(i), osin6(i), osin7(i) };
    double eosin[3] = { osin[0] - realsin , osin[1] - realsin , osin[2] - realsin };

    double ocos[3] = { ocos5(i), ocos6(i), ocos7(i) };
    double eocos[3] = { ocos[0] - realcos , ocos[1] - realcos , ocos[2] - realcos };

    if (fabs(egsin[0]) < fabs(ersin[0])) {
      egsin[0] = ersin[0];
      aegsin[0] = i;
    }
    if (fabs(egsin[1]) < fabs(ersin[1])) {
      egsin[1] = ersin[1];
      aegsin[1] = i;
    }
    if (fabs(egsin[2]) < fabs(ersin[2])) {
      egsin[2] = ersin[2];
      aegsin[2] = i;
    }

    if (fabs(egcos[0]) < fabs(ercos[0])) {
      egcos[0] = ercos[0];
      aegcos[0] = i;
    }
    if (fabs(egcos[1]) < fabs(ercos[1])) {
      egcos[1] = ercos[1];
      aegcos[1] = i;
    }
    if (fabs(egcos[2]) < fabs(ercos[2])) {
      egcos[2] = ercos[2];
      aegcos[2] = i;
    }

    if (fabs(egosin[0]) < fabs(eosin[0])) {
      egosin[0] = eosin[0];
      aegosin[0] = i;
    }
    if (fabs(egosin[1]) < fabs(eosin[1])) {
      egosin[1] = eosin[1];
      aegosin[1] = i;
    }
    if (fabs(egosin[2]) < fabs(eosin[2])) {
      egosin[2] = eosin[2];
      aegosin[2] = i;
    }

    if (fabs(egocos[0]) < fabs(eocos[0])) {
      egocos[0] = eocos[0];
      aegocos[0] = i;
    }
    if (fabs(egocos[1]) < fabs(eocos[1])) {
      egocos[1] = eocos[1];
      aegocos[1] = i;
    }
    if (fabs(egocos[2]) < fabs(eocos[2])) {
      egocos[2] = eocos[2];
      aegocos[2] = i;
    }

    printf("angle = %3d\n", i);
    printf("   real sin = %+.16lf\n", realsin);
    printf("      lazy sin5 = %+22.16lf; error = %+.0E ;      opt sin5 = %+22.16lf; error = %+.0E\n", osin[0], eosin[0], rsin[0], ersin[0]);
    printf("      lazy sin6 = %+22.16lf; error = %+.0E ;      opt sin6 = %+22.16lf; error = %+.0E\n", osin[1], eosin[1], rsin[1], ersin[1]);
    printf("      lazy sin7 = %+22.16lf; error = %+.0E ;      opt sin7 = %+22.16lf; error = %+.0E\n", osin[2], eosin[2], rsin[2], ersin[2]);
    printf("   real cos = %+.16lf\n", realcos);
    printf("      lazy cos5 = %+22.16lf; error = %+.0E ;      opt cos5 = %+22.16lf; error = %+.0E\n", ocos[0], eocos[0], rcos[0], ercos[0]);
    printf("      lazy cos6 = %+22.16lf; error = %+.0E ;      opt cos6 = %+22.16lf; error = %+.0E\n", ocos[1], eocos[1], rcos[1], ercos[1]);
    printf("      lazy cos7 = %+22.16lf; error = %+.0E ;      opt cos7 = %+22.16lf; error = %+.0E\n", ocos[2], eocos[2], rcos[2], ercos[2]);
    // angle 1
    fprintf(data, "%i", i);
    // real sin 2
    fprintf(data, "\t%.16lf", realsin);
    // osin 3, osinERR 4, rsin 5, rsinERR 6
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E", osin[0], eosin[0], rsin[0], ersin[0]);
    // osin 7, osinERR 8, rsin 9, rsinERR 10
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E", osin[1], eosin[1], rsin[1], ersin[1]);
    // osin 11, osinERR 12, rsin 13, rsinERR 14
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E", osin[2], eosin[2], rsin[2], ersin[2]);
    // real cos 15
    fprintf(data, "\t%.16lf", realcos);
    // ocos 16, ocosERR 17, rcos 18, rcosERR 19
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E", ocos[0], eocos[0], rcos[0], ercos[0]);
    // ocos 20, ocosERR 21, rcos 22, rcosERR 23
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E", ocos[1], eocos[1], rcos[1], ercos[1]);
    // ocos 24, ocosERR 25, rcos 26, rcosERR 27
    fprintf(data, "\t%.16lf\t%.0E\t%.16lf\t%.0E\n", ocos[2], eocos[2], rcos[2], ercos[2]);
  }
  fclose(data);

  printf("\ngreater errors for rsin:\n");
  printf("   sin5 (%3d) = %.0E\n", aegsin[0], egsin[0]);
  printf("   sin6 (%3d) = %.0E\n", aegsin[1], egsin[1]);
  printf("   sin7 (%3d) = %.0E\n", aegsin[2], egsin[2]);

  printf("greater errors for rcos:\n");
  printf("   cos5 (%3d) = %.0E\n", aegcos[0], egcos[0]);
  printf("   cos6 (%3d) = %.0E\n", aegcos[1], egcos[1]);
  printf("   cos7 (%3d) = %.0E\n", aegcos[2], egcos[2]);

  printf("\ngreater errors for osin:\n");
  printf("   sin5 (%3d) = %.0E\n", aegosin[0], egosin[0]);
  printf("   sin6 (%3d) = %.0E\n", aegosin[1], egosin[1]);
  printf("   sin7 (%3d) = %.0E\n", aegosin[2], egosin[2]);

  printf("greater errors for ocos:\n");
  printf("   cos5 (%3d) = %.0E\n", aegocos[0], egocos[0]);
  printf("   cos6 (%3d) = %.0E\n", aegocos[1], egocos[1]);
  printf("   cos7 (%3d) = %.0E\n", aegocos[2], egocos[2]);

  printf("\n\n");

  return 0;
}
