/*
 * @lc app=leetcode.cn id=517 lang=c
 *
 * [517] 超级洗衣机
 */

// @lc code=start


int findMinMoves(int* machines, int machinesSize){
    int sum=0,k,avg,i,j=0,m,n; //只允许同方向转移
    for(i=0;i<machinesSize;i++)
        sum += machines[i];
    avg = sum / machinesSize;
    if(avg==0){
        for(i=0;i<machinesSize;i++)
            if(machines[i]==0)
                j++;
        if(j==machinesSize)
            return 0;
        return -1;
        }
    if((sum%machinesSize)!=0)
        return -1;
    for(i=0;;i++){
        m=0;
        n=0;
        for(j=0;j<machinesSize;j++){
            if(machines[j]<avg)
                m++;
            if(machines[j]>avg)
                n++;
        }
        if(m==0)
            break;
        if(m>n){
            k=0;
            for(j=0;j<machinesSize;j++){
                if(machines[j]>avg)
                    machines[j]--;
                if(machines[j]<avg&&k<n){
                    machines[j]++;
                    k++;
                }
            }
        }
        else{
            k=0;
            for(j=0;j<machinesSize;j++){
                if(machines[j]<avg)
                    machines[j]++;
                if(machines[j]>avg&&k<m){
                    machines[j]--;
                    k++;
                }
            }

        }
    }
    return i;
}


// @lc code=end

