class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for(auto rit = digits.rbegin(); rit != digits.rend(); rit++){
            *rit += carry;
             carry = *rit/10;
            *rit %=10;
        }
        if(carry >0 ) digits.insert(digits.begin(),carry);

        return digits;
    }
};