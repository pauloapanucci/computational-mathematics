.PHONY: conversion sincos

all: conversion sincos

conversion:
	gcc -std=c99 -lm test_conversion.c -o test_conversion
	./test_conversion

sincos:
	gcc -std=c99 -lm test_sincos.c -o test_sincos
	./test_sincos
