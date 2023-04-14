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

  cout << "unique: ";
  vector<int>::iterator it = unique(a.begin(), a.end());
  a.erase(it, a.end()); // unique不会删除元素而是把元素都移动到末尾
  copy(a.begin(), it, ostream_iterator<int>(cout, ","));
  cout << endl;

  return 0;
}
