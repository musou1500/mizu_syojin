#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  long long ans = 0;
  if (c * 2 < a + b) {
    // ABピザを買うほうがお得
    ans = c * 2 * min(x, y);
    ans += x < y ? b * (y - x) : a * (x - y);
    ans = min(ans, c * 2 * max(x, y));
  } else {
    ans = x * a + y * b;
  }

  cout << ans << '\n';
  return 0;
}
