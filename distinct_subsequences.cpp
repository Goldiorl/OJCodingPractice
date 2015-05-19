Only use rolling array when only f[i][j-1] or f[i-1][j]  || f[i-1][j-1] && f[i-1][j] are used


class Solution {
public:
    int numDistinct(string S, string T) {
        // T is substring of S
        // f[i][j]: f[ (S[i) ] [ T(J) ]
        // So return f[sizeofS-1][sizeofT-1]
        // Suppose T[i]  != S(i) :Then f[i][j] = f[i-1][j]
        // Suppose T[i] == S(i) : Sum of two cases:
        // 1. T[i] is used to match S(i) : f[i-1][j-1];
        // 2. T[i] is used to match letter before S(i): f[i-1][j]
        // f[i][j] = f[i-1][j] + f[i-1][j-1];
        //最新经验总结: 当f表示的s,j的个数的时候,
        //就说明这样行不通了,建议 +1 处理. 
       // 其实只有edit distance需要真正需要加一,因为没有字母与有字母的距离有意义,却没有被表示
        //这题也是当2维更好处理.,只是练习另一unrolling
        //所以这里是 f[i][j] = f[num in S] [num in T]
        // return f[m][n]
        const int m = S.size();
        const int n = T.size();
        
        //vector will automatically initilize
        vector<int> f(n);
        
        //IMPORTANT TECHNIQUE: UNROLLING FROM THE END
        for( int i=0; i<m; i++){
            for(int j=n-1; j>=1; j--){
                f[j] += S[i] == T[j]? f[j-1] : 0;
            }
        //非常有价值的unrolling练习!!
            f[0] += S[i] == T[0]? 1:0 ;
        }
        return f[n-1];
    }
};