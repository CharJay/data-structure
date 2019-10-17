typedef char TElemType;
# include "stdlib.h"
# include <iostream>
using namespace std;


void Visit(TElemType e) {           // ���ʺ�������Ϊ�������
	cout<<e<<' ';
}

//��
# define MAX_TREE_SIZE  100         // ���н���������
# define MAX_SON_SIZE  3            // ���Ķ�
//# include "CTree.h"                 // ���ļ����������ݶ������������ز���

void ctreeTest() {
	//���� A(B(D,E(G,)),C(,F))
//	CTree T;
//	InitTree(T);
//	char str[50];                          // ����ù�����ַ���ʾ����
//	cout<<"����һ��"<<MAX_SON_SIZE<<"�����Ĺ�����ַ�����";
//	cin>>str;
//	CreateTree(T,str);                    // ������
//	cout<<"������������";
//	PreOrderTree(T,Visit);
//	cout<<endl<<"������������";
//	PostOrderTree(T,Visit);
//	cout<<endl<<"������������";
//	LevelOrderTree(T,Visit);
//	cout<<endl<<"���������ʽ�����"<<MAX_SON_SIZE<<"����Ϊ��";
//	PrintTree(T);
//	cout<<endl;
//	cout<<"������ȣ�"<<TreeDepth(T)<<endl;
//	cout<<"��������ҵ�һ���ַ���";
//	char ch;
//	cin>>ch;
//	if(SearchTree(T,ch))  cout<<"���ҳɹ���"<<endl;
//	else cout<<"����ʧ�ܣ�"<<endl;
//	DestroyTree(T);
}


//������
TElemType Nil='#';                 // ��'#'��ʾ��
# define MAX_BITREE_SIZE 100      // �������е��������
# include "BiTree.h"
void biTree() {
	//���� ��1 1 3 4 5 6 # # # # (���#�Ž�����)
	int i;
	BiTree BT,p,c;
	TElemType e1,e2;
	InitBiTree(BT);                                  // ��ʼ��������BT
	cout<<"����ն����������շ�"<<BiTreeEmpty(BT);
	cout<<"(1���� 0����)���������="<<BiTreeDepth(BT)<<endl;
	cout<<"�밴�������������(��'#'��ʾ����Ϊ��)��"<<endl;
	CreateBiTree(BT);                                 // ����������BT
	cout<<"���������������շ�"<<BiTreeEmpty(BT);
	cout<<"(1���� 0����)���������="<<BiTreeDepth(BT)<<endl;
	cout<<"����ݹ������������";
	PreOrderBiTree(BT,Visit);                          // ����ݹ����������BT
	cout<<endl<<"����ݹ������������";
	InOrderBiTree(BT,Visit);                           // ����ݹ����������BT
	cout<<endl<<"����ݹ������������";
	PostOrderBiTree(BT,Visit);                          // ����ݹ����������BT
	cout<<endl<<"����ǵݹ������������";
	NRPreOrderBiTree(BT,Visit);                         // ����ǵݹ����������BT
	cout<<endl<<"����ǵݹ������������";
	NRInOrderBiTree(BT,Visit);                          // ����ǵݹ����������BT
	cout<<endl<<"����ǵݹ������������";
	NRPostOrderBiTree(BT,Visit);                        // ����ǵݹ����������BT
	cout<<endl<<"���������������";
	LevelOrderBiTree(BT,Visit);                         // ����ݹ����������BT
	cout<<endl<<"�ð�������ʽ��ӡ������BT��"<<endl;
	PrintBiTree(BT,1);                                  // ���������BT
	cout<<endl<<"������һ���������ֵ��";
	cin>>e1;
	p=SearchBiTree(BT,e1);                              // pָ��Ϊe1��ָ��
	if(p) cout<<"���ҳɹ�������ֵΪ��"<<p->data<<endl;
	else cout<<"����ʧ�ܣ�"<<endl;
	cout<<"������һ���������ֵ��";
	cin>>e2;
	p=Parent(BT,e2);                                   // ����e2��˫��
	if(p) cout<<e2<<"��˫����"<<p->data<<endl;         // ˫�״���
	else  cout<<e2<<"û��˫�ף�"<<endl;
	p=LeftChild(BT,e2); // ����e2������
	if(p)  cout<<e2<<"��������"<<p->data<<endl;      // ���Ӵ���
	else   cout<<e2<<"û�����ӣ�"<<endl;
	p=RightChild(BT,e2);                               // ����e2���Һ���
	if(p) cout<<e2<<"���Һ�����"<<p->data<<endl;       // �Һ��Ӵ���
	else  cout<<e2<<"û���Һ��ӣ�"<<endl;
	p=LeftSibling(BT,e2);                              // ����e2�����ֵ�
	if(p) cout<<e2<<"�����ֵ���"<<p->data<<endl;        // ���ֵܴ���
	else cout<<e2<<"û�����ֵܣ�"<<endl;
	p=RightSibling(BT,e2);                            // ����e2�����ֵ�
	if(p) cout<<e2<<"�����ֵ���"<<p->data<<endl;      // ���ֵܴ���
	else cout<<e2<<"û�����ֵܣ�"<<endl;
	InitBiTree(c);                                    // ��ʼ��������c
	cout<<"�빹��һ��������Ϊ�յĶ�����c��"<<endl;
	cout<<"�밴�������������(��'#'��ʾ����Ϊ��)��";
	CreateBiTree(c);                                // ����������c
	cout <<"��c�嵽��BT�У���������BT����c��˫�׽���ֵ��";
	cin>>e1;
	cout<<"cΪ��������������0��Ϊ��������������1��";
	cin>>i;
	p=SearchBiTree(BT,e1);   // pָ�������BT�н���Ϊ������c��˫�׽���e1
	InsertChild(p,i,c);      // ����c��Ϊp�����ң��������뵽������BT��
	cout<<"����ݹ������������c��Ķ�����BT��";
	InOrderBiTree(BT,Visit);             // ����ݹ����������BT
	cout<<endl<<"ɾ���������������ɾ��������˫�׽���ֵ:";
	cin>>e1;
	cout<<"ɾ����������������0��ɾ����������������1��";
	cin>>i;
	p=SearchBiTree(BT,e1);     // pָ�������BT�н���Ϊ������c��˫�׽���e1
	DeleteChild(p,i);          // ɾ��p��ָ���(e1)����)��������
	cout<<"����ݹ����ɾ��������Ķ�����BT��";
	InOrderBiTree(BT,Visit);          // ����ݹ����������BT
	DestroyBiTree(BT);                 // ����������BT
}

//��������
# define MAXVALUE  10000       // Ҷ����Ȩֵ���ֵ
# define MAXBIT  10           // ������λ��
# include "HuffmanTree.h"      // ���ļ�����������������͹���������Ĳ���
void huffmanTree() {
	int i,j,*w,n;
	HuffmanTree HT;
	HuffmanCode HC;
	cout<<"������Ȩֵ�ĸ�����";
	cin>>n;
	w=(int*)malloc(n*sizeof(int));         // ��̬���ɴ��n��Ȩֵ�Ŀռ�
	cout<<"����������"<<n<<"��Ȩֵ(����)��";
	for(i=0; i<=n-1; i++)
		cin>>w[i];                            // ��������Ȩֵ
	HuffmanTreeing(HT,w,n);                 // ����w�����n��Ȩֵ����շ�����HT
	HuffmanCoding(HT,HC,n);                 // n���շ����������HC
	for(i=0; i<n; i++) {                    // ��������շ�������
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

