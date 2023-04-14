#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  vector<string> names{"A1",   "Beth",   "Carol", "Dan",  "Eve",
                       "Fred", "George", "Harry", "Iain", "Joe"};
  unordered_set<string> more_names{"Janet", "John"};
  copy_n(begin(names), 4, std::inserter(more_names, end(more_names)));
  copy(more_names.begin(), more_names.end(),
       ostream_iterator<string>(cout, ","));
  return 0;
}
