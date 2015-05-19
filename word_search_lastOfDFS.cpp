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
//TIME LIMITE EXCEEDED VERSION
//BETTER DONE WITH BFS


class Solution {
public:
    int m;
    int n;
    int end;
    string word;
    bool exist(vector<vector<char> > &board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->end = word.size();
	    this->word = word;
	    vector<vector<bool> > visited(m, vector<bool> (n, false));
        for(int i = 0; i<m;i++)
            for(int j = 0; j<n; j++){
                if( dfs(0, i,j, board, visited) ) return true;
            }
        return false;
    }

    bool dfs( int index, int row, int column, vector<vector<char> > &board,
               vector<vector<bool> > &visited){
        //For first time omitted the case the string to be searched could be larger
        // than the board;
        if(  row<0 || column <0 || row >= m || column >=n  ||visited[row][column]){
            return false;
        }
        
        //prune
        if(board[row][column] != word[index])
            return false;
            

        
        if( index == (end-1) ) return true;
        //dfs adjacent points
        //Pre visit
        visited[row][column] = true;        
        bool ret = 
            dfs(index+1, row-1, column, board, visited) || // up; down; left; right
            dfs(index+1, row+1, column, board, visited) ||
            dfs(index+1, row, column-1, board, visited) ||
            dfs(index+1, row, column+1, board, visited) ;
        //post visit
        visited[row][column] = false;
        return ret;
    }
};

//If TLE: see if the parameter is a reference (or a copy)
//duplication problem(have duplicate answer), prune


// template

// Pay attention to duplicate removal 
// (this is a problem of how to correctly traverse all not visited adjacent points)
// removal could use a vector, map, hashtable, 
// or if for char and string, change that char and then recover

// termination : 
// 1. when finish correct, insert result
// 2. wrong, then over

// prune

// dfs:
// Visit adjacent points
// previsit
// visit
// postvisit recover



int main(){


} 

