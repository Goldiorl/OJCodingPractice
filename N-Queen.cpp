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
#include<vector>
#include<tuple>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    vector<bool> mainD;
    vector<bool> antiD;
    vector<bool> col;
    vector<int> index;
    int n;
    
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        mainD = vector<bool> (2*n);
        antiD = vector<bool> (2*n);
        col = vector<bool> (n);
        index = vector<int> (n,-1);
        vector<vector<string> > results;
        dfs(0, results);
	//You wangji xie return!!!! Leads to segmentation fault;
        return results;
    }
    
    void dfs(int row, vector<vector<string> > &results ){
        //termination
        // row == n, write back results, and teminate
        if(row == n) {
            vector<string> ret( n, string(n,'.') );
            int idx = 0;
            for(auto i: index){
                ret[idx++][i] = 'Q';
            }
	    results.push_back(ret);
        }
        
        for(int i =0; i<n; i++){
            if( !col[i] && !mainD[n-row+i] && !antiD[n-row+n-1-i] ){
                col[i] = mainD[n-row+i]=antiD[n-row+n-1-i]=true;
                index[row] = i;
                dfs(row+1, results);
                col[i] = mainD[n-row+i]=antiD[n-row+n-1-i]=false;
                index[row] = -1;
            }

        }
    }
};
int main(){


Solution sol;
vector<vector<string> > ret = sol.solveNQueens(4);
for(auto i:ret){
	for(auto j:i)
		cout<<j<<endl;
	cout<<"--------"<<endl;
}
} 

