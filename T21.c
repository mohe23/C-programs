// 合并2个有序链表(升序)。

#include<stdio.h>
#include<stdlib.h>

 struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    //
    struct ListNode *Node1,*Node2,*rear,*re;//3个分别是表一指针，表二指针，以及合并后的链表的尾指针。
    int f=0;// 用这个作为标记，判断是不是第1次比较。
    Node1 = list1; Node2=list2; //rear=list1;//将list1作为合并的链表的头指针。
    // 力扣题目中单链表没有头结点，第1个结点就是数据结点。
    if(NULL==Node1)//包含2种，Node2空或Node2不空。
        re = list2;
    else if(NULL!=Node1&&NULL==Node2)//表二空，表一不空。
        re = list1;
    else{// 表一与表二都不空。
        //Node1=Node1->next; Node2=Node2->next;//此时将指针指向2个链表中的数据结点。
        while(Node1&&Node2){// 循环条件：2个链表都没有扫描完毕
            if(Node2->val > Node1->val){//list1当前结点的值小。
                if(0==f){// 通过第1次判断，表一的第1个结点的数值小，所以将返回值定为list1.
                    re = list1;// 返回表一的指针。
                    rear = list1;
                    f++;
                }
                else{//第2次及以后的比较
                    rear->next = Node1;
                    rear = Node1;
                }

                Node1 = Node1->next;//

            }
            else{// list2当前结点的值小。
                if(0==f){
                    re = list2;//返回的是表二的指针。
                    rear = list2;
                    f++;
                }
                else{
                     rear->next = Node2;
                     rear = Node2;
                }

                Node2 = Node2->next;//将较小结点的指针向右减1。
            }
        }
        if(NULL!=Node1){//此时表二扫描完毕，而表一未扫描完毕。
            rear->next = Node1;//直接将表一剩余部分插入到合并的位置。因为是合并前与合并后都是升序。要是合并前与合并后
                               //序位相反，才要结点一个一个的插入到合并链表中。
        }
        else{// 表一扫描完毕，表二未扫描完毕。

             rear->next = Node2;
        }
    }


return re;
}

