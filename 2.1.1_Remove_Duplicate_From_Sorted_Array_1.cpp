#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if( n == 0 ) return 0;
    	int* firstPtr=A; int *secondPtr=A;
    	int* last = std::next( A, n);
    	while( firstPtr != last ){
    		if ( *firstPtr != *secondPtr ){
    			*++secondPtr = *firstPtr;
    		}
    		firstPtr++;
    	}
    	return distance(A, secondPtr)+1; //Forget+1 for the first time
    }

};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {1,1,2};
    //Solve
    cout<<sol.removeDuplicates( test,3);

}

