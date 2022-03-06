// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double num = value;
  for (uint16_t i = 1; i < n; i++) {
    num *= value;
  }
  if (n == 0) { 
    num = 1;
  }
  return num;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  double res = (pown(x, n) / (fact(n)));
  return res;
}

double expn(double x, uint16_t count) {
  double exp = 0;
  for (uint16_t i = 0; i <= count; i++) {
    exp += calcItem(x, i);
  }
  return exp;
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  for (uint16_t i = 1; i <= count; i++) {
    sin += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 0;
  for (uint16_t i = 1; i <= count; i++) {
    cos += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return cos;
}
