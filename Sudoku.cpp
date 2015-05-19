Dancing links:
http://stackoverflow.com/questions/1518335/the-dancing-links-algorithm-an-explanation-that-is-less-explanatory-but-more-o


class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		vector<short> row(9,0),col(9,0),grid(9,0);
		//出现了哪些数字
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(board[i][j]!='.')
				{
					row[i] |= 1<<(board[i][j]-'1');
					col[j] |= 1<<(board[i][j]-'1');
					grid[3*(i/3)+j/3] |= 1<<(board[i][j]-'1');
				}
			}
		}
		//低9位求反,表示现在可以插入的那些数字
		short flag = pow(2,9)-1;
		for(int i=0;i<9;i++)
		{
			row[i] ^= flag ;
			col[i] ^= flag ;
			grid[i] ^= flag;
		}
		bool isEnd=false;
		solve(board,row,col,grid,isEnd);
	}

	void solve(vector<vector<char>> &board,vector<short> &row,vector<short> &col,vector<short> &grid,bool &isEnd)
	{
	    //forgot to end..
	    if(isEnd)
	        return;
		for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
					//尝试赋值
					short flag= row[i]&col[j]&grid[i/3*3+j/3];

                    for(int k=0;flag!=0 && k<9;k++)
					{
						if((flag & (1 << k)) !=0 )
						{
							board[i][j]=k+'1';
							row[i] ^= (1<<k);
							col[j] ^= (1<<k);
							grid[i/3*3+j/3] ^= (1<<k);

							solve(board,row,col,grid,isEnd);
							if(isEnd)
							{//找到解后不回退
							    return;
							}
							//回退
    						board[i][j]='.';
    						row[i] ^= (1<<k);
    						col[j] ^= (1<<k);
    						grid[i/3*3+j/3] ^= (1<<k);
							
						}
                    }
					return;
                }
            }
        }
        isEnd=true;
    }
};