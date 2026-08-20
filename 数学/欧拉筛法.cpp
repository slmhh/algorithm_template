#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10,mod = 1e9 + 7;

bitset<N> isprime;
vector<ll> prime;

void euler() {
    isprime.set();
    isprime[1] = 0;
    for (ll i = 2; i <= N; i++) {
        if (isprime[i]) prime.push_back(i);
        for (ll j = 0; j < prime.size() && i * prime[j] < N; j++) {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    euler();
    for (int i = 1; i < 10; i++) {
        cout << prime[i] << endl;
    }
	cout << "cnt = " << prime.size() << "\n";
    return 0;
}
