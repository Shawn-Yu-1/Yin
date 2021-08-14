/*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 */

// @lc code=start


int trailingZeroes(int n){
    int count=0,i;
    long long temp=1;
    if(n==0){
        return 0;
    }
    for(i=1;i<=n;i++){
        temp *= i;
        for(;temp%10==0;){
            temp = temp / 10;
            count++;
        }
    }
    return count;

}


// @lc code=end

