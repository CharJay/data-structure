#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX_N 100+7
#define MAX_M 100000+7
#define INF 10000000+7
using namespace std;

int i,j;
int n,m,s,e;//点 路 起点 终点 

bool vis[MAX_N];
int dist[MAX_N];//距离数组 
int path[MAX_N];//路径数据 
int id[MAX_N];//点数据 

int head[MAX_N];//?? 
int next[2*MAX_M];//??
int tot = 0;

struct Edge {
	int to;
	int val;//权重 
} edge[2*MAX_M];

//添加路径
void addEdge(int u ,int v, int w) {
//	printf("addEdge u=%d v=%d w=%d \n",u,v,w);
	edge[++tot].to = v;//0是空的 
	edge[tot].val = w;
	next[tot] = head[u];//12条路径（无向图） ,记录5个点的路径索引历史 
	head[u] = tot;//5个点 ,记录5个点最后的索引 
}

void spfa() { //源点到结点距离dist 最短路径条数path
	queue<int> que;
	que.push(s);
	vis[s] = true;

	while(!que.empty()) {
		int u = que.front();
		printf("==== 出队列 %d \n",u);
		for(j = head[u]; j ; j = next[j]) {
			int v = edge[j].to;
			int minDist = dist[u]+edge[j].val;
			printf("===[from%d - to%d] head=%d dist from=%d dist to=%d[%d] to.val=%d\n",u,v,j,dist[u],dist[v],minDist,edge[j].val);
//			printf("== head[u]=%d edge[j].to=%d dist[u]=%d edge[j].val=%d dist[v]=%d\n",j,v,dist[u],edge[j].val,dist[v]);
			if(minDist < dist[v]) {
				dist[v] = minDist;//找到最小距离 
				if(!vis[v]) {
					que.push(v);
					vis[v] = true;
				}
			}
		}
		que.pop();
		vis[u] = false;
	}
}

bool cmp(int a,int b) {
	return dist[a] < dist[b];
}


/**
无向图 

问题： 
N个地点，M条道路 
亚索所在的地点编号为S，泉水地点编号为E 
接下来M行每三个整数 u v w表示地点u到地点v的距离为w


结果：求最短回城路径 
输入：
5 6 1 5
1 2 5
2 5 5
1 3 3
3 5 7
1 4 1
4 5 9

输出：
有3条路，距离都是10
10 3 
**/ 
int main() {
	
//	printf("123"); 
	
	//n个点 m条路 当前s 目的地e 
	scanf("%d%d%d%d",&n,&m,&s,&e);
	int u,v,w;
	for(i = 1; i <= m; i++) {//对路进行 
		//地点u到地点v的距离为w 
		scanf("%d%d%d",&u,&v,&w);
		//无向图左右都有 
		addEdge(u,v,w); 
		addEdge(v,u,w);
	}
	//0 0 2 0 1 0 6 4 5 0 10 8 0 0 0 0 0 0 0 0
	printf("\n==============\n"); 
	for(i = 1; i <= m*2; i++){
		printf("%d ",next[i]); 
	} 
	printf("\n==============\n"); 
	//9 3 7 11 12 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	for(i = 1; i <= n; i++){
		printf("%d ",head[i]); 
	}
	printf("\n==============\n"); 
	
	//初始化数据 
	for(i = 1; i <= n; i++) {
		id[i] = i;
		dist[i] = INF;
	}
	//距离与路径 
	dist[s] = 0;
	path[s] = 1;

	spfa();
	
	printf("\ndist:"); 
	for(i = 1; i <= n; i++){
		printf("%d ",dist[i]); 
	}
	printf("\npath:"); 
	for(i = 1; i <= n; i++){
		printf("%d ",path[i]); 
	}
	printf("\n"); 
	
	sort(id+1,id+n+1,cmp); //按dist距离排序id 
	for(i = 1; i <= n; i++) { //从s开始更新每个较近结点
		int index = id[i];
		printf("id=%d\n",index);
		for(j = head[index]; j ; j = next[j]) {
			int t = edge[j].to;
			if(dist[index]+edge[j].val < dist[t])
				path[t] = path[index];
			else if(dist[index]+edge[j].val == dist[t])
				path[t] += path[index];
		}
	}
	
	printf("\ndist:"); 
	for(i = 1; i <= n; i++){
		printf("%d ",dist[i]); 
	}
	printf("\npath:"); 
	for(i = 1; i <= n; i++){
		printf("%d ",path[i]); 
	}
	printf("\n"); 
	
	printf("from%d-to%d 的距离=%d 路径=%d\n",s,e,dist[e],path[e]);
	printf("1到3点的距离=%d 路径=%d\n",dist[3],path[3]);
	return 0;
}

