#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

string test = "awbwoiacvwdfgc";

string removeVow( string s1 ){
	string removeset= "abcde";
	unordered_set<char> strset (removeset.begin(),removeset.end());
	vector<char> vec;
	for(auto i: test){
		if( strset.find(i) == strset.end() ) vec.push_back(i);
	}
	string result(vec.begin(),vec.end());
	return result;
}

int main(){

	cout<<removeVow(test)<<endl;

}