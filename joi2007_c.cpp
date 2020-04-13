#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<int, int>> coords(n);
  for (int i = 0; i < n; i++) {
    cin >> coords[i].first >> coords[i].second;
  }

  sort(coords.begin(), coords.end());

  auto search_coord = [&](pair<int, int> &coord) {
    return binary_search(coords.begin(), coords.end(), coord);
  };

  int max_area = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      // coords[i] < coords[j]
      auto &va = coords[i], &vb = coords[j];
      int dx = abs(vb.first - va.first), dy = abs(vb.second - va.second);

      pair<int, int> c1, c2, c3, c4;
      c1 = {va.first + dy, va.second + dx};
      c2 = {vb.first + dy, vb.second + dx};
      c3 = {va.first - dy, va.second - dx};
      c4 = {vb.first - dy, vb.second - dx};
      if ((search_coord(c1) && search_coord(c2)) ||
          (search_coord(c3) && search_coord(c4))) {
        max_area = max(max_area, dx * dx + dy * dy);
      }
    }
  }

  cout << max_area << '\n';

  return 0;
}
