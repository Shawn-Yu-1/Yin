# include <stdio.h>
# include <stdbool.h>
# define infinity __INTMAX_MAX__
int d[1000][1000],path[1000][1000];
void ShortestPath_Floyd(MGraph G,PathMatrix & P[],DistancMatrix &D[]){
    int v,w,u;
    for(v = 0;v < G.vexnum; ++v)  //初始化邻接矩阵
        for(w = 0;w < G.vexnum; ++w){
            D[v][w] = G.arcs[v][w];
            for(u = 0;u < G.vexnum; ++u)    //初始化路径
            P[v][w][u] = false;
            if(D[v][w] < infinity){
                p[v][w][v] = true;
                P[v][w][w] = true;
            }
        }
    for(u = 0;u < G.vexnum; ++u)  //对于每一个中间定点
        for(v = 0;v < G.vexnum; ++v)
            for(w = 0;w < G.vexnum; ++w)
                if(D[v][u] + D[u][w] < D[v][w]){ //更新最短距离
                    D[v][w] = D[v][u] + D[u][w];
                    for(int i = 0;i < G.vexnum; ++i) //记录路径
                        P[v][w][i] = P[v][u][i] || P[u][w][i];
                }

}
int main(void){
    int i,j,k,m,n;
    int x,y,z;
    scanf("%d%d",&n,&m);
     
    for(i = 1;i <= n;++i)
        for(j = 1;j <= n;++j){
            d[i][j] = infinity;
            path[i][j] = j;
    }
     
    for(i=1 ;i <= m;++i) {
            scanf("%d%d%d",&x,&y,&z);
            d[x][y] = z;
            d[y][x] = z;
    }
     
    for(k = 1;k <= n;++k)
        for(i = 1;i <= n;++i)
            for(j = 1;j <= n;++j) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k]+d[k][j];
                    path[i][j] = path[i][k];
                }
            }
    for(i=1;i<=n;++i)
        for(j=1;j<=i;++j)
          if (i!=j) printf("%d->%d:%d\n",i,j,d[i][j]);
    int f, en;
    scanf("%d%d",&f,&en);
    while (f!=en) {
        printf("%d->",f);
        f=path[f][en];
    }
    printf("%d\n",en);
    return 0;
}