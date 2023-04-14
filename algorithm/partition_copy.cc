#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare {
public:
  bool operator()(int i) { return i % 2 == 0; }
};

int main() {
  const int kNum = 10;
  srand(time(nullptr));
  vector<int> a(kNum, 0);
  for (int i = 0; i < a.size(); i++) {
    a[i] = rand() % 10;
  }

  int b[10]{0};
  int c[10]{0};
  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  pair<int *, int *> bound =
      partition_copy(a.begin(), a.end(), b, c, MyCompare());

  copy(b, bound.first, ostream_iterator<int>(cout, ","));
  cout << endl;

  copy(c, bound.second, ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "######################################################" << endl;
  vector<int> d{1, 3, 5, 2, 4, 6};
  vector<int>::iterator iter =
      partition_point(d.begin(), d.end(), [](const int &i) { return i % 2; });
  copy(d.begin(), iter, ostream_iterator<int>(cout, ","));
  cout << endl;
  copy(iter, d.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  return 0;
}
