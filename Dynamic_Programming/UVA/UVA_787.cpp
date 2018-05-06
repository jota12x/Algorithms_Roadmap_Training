#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long long ll;
typedef vector<int> BigInt;


int main(){
  string line;
  long long int dp[105][105];
  while(getline(cin,line)){
    vector<long long int> arr;
    string number;
    stringstream ss(line);
    memset(dp, 0, sizeof(dp[0][0]) * 105 * 105);
    while(ss>>number){
        if(number.compare("-999999") == 0){
            break;
        }
        arr.push_back(stoi(number));
    }

    long long int max_product = -999999;
    for(int i =0;i<arr.size();i++){
        dp[i][1] =  arr[i];
        max_product = max(dp[i][1],max_product);
    }
    for(int j=2;j<=arr.size();j++){
        for (int i = 0; i < arr.size(); ++i)
        {
            if(i+j>arr.size()){
                break;
            }
            dp[i][j] = arr[i+j-1] * dp[i][j-1];
            max_product = max(dp[i][j],max_product);
        }
    }

    cout<<max_product<<endl;
  }

}
