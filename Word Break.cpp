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
using namespace std;

class Solution {
public:
    string str;
    bool wordBreak(string s, unordered_set<string> &dict) {
        //f[i] present string[0,i] could be break
        // we want f[m-1];
        //p[j][i] present s[j, i] could be found in dict and find a way to break;
        str = s;
        int m = s.size();
        vector<bool> f(m, false);
        vector<vector<bool> > p(m, vector<bool> ( m,false ) ); 
        for(int i =0; i<m; i++ ){
            p[0][i] = f[i] = ( dict.find( s.substr(0,i+1)) != dict.end() );
            for(int j=0; j<i; j++){
                if( f[j] && ( dict.find( s.substr(j+1,i-j) ) != dict.end() ) )
                p[j+1][i] =  f[i] = true;
                //cout<<"f["<<i<<"]"<<f[i]<<"  f["<<j<<"]"<<f[j]<<"p["<<j<<"+1]"<<"["<<i<<"]"<<"is"<<p[j+1][i]<<endl;
            }
            
        }

        return f[m-1];
    }

};

int main(){
    //TEST DATA
    //int test[] = {100, 4, 200, 1, 3, 2};
    //vector<int> testVector (test, test+6);
    //Solve
    //string s1 = "molsevndlihckceamwlgovkavcfcna";
    //string s2 = "alknclsklamvndvcocwhfcgmoveaie";
    string s = "leetcode";
    unordered_set<string> dict;
    dict.insert(string("leet"));
    dict.insert(string("code"));

    Solution sol;
    bool n = sol.wordBreak( s, dict );
    cout<<n<<endl;
}

