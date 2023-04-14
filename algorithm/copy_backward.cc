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

  a.resize(kNum * 2);
  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "copy: ";
  vector<int> b(a.begin(), a.end());
  copy(b.begin(), b.begin() + 6, b.begin() + 9);
  copy(b.begin(), b.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "copy backward: ";
  vector<int> c(a.begin(), a.end());
  copy_backward(c.begin(), c.begin() + 6, c.begin() + 9);
  copy(c.begin(), c.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "reverse copy: ";
  vector<int> d(a.size(), 0);
  reverse_copy(a.begin(), a.end(), d.begin());
  copy(d.begin(), d.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  return 0;
}
