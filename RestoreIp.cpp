#include<iostream>
#include<string>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	int strSize = 0;
	char base = '0';
	vector<string> restoreIpAddresses(string s) {
		strSize = s.length();
		if (strSize <= 1) return vector<string>();
		string tempStr;
		vector<string> result = vector<string>();
		dfs(s, 0, 0, tempStr, result);
		return result;
	}
	void dfs(string & s, int startPos, int level, string  tempStr, vector<string> & result){ //Error1: forgot the reference
		//termination
		//	level = 3
		if (startPos == strSize && level ==4 ) { //Error 4: careless about level number
			tempStr.pop_back(); result.push_back(tempStr);
			return;
		}
		if (level == 4) return;
		//prune
		if (s.size() - startPos > (4 - level) * 3) return;
		if (s.size() - startPos < (4 - level)) return;
		int tempValue = 0;
		for (size_t i = startPos; i < startPos + 3; i++){
			//previsit
			if (i >= strSize) return;
			tempValue = tempValue * 10 + s[i] - base;
			if (tempValue >255) return;
			tempStr += s[i];
			//if (tempStr == "01"){ cout << "shout " << i << " " << startPos <<" "<<tempValue<< endl; }
			//dfs
			dfs(s, i + 1, level + 1, tempStr + '.', result);
			if (tempValue == 0) return;    //ERROR 2: 
		}

	}
};

int main(){
	Solution sol;
	string s = "010010";
	vector<string> returnRet = sol.restoreIpAddresses(s);
	for (auto ip : returnRet) cout << ip << endl;
	system("pause");
}