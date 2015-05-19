#include <iostream>
#include <string>
using namespace std;

bool isRotation( string s1, string s2){
	int len = s1.length();
	if( len == s2.length() && len>0 ) {
		string strstr = s1+s1;
		//cout<<strstr<<endl;
		//cout<<s2<<endl;
		//cout<<strstr.find(s2)<<endl;
		return strstr.find(s2) !=  string::npos;
	}
	return false;
}

int main(){
	string test = "abcabcde";
	string origin = "abcdabce";
	cout<<"is " <<isRotation(test,origin)<<endl;
}