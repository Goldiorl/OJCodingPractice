#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        add(digits,1);
        return digits;
    }
private:
    void add(vector<int> &digits, int digit){
        int carry = digit;
        for_each(digits.rbegin(), digits.rend(), [&] (int & d){
           d+= carry;
           carry = d/10;
           d = d % 10;
        });
        if (carry >0 ) digits.insert( digits.begin(),carry);
    }
};
int main(){
    Solution sol;
    //TEST DATA

    
}

