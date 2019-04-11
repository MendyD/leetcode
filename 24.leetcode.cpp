/*************************************************************************
	> File Name: 2.LinkList.cpp
	> Author: Mendy
	> Mail: dolai_c@163.com
	> Course: 链表操作
	> Created Time: 二  4/ 9 20:55:06 2019
 ************************************************************************/
#include<stdio.h>
#include <stdlib.h>
//结点结构定义
typedef struct LinkListNode{
    int data;
    struct LinkListNode *next;
} LinkListNode;
//链表结构定义
typedef struct LinkList{
    LinkListNode head;//虚拟头结点
    int length;
} LinkList;

LinkListNode *getNewNode(int val){
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *getNewList(){
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val){
    if(ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = getNewNode(val);
    while(ind--) p = p->next;
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}
LinkList* removeNthFromEnd(LinkList* l, int n) {
        int i = 0;
        LinkListNode *p = &(l->head);
    LinkListNode *q = &(l->head);
    LinkListNode *r = &(l->head);
        while(p->next != NULL){
            p = p->next;
            i++;
        }
        for(int j = 0; j < i - n; j++){
            q = q->next;
        }
        r = q->next;
        q->next = r->next;
        free(r);
        return l;
}
int search(LinkList *l, int val){
    int ind = 0;
    LinkListNode *p = l->head.next;
    while(p && p->data != val) p = p->next, ind +=1;
    if(ind == l->length) return -1;
    return ind;
}

void clear(LinkList *l){
    LinkListNode *p = l->head.next, *q;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

void output(LinkList *l){
    printf("head -> ");
    LinkListNode *p = l->head.next;
    while(p){
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return ;
}

LinkList* swapPairs(LinkList* l) {
    LinkListNode *p = l->head.next, *q, *temp;
        q = p->next;
        p->next = q->next;
        q->next = p;
        l->head.next = q;
    while(p->next->next != NULL){
        if(p->next->next->next != NULL){
            temp = p;
            p = p->next;
            q = p->next;
            p->next = q->next;
            q->next = p;
            temp->next = q;
        }else {
            temp = p;
            p = p->next;
            q = p->next;
            p->next = NULL;
            q->next = p;
            temp->next = q;
        }
    }
    return l;
}

int main(){
    LinkList *l = getNewList();
    LinkList *m;
    int ind, val;
    int  i = 6;
    while(i){
        scanf("%d %d", &ind, &val);
        //~scanf();//~按位取反
        printf("insert %d to LinkList at %d = %d\n", val, ind, insert(l, ind, val));
        output(l);
        //ind = search(l, val);
        //output_search(l, ind);
        i--;
    }
        int nth;
        scanf("%d", &nth);
        m = removeNthFromEnd(l, nth);
        output(m);
    m = swapPairs(l);
    output(m);
    return 0;
}
