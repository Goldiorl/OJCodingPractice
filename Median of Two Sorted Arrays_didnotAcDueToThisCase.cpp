#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	int half = (m+n)/2;
    	if( (m^n)&1 ){
    		return (double)(find_kth(A,m,B,n,half+1));
    	}else{
    		return (find_kth(A,m,B,n,half+1)+find_kth(A,m,B,n,half));
    	}
    }
private:
	int find_kth(int A[], int m, int B[], int n, int k){
		//k > m+n
		if (m >n ) return find_kth( B, n, A, m,k);
		//Termination
		//if m = 0, 
		if ( m == 0 ) return B[k-1];
		if ( k == 1 ) return min(A[0], B[0]); //Pay attention, K is the "Kth"
		// if k =0 
		int half = k/2;
		int numA = min(m, half);
		int numB = k-numA;
		if( A[numA-1] < B[numB] ){
			find_kth( A+numA, m-numA, B, n, k-numA);
		}
		else if ( A[numA-1] < B[numB] ){
			find_kth( A,m, B+numB, n-numB, k-numB);
		}else
			return A[numA-1];


	}
};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {1,2};
    int test2[] = {1,2};
    //Solve
    double n = sol.findMedianSortedArrays(test,2,test2,2 );
    cout<<n<<endl;
}

