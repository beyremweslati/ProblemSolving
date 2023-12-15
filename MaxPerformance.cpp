#include <bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans = 0;
        if(k == 1){
            for(int i=0;i<n;i++){
                ans = ans > (speed[i] * efficiency[i]) ? ans : speed[i] * efficiency[i]; 
            }
            return ans;
        }

        vector<pr> v;
        for(int i =0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end(), greater<pr>());

        k--;
        priority_queue<int, vector<int> , greater<int>> pq;
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long sp = v[i].second;
            long long eff = v[i].first;
            ans = max(ans , eff * (sp+sum));
            if(pq.size() < k){
                pq.push(sp);
                sum += sp;
            }else if(pq.top() < sp){
                    sum -= pq.top();
                    sum += sp;
                    pq.pop();
                    pq.push(sp);
            }
        }
        int m = 1e9+7;
        return ans % m;
    }
};

int main (){
    Solution sol;
    vector<int> speed = {2,10,3,1,5,8};
    vector<int> efficiency  = {5,4,3,9,7,2};
    int k = 2;
    int n = 6;
    cout << sol.maxPerformance(n,speed,efficiency,k);
    return 0;
}