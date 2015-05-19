#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

// class Solution {
// public:
//     int removeDuplicates(int A[], int n) {
//         if( n == 0 ) return 0;
//         int occur = 0;
//         int index = 0;
//         for (int i = 0; i < n; i++){
//         	if( A[index] != A[i] ){
//         		A[index++] = A[i];
//         		occur = 0;
//         	}else{
//         		if( occur <2 ){
//         			index++;
//         			occur++;
//         		}
//         	}
//         }
//         return index;
//     }
// };

//WA, for [1, 2, 2] the two pointers would move simultanously
//So force the first pointer to move faster than the index
// class Solution {
// public:
//     int removeDuplicates(int A[], int n) {
//         if( n == 0 ) return 0;
//         if( n == 1 ) return 1;
//         int occur = 0;
//         int index = 0;
//         for (int i = 1; i < n; i++){
//         	if( A[index] != A[i] ){
//         		A[++index] = A[i];
//         		occur = 0;
//         	}else{
//         		if( occur <1 ){
//         			index++;
//         			occur++;
//         		}
//         	}
//         }
//         return index+1;
//     }
// };
//This edition still has its problem in Line 42. Cannot just scape it, for example:
//[1,1,1,1,3,3] will become [1,1,3,1,]
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( n == 0 ) return 0;
        if( n == 1 ) return 1;
        int occur = 0;
        int index = 0;
        for (int i = 1; i < n; i++){
        	if( A[index] != A[i] ){
        		A[++index] = A[i];
        		occur = 0;
        	}else{
        		if( occur <1 ){
        			A[++index] = A [i];
        			occur++;
        		}
        	}
        }
        return index+1;
    }
};


//还有种奇妙的解法就是
// index = 0;
// for (int i = 0; i<n; ++i){
// 	if( i>0 && i< n-1 && A[i-1] == A[i] && A[i] == A[i+1]) continue;
// 	//Otherwise
// 	A[index++] = A[i]
// }


int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {1,1,1,2,2,3};
    //Solve
    int n = sol.removeDuplicates( test,6);
    cout<<n<<endl;
    for(int i=0; i<n;i++)
    	cout<<test[i];

}

