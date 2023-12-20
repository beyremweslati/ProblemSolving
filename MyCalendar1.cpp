#include <bits/stdc++.h>
using namespace std;
class MyCalendar {
private:
    vector<vector<int>> time;
public:
    MyCalendar() {
        time = {};
    }
    
    bool book(int start, int end) {
        for(int i=0;i<time.size();i++){
            if(!((start <= time[i][0] && end <= time[i][0]) || (start >= time[i][1] && end >= time[i][1]))){
                return false;
            }
        }
        time.push_back({start,end});
        return true;
    }
};

int main() {
    MyCalendar obj;
    cout << obj.book(10, 20);
    cout << obj.book(15, 25);
    cout << obj.book(20,30);
}