#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        int i = 0;
        while(i < sentence.size() && s.size() < 26){
            s.insert(sentence[i]);
            i++;
        }
        return s.size() == 26;
    }
};