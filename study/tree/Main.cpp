typedef char TElemType;
# include "stdlib.h"
# include <iostream>
using namespace std;


void Visit(TElemType e) {           // 访问函数定义为输出操作
	cout<<e<<' ';
}

//树
# define MAX_TREE_SIZE  100         // 树中结点的最大个数
# define MAX_SON_SIZE  3            // 树的度
//# include "CTree.h"                 // 该文件包含树数据对象的描述及相关操作

void ctreeTest() {
	//输入 A(B(D,E(G,)),C(,F))
//	CTree T;
//	InitTree(T);
//	char str[50];                          // 存放用广义表字符表示的树
//	cout<<"输入一棵"<<MAX_SON_SIZE<<"度树的广义表字符串：";
//	cin>>str;
//	CreateTree(T,str);                    // 创建树
//	cout<<"先序遍历结果：";
//	PreOrderTree(T,Visit);
//	cout<<endl<<"后序遍历结果：";
//	PostOrderTree(T,Visit);
//	cout<<endl<<"层序遍历结果：";
//	LevelOrderTree(T,Visit);
//	cout<<endl<<"按广义表形式输出的"<<MAX_SON_SIZE<<"度树为：";
//	PrintTree(T);
//	cout<<endl;
//	cout<<"树的深度："<<TreeDepth(T)<<endl;
//	cout<<"输入待查找的一个字符：";
//	char ch;
//	cin>>ch;
//	if(SearchTree(T,ch))  cout<<"查找成功！"<<endl;
//	else cout<<"查找失败！"<<endl;
//	DestroyTree(T);
}


//二叉树
TElemType Nil='#';                 // 用'#'表示空
# define MAX_BITREE_SIZE 100      // 二叉树中的最大结点数
# include "BiTree.h"
void biTree() {
	//输入 ：1 1 3 4 5 6 # # # # (多个#号结束树)
	int i;
	BiTree BT,p,c;
	TElemType e1,e2;
	InitBiTree(BT);                                  // 初始化二叉树BT
	cout<<"构造空二叉树后，树空否？"<<BiTreeEmpty(BT);
	cout<<"(1：是 0：否)。树的深度="<<BiTreeDepth(BT)<<endl;
	cout<<"请按先序输入二叉树(用'#'表示子树为空)："<<endl;
	CreateBiTree(BT);                                 // 建立二叉树BT
	cout<<"建立二叉树后，树空否？"<<BiTreeEmpty(BT);
	cout<<"(1：是 0：否)。树的深度="<<BiTreeDepth(BT)<<endl;
	cout<<"先序递归遍历二叉树：";
	PreOrderBiTree(BT,Visit);                          // 先序递归遍历二叉树BT
	cout<<endl<<"中序递归遍历二叉树：";
	InOrderBiTree(BT,Visit);                           // 中序递归遍历二叉树BT
	cout<<endl<<"后序递归遍历二叉树：";
	PostOrderBiTree(BT,Visit);                          // 后序递归遍历二叉树BT
	cout<<endl<<"先序非递归遍历二叉树：";
	NRPreOrderBiTree(BT,Visit);                         // 先序非递归遍历二叉树BT
	cout<<endl<<"中序非递归遍历二叉树：";
	NRInOrderBiTree(BT,Visit);                          // 中序非递归遍历二叉树BT
	cout<<endl<<"后序非递归遍历二叉树：";
	NRPostOrderBiTree(BT,Visit);                        // 后序非递归遍历二叉树BT
	cout<<endl<<"层序遍历二叉树：";
	LevelOrderBiTree(BT,Visit);                         // 层序递归遍历二叉树BT
	cout<<endl<<"用凹入表的形式打印二叉树BT："<<endl;
	PrintBiTree(BT,1);                                  // 输出二叉树BT
	cout<<endl<<"请输入一个待查结点的值：";
	cin>>e1;
	p=SearchBiTree(BT,e1);                              // p指向为e1的指针
	if(p) cout<<"查找成功！结点的值为："<<p->data<<endl;
	else cout<<"查找失败！"<<endl;
	cout<<"请输入一个待查结点的值：";
	cin>>e2;
	p=Parent(BT,e2);                                   // 查找e2的双亲
	if(p) cout<<e2<<"的双亲是"<<p->data<<endl;         // 双亲存在
	else  cout<<e2<<"没有双亲！"<<endl;
	p=LeftChild(BT,e2); // 查找e2的左孩子
	if(p)  cout<<e2<<"的左孩子是"<<p->data<<endl;      // 左孩子存在
	else   cout<<e2<<"没有左孩子！"<<endl;
	p=RightChild(BT,e2);                               // 查找e2的右孩子
	if(p) cout<<e2<<"的右孩子是"<<p->data<<endl;       // 右孩子存在
	else  cout<<e2<<"没有右孩子！"<<endl;
	p=LeftSibling(BT,e2);                              // 查找e2的左兄弟
	if(p) cout<<e2<<"的左兄弟是"<<p->data<<endl;        // 左兄弟存在
	else cout<<e2<<"没有左兄弟！"<<endl;
	p=RightSibling(BT,e2);                            // 查找e2的右兄弟
	if(p) cout<<e2<<"的右兄弟是"<<p->data<<endl;      // 右兄弟存在
	else cout<<e2<<"没有右兄弟！"<<endl;
	InitBiTree(c);                                    // 初始化二叉树c
	cout<<"请构造一个右子树为空的二叉树c："<<endl;
	cout<<"请按先序输入二叉树(用'#'表示子树为空)：";
	CreateBiTree(c);                                // 建立二叉树c
	cout <<"树c插到树BT中，请输入树BT中树c的双亲结点的值：";
	cin>>e1;
	cout<<"c为其左子树请输入0，为其右子树请输入1：";
	cin>>i;
	p=SearchBiTree(BT,e1);   // p指向二叉树BT中将作为二叉树c的双亲结点的e1
	InsertChild(p,i,c);      // 将树c作为p的左（右）子树插入到二叉树BT中
	cout<<"中序递归遍历插入子树c后的二叉树BT：";
	InOrderBiTree(BT,Visit);             // 中序递归遍历二叉树BT
	cout<<endl<<"删除子树，请输入待删除子树的双亲结点的值:";
	cin>>e1;
	cout<<"删除其左子树请输入0，删除其右子树请输入1：";
	cin>>i;
	p=SearchBiTree(BT,e1);     // p指向二叉树BT中将作为二叉树c的双亲结点的e1
	DeleteChild(p,i);          // 删除p所指结点(e1)的左)或右子树
	cout<<"中序递归遍历删除子树后的二叉树BT：";
	InOrderBiTree(BT,Visit);          // 中序递归遍历二叉树BT
	DestroyBiTree(BT);                 // 撤销二叉树BT
}

//哈夫曼树
# define MAXVALUE  10000       // 叶结点的权值最大值
# define MAXBIT  10           // 最大编码位数
# include "HuffmanTree.h"      // 该文件包含构造哈夫曼树和哈夫曼编码的操作
void huffmanTree() {
	int i,j,*w,n;
	HuffmanTree HT;
	HuffmanCode HC;
	cout<<"请输入权值的个数：";
	cin>>n;
	w=(int*)malloc(n*sizeof(int));         // 动态生成存放n个权值的空间
	cout<<"请依次输入"<<n<<"个权值(整型)：";
	for(i=0; i<=n-1; i++)
		cin>>w[i];                            // 依次输入权值
	HuffmanTreeing(HT,w,n);                 // 根据w所存的n个权值构造赫夫曼树HT
	HuffmanCoding(HT,HC,n);                 // n个赫夫曼编码存于HC
	for(i=0; i<n; i++) {                    // 依次输出赫夫曼编码
		cout<<"Weight="<<HT[i].weight<<"  Code=";
		for(j=HC[i].start; j<MAXBIT; j++)
			cout<<HC[i].bit[j];
		cout<<endl;
	}
}


int main() {
//	ctreeTest();
//	biTree();
	huffmanTree();
	return 1;
}

