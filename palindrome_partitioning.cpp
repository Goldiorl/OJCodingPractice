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
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        //f[i][j] to represent if s[i][j] form a palindrome
        //So f[i][j] = f[i+1][j-1] && s[i] == s[j]
        vector<vector<bool> > f(n, vector<bool> (n)) ;
        // //initilize:
        // can bo omitted due to the correctenss of recursion;
        // for(int i=0; i<n; i++){
        //     f[i][i] = true;
        // }
        
        
        for(int i =0; i<n; i++){
            for(int j = 0;j<=i; j++){
                f[j][i] = ( s[j] == s[i] ) && ( ( i-j <=1)? 1: f[j+1][i-1] );
                //or right part become (j-i <2 )|| f[i+1][j-1]
		//if(f[j][i])
		//cout<<s.substr(j,i-j+1)<<"becuase "<<s[j]<<"=="<<s[i]<<"are they equal?? "<<(s[j]==s[i])<< "yes or no"<< " and "<<" or "<<i-j<<endl;
		//cout<<s.substr(j,i-j+1)<<endl;
            }
        }
        
        //construct results:
        vector<vector<string> > result[n];
        for(int i = 0; i< n; i++){
            //Zhuyi de dian
            if(f[0][i]) result[i].push_back(vector<string> {s.substr(0,i+1)} );
            for(int j = 1; j<=i; j++){
                if(f[j][i]){
                    for(auto k: result[j-1]){
			k.push_back(s.substr(j,i-j+1));
                        result[i].push_back(k);
		    }
                }
            }
        }
        return result[n-1];
    }
};
int main(){

string str = "eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj";
Solution sol;
vector<vector<string> > ret = sol.partition(str);
for(auto i:ret){
	for(auto j:i)
		cout<<j<<" ";
	cout<<endl;
}
} 

