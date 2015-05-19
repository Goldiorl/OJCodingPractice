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
    bool isScramble(string s1, string s2){
        if ( s1.length() != s2.length() ) return false;
        const int n = s1.length();
        //两维以上还是用const int定义数组更方便；
        //vector<vector<vector<bool> > > f(n+1, vector<vector<bool> > (n, vector<bool> (n, false) ) );
        bool f[n+1][n][n];
        fill_n(&f[0][0][0], (n+1)*n*n, false);

        //initilization;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                f[1][i][j] = s1[i] == s2[j];
            }
        }


        //这里是最重要的，RODO, 弄清楚各个变量的界限，就可以了
        //其实就是应该这么想：对于取之为0到n-1的n个数，那么f[n]相当于是一个界，即f.end(),那么跟它相隔K的数的起点就是
        //n-k, 即f.end()-k
        for(int i=2; i<=n ; i++){
            for(int j=0; j<=n-i; j++)
                for(int k=0; k<=n-i;k++)
                    for(int m=1; m<i; m++)
                        if( ( f[m][j][k] && f[i-m][j+m][k+m] ) ||
                                     ( f[m][j][k+i-m] && f[i-m][j+m][k]) ){
                            f[i][j][k] = true;
                            break;
                            //IMPORTANT!!!
                            //直接用 f[i][j][k] = f[m][j][k] && f[i-m][j+m][k+m] ) ||
                            //       ( f[m][j][k+i-m] && f[i-m][j+m][k])
                            //会出错！！
                        }
                        

                    
        }

        return f[n][0][0];
    }
};
//下面这个time limit exceeds

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         //always check at the beginning
//         if ( s1.length() != s2.length() ) return false;
//         s1last = s1.end();
//         s2last = s2.end();
//         n = s1.length();
//         return isScramble( s1.begin(), s2.begin(), n);
//     }

//     bool isScramble( string::iterator s1begin, string::iterator s2begin, int n ){
//         //ending condition
//         //don't consider n == 0, erase this case from the loop
//         if( n==1 ) return *s1begin == *s2begin;

//         for( int i=1; i<n; i++ ){
//             if( ( getOrUpdate(s1begin, s2begin, i) && getOrUpdate( next(s1begin,i), next(s2begin,i), n-i ) )
//                 || getOrUpdate(s1begin, next(s2begin, n-i), i) && 
//                     getOrUpdate( next(s1begin, i), s2begin, n-i ) ){
//                 return true;                
//             }

//         }

//         //一开始忘了指定回复值了，SB了
//         //本来一个函数，在开辟stack的时候会规定一个存储位置用于存放Return，然后会赋值，再返回它
//         //如果没有的话就变返回随机数了
//         return false;
//     }

//     bool getOrUpdate( string::iterator s1, string::iterator s2, int n){
//         auto key = make_tuple(s1, s2, n);
//         auto pos = cache.find( key );
//         return pos == cache.end()? cache[key] = isScramble( s1, s2, n ) : cache[key];
//     }
//     int n = 0;
//     string::iterator s1last;
//     string::iterator s2last;
//     map< tuple< string::iterator, string::iterator, int>, bool> cache;
// };


bool test(){
    return false;
}

int main(){
    //TEST DATA
    //int test[] = {100, 4, 200, 1, 3, 2};
    //vector<int> testVector (test, test+6);
    //Solve
    //string s1 = "molsevndlihckceamwlgovkavcfcna";
    //string s2 = "alknclsklamvndvcocwhfcgmoveaie";
    string s1 = "rgtae";
    string s2 = "great";

    Solution sol;
    bool n = sol.isScramble( s1, s2 );
    cout<<n<<endl;
}

