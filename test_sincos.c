#include <stdio.h>
#include "sincos/sincos.h"

int main(){

  printf("\nTESTING SINCOS\n");

  FILE * data = fopen("sincos.dat", "w");
  for (int i = 0; i < 540; i++) {
    double nsin = fsin(i);
    double ncos = fcos(i);
    double realsin = sin(i * FA);
    double realcos = cos(i * FA);
    printf("ANGLE %3d; SIN = %.12lf; RSIN = %.12lf; ERR = %.12lf\n", i, nsin, realsin, realsin - nsin);
    fprintf(data, "%i\t%.12lf\t%.12lf\t%.12lf\t%.12lf\n", i, nsin, realsin, ncos, realcos);
  }
  fclose(data);

  printf("\n\n");

  return 0;
}
