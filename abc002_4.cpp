#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> v_xy(n, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    v_xy[x] |= (1 << y);
    v_xy[y] |= (1 << x);
  }

  for (int i = 0; i < n; i++) {
    v_xy[i] |= (1 << i);
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    bool t = true;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) && (i & v_xy[j]) != i) {
        t = false;
        break;
      }
    }

    if (t) {
      ans = max(ans, static_cast<int>(bitset<20>(i).count()));
    }
  }

  cout << ans << '\n';
  return 0;
}

