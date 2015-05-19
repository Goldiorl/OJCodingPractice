// 不能用Dp, 会memory out of limit 


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        string str;
        for(auto i:s){
            //cctype header
            if( !isdigit(i) && !isalpha(i)) continue;
            if( isalpha(i)) i= tolower(i);
            str.push_back(i);
        }
	
        const int n = str.size();
        if(n==0) return true;
        
        for(auto i=0; i< n/2; i++){
            if(str[i] != str[n-1-i]) return false;
        }
        return true;
        
        //memory exceedos
        // vector<vector<bool> > f(n, vector<bool> (n));
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<=i; j++){
        //         f[j][i] = (str[j] == str[i]) && (i-j<2? 1: f[j+1][i-1]);
        //     }
        // }
        
        // return f[0][n-1];
    }
};




class Solution {
public:
	bool isPalindrome(string s) {
		string squeezed;
		for (auto i : s){
			//cctype header
			if (!isdigit(i) && !isalpha(i)) continue;
			if (isalpha(i)) i = tolower(i);
			squeezed += i;
		}
		if (squeezed.length() == 0) return true;

		const int strSize = squeezed.length();
		vector < vector<bool>> pal(strSize, vector<bool>(strSize, false));
		for (auto i = 0; i < strSize; i++){
			for (auto j = 0; j <= i; j++){ //Needs to be consisten: contagious
				if (squeezed[i] == squeezed[j] && ((i - j) < 2 || pal[j + 1][i - 1])){
					pal[j][i] == true;
				}

			}
		}
		if (pal[0][strSize - 1]) return true;
		return false;
	}
};