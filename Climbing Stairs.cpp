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
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if( n==0 ) return 0;
        if( n==1 ) return 1;
        if( n==2 ) return 2;
        int fn_2 = 1;
        int fn_1 = 2;
        int fn = 0;
        for( int i = 3; i<=n; i++ ){
            fn = fn_1+fn_2;
            fn_2 = fn_1;
            fn_1 =fn;
        }
        return fn;
    }
};
int main(){
    Solution sol;
    //TEST DATA
    string str = "aab";
    int n = sol.minCut(str);
    cout<<n<<endl;
    
}

