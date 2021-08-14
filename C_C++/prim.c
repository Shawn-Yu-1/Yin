# include <stdio.h>

void MiniSpanTree_PRIM(MGraph G,VertexType u){
    /*struct{
        VertexType adjvex;
        VRType lowcost;
    }closedge[Max_vertex_num];
    */
    k = LocateVex(G,u);
    for(j = 0;j < G.vexnum; ++j)    //初始化
        if(j!= k)
            closedge[j] = {u,G.arcs[k][j].adj};
    closedge[k].lowcost = 0;
    for(i = 1;i < G.vexnum; ++i){   //主循环，依次将其余定点加入
        k = minmum(closedge);   //求出下一个定点
        printf(closedge[k].adjvex.G.vexs[k]);
        closedge[k].lowcost = 0;    //将该顶点并入生成树中
        for(j = 0;j < G.vexnum; ++j)    //更新其余节点的到该集合的最小弧长
            if(G.arcs[k][j].adj < closedge[j].lowcost)
                closedge[j] = {G.vexs[k],G.arcs[k][j].adj};
    }
}