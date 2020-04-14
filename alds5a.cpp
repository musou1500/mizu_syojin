#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> solve(vector<int> &va) {
  set<int> ans;
  for (int i = 0; i < (1 << va.size()); i++) {
    int sum = 0;
    for (int j = 0; j < va.size(); j++) {
      if ((i >> j) & 1) {
        sum += va[j];
      }
    }

    ans.insert(sum);
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, q;
  cin >> n;
  vector<int> va(n);
  for (auto &a : va) {
    cin >> a;
  }

  cin >> q;
  vector<int> vm(q);
  for (auto &m : vm) {
    cin >> m;
  }

  set<int> nums = solve(va);
  for (auto &m : vm) {
    cout << (nums.count(m) > 0 ? "yes" : "no") << '\n';
  }
  return 0;
}
