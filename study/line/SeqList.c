#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

 /**
 头文件中定义为void 
 实现时定义真实的类型
 
 数据封装
 
 1、对外不用关心list,listNode的真实类型 
 2、不会产生误操作 
 
 */
 
typedef unsigned int TSeqListNode; //存储地址，这样可以适用于任何数据类型，更通用 【查看typedef常见用法】 

typedef struct _tag_SeqList // _tag_SeqList是结构体的标签名 
{
    int capacity;
    int length;
    TSeqListNode* node;
} TSeqList;//结构体的名字 TSeqList ==  struct _tag_SeqList

SeqList* SeqList_Create(int capacity) // O(1)
{
    TSeqList* ret = NULL;
    
    if( capacity >= 0 )
    {
        //结构体本身+数组 
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1);
    }
    
    return ret;
}

void SeqList_Destroy(SeqList* list) // O(1)
{
    free(list);
}

void SeqList_Clear(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list;
    
    if( sList != NULL )
    {
        sList->length = 0;
    }
}

int SeqList_Length(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->length;
    }
    
    return ret;
}

int SeqList_Capacity(SeqList* list) // O(1)
{
    TSeqList* sList = (TSeqList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

// pos 从0开始算起 
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) // O(n) 
{
    TSeqList* sList = (TSeqList*)list;
    int ret = (sList != NULL);
    int i = 0;
    
    ret = ret && (sList->length + 1 <= sList->capacity);
    ret = ret && (0 <= pos);
    
    if( ret )
    {
        if( pos >= sList->length )
        {
            pos = sList->length;
        }
        
        for(i=sList->length; i>pos; i--)
        {
            sList->node[i] = sList->node[i-1];
        }
        
        sList->node[i] = (TSeqListNode)node;
        
        sList->length++;
    }
    
    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) // O(1) 
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = NULL;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->length) )
    {
        ret = (SeqListNode*)(sList->node[pos]);
    }
    
    return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) // O(n)
{
    TSeqList* sList = (TSeqList*)list;
    SeqListNode* ret = SeqList_Get(list, pos);
    int i = 0;
    
    if( ret != NULL )
    {
        for(i=pos+1; i<sList->length; i++)
        {
            sList->node[i-1] = sList->node[i];
        }
        
        sList->length--;
    }
    
    return ret;
}
