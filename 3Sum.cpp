#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int> > result;
    	if(num.size()<3) return result;
    	sort(num.begin(), num.end());
    	//decide to use iterator because can use binary search
    	for(auto a= num.begin(); a < prev( num.end(),2); a = upper_bound( a, prev(num.end(),2), *a) ){
       	//don't forget to prune duplicate result, using the upper_bound() routine.
       		for( auto b = next(a); b< prev(num.end()); b= upper_bound(next(a), prev(num.end()),*b) ){
       			int searchValue = 0 - *a-*b;
       			if(binary_search(next(b), num.end(),searchValue)){
       				result.push_back(vector<int> {*a,*b,searchValue});
       			}
       		}
       }
     }
};
int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {-1, 0, 1, 2, -1, -4};
    //Solve
    vector<int> testVector(test,test+6);
    vector<vector<int> > n= sol.threeSum(testVector);
    for( auto i : n){
    	for (auto j:i)
    		cout<<j<<" ";
    	cout<<endl;
    }
}

