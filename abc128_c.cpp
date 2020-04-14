#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> lamps(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      s--;
      lamps[i].push_back(s);
    }
  }

  vector<int> vp(m);
  for (int i = 0; i < m; i++) {
    cin >> vp[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    bool on = true;
    bitset<10> bs(i);
    for (int j = 0; j < lamps.size(); j++) {
      // j個目の電球がつくかどうか．．．．
      int cnt = 0;
      for (int k = 0; k < lamps[j].size(); k++) {
        if ((i >> lamps[j][k]) & 1) {
          cnt++;
        }
      }

      if (cnt % 2 != vp[j]) {
        on = false;
        break;
      }
    }

    if (on) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}
