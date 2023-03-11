#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare1 {
public:
  bool operator()(int i, int j) { return i > j; }
};

int main() {
  const int kNum = 10;
  srand(time(nullptr));
  vector<int> a(kNum, 0);
  for (int i = 0; i < a.size(); i++) {
    a[i] = rand() % 10;
  }
  sort(a.begin(), a.end(), MyCompare1()); // 从大到小的排序

  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  bool has_val = binary_search(a.begin(), a.end(), 3, MyCompare1());
  cout << (has_val ? "yes" : "no") << endl;

  return 0;
}