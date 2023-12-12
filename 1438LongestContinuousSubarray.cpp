#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int d, i=0, j=0 , ans = 0;
        int b = 0;
        int n = nums.size();
        while(j < n){
            d = j-i+1;
            if (b == 0){
            st.insert(nums[j]);
            }
            if(*st.rbegin() - *st.begin() <= limit){
                j++;
                b = 0;
                if(d > ans){
                    ans = d;
                }
            }else{
                st.erase(st.find(nums[i]));
                i++;
                b = 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {10,1,2,4,7,2};
    Solution sl;
    int limit = 5;
    cout << sl.longestSubarray(nums,limit);
    return 0;
}