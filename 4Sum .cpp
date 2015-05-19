#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        //would return error if here use the unordered_set
        set<vector<int> > result;
        sort(num.begin(), num.end());
        if(num.size()<4) return vector<vector<int> >();
        map<int, vector<pair<int,int> > > cache;
        for(size_t a=0; a<num.size()-3; a++ )
            for(size_t b=a+1; b<num.size()-2;b++)
                cache[num[a]+num[b]].push_back(pair<int,int>(a,b));

        for(size_t c =2; c<num.size()-1; c++)
            for(size_t d = c+1; d< num.size(); d++){
                int expectedValue = target - num[c] - num[d];
                if(cache.find(expectedValue)!=cache.end()){
                     auto vpair = cache[expectedValue];
                     for( auto i : vpair){
                        if ( i.second < c ){ //pay attention!! here is the index, not the value: c instead of num[c]
                            //also this line, value, not index!!
                            result.insert(vector<int> {num[i.first], num[i.second], num[c], num[d]});
                        }
                     }
                }
            }
        return vector<vector<int> > (result.begin(), result.end());
    }
};


int main(){
    Solution sol;
    //TEST DATA
    int test[] ={1, 0, -1, 0, -2, 2};
    //Solve
    vector<int> testVector(test,test+6);
    vector<vector<int> > n= sol.fourSum(testVector,0);
    cout<<"size is "<<n.size()<<endl;
   	for_each(n.begin(),n.end(), [&](vector<int> vec){
        for( auto i : vec)
            cout<<i<<" ";
        cout<<endl;
    });
    
}

