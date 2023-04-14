#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<int> first = {5, 10, 15, 20, 25};
  vector<int> second = {7, 17, 27, 37, 47, 57};
  vector<int> vc(first.size() + second.size());
  merge(first.begin(), first.end(), second.begin(), second.end(), vc.begin());
  copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, ", "));
  inplace_merge(first.begin(), first.begin() + 3, first.end());
  return 0;
}