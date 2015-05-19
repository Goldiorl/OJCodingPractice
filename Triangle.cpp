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
    int minimumTotal(vector<vector<int> > &triangle) {
        int row =triangle.size();
        for ( int i = row -2; i>=0; i-- ){
            //the condition for i includes i == 0 ( due to the special case of 2 rows)
            for (int j = 0; j<i+1; j++){
                //dont'r forget j can be extened to i+1
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
int main(){

    
}

