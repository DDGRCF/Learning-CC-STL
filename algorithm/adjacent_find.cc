#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare {
 public:
  bool operator()(const int& lhs, const int& rhs) { return lhs == rhs; }
};

int main() {
  srand(time(nullptr));
  vector<int> a(10, 0);
  for (int i = 0; i < a.size(); i++) {
    a[i] = rand() % 10;
  }

  copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  auto it = adjacent_find(a.begin(), a.end());
  if (it != a.end()) {
    cout << "first: " << *it << endl;
  }

  it = adjacent_find(++it, a.end(), MyCompare());
  if (it != a.end()) {
    cout << "two: " << *it << endl;
  }

  return 0;
}