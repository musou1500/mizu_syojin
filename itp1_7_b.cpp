#include <iostream>

using namespace std;

int solve(int n, int x) {
  int ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    for (int j = i + 1; j <= n - 1; j++) {
      for (int k = j + 1; k <= n; k++) {
        if (i + j + k == x) {
          ans++;
        }
      }
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, x;
  cin >> n >> x;
  while (n != 0 || x != 0) {
    cout << solve(n, x) << '\n';
    cin >> n >> x;
  }

  return 0;
}
