#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "LinkList.h"
#include "StaticList.h"
#include "CircleList.h"
#include "DLinkList.h"

void seqTest();//顺序表
void linkTest();//单链表
void staticTest();//静态链表
void circleTest();//循环链表
void dlinkTest();//双向链表



int main(int argc, char *argv[]) 
{
	
//    seqTest();
//    linkTest();
//    staticTest();
    circleTest();
//    dlinkTest();
    
    return 0;
}


void seqTest(){
	SeqList* list = SeqList_Create(5);
    
    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    int index = 0;
    
   /**
   找不到  TSeqList 因为在 SeqList.c 中定义 
    TSeqList *a = (TSeqList*)list;
    a->length = 0;
   */
   
    // 由于list是void*类型，所以不被允许，更加安全 
      // list->length = 0; 
    
    SeqList_Insert(list, &i, 0);
    SeqList_Insert(list, &j, 0);
    SeqList_Insert(list, &k, 0);
    SeqList_Insert(list, &x, 0);
    SeqList_Insert(list, &y, 0);
    SeqList_Insert(list, &z, 0);
    
    for(index=0; index<SeqList_Length(list); index++)
    {
        int* p = (int*)SeqList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    while( SeqList_Length(list) > 0 )
    {
        int* p = (int*)SeqList_Delete(list, 0);
        
        printf("%d\n", *p);
    }
    
    SeqList_Destroy(list);
}



struct LinkValue
{
    LinkListNode header;
    int v;
};
void linkTest(){
	 int i = 0;
    LinkList* list = LinkList_Create();
    
    struct LinkValue v1;
    struct LinkValue v2;
    struct LinkValue v3;
    struct LinkValue v4;
    struct LinkValue v5;
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    
    //尾插法建立链表
     
    LinkList_Insert(list, (LinkListNode*)&v1, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v2, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v3, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v4, LinkList_Length(list));
    LinkList_Insert(list, (LinkListNode*)&v5, LinkList_Length(list));
    
    for(i=0; i<LinkList_Length(list); i++)
    {
        struct LinkValue* pv = (struct LinkValue*)LinkList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    while( LinkList_Length(list) > 0 )
    {
        struct LinkValue* pv = (struct LinkValue*)LinkList_Delete(list, 0);
        
        printf("%d\n", pv->v);
    }
    
    LinkList_Destroy(list);
}



void staticTest(){
	StaticList* list = StaticList_Create(10);
    
    int index = 0;
    
    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    
    StaticList_Insert(list, &i, 0);
    StaticList_Insert(list, &j, 0);
    StaticList_Insert(list, &k, 0);
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    while( StaticList_Length(list) > 0 )
    {
        int* p = (int*)StaticList_Delete(list, 0);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    StaticList_Insert(list, &x, 0);
    StaticList_Insert(list, &y, 0);
    StaticList_Insert(list, &z, 0);
    
    printf("Capacity: %d Length: %d\n", StaticList_Capacity(list), StaticList_Length(list));
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    StaticList_Destroy(list);
}


struct CircleValue
{
    CircleListNode header;
    int v;
};
void circleTest(){
	int i = 0;

    CircleList* list = CircleList_Create();
    
    struct CircleValue v1;
    struct CircleValue v2;
    struct CircleValue v3;
    struct CircleValue v4;
    struct CircleValue v5;
    struct CircleValue v6;
    struct CircleValue v7;
    struct CircleValue v8;
    
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    v6.v = 6;
    v7.v = 7;
    v8.v = 8;
    
    CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
    
    CircleList_Insert(list, (CircleListNode*)&v5, 5);
    CircleList_Delete(list, 0);
    
    for(i=0; i<2*CircleList_Length(list); i++)
    {
        struct CircleValue* pv = (struct CircleValue*)CircleList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    while( CircleList_Length(list) > 0 )
    {
        struct CircleValue* pv = (struct CircleValue*)CircleList_Delete(list, 0);
        
        printf("%d\n", pv->v);
    }
    
   
   
    CircleList_Destroy(list);
    
} 


struct DLinkValue
{
    DLinkListNode header;
    int v;
};
void dlinkTest(){
	int i = 0;
    DLinkList* list = DLinkList_Create();
    struct DLinkValue* pv = NULL;
    struct DLinkValue v1;
    struct DLinkValue v2;
    struct DLinkValue v3;
    struct DLinkValue v4;
    struct DLinkValue v5;
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    
    DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
    DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));
    
    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct DLinkValue*)DLinkList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    DLinkList_Delete(list, DLinkList_Length(list)-1);
    DLinkList_Delete(list, 0);
    
    for(i=0; i<DLinkList_Length(list); i++)
    {
        pv = (struct DLinkValue*)DLinkList_Next(list);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    DLinkList_Reset(list);
    DLinkList_Next(list);
    
    pv = (struct DLinkValue*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_DeleteNode(list, (DLinkListNode*)pv);
    
    pv = (struct DLinkValue*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    DLinkList_Pre(list);
    
    pv = (struct DLinkValue*)DLinkList_Current(list);
    
    printf("%d\n", pv->v);
    
    printf("Length: %d\n", DLinkList_Length(list));
    
    DLinkList_Destroy(list);
} 
