#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> l1{1, 2, 3, 4};
  vector<int> l2{2, 3, 4, 5, 6};

  auto l1_begin = l1.begin();
  auto l1_end = l1.end();
  auto l2_begin = l2.begin();
  auto l2_end = l2.end();

  cout << boolalpha << equal(l1_begin, l1_end, l2_begin) << endl;
  cout << boolalpha << equal(l1_begin + 1, l1_end, l2_begin) << endl;
  cout << boolalpha << equal(l1_begin + 1, l1_end, l2_begin, l2_begin + 2)
       << endl;

  return 0;
}