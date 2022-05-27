#include <bits/stdc++.h>
#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        long long m,n;
        cin >> n >> m;
        long long pra = 1ll * m*(m-1) + m - 2;
        //dbg(pra);
        pra %= MOD;

        long long ans = 1ll * pra * n;
        ans %= MOD;
        ans += n + 1;
        ans %= MOD;
        cout << ans << endl;
    }
    
    return 0;
}