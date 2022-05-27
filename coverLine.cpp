#include <bits/stdc++.h>

using namespace std;

struct Line{
    int start, end;
    int index;

    bool operator<(const Line& other) const{
        if(start == other.start){
            return end < other.end;
        }
        return start < other.start;
    }
};
Line lines[1000];
int ans[1000];

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i<n; i++){
        cin >> lines[i].start >> lines[i].end;
        lines[i].index = i+1;
    }

    sort(lines, lines+n);
    if(lines[0].start > a){
        cout << -1 << "\n";
        return 0;
    }
    
    int i = 0, k = 0;
    int maxEndIndex = 0;
    int start = lines[0].start;
    int end = a;

    while(i<n){
        while(i < n){
            if(lines[i].start > end){
                break;
            }
            if(lines[i].end > lines[maxEndIndex].end){
                maxEndIndex = i;
            }
            i++;
        }

        if(lines[maxEndIndex].end <= end){
            cout << -1 << "\n";
            return 0;
        }

        ans[k] = lines[maxEndIndex].index; k++; 
        start = lines[maxEndIndex].start;
        end = lines[maxEndIndex].end;
        if(end >= b) break;
        i = maxEndIndex;
    }

    if(end < b){
        cout << -1 << "\n";
        return 0;
    }

    cout << k << "\n";
    for(int i = 0; i<k; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
    