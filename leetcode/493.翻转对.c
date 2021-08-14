/*
 * @lc app=leetcode.cn id=493 lang=c
 *
 * [493] 翻转对
 */

// @lc code=start


int reversePairs(int* nums, int numsSize){
    int hash[50000];
    int i,j,count=0,temp;
    long long n;
    for(i=0;i<50000;i++){
        hash[i] = -1;
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]<50000&&nums[i]>=0){
            if(hash[nums[i]]==0){
                continue;
            }
        }
        temp = count;
        for(j=i+1;j<numsSize;j++){
            n = nums[j];
            if(nums[i]>n*2){
                count++;
            }
        }
        if(temp==count){
            if(nums[i]<50000&&nums[i]>=0){
                hash[nums[i]] = 0;
            }
        }
    }
    return count;

}


// @lc code=end

