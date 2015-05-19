class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> dict;
        for(int i = 0; i< numbers.size(); i++){
            if(dict.find(target - numbers[i]) != dict.end()){
                vector<int> result{dict[target - numbers[i]], i+1 };
                return result;
            }
            else{
                dict[numbers[i]] = i+1; 
            }
        }
    }
};