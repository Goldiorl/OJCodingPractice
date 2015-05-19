#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> checked;
        for (auto i : num ) {checked[i] = false;} //need to loops. inevitable
        int cachedLength = 0;
        for (auto i:num){
            int length = 1;
            if ( checked[i] == true ) continue; // to avoid duplication
            checked[i] = true;
            for (int j = i+1; checked.find(j) != checked.end();j++ ){
                checked[j] = true;
                length++;
            }
            for( int j = i-1; checked.find(j) != checked.end(); j--){
                checked[j] = true;
                length++;
            }
            cachedLength = max (cachedLength, length);
        }        
        return cachedLength;
    }
};

int main(){
    Solution sol;
    
    //TEST DATA
    int test[] = {100, 4, 200, 1, 3, 2};
    vector<int> testVector (test, test+6);
    //Solve
    int n = sol.longestConsecutive(testVector);
    cout<<n<<endl;
}

