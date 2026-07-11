class Solution {
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                ans=check(board,word,i,j,1);
                if(ans)return ans;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>&board, string word, int i,int j, int x){
        if((x)==word.size())return true;
        char temp=board[i][j];
        board[i][j]='#';
        bool ans;
        if(i!=0 && board[i-1][j]!='#' && board[i-1][j]==word[x]){
            ans=check(board,word,i-1,j,x+1);
            if(ans)return ans;

        }
        if(j!=0 && board[i][j-1]!='#' && board[i][j-1]==word[x]){
            ans=check(board,word,i,j-1,x+1);
            if(ans)return ans;

        }
        if((i!=board.size()-1)&& board[i+1][j]!='#' && board[i+1][j]==word[x]){
            ans=check(board,word,i+1,j,x+1);
            if(ans)return ans;

        }
        if((j!=board[0].size()-1)&& board[i][j+1]!='#' && board[i][j+1]==word[x]){
            ans=check(board,word,i,j+1,x+1);
            if(ans)return ans;

        }
        board[i][j]=temp;
        return false;
    }
};
