#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int operation(int a,int b,char op){
        if(op == '+'){
            return a+b;
        }else if (op == '-'){
            return a-b;
        }else if (op == '*'){
            return a*b;
        }else{
            return trunc(a/b);
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
                if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(operation(b,a,tokens[i][0]));
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();      
    }
};

vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
int main(){
    Solution sol = Solution();
    int res;
    res = sol.evalRPN(v);
    cout << res;
}