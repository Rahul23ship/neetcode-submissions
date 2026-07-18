class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,('.')));
        solve(ans,board,n,0);
        return ans;
    }
    void solve(vector<vector<string>>&ans,vector<string>&board,int n,int i){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(checkup(board,i-1,j) && checkld(board,i-1,j-1) && checkrd(board,i-1,j+1,n)){
                board[i][j]='Q';
                solve(ans,board,n,i+1);
                board[i][j]='.';
            }
        }
        return;
    }
    bool checkup(vector<string>&board,int i,int j){
        while(i>=0){
            if(board[i][j]=='Q')return false;
            i--;
        }
        return true;
    }
    bool checkld(vector<string>&board,int i,int j){
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')return false;
            i--;j--;
        }
        return true;
    }
    bool checkrd(vector<string>&board,int i,int j,int n){
        while(i>=0 && j<n){
            if(board[i][j]=='Q')return false;
            i--;j++;
        }
        return true;
    }
};
