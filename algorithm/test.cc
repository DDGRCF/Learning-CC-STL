#include <iostream>
#include <iterator>

using namespace std;

int main() {
  deque<int> a(20);
  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
  cout << endl;
  cout << a[2] << endl;
  return 0;
}
