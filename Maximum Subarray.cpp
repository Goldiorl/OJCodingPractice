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
    int maxSubArray(int A[], int n) {
        // if ( n == 0 ) return 0;
        // if ( n == 1 ) return A[0];
        // int* f = new int[n];
        // f[0] = A[0];
        // for ( int i = 1; i < n; i ++){
        //     f[i] = f[i-1] >0 ? f[i-1]+A[i] : A[i];
        // }
        
        // int result = INT_MIN;
        // for (int i =0; i < n ; i++ ){
        //     if(f[i]> result ) result = f[i];
        // }
        // return result;
        //TOOOOOOO SLOW !!!! Two loops can be combined to one.
        int f = 0;
        int result = INT_MIN;
        //result should be a INT_MIN!! Very important
        for ( int i =0 ; i <n ; i ++){
            f = f>0 ? f+A[i]: A[i];
            if (f > result ) result = f;
        }
        return result;
    }
};
int main(){

    
}

