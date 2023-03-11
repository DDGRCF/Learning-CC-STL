#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare1 {
 public:
  bool operator()(const char& i) { return i == '5'; }
};

int main() {
  string a = "1234556";
  auto it = find(a.begin(), a.end(), '2');
  cout << *it << endl;

  it = find_if(a.begin(), a.end(), MyCompare1());
  cout << *it << endl;

  return 0;
}