#include <bits/stdc++.h>
#define ll long long
#define MAXN 30005
using namespace std;

struct People{
    int id, salary, height;

    People(){}

    People(vector<int>& v){
        id = v[0];
        salary = v[1];
        height = v[2];
    }

    People(int _id, int _salary, int _height){
        id = _id;
        salary = _salary;
        height = _height;
    }

    bool operator>(const People& p) const{
        // order by salary, then height
        if(salary != p.salary){
            return salary > p.salary;
        }else{
            return height > p.height;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    People p[MAXN];
    int boss[MAXN], employee[MAXN];
    int test,n,q;

    cin >> test;
    while(test--){
        cin >> n >> q;
        fill_n(boss, n, -1);
        fill_n(employee, n, 0);
        int id, salary, height;
        for(int i = 0; i < n; i++){
            cin >> id >> salary >> height;
            p[i] = People(id, salary, height);
        }
        sort(p, p + n, greater<People>());

        for(int i = 1; i<n; i++){
            int j = i-1;
            while(j >= 0){
                if(p[j].height >= p[i].height){
                    boss[i] = j;
                    break;
                }
                j--;
            }
            
        }

        for(int i = n-1; i>=0; i--){
            if(boss[i] >= 0){
                employee[boss[i]] += 1 + employee[i];
            }
        }

        map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            int b = 0;
            if(boss[i] >= 0){
                b = p[boss[i]].id;
            }
            mp[p[i].id] = {b, employee[i]};
        }

        for(int i = 0; i < q; i++){
            int id;
            cin >> id;
            auto it = mp.find(id);
            if(it == mp.end()){
                cout << "0 0" << endl;
            }else{
                cout << it->second.first << " " << it->second.second << endl;
            }
        }
    }
    return 0;
}