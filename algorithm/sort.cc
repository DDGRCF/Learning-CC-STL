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
  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  sort(a.begin(), a.end(), greater<int>());  // 从大到小的排序
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  partial_sort(a.begin(), a.begin() + 3, a.end(), less<int>());
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  int tmp[3];
  partial_sort_copy(a.begin(), a.end(), tmp, tmp + 3, greater<int>());
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  copy(tmp, tmp + 3, ostream_iterator<int>(cout, ","));
  nth_element(a.begin(), a.begin() + 2, a.end());
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  return 0;
}