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

  pair<vector<int>::const_iterator, vector<int>::const_iterator> range =
      equal_range(a.begin(), a.end(), 5, MyCompare1());

  if (range.first != range.second) {
    cout << "yes:" << range.second - range.first << endl;
  } else {
    cout << "no:" << endl;
  }
  return 0;
}