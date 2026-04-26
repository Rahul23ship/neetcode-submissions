class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int top=0,bottom=n-1;
        while(top<=bottom){
            int mid=(top+bottom)/2;
            if(target<matrix[mid][0])bottom=mid-1;
            else if(target>matrix[mid][m-1])top=mid+1;
            else break;
        }
        int row=(top+bottom)/2;
        int l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(target<matrix[row][mid])r=mid-1;
            else if(target>matrix[row][mid])l=mid+1;
            else return true;
        }
        return false;
    }
};
