#include<iostream>
#include<string.h>
using namespace std;

const int N = 100000;

bool isprime[N + 10];
int prime[N + 10], cnt = 0, temp;

void eular() {
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    eular();
    for (int i = 1; i < 10; i++) {
        cout << prime[i] << endl;
    }

    return 0;
}
