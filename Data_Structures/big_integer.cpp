// Code originally posted in http://codeforces.com/blog/entry/16380
// I only adapt it for supporting negatives
// All credits to its author
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
//#include <bits/stdc++.h>

using namespace std;
//typedef int64_t ll;
typedef long long ll;
typedef vector<int> BigInt;
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define EL printf("/n")

void Set(BigInt &a){
    while(a.size()>1 && a.back() == 0){
        a.pop_back();
    }
}


//utilitary function for handling the loop
BigInt sumUtil(BigInt a,BigInt b){
    BigInt result;
    int carry = 0,j=0;
    j = b.size()-1;
    FORD(i,a.size()-1,0){
        if(j>=0){
            int sum = b[j]+a[i]+carry;
            if(sum>10){
                carry = sum/10;
                sum=sum %10;
            }
            result.insert(result.begin(),sum);
            if(i==0 && carry!=0){
                result.insert(result.begin(),carry);
            }
            j--;
        }else{
            result.insert(result.begin(),a[i]);
        }
    }
    return result;
}

//positive numbers
BigInt sum(BigInt a, BigInt b){
    BigInt result;
    if(a.size()>=b.size()){
        result = sumUtil(b,a);
    }else{
        result = sumUtil(a,b);
    }
    return result;

}



BigInt Integer(string number){
    BigInt a;
    bool negative=false;
    int limit = 0;
    //std::cout << number << "\n";
    if(number.size()==0){
        a.push_back(0);
        return a;
    }

    if(number[0]=='-'){
        negative=true;
        limit=1;
    }
    //cout<<number<<endl;
    for(int i =number.size()-1 ; i>=limit;i--){
        a.insert(a.begin(),number[i]-'0');
    }
    if(negative){
        a[0]*=-1;
    }
    return a;
}

BigInt Integer(ll number){
    int it = 10;
    string s="";
    bool negative = false;

    //check if the number is negative first
    if(number<0){
        negative = true;
        number *= -1;
    }

    if(number<=9){
        char digit  = (number + '0');
        s = digit + s;
    }

    // std::cout << number << "\n";
    while(number>=10){
        char digit_char;
        int digit = number%it;
        //transform digit to char
        digit_char = digit + '0';
        //add digit to string
        s = digit_char + s;
        //divide number by 10
        number = number/it;
        //last case
        if(number <10){
            digit = number %it;
            digit_char = digit + '0';
            s = digit_char + s;
            //s = digit + s;
        }
        //it*=10;
    }

    if(negative){
        s = '-' + s;
    }

    // std::cout << s << "\n";
    return Integer(s);
}

bool operator <(BigInt a, BigInt b){
    if(a.size()!=b.size()){
        return(a.size()<b.size());
    }
    FORD(i,a.size()-1,0){
        if(a[i]!=b[i]){
            return(a[i]<b[i]);
        }
    }
    return false;
}

bool operator >(BigInt a, BigInt b){
    return (b<a);
}

bool operator ==(BigInt a, BigInt b){
    return(!(a<b) && !(b<a));
}



void printBigInt(BigInt a){
    //Set(a);
    //printf("%d", (a.size() == 0) ? 0 : a.back());
    for(int i=0;i<a.size();i++){
        //std::cout << a[i];
    }
    //std::cout <<endl<< "finished" << "\n";
}

int main(){
    ll a = 12313213123122;
    ll b = 3123123123123;
    //string number = "-102301023010331312313211231";
    BigInt aBig = Integer(a);
    BigInt bBig = Integer(b);
    printBigInt(aBig);
    printBigInt(bBig);
    BigInt result = sum(aBig,bBig);
    if(aBig<bBig){
        std::cout << "b es mayor" << "\n";
    }else{
        std::cout << "a es mayor" << "\n";
    }
    printBigInt(result);
}
