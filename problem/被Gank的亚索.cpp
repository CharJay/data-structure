#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX_N 100+7
#define MAX_M 100000+7
#define INF 10000000+7
using namespace std;

int i,j;
int n,m,s,e;//�� · ��� �յ� 

bool vis[MAX_N];
int dist[MAX_N];//�������� 
int path[MAX_N];//·������ 
int id[MAX_N];//������ 

int head[MAX_N];//?? 
int next[2*MAX_M];//??
int tot = 0;

struct Edge {
	int to;
	int val;//Ȩ�� 
} edge[2*MAX_M];

//���·��
void addEdge(int u ,int v, int w) {
//	printf("addEdge u=%d v=%d w=%d \n",u,v,w);
	edge[++tot].to = v;//0�ǿյ� 
	edge[tot].val = w;
	next[tot] = head[u];//12��·��������ͼ�� ,��¼5�����·��������ʷ 
	head[u] = tot;//5���� ,��¼5������������ 
}

void spfa() { //Դ�㵽������dist ���·������path
	queue<int> que;
	que.push(s);
	vis[s] = true;

	while(!que.empty()) {
		int u = que.front();
		printf("==== ������ %d \n",u);
		for(j = head[u]; j ; j = next[j]) {
			int v = edge[j].to;
			int minDist = dist[u]+edge[j].val;
			printf("===[from%d - to%d] head=%d dist from=%d dist to=%d[%d] to.val=%d\n",u,v,j,dist[u],dist[v],minDist,edge[j].val);
//			printf("== head[u]=%d edge[j].to=%d dist[u]=%d edge[j].val=%d dist[v]=%d\n",j,v,dist[u],edge[j].val,dist[v]);
			if(minDist < dist[v]) {
				dist[v] = minDist;//�ҵ���С���� 
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
����ͼ 

���⣺ 
N���ص㣬M����· 
�������ڵĵص���ΪS��Ȫˮ�ص���ΪE 
������M��ÿ�������� u v w��ʾ�ص�u���ص�v�ľ���Ϊw


���������̻س�·�� 
���룺
5 6 1 5
1 2 5
2 5 5
1 3 3
3 5 7
1 4 1
4 5 9

�����
��3��·�����붼��10
10 3 
**/ 
int main() {
	
//	printf("123"); 
	
	//n���� m��· ��ǰs Ŀ�ĵ�e 
	scanf("%d%d%d%d",&n,&m,&s,&e);
	int u,v,w;
	for(i = 1; i <= m; i++) {//��·���� 
		//�ص�u���ص�v�ľ���Ϊw 
		scanf("%d%d%d",&u,&v,&w);
		//����ͼ���Ҷ��� 
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
	
	//��ʼ������ 
	for(i = 1; i <= n; i++) {
		id[i] = i;
		dist[i] = INF;
	}
	//������·�� 
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
	
	sort(id+1,id+n+1,cmp); //��dist��������id 
	for(i = 1; i <= n; i++) { //��s��ʼ����ÿ���Ͻ����
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
	
	printf("from%d-to%d �ľ���=%d ·��=%d\n",s,e,dist[e],path[e]);
	printf("1��3��ľ���=%d ·��=%d\n",dist[3],path[3]);
	return 0;
}

