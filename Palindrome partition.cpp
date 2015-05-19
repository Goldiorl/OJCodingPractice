#include<iostream>
#include<string>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		int strSize = s.length();
		vector <vector<bool>> pal(strSize, vector<bool>(strSize, false));
		for (int i = 0; i < strSize; i++){
			for (int j = 0; j <= i; j++){
				if (s[j] == s[i] && (i - j < 2 || pal[j + 1][i - 1])){
					pal[j][i] = true;
				}
			}
		}

		vector<vector<vector<string>>> palindron_till_i(strSize);
		for (int i = 0; i < strSize; i++){
			for (int j = 0; j <= i; j++){   //Cautious: stick to j=i
				if (pal[j][i]){
					string palindrome = s.substr(j, i - j + 1);
					//in terms of palindrome_till_i[i]
					if (j == 0){
						palindron_till_i[i].push_back(vector<string> {palindrome});
					}
					else{
						for (auto ii : palindron_till_i[j-1]){  //HUGE ERROR: Slicing position
							ii.insert(ii.end(), palindrome);
							palindron_till_i[i].push_back(ii);
						}
					}
				}
			}
		}
		return palindron_till_i[strSize - 1];
	}
};


int main(){
	Solution sol;
	string s = "ab";
	vector<vector<string>> resultRet = sol.partition(s);
	for (auto vs : resultRet){
		for (auto s : vs) cout << s<<".";
		cout << endl;
	}
	system("pause");
}