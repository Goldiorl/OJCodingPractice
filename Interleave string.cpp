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
#include<vector>
#include<tuple>
using namespace std;


//用unordered_map的话需要自己订制hash：
// namespace std{
//     template<> struct hash<Key> {
//         size_t operator()(const Key & x ) const{
//             Iterator first1, last1, first2;

//         }
// }
// }
// there is no template in such form or definition, I don't know why they write like this.
class Solution{
public:
    bool isInterleave(string s1, string s2, string s3){
/*
f[i][j] = f[i-1][j] && s1[i] == s3[i+j+1] || f[i][j-1] && s2[j] == s3[i+j+1]
such a equation should consider where i,j starts
Actually if let i start from 1:
f[i][j] = f[i-1][j] && s1[i-1] == s3[i+j-1] || f[i][j-1] && s2[j-1] ==  s3[i+j-1]
another reason the below should be used is because we cannot represent the state
where no matching happenes

A tip in DP:
For 2D matrix, usually x=0 or y=0, should be filled manually
*/
    if( s1.length()+ s2.length() != s3.length() ) return false;

    // int** ary = new int*[sizeX];
    // for(int i = 0; i < sizeX; ++i)
    //     ary[i] = new int[sizeY];
    //Attention!!! This is not linear, Actually &ary != &ary[0][0]
    //Shouldn't be the case for other multi-dimensional array
    //or
    // int (* arr)[COLUMN_SIZE];
    // int rows = 20; // this is dynamic and can be input from user at run time
    // arr = new int[rows][COLUMN_SIZE];

    //error proof:
    //A technique is to assign s1.lengt() and s2.length() to const int. Then can
    //directly allocate the array;
    // const int m = s1.length()+1;
    // const int n = s2.length()+1;
    //int f[m][n];
    //Otherwise:
    // vector<vector<bool> > f( s1.length(), vectr<bool>(s2.length(), false ) )


    //the method below not gonna work: defining bool (*f)[n]; n should be constant;
    //const int m = s1.length()+1;
    //const int n = s2.length()+1;
    //bool (*f)[n];
    //f = new bool[m][n]; 
    
    //attention !!!!!!!! fill_n cannot fill 2 dimension arrayd
    //fill_n(f, ( s1.length()+1 )*( s2.length()+1 ), false);
    //f[0][0] = true;  //if I initilized the sentence above to be true, that this 
    // could be omitted.
    vector<vector<bool> > f(s1.length()+1, vector<bool> (s2.length()+1, true));
    for(auto i = 1; i < s1.length()+1; i++){
        f[i][0] = f[i-1][0] && s1[i-1] ==  s3[i-1];
    }
    for(auto j = 1; j < s2.length()+1; j++){
        f[0][j] = f[0][j-1] && s2[j-1] == s3[j-1];
    }
    //if is fill, then must give two iterators




    //IMPORTANT!!!! RANGE IS FROM 1 TO S1.LENGTH()+1 !!!
    for ( auto i=1; i< s1.length()+1; i++ ){
        for( auto j =1; j<s2.length()+1 ; j++){
            f[i][j] = f[i-1][j] && s1[i-1] == s3[i+j-1] || f[i][j-1] \
            && s2[j-1] == s3[i+j-1];
        }
    }
    //sometimes should write down return first
    return f[s1.length()][s2.length()];
    }
};

// class Solution {
// public:
//     typedef string::iterator Iterator;
//     map< tuple<Iterator,Iterator,Iterator> , bool> cache;

//     bool isInterleave(string s1, string s2, string s3) {
//        if( s1.length() + s2.length() != s3.length() ){
//         return false;
//        } 
//        s1last = s1.end();
//        s2last = s2.end();
//        s3last = s3.end();

//        return isInterleave( s1.begin(), s2.begin(), s3.begin() );
//     }

//     //generic programming is the source of all evail
//     bool isInterleave( Iterator first1, Iterator first2, Iterator first3 ){
//         //One line of good code: In case the string passed in is a emtpy string
//         if( first3 == s3last ) return first1 == s1last && first2 == s2last;
//         //Come directly to this part would fascilitate the whole process
//         //don't forget use next, instead of +1;
//         return ( *first1 == *first3 && getOrUpdate( next(first1), first2, next(first3) ) ||
//                  *first2 == *first3 && getOrUpdate( first1, next(first2), next(first3) ) );
//     }

//     bool getOrUpdate( Iterator first1, Iterator first2, Iterator first3 ){
//         //std::make_tuple
//         auto key = make_tuple(first1, first2, first3);
//         auto pos = cache.find(key);

//         return  pos == cache.end() ? cache[key] = isInterleave(first1, first2, first3) :pos->second;
//     }
//     string::iterator s1last;
//     string::iterator s2last;
//     string::iterator s3last;
// };

int main(){
    //TEST DATA
    //int test[] = {100, 4, 200, 1, 3, 2};
    //vector<int> testVector (test, test+6);
    //Solve
    string s1 = "a";
    string s2 = "b";
    string s3 = "ab";


    Solution sol;
    bool n = sol.isInterleave( s1, s2, s3 );
    cout<<n<<endl;
}

