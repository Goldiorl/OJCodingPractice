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
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if ( m == 0 ) return 0; //in order to AC, need to include this ( stupid )
        int n = matrix[0].size();
        vector<int> l(n,0);
        vector<int> r(n,n); // no better values to initilize them
                            // think: why is n, instead of n-1
                            // left inclusive ; right exclusive
        vector<int> h(n,0); // pay attention, there are only n values in H

        int result = 0;
        int left = 0;
        int right = n;
        //left right are two pointers to exclude the non-one region.
        for(int i =0; i< m ; i ++){
            left = 0; right =n;
            for ( int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    l[j] = max(l[j], left);
                    h[j]++;
                }else
                {
                    //reset all 
                    left = j+1; h[j] = 0; l[j] = 0; r[j] = n;
                    //no better reset value because 
                    //if use l[j] = j+1; r[j] = j-1; there would be boundary problem
                    //the usage of h[] guarantees there would be no problems
                }
            }

            //think: the right can only be calculated from the right side
            for( int j = n-1; j>=0; j-- ){
                if(matrix[i][j] =='1'){
                    r[j] = min(r[j], right);
                    //if( j == (r[j]-1) || j == l[j]) //This sentence cannot be added: Think about if the boundary elemnt is
                    // in multiple rectangles, It will only calculate the tallest. So every element with an 1 needs to calculate
                    result = max( result, h[j]*(r[j]-l[j]));
                }else{
                    right = j; //think: left inclusive and right exclusive.
                }

            }
        }
        return result;
    }
};


int main(){
    Solution sol;
    //TEST DATA
    vector<char> f{'0', '1', '1', '1', '0', '0'};
    vector<char> s{'0', '1', '0', '1', '1', '0'};
    vector<vector<char> > matrix {f,s};
    int n = sol.maximalRectangle(matrix);
    cout<<n<<endl;
    
}

