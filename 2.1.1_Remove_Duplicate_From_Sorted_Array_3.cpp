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
    		firstPtr = find_if(firstPtr, last, bind1st(not_equal_to<int>(), *secondPtr));
    		*++secondPtr = *firstPtr;
    		
    	}
    	return distance(A, secondPtr); //Where is different from version 1
    }

};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {1,1,2};
    //Solve
    cout<<sol.removeDuplicates( test,3);

}

