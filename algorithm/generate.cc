#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  const int kNum = 10;
  srand(time(nullptr));
  vector<int> a(kNum, 0);
  for (int i = 0; i < a.size(); i++) {
    a[i] = rand() % 10;
  }
  generate(a.begin(), a.end(), []() { return 0; });
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));

  return 0;
}
