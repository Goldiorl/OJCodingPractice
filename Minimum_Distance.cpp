
class Solution {
public:
    int minDistance(string word1, string word2) {
        // If find something wrong while defining an array, possibly need to
        // add one.
        // f[i+1][j+1] represents the number steps from word1[i] to word2[j]
        // f[(num in word1)[(num in word2]
        // yinwei hiayou ge f[0][0] word1, word2 meiyou duiying
        // In this case, only return f[n];
        // So the range is from f[0][0] to f[m][n];
        
        // think flow should follow the operations.
        // f[i][j] =  // insert is plus 1; 
        // But you can directly remember the trick to start with
        // distance between str1[i-1]c[i] and str2[j-1]d[j]
        // insert d: f[i][j-1]+1  insert c: f[i-1][j]+1
        // delete c: f[i-1][j]+1 delete d: f[i][j-1]+1
        // repalce f[i-1][j-1]+1
        // do nothing if [i] == [j]: f[i-1][j-1]
        const int m = word1.size();
        const int n = word2. size();
        
        //Yao yong gundong shuzu jiu yao zhuyi fanwei
        int f[n+1];
        
        int i1m1 = 0;
        // This time the equation for first line is too
        // different, so decide to initialize them separately
        
        //IMPORTANT!!! i<=n!!!
        for( int i = 0; i<=n; i++) f[i] = i;
        
        //IMPORTANT!!! i's range, and j's range
        for(int i=1; i<=m; i++){
            //IMPORTANT!!! update i1m1!!
            i1m1 = f[0];
            f[0] = i;
            
            for(int j=1; j<=n; j++){
                int temp = f[j];
                if( word1[i-1] == word2[j-1] ){
                    f[j] = i1m1;
                    i1m1 = temp;
                }
                else{
                    f[j] = min(i1m1, min(f[j],f[j-1]))+1;
                    i1m1 = temp;
                }
            }
        }
        
        //IMPORTANT, RETURN f[n]
        return f[n];
    }
};

