#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int lli;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> v;
typedef vector<vector<int>> v2;
const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const ll maxn = 1e5 + 1;
const ll inf = 5e18;
const ll minf = -inf;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define fastread()                  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define f                           first
#define s                           second
#define mp                          make_pair
#define pb                          push_back
int sieve[100005];
void generateSieve() {
    for (int i = 2; i <= 100004; i++) sieve[i] = 1;
    for (int i = 2; i * i <= 100004; i++) {
        if (sieve[i] == 1) {
            for (int j = 2 * i; j <= 100004; j += i) {
                sieve[j] = 0;
            }
        }
    }
}
/********************************************************************************************
*********************************************************************************************
*********************************************************************************************
*********************************************************************************************/
void solve() {
    ll a, b, c, d, e, f;
    
}

signed main() {
    fastread();
#ifdef prabhat78
    clock_t tStart = clock();
#endif

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }
#ifdef prabhat78
    fprintf(stderr, "\n>> Runtime: %.10fs\n",
            (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
}
