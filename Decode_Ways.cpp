Decode ways

class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        int f[n];
        //f[(how many numbers used in s] n elements,
        f[0] = s[0] == '0' ? 0:1;
        for(int i=1; i<n;i++){
            f[i] = (s[i] == '0' ? 0:f[i-1])+  
               ((s[i-1] =='1' || s[i-1] =='2' && s[i]<='6')?
                    ( i<2? 1:f[i-2] ) : 0 );
        }
        return f[n-1];
    }
};
