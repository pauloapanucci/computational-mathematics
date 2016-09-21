#include "conversion/bits.h"
#include "conversion/hex.h"

double PI = 3.1415926535897932;

int main(){

  printf("\nTESTING CONVERSION\n");

  printb_double(PI);
  printf("\n");
  printb_float(0.5);
  printf("\n");
  printh_float(0.5);
  printf("\n");
  printh_double(0.5);
  printf("\n");
  
  printf("\n\n");

  return 0;
}
