#include <bits/stdc++.h>
#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    long long a[n], dp[n];
    long long s = 0;
    long long ss = 0;
    for(int i = 0; i<2; i++){
        cin >> a[i];
        s += a[i];
    }
    dp[2] = (a[0] * a[1]) % MOD;
    cin >> a[2];
    ss += (a[2] * dp[2]) % MOD;

    for(int i = 3; i<n; i++){
        cin >> a[i];
        dp[i] = ((a[i-1] * s) % MOD) + dp[i-1];
        dp[i] %= MOD; 
        ss += (a[i] * dp[i]) % MOD;
        s += a[i-1];
        s %= MOD;
    }

    cout << ss % MOD << endl;
}