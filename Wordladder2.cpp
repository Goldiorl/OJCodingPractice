#include<iostream>
#include<string>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	unordered_map<string, vector<string>> fatherTree;
	unordered_set<string> visited;
	vector<vector<string>> result;
	vector<string> tempPath;
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		int length = 0;
		if (start == end) return vector<vector<string>>(1, vector<string>(1,start));
		int foundFlag = 0;
		unordered_set<string> current, next; //Error 1: Duplicate removing, needs it to be a "set", because this time add to "current" wont be 
																				 // ahead of checking if it is in dict.
		current.insert(start);
		visited.insert(start);


		while (!current.empty() && !foundFlag){

			//TODO visited all current queue
			for (auto f : current){
				visited.insert(f);
			}
			for (auto f : current){
				//TODO for all current member,
				//	found next not visited
				//check if contains descendants in the dict
				string frontStr = f;
				for (char charC = 'a'; charC <= 'z'; charC++){
					for (int i = 0; i < frontStr.size(); i++){
						swap(frontStr[i], charC);
						if (frontStr == end) {
							//cout << "==========found======" <<f<< endl;
							foundFlag = 1;
							next.insert(frontStr);
							 //ERROR 3: when found, need to add to the tree!!!! BUT NOT NECESSARILY IN DICT
						}

						if ( (dict.count(frontStr) != 0 && visited.count(frontStr) == 0) ||
								frontStr == end){ //ERROR 3
							next.insert(frontStr);
							//cout << "pushed" << frontStr << endl;
							fatherTree[frontStr].push_back(f);
						}
						swap(frontStr[i], charC);

					}
				}
			}


			current.clear();
			swap(current, next);
		}

		if (foundFlag) {  buildPath(result, start, end, tempPath); return result; }
		else return vector<vector<string>>();
	}

	void buildPath(decltype(result) & result, string start, string currentWord, decltype(tempPath)& tempPath){
		tempPath.push_back(currentWord);
		//cout << "flag" << currentWord << endl;
		//cout << "flag" << std::to_string(fatherTree[currentWord].size()) << endl;
		if (currentWord == start){
			result.push_back(tempPath);
			reverse(result.back().begin(), result.back().end()); //ERROR 2: tempPath is a ref, when modifying ,needs a copy, otherwise affect others
		}
		else {
			for (auto i : fatherTree[currentWord]){
				//cout << "father for " << currentWord << " is " << i << endl;
				buildPath(result, start, i, tempPath);
			}
		}
		tempPath.pop_back();
	}
};


int main(){
	Solution sol;
	int testCase[] = { 1, 2, 2 };
	string start = "hit", end = "cog";
	unordered_set<string> dicts;
	dicts.insert("hot");
	dicts.insert("dot");
	dicts.insert("dog");
	dicts.insert("lot");
	dicts.insert("log");
	vector<vector<string>> result = sol.findLadders(start, end, dicts);
	//cout << result << endl;
	for (auto vstr : result){
		for (auto strInTree : vstr){
			cout << strInTree << " ";
		}
		cout << endl;
	}
	system("pause");
}