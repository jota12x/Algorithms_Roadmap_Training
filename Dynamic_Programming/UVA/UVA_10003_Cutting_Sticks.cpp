#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define f(i,a,b) for(int i = a ; i < b ; i++)
using namespace std;

int dp[52][52]={{0}},cuts[52];

int solve(aint start, int end){
  int minCost = 100000;
  if(start + 1 == end){
    return (dp[start][end] = 0);
  }
  if(dp[start][end]!=0){ //memoization step : it's not necesary to compute values that have been computed before
    return dp[start][end];
  }
  //Iterate through all posible cuts
  for(int i = start +1; i<end;i++){
    //cout<<"Solving for " << start << "-"<<end<<endl;
    minCost = min(minCost,solve(start,i) + solve(i,end) + (cuts[end] - cuts[start]));
  }
  dp[start][end] = minCost;
  return dp[start][end];
}
int main(){
  int l,n, minCost;
  /*Top down DYNAMIC PROGRAMMING*/
  while(cin >>l && l){

    //inicialization
    memset(dp,0, sizeof(dp));
    memset(cuts,0,sizeof(cuts));

    //Input reading
    cin>>n;
    cuts[0]=0;
    for(int i=1;i<n+1;i++){
      cin>>cuts[i];
    }
    cuts[n+1] = l;

    //Solving phase
    minCost = solve(0,n+1);
    cout<<"The minimum cutting is " <<minCost<<"."<<endl;
  }
}
