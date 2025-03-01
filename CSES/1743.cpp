#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  vi cnt(26);
  for (char c : s) cnt[c - 'A'] += 1;

  for (int c : cnt)
    if (c > (sz(s) + 1) / 2) {
      cout << -1 << '\n';
      exit(0);
    }

  int last = -1;
  rep (i, 0, sz(s)) {
    auto it = max_element(all(cnt));
    if (*it > (sz(s) - i) / 2)
      last = (int) (it - begin(cnt));
    else {
      rep (c, 0, 26) if (cnt[c] > 0 and c != last) {
        last = c;
        break;
      }
    }
    cnt[last] -= 1;
    cout << char('A' + last);
  }
  cout << '\n';

  return 0;
}
