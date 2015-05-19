#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int length = num.size();
        int closest = 0;
        int min_gap = INT_MAX;
        for ( auto i = num.begin(); i < num.end(); i= upper_bound(i, num.end(),*i)){
            //here better use i< prev( `num.end(), 2)
            auto first = i+1;
            auto last = num.end()-1;
            int value = 0;
            int gap = 0;
            while( first < last  ){
                value = *first+*last+*i;
                if(value == target ) return value;
                if(value < target ) first++;
                //here can enhance: upper_bound
                else last--;
                //use upper_bound to accelerate
                gap = abs( value - target);
                if(gap < min_gap) { 
                    min_gap=gap;
                    closest = value;
                }
            }
        }
        return closest;
    }
};
int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {-1, 2, 1, -4};
    //Solve
    vector<int> testVector(test,test+4);
    int n= sol.threeSumClosest(testVector,1);
   	cout<<n<<endl;
    
}

