#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int ans = 0;
  string acgt = "ACGT";
  for (int i = 0; i < s.size(); i++) {
    int cnt = 0, j = i;
    while (acgt.find(s[j]) != string::npos) {
      j++;
      cnt++;
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}
