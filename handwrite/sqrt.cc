#include <cmath>
#include <iostream>

double my_sqrt(double n, double eps) {
  double left = 0, right = n;
  double mid = 0, last = 0;

  do {
    if (mid > n / mid) {
      right = mid;
    } else {
      left = mid;
    }
    last = mid;
    mid = left + (right - left) / 2;
  } while (fabs(last - mid));
  return mid;
}

int main() {
  std::cout << my_sqrt(2, 1e-3) << std::endl;

  return 0;
}
