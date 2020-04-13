#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n;
  cin >> n;

  auto sum_dist = [](const vector<ll> &v) {
    ll ans = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      ans += abs(v[i] - v[i + 1]);
    }

    return ans;
  };

  vector<pair<ll, ll>> v_ab(n);
  vector<ll> v_pos;
  for (auto &ab : v_ab) {
    cin >> ab.first >> ab.second;
    v_pos.push_back(ab.first);
    v_pos.push_back(ab.second);
  }

  ll ans = -1;
  for (int i = 0; i < v_pos.size(); i++) {
    for (int j = 0; j < v_pos.size(); j++) {
      ll g1 = v_pos[i], g2 = v_pos[j];
      ll dist = 0;
      for (int k = 0; k < n; k++) {
        // g1 -> a -> b -> g2
        dist += sum_dist({g1, v_ab[k].first, v_ab[k].second, g2});
      }

      ans = ans < 0 ? dist : min(ans, dist);
    }
  }

  cout << ans << '\n';

  return 0;
}
