#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class MyCompare1 {
 public:
  bool operator()(const char& i, const char& j) { return i > j; }
};

int main() {
  const char* url = "https://baidu.com";
  const char* stl = "stl";
  auto it = find_first_of(url, url + 27, stl, stl + 4);
  if (it != url + 27) {
    cout << *it << endl;
  }
  it = find_first_of(url, url + 27, stl, stl + 4, MyCompare1());
  if (it != url + 27) {
    cout << *it << endl;
  }
  return 0;
}