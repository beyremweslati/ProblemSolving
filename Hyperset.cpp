#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1287/problem/B

string generate(string s1,string s2,int k){
    string res = "";
    for(int i=0;i<k;i++){
        if(s1[i] == s2[i]){
            res += s1[i];
        }else{
            if(s1[i] == 'S'){
                if(s2[i] == 'E')
                    res += 'T';
                else
                    res += 'E';
            }else if (s1[i] == 'T'){
                if(s2[i] == 'S')
                    res += 'E';
                else
                    res += 'S';
            }else{
                if(s2[i] == 'S')
                    res+= 'T';
                else
                    res+= 'S';
            }
        }
    }
    return res;
}



int main(){
    string tab[1500];
    vector<string> triplets;
    set<vector<string>> uniqueTriplets;
    set<string> sett;
    int n,k,s;
    cout << "Num of cards: ";
    cin >> n;
    cout << "Num of features: ";
    cin >> k;
    for(int i=0;i<n;i++){
        cin >> tab[i];
        sett.insert(tab[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string s1 = tab[i];
            string s2 = tab[j];
            string s3 = generate(s1,s2,k);
            if(sett.find(s3) != sett.end()){
                triplets.clear();
                triplets.push_back(s1);
                triplets.push_back(s2);
                triplets.push_back(s3);
                sort(triplets.begin(),triplets.end());
                uniqueTriplets.insert(triplets);
            }
        }
    }
    cout << "the number of ways to choose three cards that form a valid set = " << uniqueTriplets.size();
}