#include<iostream>
#include<string>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int length = 0;
		if (start == end) return 1;

		unordered_set<string> visited;
		//unordered_set
		int foundFlag = 0;
		queue<string> current, next;
		//while not empty
		current.push(start);
		visited.insert(start);

		while (!current.empty() && !foundFlag){
			length++;
			//current.front(), current.pop()
			while (!current.empty() && !foundFlag){ //to check if next queue is empty
				
				string frontStr = current.front(); current.pop();
				cout << " ============" << frontStr << " has been poped out" << endl;
				//check if contains descendants in the dict
				for (char charC = 'a'; charC <= 'z'; charC++){
					for (int i = 0; i < frontStr.size(); i++){
						swap(frontStr[i], charC);
						if (frontStr == end) {
							cout << "==========found======" << endl;
							foundFlag = 1;
							length++;
							break;
						}
						//cout << "gonna test this" << frontStr << "dict counts: "<<dict.count(frontStr) <<"visited counts: "<<visited.count(frontStr)<< endl;;
						if (dict.count(frontStr) != 0 && visited.count(frontStr) == 0){
							next.push(frontStr);
							cout << "pushed" << frontStr << endl;
							visited.insert(frontStr);

						}
						swap(frontStr[i], charC);

					}
					if (foundFlag) break;
				}
				
			}
			swap(current, next);
		}
		if (foundFlag) return length;
		else return 0;
	}
};


int main(){
	Solution sol;
	int testCase[] = { 1, 2, 2 };
	string start = "kiss", end = "tusk";
	unordered_set<string> dicts;
	dicts.insert("miss");
	dicts.insert("dusk");
	dicts.insert("kiss");
	dicts.insert("musk");
	dicts.insert("tusk");
	dicts.insert("diss");
	dicts.insert("disk");
	dicts.insert("sang");
	dicts.insert("ties");
	dicts.insert("muss");
	int result = sol.ladderLength(start, end, dicts);
	cout << result << endl;
	system("pause");
}