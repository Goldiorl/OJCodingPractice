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
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > p(n, vector<bool> (n,false) );
        //Initilized the f array with the worst case
        vector<int> f(n+1);  //needs to be f(n+1). Think about the "bb" case, which returns 0
        // instead of 1
        for ( int i =0 ; i <=n ;i ++ ){
            f[i] = n-i-1;
        } 

        //don't forget to update the one-cut case. That is j should start
        // from j=i
        p[n-1][n-1] = true;
        for ( int i = n-2; i >=0; i -- )
            for ( int j = i ; j<n; j ++){
                if( s[i] == s[j] && ( j-i <2 || p[i+1][j-1] ) ){
                    p[i][j] = true;
                    f[i] = min( f[i], f[j+1]+1); 
                }
            }
        return f[0];
    }
};
int main(){
    Solution sol;
    //TEST DATA
    string str = "aab";
    int n = sol.minCut(str);
    cout<<n<<endl;
    
}

