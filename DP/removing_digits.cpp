#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
vector<int> digit(int n){
    vector<int> ans;
    while(n>0){
        if (n % 10 != 0) ans.push_back(n % 10);
        n=n/10;
    }
    return ans;
}
vector<int> dp;

int f(int n){
    if (n == 0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int> d=digit(n);
    int x= INT_MAX;
    for(int i=0;i<d.size();i++) x=min(x,f(n-d[i]));
    return dp[n]=1+ x;
}
int main() {
    int x;
    cin>>x;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<f(x);
  return 0;
}