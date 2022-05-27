/***************************************************\
*                                                   *
*   000   000       111        00000       11111    *
*   0000 0000      11 11       00  00     11        *
*   00 000 00     11   11      00000       11111    *
*   00     00    111111111     00  00          11   *
*   00     00   11       11    00   00     11111    *
*                                                   *
\***************************************************/

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define mod 1000000007
#define MAXN 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int main(){
    fast_io;
    int n;
    cin >> n;
    double a[n];
    double prefixSum[n];
    cin >> a[0];
    prefixSum[0] = a[0];
    fow(i,1,n){
        cin >> a[i];
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    double avg = prefixSum[n-1]/n;
    fow(i,0,n){
        a[i] -= avg;
    }
    // find max sum subarray in a[1..n-2]
    double maxSum = -1e9, curSum = 0;
    int start = 1, end = 1, maxStart = 1, maxEnd = 1;
    fow(i,1,n-1){
        curSum += a[i];
        if(curSum > maxSum){
            maxSum = curSum;
            end = i;
            maxStart = start;
            maxEnd = end;
        }
        if(curSum < 0){
            curSum = 0;
            start = i+1;
        }
    }
    double newAvg = prefixSum[n-1] - (prefixSum[maxEnd] - prefixSum[maxStart-1]);
    newAvg /= n - (maxEnd - maxStart + 1);
    cout << fixed << setprecision(3) << newAvg << endl;

    return 0;
}
