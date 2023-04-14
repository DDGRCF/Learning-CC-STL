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
  vector<int> b(a.size(), 0);
  // vector<int> b(a.begin(), a.end());

  cout << "origin: ";
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;

  std::pair<vector<int>::iterator, vector<int>::iterator> out =
      mismatch(a.begin(), a.end(), b.begin(), b.end());
  if (out.first != a.end()) {
    cout << "Diffs between " << *out.first << " and " << *out.second << endl;
  } else {
    cout << "Equal" << endl;
  }
  return 0;
}
