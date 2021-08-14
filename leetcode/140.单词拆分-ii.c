/*
 * @lc app=leetcode.cn id=140 lang=c
 *
 * [140] 单词拆分 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void makeword(char* s,char** wordDict,int wordDictSize,int* returnSize,int** res,char* temp,int p,int len){
    int i,j;
    if(p==strlen(s)){
        temp[len-1] = '\0';
        res[(*returnSize)++] = (char*)malloc(sizeof(char)*(len));
        strcpy(res[(*returnSize)-1],temp);
        return;     
    }
    for(i=0;i<wordDictSize;i++){
        if(strlen(wordDict[i])>(strlen(s)-p)){
            continue;
        }
        for(j=0;j<strlen(wordDict[i]);j++){
            if(s[p+j] != wordDict[i][j]){
                break;
            }
            if(j==strlen(wordDict[i])-1){
                temp[len] = '\0';
                strcat(temp,wordDict[i]);
                temp[len+j+1] = ' ';
                makeword(s,wordDict,wordDictSize,returnSize,res,temp,p+j+1,len+j+2);
                break;
            }
        }
    }
}
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    char** res = (char**)malloc(sizeof(char*)*100);
    *returnSize = 0;
    char* temp = (char*)malloc(sizeof(char)*(strlen(s)*2));
    makeword(s,wordDict,wordDictSize,returnSize,res,temp,0,0);
    return res;

}


// @lc code=end

