const ll mod = 1e9;
ll power(ll n, ll x)
{
	if (x == 0) return 1;
	x = x % mod;
	int p = power(n, x / 2);
	if (x % 2 == 0)return ((p) % mod * (p) % mod) % mod;
	else return ((p) % mod * (p) % mod * (n) % mod) % mod;
}

ll hcf(ll a, ll b) {
	if (a ==  0) return b;
	return hcf(b % a, a);
}
ll lcm(ll a, ll b) {
	ll prod = a * b;
	return prod / (hcf(a, b));
}
vector<int>prime(100005, 1);
// //time  - > 0(sqrt(n))
bool isPrime() {
	int n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return n > 1;
}
//seive of eratothenis - >
void generateSieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= 100005; i++) {
		if (prime[i] % 2 == 1) {
			for (int j = i * i; j <= 100005; j += i) {
				prime[j] = 0;
			}
		}
	}
}
vector<int> factorize(int n) {
	vector<int>fact;
	fact.push_back(1);
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			fact.push_back(i);
			n /= i;
		}
	}
	if (n > 1)fact.push_back(n);
	return fact;
}
