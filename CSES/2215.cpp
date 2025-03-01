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

  int t;
  cin >> t;

  while (t --> 0) {
    int n, k;
    cin >> n >> k;

    if (k * k < n) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    for (int i = k; i >= 1; --i)
      for (int j = i; j <= k * k and j <= n; j += k)
        cout << j << ' ';
    cout << '\n';
  }

  return 0;
}
