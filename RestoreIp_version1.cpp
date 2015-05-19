
class Solution {
public:
    string s;
    vector<string> restoreIpAddresses(string s) {
        //Think flow: each time do a DFS, should think two things
        //What is the adjacent vertix, how to previsit, post visit
        //What is the parameter to pass to the dfs
        this->s = s;
        vector<string> result;
        string temp;
        dfs(0, 0, temp, result);
        
        return result;
    }
    void dfs(int level,int start,string temp, vector<string> & result ){
        //if level is four, add the result back
        if(level == 4 && start==s.size() ){
            temp.pop_back();
            result.push_back(temp);
        }
        
        //termination:
        //this is equivalent to the following two sentences
        if( start == s.size() || level ==4 ) return;
        //if( (s.size()-start) < (4-level) return; 
        //if( (s.size()-start) > (4-level)*3 ) return;
        
        //
        int num=0;
        for(int i=start; i<start+3; i++){
            //previsit, check conditions
            num= num*10+s[i]-'0';
            if( num<=255 ){
                temp+=s[i];
                //zhezhong xiaoti i he start qu nong nong cuo... 
                dfs(level+1, i+1, temp+'.',result);
            //post visit: gonna continue
            //basically just do nothing, but cannot continue with starting 0 in this level
            //(stop trying to reach other adjacant vertics because illegal)
                //IMPORTANT!!!!
                if(num == 0) break; //first time two continuous 0 happens
            }
                
        }
        
    }
};

