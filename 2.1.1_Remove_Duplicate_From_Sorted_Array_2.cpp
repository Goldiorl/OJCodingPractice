#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        distance( unique( A, A+n ), A );
    }
};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {1,1,2};
    //Solve
    cout<<sol.removeDuplicates( test,3);

}

