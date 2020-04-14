#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> m;
  vector<pair<int, int>> coords1(m);
  for (auto &c : coords1) {
    cin >> c.first >> c.second;
  }

  cin >> n;
  vector<pair<int, int>> coords2(n);
  for (auto &c : coords2) {
    cin >> c.first >> c.second;
  }

  sort(coords1.begin(), coords1.end());
  sort(coords2.begin(), coords2.end());

  auto min_c = coords1[0];
  vector<pair<int, int>> dists(m - 1);
  transform(coords1.begin() + 1, coords1.end(), dists.begin(),
            [&](auto &c) -> pair<int, int> {
              return {min_c.first - c.first, min_c.second - c.second};
            });

  auto ans = find_if(coords2.begin(), coords2.end(), [&](auto &c) {
    return all_of(dists.begin(), dists.end(), [&](auto &dist) {
      pair<int, int> p{c.first - dist.first, c.second - dist.second};
      return binary_search(coords2.begin(), coords2.end(), p);
    });
  });

  cout << ans->first - min_c.first << ' ' << ans->second - min_c.second << '\n';
  return 0;
}
