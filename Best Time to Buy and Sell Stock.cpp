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
        int n = prices.size();
        if ( n == 0 ) return 0;
        //This sentence and the return should be typed at the first place
        int currentMax = INT_MIN;
        int currentLow = INT_MAX ;
        for ( auto i : prices){
            if(i < currentLow ) currentLow = i;
            currentMax = max(currentMax, i-currentLow);
        }
        return currentMax;
    }
};

int main(){

    
}

