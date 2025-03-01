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

  ll n;
  cin >> n;

  ll ans = 0;
  for (ll l = 2; l / 2 <= n; l *= 2) {
    ans += (l / 2) * ((n + l - 1) / l);
    ans -= (n % l == 0 ? 0 : min(l - 1 - n % l, l / 2));
  }

  cout << ans << '\n';

  return 0;
}
