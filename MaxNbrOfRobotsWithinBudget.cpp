#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        multiset<int, greater<int>> sl;
        int i = 0,j = 0;
        long long k,mx, ans = 0, sum = 0; 
        while(j< chargeTimes.size()){
            k = j - i + 1;
            mx = !sl.empty() ? (*sl.begin() > chargeTimes[j] ? *sl.begin() : chargeTimes[j]) : chargeTimes[j];
            if(mx + k * (sum + runningCosts[j]) > budget){
                ans = ans > k-1 ? ans : k-1;
                if(!sl.empty()){
                    sl.erase(sl.find(chargeTimes[i]));
                    sum -= runningCosts[i];
                }
                i++;
                j = i > j ? i : j;
            }else{
                sl.insert(chargeTimes[j]);
                sum += runningCosts[j];
                j++;
                if(j == chargeTimes.size()){
                    ans = ans > k ? ans : k; 
                }
            }
        }
        return ans;
    }
};

vector<int> ChargeTimes = {3,6,1,3,4};
vector<int> RunningCosts = {2,1,3,4,5};

int main(){
    Solution sol;
    long long budget = 25;
    int res = sol.maximumRobots(ChargeTimes, RunningCosts , budget);
    
    cout << res;
    return 0;
}