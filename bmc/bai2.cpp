/*
    001000
    100111
    000001
    // xnor
    100000
*/

#include <bits/stdc++.h>

using namespace std;

string a[1005], x[1005];

string Xor(string a, string b){
    string res = "";
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) res += '0';
        else res += '1';
    }

    return res;
}

string Xnor(string a, string b){
    string res = Xor(a, b);
    int n = res.size();
    for(int i = 0; i < n; i++){
        if(res[i] == '0') res[i] = '1';
        else res[i] = '0';
    }
    return res;
}

int diff(string a, string b){
    int n = a.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) res++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string toxor(k, '1');
    //string bin;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x[i] = Xor(toxor, a[i]);
        //cout << x[i] << endl;
    }
    cout << endl;

    string res = x[0];
    for(int i = 1; i < n; i++){
        cout << res << endl;
        res = Xnor(res, x[i]);
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        int x = diff(res, a[i]);
        ans = max(ans, x);
    }
    
    cout << ans << endl;

    return 0;
}