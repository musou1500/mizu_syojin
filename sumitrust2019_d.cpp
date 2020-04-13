#include <algorithm>
#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  array<vector<int>, 10> pos;
  for (int i = 0; i < s.size(); i++) {
    pos[s[i] - '0'].push_back(i);
  }

  long long ans = 0;
  for (int i = 0; i <= 999; i++) {
    stringstream ss;
    ss << setfill('0') << right << setw(3) << i;

    // num_sを作れるかどうか
    auto num_s = ss.str();
    int cur = -1;
    bool found = true;
    for (int i = 0; i < num_s.size(); i++) {
      auto &ch_pos = pos[num_s[i] - '0'];
      auto it = upper_bound(ch_pos.begin(), ch_pos.end(), cur);
      if (it == ch_pos.end()) {
        found = false;
        break;
      }

      cur = *it;
    }

    if (found) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}
