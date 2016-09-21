#include <stdio.h>

void printh_float(float val){
  unsigned char *hack = (unsigned int*)&val;
  printf("0x");
  for (int i = 3; i >= 0; i--){
    printf("%02X ", hack[i]);
  }
}

void printh_double(double val){
  unsigned char *hack = (unsigned int*)&val;
  printf("0x");
  for (int i = 7; i >= 0; i--){
    printf("%02X ", hack[i]);
  }
}
