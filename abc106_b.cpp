#include <iostream>

using namespace std;

bool cnt_divisor(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      cnt++;
    }

    if (cnt > 8) {
      return false;
    }
  }

  return cnt == 8;
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (cnt_divisor(i)) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}
