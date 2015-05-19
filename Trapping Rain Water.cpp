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
    int trap(int A[], int n) {
        stack<int> stk;
        int rainAccu = 0;
        
        if ( n <2 ) return 0;

        // //sequeeze leading zeros
        // int leading_index = 0;
        // while ( A[leading_index] == 0 ) leading_index++;

        // stk.push( leading_index++ );
        stk.push( 0 );
        for ( int i = 1; i <n; i ++){
            if( A[i] > A[ stk.top() ] ){
                int popValue = 0;
                while ( !stk.empty() && A[i] > A[ stk.top() ]){
                    popValue = stk.top();
                    stk.pop();
                    if( !stk.empty() )
                    rainAccu += (i - stk.top() -1 ) * ( min( A[stk.top()], A[i] ) - A[popValue] );
                //First errors come from deciding whether pushing the latest index to the stack.
                //also pay attention to the fact that 
                }
            }
            
            stk.push( i );
            
        }
    return rainAccu;
    }
};

int main(){
    Solution sol;
    //TEST DATA
    int test[] ={0,1,0,2,1,0,1,3,2,1,2,1};
    //Solve
    // vector<int> testVector(test,test+6);
    // for(auto i:testVector){
    //     cout<<i<<" ";
    // }    
    // cout<<endl;
    // sol.nextPermutation(testVector);
    // for(auto i:testVector){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    cout<<sol.trap(test,12)<<endl;
    
}

