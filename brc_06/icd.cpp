#include <bits/stdc++.h>
#define MOD 1000000007
#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, a, c;
    c = 0;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a;
        a += c;
        c += a / (n-i);
        a %= (n-i);
        cout << a << " ";
    }
    cin >> a;
    a += c;
    cout << a << endl;
}