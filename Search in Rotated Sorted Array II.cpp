#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    bool search( int A[], int n, int target){
        int * first = A;
        int * last = A+n;
        int * mid =nullptr;
        while( first != last ){
            mid = first + ( last - first )/2;
            if( *mid == target ) return true;
            if( *first < * mid ){
                if( target >= * first && target < *mid ){ // don't forget = sign to first
                    last = mid;
                }else{
                    first = mid+1;
                }
            }else if( *first > * mid){
                if( target < *first && target > *mid ){
                    first = mid +1;
                }else{
                    last = mid;
                }
            }else{
                first = next(first,1);
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {4,5,6,7,0,1,2};
    //Solve
    int n = sol.search( test,7,0);
    cout<<n<<endl;
}

