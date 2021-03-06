#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
using namespace std;


class Solution {
public:
//在中间没有重复的情况下,找到要不是 奇数的中点,要不就是偶数的中间两个的第二个,所以才有了upper_sum和low_sum用upperbound和lowerbound来判定的依据
//其实这种做法和放在一个数组里没区别啊!!!因为用了Upperbound, lowerbound,多个数组也一样
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	long long low = INT_MIN, high = INT_MAX, mid = 0, half = ( m + n )/2, low_sum, upp_sum;
    	for(; low <= high; mid = (low+high)/2 ){
	//for the first time upp_sum > half
    	 if((upp_sum = (upper_bound(A, A+m, mid)-A ) +(upper_bound(B, B+n, mid)-B))<=half ) low = mid +1;
    	 // for the first time low_sum <= half {for odd numbers,equal sign(=) means the only median} [due to half=(m+n)/2 is floored]
	 // equal sign is also useful for even number case, found the second
    	 else if ((low_sum = (lower_bound(A, A+m, mid) -A)+(lower_bound(B, B+n, mid) -B ))>half ) high = mid;
	//[left[ if it is odd, then low_sum = half renders the median    	 
	//[right] if low_sum < half and upp_sum < half, no matter odd or even, there are multiple values as median.
    	 else if((upp_sum > half && low_sum<half) || ((m^n)&1) ) return mid;
    	 // don't mess around the parenthesis between m and n.
    	 //so the last case is even number with non-identical median,
    	 //so mid would approach the second one, interestingly now it would be low_sum = half
    	 else break;
    	}
    	return (mid + 
	//The choice sentence is to detect the case the pointer -1 exceeded the front boundary
    	max( lower_bound(A,A+m,mid)==A ? INT_MIN: *(lower_bound (A, A+m, mid)-1), 
    	lower_bound(B, B+n, mid)==B? INT_MIN:*(lower_bound(B,B+n,mid)-1 ))) /2.0;
    }
};
int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {3,4};
    int test2[] = {};
    //Solve
    double n = sol.findMedianSortedArrays(test,2,test2,0 );
    cout<<n<<endl;
}

