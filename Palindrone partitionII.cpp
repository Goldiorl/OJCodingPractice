#include<iostream>
#include<string>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		size_t strSize = s.length();
		int n = strSize;
		vector<vector<bool>> pal(strSize, vector<bool>(strSize, false));
		vector<int> f(strSize + 1);// ERROR 1: need a partition board to show direct palindrome's partition
		//So the meaning here is pointing to the concrete number of numbers
		for (int i = 1; i < strSize + 1; i++){
			f[i] = i - 1;
		}
		f[0] = -1; //ERROR 1: f[0] = 0
		//Figure
		//1. cuts at this index = cuts till some index + one (for palindrome)
		//2. f[x] means the actually numbers that have been used
		//ERROR 0: FORGOT to use f[0]
		for (int i = 0; i < strSize; i++){
			for (int j = 0; j <= i; j++){
				if (s[j] == s[i] && (i - j < 2 || pal[j + 1][i - 1])){
					pal[j][i] = true;
				}
				if (pal[j][i]){
					f[i+1] = min(f[i+1], 1 + f[j]);  //ERROR 2: misunderstand figure 1
				}
			}
		}
		return f[n];
	}
};
int main(){
	Solution sol;
	string s = "bb";
	int ret = sol.minCut(s);
	cout << ret << endl;
	system("pause");
}