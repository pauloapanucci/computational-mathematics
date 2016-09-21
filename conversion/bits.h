#include <stdio.h>

void printb_float(float val){
  unsigned int hack = *(unsigned int*)&val;
  unsigned int i = 1;
  for (i = i << 31; i != 0; i = i >> 1){
    char aux = (hack & i) > 0;
    printf("%d", aux);
    switch (i) {
      case 0x80000000:
      case 0x00800000:
        printf(" ");
      break;
    }
  }
}

void printb_double(double val){
  unsigned long long int hack = *(unsigned long long int*)&val;
  unsigned long long int i = 1;
  for (i = i << 63; i != 0; i = i >> 1){
    char aux = (hack & i) > 0;
    printf("%d", aux);
    switch (i) {
      case 0x8000000000000000:
      case 0x0010000000000000:
        printf(" ");
      break;
    }
  }
}
