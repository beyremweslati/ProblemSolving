#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> s;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*s.begin());
        int i = 0;
        int j = k;
        while(j<nums.size()){
            s.erase(s.find(nums[i]));
            s.insert(nums[j]);
            ans.push_back(*s.begin());
            j++;
            i++;
        }
        return ans;
    }
};

vector<int> nums = {1,3,-1,-3,5,3,6,7};
vector<int> ans;
int main(){
    Solution sol;
    int k = 3;
    ans = sol.maxSlidingWindow(nums,k);
    for(vector<int>::iterator it = ans.begin();it != ans.end(); it++){
        cout << *it << " | ";
    }
    return 0;
}
