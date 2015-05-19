#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //major error:
        //Forgot curRightHigh -;
        //forgot to use prices[i] instead of i; 
        int n = prices.size();
        if (n == 0 ||n==1 ) return 0;
        int result = 0;//TODO
        vector<int> left(n,0);
        vector<int> right(n,0);
        int curLeftLow = prices[0];
        left[0] = 0;
        right[n-1] = 0;
        int curRightHigh = prices[n-1];
        for( int i = 1; i<n; i++ ){
            left[i]= max(prices[i]-curLeftLow,left[i-1]);
            if( prices[i] < curLeftLow ) curLeftLow = prices[i];
        }
        
        for( int i = n-2; i>=0; i--){
            right[i] = max(curRightHigh-prices[i],right[i+1]);
            if( prices[i] > curRightHigh) curRightHigh = prices[i];
        }
        
        for( int i = 0 ; i<n; i++){
            result = max( result, left[i]+right[i]);
        }
        return result;
    }
};
int main(){

    
}

