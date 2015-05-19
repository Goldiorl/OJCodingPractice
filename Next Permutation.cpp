#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;


//this problem can be used to practice reverse iterator
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        //also can be written as 
        //vector<int>::reverse_iterator rfirst = reverse_iterator<vector<int>::iterator>(num.end());
        //vector<int>::reverse_iterator rfirst = num.rbegin();
        auto rfirst = num.rbegin();
        auto rlast = num.rend();
        while ( rfirst != prev(rlast) && *rfirst <= *next(rfirst) ) {
            //for example like {1,5,5,4,3}, we want the first 5.
            rfirst++;
        }

        if( rfirst == prev(rlast) ){
            reverse(num.begin(), num.end());
            return;
        }else{
            auto pivotNext = next(rfirst);
            //remember how to use reverse on reverse iterator
            auto firstNum = upper_bound( num.rbegin(), pivotNext, *pivotNext);
            //use upper because of examples like {5,7,5,4,3} (next is 7,3,4,5,5)
            swap( *firstNum, *pivotNext); 
            reverse( num.rbegin(), pivotNext );
            //midtake made in first time: use rfirst to replace num.rbegin();
        }
    }
};

int main(){
    Solution sol;
    //TEST DATA
    int test[] ={6,8,7,4,3,2};
    //Solve
    vector<int> testVector(test,test+6);
    for(auto i:testVector){
        cout<<i<<" ";
    }    
    cout<<endl;
    sol.nextPermutation(testVector);
    for(auto i:testVector){
        cout<<i<<" ";
    }
    cout<<endl;
    
}

