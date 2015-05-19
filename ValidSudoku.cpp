class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		if( board.size()!=9 && board[0].size()!=9) return false;
        char num[10]={0};
		//check rows
		for(size_t i=0;i<board.size();i++)
		{
			memset(num,0,sizeof(char)*10);
			for(size_t j=0;j<board[i].size();j++)
			{
				if(board[i][j]!='.')
				{
					const int index=board[i][j]-'0';
					if(index<1 || index>9 || num[index]>=1)
					{
						return false;
					}
					else
					{
						num[index]=1;
					}
				}
			}
		}
		//check columns
		for(size_t j=0;j<board[0].size();j++)
		{
			memset(num,0,sizeof(char)*10);
			for(size_t i=0;i<board.size();i++)
			{
				if(board[i][j]!='.')
				{
					const int index=board[i][j]-'0';
					if(index<1 || index>9 || num[index]>=1)
					{
						return false;
					}
					else
					{
						num[index]=1;
					}
				}
			}
		}
		//check boxs
		const int a[9]={0,3,6,27,30,33,54,57,60};
		for(int i=0;i < 9;i++)
		{
			memset(num,0,sizeof(char)*10);
			for(int p=a[i],times=0;times<9;times++)
			{
				if(times%3 == 0)
				{
					p=a[i]+times*3;
				}
				else
				{
					p++;
				}
				if(board[p/9][p%9]!='.')
				{
					const int index=board[p/9][p%9]-'0';
					if(index<1 || index>9 || num[index]>=1)
					{
						return false;
					}
					else
					{
						num[index]=1;
					}
				}
			}
		}
		return true;
    }
};