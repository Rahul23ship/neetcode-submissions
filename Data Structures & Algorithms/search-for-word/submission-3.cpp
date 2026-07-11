class Solution {
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        vector<vector<int>>mp(board.size(),vector<int>(board[0].size(),-1));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                ans=check(board,word,i,j,1,mp);
                if(ans)return ans;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>&board, string word, int i,int j, int x, vector<vector<int>>&mp){
        if((x)==word.size())return true;
        
        bool ans;
        mp[i][j]=1;
        if(i!=0 && mp[i-1][j]==-1 && board[i-1][j]==word[x]){
            ans=check(board,word,i-1,j,x+1,mp);
            if(ans)return ans;

        }
        if(j!=0 && mp[i][j-1]==-1 && board[i][j-1]==word[x]){
            ans=check(board,word,i,j-1,x+1,mp);
            if(ans)return ans;

        }
        if((i!=board.size()-1)&& mp[i+1][j]==-1 && board[i+1][j]==word[x]){
            ans=check(board,word,i+1,j,x+1,mp);
            if(ans)return ans;

        }
        if((j!=board[0].size()-1)&& mp[i][j+1]==-1 && board[i][j+1]==word[x]){
            ans=check(board,word,i,j+1,x+1,mp);
            if(ans)return ans;

        }
        mp[i][j]=-1;
        return false;
    }
};
