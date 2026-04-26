class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9),column(9),box(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                char a=board[i][j];
                int boxi=(i/3)*3+(j/3);
                if(row[i].count(a)||column[j].count(a)||box[boxi].count(a)) return false;

                row[i].insert(a);
                column[j].insert(a);
                box[boxi].insert(a);
            }
        }
        return true;
    }
};
