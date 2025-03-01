#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const auto simulate = [](bitset<5> a) { // bubbles pushed
    a = (a & (a >> 1));
    return bitset<5>(0b111) & (a | (a >> 1));
  };

  string s;
  while (cin >> s) {
    if ((int) s.size() == 5) cout << simulate(bitset<5>(s)).to_string().substr(2) << '\n';
    else {
      int ans = 0;
      for (int i = 0; i < (1 << 5); ++i)
        ans += (simulate(bitset<5>(i)) == bitset<5>(s));
      cout << ans << '\n';
    }
  }

  return 0;
}
