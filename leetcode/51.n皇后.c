/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool noconflict(int* temp,int row,int i){
    if(row == 0){
            temp[row]=i;
            return true;
        }
    for(int p=0;p<row;p++){
        
        if(temp[p]==i)
            return false;
        if(row-p == abs(i-temp[p]))
            return false;
        temp[row] = i;
        return true;
    }
    return false;

}

void solveQueen(char*** result,char* blank,int n,int* returnSize,int row,int count,int* temp){
    if(count==n){
        *returnSize++;
        return;
    }
    for(int i=0;i<n;i++){
        if(noconflict(temp,row,i)){
            count++;
            blank[i]='Q';
            strcpy(result[*returnSize][row],blank);
            blank[i]='.';
            solveQueen(result,blank,n,returnSize,row+1,count,temp);
            count--;
        }
    }

    

}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int i,j;
    char*** result=(char***)malloc(sizeof(char**)*50);
    for(i=0;i<50;i++){
        result[i]=(char**)malloc(sizeof(char*)*n);
        for(j=0;j<n;j++){
            result[i][j]=(char*)malloc(sizeof(char)*(n+1));
        
    }
    }
    
    int* temp=(int*)malloc(sizeof(int)*40);
    char* blank=(char*)malloc(sizeof(char)*(n+1));
    for(i=0;i<n;i++)
        blank[i]='.';
    blank[i]='\0';
    **returnColumnSizes = n;
    *returnSize=0;
    solveQueen(result,blank,n,returnSize,0,0,temp);
    return result;


}


// @lc code=end

