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

  cout << ((std::none_of(a.begin(), a.end(),
                         [](const int &x) { return 0 > x; }))
               ? "yes"
               : "no")
       << endl;
  cout << ((std::any_of(a.begin(), a.end(), [](const int &x) { return 5 > x; }))
               ? "yes"
               : "no")
       << endl;
  cout << ((std::any_of(a.begin(), a.end(), [](const int &x) { return 0 < x; }))
               ? "yes"
               : "no")
       << endl;

  cout << "There are " << std::count(a.begin(), a.end(), 5) << " people aged "
       << 5 << endl;

  cout << "There are "
       << std::count_if(a.begin(), a.end(), [](const int &x) { return x > 5; })
       << " people over " << 5 << endl;
  return 0;
}