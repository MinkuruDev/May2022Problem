#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        pair<int, int> minn = {nums[0], 0}, maxx = {nums[0], 0};
        vector<pair<int, int>> vtmin, vtmax;
        vtmin.push_back(minn);
        vtmax.push_back(maxx);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] < minn.first){
                minn = {nums[i], i};
                vtmin.push_back(minn);
            }else if(nums[i] > maxx.first){
                maxx = {nums[i], i};
                vtmax.push_back(maxx);
            }else{
                if(minn.second < maxx.second){
                    return true;
                }
            }
        }
    }

    // lower_bound for vector of pair, compare second element
    int lower_bound(vector<pair<int, int>>& vt, int target) {
        int l = 0, r = vt.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (vt[mid].second < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

};

int main(){

    return 0;
}