#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<long long>> scores(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> scores[i][j];
    }
  }

  long long ans = 0;
  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
      long long sum = 0;
      for (int k = 0; k < n; k++) {
        sum += max(scores[k][i], scores[k][j]);
      }

      ans = max(sum, ans);
    }
  }

  cout << ans << '\n';

  return 0;
}
