# include <stdio.h>
# include <stdbool.h>
# define infinity __INT32_MAX__
void ShortestPath_DIJ(MGraph G,int v0;PathMatrix &P,ShortPathTable &D){
    for(v = 0;v < G.vexnum;++v){    //初始化
        final[v] = false;
        D[v] = G.arcs[v0][v];   //最短距离
        for(w = 0;w < G.vexnum; ++w)
            P[v][w] = false;    //路径数组
        if(D[v] < infinity){
            P[v][v0] = true;
            P[v][v] = true;
        }
    }
    D[v0] = 0;
    final[v0] = true;
    for(i = 0;i<G.vexnum; ++i){ //主循环，每次求得v0到摸个v顶点的最短路径，并加v到S集合中
        min = infinity;
        for(w = 0;w < G.vexnum; ++w)
            if(!final[w])   //选取一个非S中定点，求得距离S最短路径的定点加入S中
                if(D[w] < min){     //选择距V0最短的定点
                    v = w;
                    min = D[w];
                }
        final[v] = true;//加入S中
        for(w = 0;w < G.vexnum; ++w)    //更新当前最短路径及距离
            if(!final[w] && (min + G.arcs[v][w] < D[w])){
                D[w] = min + G.vexnum[v][w];
                P[w] = P[v];
                P[w][w] = true;
            }

    }
}
