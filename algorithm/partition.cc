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

  vector<int> b(a.begin(), a.end());
  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  vector<int>::iterator bound = partition(a.begin(), a.end(), MyCompare());
  cout << "first group: " << endl;
  copy(a.begin(), bound, ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "second group: " << endl;
  copy(bound, a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "####################################" << endl;
  bound = stable_partition(b.begin(), b.end(), MyCompare());
  cout << "first group: " << endl;
  copy(b.begin(), bound, ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "second group: " << endl;
  copy(bound, a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  return 0;
}
