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
#include<unordered_set>
#include<queue>
using namespace std;


// Surrounded region:
// When encountered bug:
// Restart checking from the Code respective:


class Solution {
public:
    vector<vector<char> > board;
    int m;
    int n;
    queue<int> q;
    void solve(vector<vector<char>> &board) {
        this->board = board;
        this->m = board.size();
        this->n = m==0? 0:board[0].size();
        this->q = queue<int>(); 
        //IMPORTANT: very good idea to index;
       
        
        //First and last row
        //Iterates by column
        for(int c= 0; c<n; c++){
            bfs(0,c);
            if(m-1>0)
                bfs(m-1,c);
        }
        
        for(int r=1; r<m-1; r++){
            bfs(r,0);
            if(n-1>0);
                bfs(r,n-1);
        }
        
        for(int i =0; i<m; i++)
            for(int j=0; j<n; j++){
                if(this->board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                //if(this->board[i][j] == '+'){
                //    board[i][j] = 'O';
                //}                
            }
    }
    
    void visitAndChange(int row, int column){
        if(row<0 || row>m-1 ||column <0 || column >n-1)
            return;
        
//	    cout<<"visited ["<<row<<"]["<<column<<"]"<<endl;
        if( board[row][column] == 'O' ){
//	    cout<<"Conversed ["<<row<<"]["<<column<<"]"<<endl;
            board[row][column] = '+';
            q.push(row*n+column);
        }
        
    }
    void bfs(int row, int column){
//	    cout<<"BFS was started on ["<<row<<"]["<<column<<"]"<<endl;
        //check current point
        visitAndChange(row, column);
        
        while(!q.empty()){
            int idx = q.front();q.pop();
            int r = idx / n;
            int c = idx % n;

            visitAndChange(r-1,c);
            visitAndChange(r+1,c);
            visitAndChange(r, c-1);
            visitAndChange(r, c+1);
            
        }

    }
};
int main(){
//    //TEST DATA
//    //int test[] = {100, 4, 200, 1, 3, 2};
//    //vector<int> testVector (test, test+6);
//    //Solve
//    //string s1 = "molsevndlihckceamwlgovkavcfcna";
//    //string s2 = "alknclsklamvndvcocwhfcgmoveaie";
//    string s = "catsanddog";
vector<string> input = {"XOXOXO","OXOXOX","XOXOXO","OXOXOX"};
vector<vector<char> > board;
for(auto i:input){
vector<char> newChar;
	for(auto cr :i){
		newChar.push_back(cr);
	}
	board.push_back(newChar);
}
Solution sol;
sol.solve(board);
for(auto i:board){
	cout<<"output ";
	for(auto j:i)
	cout<<j<<" ";
	cout<<endl;
}
} 

