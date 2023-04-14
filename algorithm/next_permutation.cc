#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare1 {
public:
  bool operator()(const char &i, const char &j) { return i > j; }
};

int main() {
  string a = "123455678";
  string b = "556";
  auto it = find_end(a.begin(), a.end(), b.begin(), b.end());
  cout << *it << endl;
  it = find_end(a.begin(), a.end(), b.begin(), b.end(), MyCompare1());
  cout << *it << endl;

  return 0;
}
