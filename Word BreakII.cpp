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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
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
        vector<vector<string> > printV = recover( p, f, m-1, m-1);
        vector<string> returnTwo;
        string temp;
        for_each(printV.begin(),printV.end(), [&](vector<string> vec){
            for( auto i : vec)
                temp += i+" ";
            temp.pop_back();
            returnTwo.push_back(temp);
            temp.clear();

        });

        return returnTwo;
        //return f[m-1];
    }


    //reference version: 像这种每一次递归就加一层的，建议用reference version, 到最后一层解开所有关卡

    //iteration version
    void recover( vector<vector<bool> > &p, vector<bool> &f, 
                  vector<string> &result, vector<string> &temp, int cur, int end ){
        if( cur < 0 ) {
            string _tmp;
            for(auto i = temp.rbegin(); i!= temp.rend(); i++ ){
                _tmp += *i+" ";
            }
            _tmp.pop_back();
            result.push_back(_tmp);

            return;
        }

    
        for( ; end >=0; end--){
            if( p[end][cur] ) {
            // pre-visit, do nothing
            //dfs
            temp.push_back( str.substr(end, cur-end+1) );
            recover( p, f, result, temp, end-1, end-1);
            //post-visit :
            temp.pop_back();
            }
            
        }
    }

    //No reference of vector version
    vector<vector<string> > recover( vector<vector<bool> > &p, 
                                     vector<bool> &f, int cur, int end ){
        if( cur < 0 ) return vector<vector<string> > (1);
        vector<vector<string> > returnV;        
        for( ; end >=0; end--){
            if( p[end][cur] ) {
            // pre-visit, do nothing
            //dfs
            vector<vector<string> > ret = recover( p, f, end-1, end-1);
            //post-visit :insert
            for( vector<vector<string> >::iterator i = ret.begin(); i!= ret.end(); i++ ){
                i->push_back( str.substr(end, cur-end+1) );      
                returnV.push_back(*i);        
            }      

            }
            
        }
        return returnV;
    }
};

int main(){
    //TEST DATA
    //int test[] = {100, 4, 200, 1, 3, 2};
    //vector<int> testVector (test, test+6);
    //Solve
    //string s1 = "molsevndlihckceamwlgovkavcfcna";
    //string s2 = "alknclsklamvndvcocwhfcgmoveaie";
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert(string("cat"));
    dict.insert(string("cats"));
    dict.insert(string("and"));
    dict.insert(string("sand"));
    dict.insert(string("dog"));

    Solution sol;
    bool n = sol.wordBreak( s, dict );
    cout<<n<<endl;
}

