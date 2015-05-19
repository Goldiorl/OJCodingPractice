#include<iostream>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<climits>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<stack>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> sequence;
        for( int i = 0; i <n; i ++)
            sequence.push_back(i+1);

        //get the string
        int m = k-1; // the num to be divided
        string result;
        for ( auto i = n; i >0; i--){
            int factorial = get_factorial_k( i-1 );
            int index = (m / factorial) % sequence.size() ;
            result += '0' + sequence[ index ];
            sequence.erase( sequence.begin()+index );
            m = m % factorial ; 
        }
        return result;
    }
private:
    int get_factorial_k( int k ){
        if ( k == 0 ) return 1;
        if (k == 1 )
            return 1;
        return k*get_factorial_k(k-1);
    }
};

int main(){

    
}

