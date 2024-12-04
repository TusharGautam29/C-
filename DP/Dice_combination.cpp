#include <iostream>
#include <vector>
 
using namespace std;
vector<int> dp;
int f(int n){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int x=0;
    for(int i=1;i<=6;i++){
        if(n-i<0) break;
         x = (x + f(n - i)) % 1000000007;
    }
    return dp[n]=x;   
}
int main() {
    dp.clear();
    dp.resize(1000005,-1);
    int x;
    cin>>x;
    cout<<f(x);
  return 0;
}