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

  sort(a.begin(), a.end());
  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  cout << "remove: ";
  vector<int> b;
  remove_copy(a.begin(), a.begin() + 3, back_inserter(b), 2);
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  copy(b.begin(), b.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  return 0;
}
