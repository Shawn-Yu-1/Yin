/*
 * @lc app=leetcode.cn id=233 lang=c
 *
 * [233] 数字 1 的个数
 */

// @lc code=start


int countDigitOne(int n){
    int count=0,i,j;
    for(i=1;i<=n;i++){
        for(j=i;j!=0;j=j/10){
        if(j%10==0){
            j=j/10;
        }
        if(j%10 == 1){
                    count++;
                }
        }
    }
    return count;

}


// @lc code=end

