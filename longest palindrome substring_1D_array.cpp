class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<bool> f(n*n, false);
    // for s[0]....s[n-1] f[0][n-1] means if  
    size_t max_temp_length = 0, start = 0;
    for (int i = 0; i < n; i++){
      for (int j = 0; j <= i; j++){
        if ((s[i] == s[j]) && ((i - j < 2) || f[(j + 1)*n+(i - 1)])){
          f[j *n+i] = true;
          if ((i - j + 1) > max_temp_length){
            max_temp_length = i - j + 1;
            start = j;
          }
        }
      }
    }
    return s.substr(start, max_temp_length);
  }
};

