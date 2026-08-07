class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O' && (i==0 or i==board.size()-1 or j==0 or j==board[0].size()-1))
                cover(board,i,j);
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(board[i][j]=='A')board[i][j]='O'; 
            }
        }
        
    }
    void cover(vector<vector<char>>&board,int i,int j){
        if(i<0 || j<0 || i==board.size() || j== board[0].size() || board[i][j]!='O'){
            return;
        }
        board[i][j]='A';
        cover(board,i-1,j);
        cover(board,i+1,j);
        cover(board,i,j-1);
        cover(board,i,j+1);
    }
};
