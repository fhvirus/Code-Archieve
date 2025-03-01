#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Data {
  int val, sum, mnv, mxv;
  Data(int v) : val(v), sum(v), mnv(v), mxv(v) {}
  Data(int v, int s, int a, int b) :
    val(v), sum(s), mnv(a), mxv(b) {}
  Data operator + (const Data& o) const {
    return { 0, sum + o.sum, min(mnv + o.sum, o.mnv),
      max(mxv + o.sum, o.mxv) };
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  int t = (1 << (__lg(n) + ((n & (n - 1)) != 0)));
  vector<Data> data(t * 2, 0);
  for (int c, s, i = 0; i < n; ++i) {
    cin >> c >> s;
    c = c - 1 + t;
    data[c] = Data(s == 1 ? -1 : 1);
    for (c /= 2; c > 0; c /= 2)
      data[c] = data[c << 1] + data[c << 1 | 1];
    if (data[1].mxv <= 0) cout << ">\n";
    else if (data[1].mnv >= 0) cout << "<\n";
    else cout << "?\n";
  }

  return 0;
}
