/*
 * @lc app=leetcode.cn id=990 lang=c
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start


bool equationsPossible(char ** equations, int equationsSize){
    char** test=(char**)malloc(sizeof(char*)*equationsSize);
    char* temp=(char*)malloc(sizeof(char)*1000);
    test[0]="";test[0]=(char*)malloc(sizeof(char)*1000);
    int i,j,k,testlen=0,p,q;
    for(i=0;i<equationsSize;i++){
        if(equations[i][0]==equations[i][3]){
            if(equations[i][1]=='!'){
                return false;
            }
            else{
                continue;
            }
        }
        else{
            if(equations[i][1]=='='){
                if(test[0][0]=='\0'){
                    test[0][0]=equations[i][0];
                    test[0][1]=equations[i][3];
                    test[0][2]='\0';
                    testlen++;
                    continue;
                }
                for(j=0;j<testlen;j++){
                    p=0;
                    for(k=0;k<strlen(test[j]);j++){
                        if(test[j][k]==equations[i][0]||test[j][k]==equations[i][3]){
                            p=strlen(test[j]);
                            test[j][p-1]=equations[i][0];
                            test[j][p]=equations[i][3];
                            test[j][p+1]='\0';
                            break;
                        }
                    }
                    if(p!=0){
                        break;
                    }

                }
                if(j==testlen){
                    test[testlen]=(char*)malloc(sizeof(char)*1000);
                    test[testlen][0]=equations[i][0];
                    test[testlen][1]=equations[i][3];
                    test[testlen][2]='\0';
                    testlen++;
                }

            }
        }
    }if(test[0][0]=='\0'){
        return  true;

    }
    do{
        i=0;
        for(j=0;j<testlen;j++){
            for(k=j+1;k<testlen;k++){
               for(p=0;p<strlen(test[j]);p++){
                   for(q=0;q<strlen(test[k]);q++){
                       if(test[j][p]!='\0'&&test[k][q]!='\0'&&test[j][p]==test[k][q]){
                           strcat(test[j],test[k]);
                           test[k][0]='\0';
                           i++;
                           }
                   }
               }  
            }
        }
        
    } while (i>0);
    for(i=0,j=0;i<testlen;i++){
        if(test[i][0]!='\0'){
            strcpy(temp,test[i]);
            strcpy(test[j],temp);
            j++;
        }
    }
    testlen=j;
    printf("%s",test[0]);
    for(i=0;i<equationsSize;i++){
        if(equations[i][1]=='!'&&equations[i][0]!=equations[i][3]){
            for(j=0;j<testlen;j++){
                q=0;
                p=0;
                for(k=0;k<strlen(test[j]);k++){
                    if(equations[i][0]==test[j][k]){
                        q++;
                    }
                    if(equations[i][3]==test[j][k]){
                        p++;
                    }
                    if(p>0&&q>0){
                        return false;
                    }
                }
            }
        }
    }
    return true;
    

}


// @lc code=end

