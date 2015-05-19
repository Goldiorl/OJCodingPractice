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
     int result =0 ;
     int n = prices.size();
     if ( n == 0 )  return 0;
     int prev = prices[0];
     //For the first time should concider here to be initialized to be 0;
     for (int i : prices){
         if ( i-prev > 0 ){
             result+=i-prev;
         }
         prev = i;
     }
     return result;
    }
};

int main(){

    
}

