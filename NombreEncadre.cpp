#include <iostream>
using namespace std;

string aff(int n, int nc){
    if(nc == 0){
        return to_string(n);
    }else{
        return "[" + aff(n,nc-1) + "]";
    }
}

int main(){
    int n,nc;
    string ch;
    cin>>n>>nc;
    ch = aff(n,nc);
    cout<<ch;
}