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
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for ( int i = 0; i < n/2; i ++)
            for ( int j = 0; j < n ; j ++)
                swap( matrix[i][j], matrix[n-i-1][j]);
                // this line was wrong for first a few times 

        for ( int i =0; i < n ; i ++)
            for ( int j = i+1; j< n; j++)
                swap( matrix[i][j], matrix[j][i]);
            
    }
};
int main(){
    Solution sol;
    //TEST DATA

    
}

