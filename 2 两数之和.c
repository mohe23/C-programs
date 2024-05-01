//#ifndef 两数之和_C_INCLUDED
//#define 两数之和_C_INCLUDED
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void Prit(struct ListNode* l1,int la){//打印单链表中所有数据。
    if(1==la)
        printf("计算数：\n");
    else
        printf("计算结果： \n");

    while(l1!=NULL){
        printf("%d ",l1->val);
        l1 = l1->next;
    }
  printf("\n");
}

struct ListNode* CreatList(int*a,int len){//创建单链表
    int i;
    struct ListNode* l=(struct ListNode*)malloc(sizeof(struct ListNode));//作为标记当前单链表的最后1个节点。分配存储空间。*
    struct ListNode* lt=(struct ListNode*)malloc(sizeof(struct ListNode));
    lt->next=NULL;                                                                       //***可以试试如果不分配空间会怎样***
    for(i=0;i<len;i++){
        if(0==i){
            lt->val = a[i];//单链表的第一个节点。
            l = lt;//将标记结点指向链表当前最后1个结点。
        }
        else{
            //ln->val = a[i];
            struct ListNode* ln=(struct ListNode*)malloc(sizeof(struct ListNode));//创建节点，并分配存储空间。
            ln->val = a[i];
            l->next = ln;//将新增节点挂在表尾。
            l = ln;//更新标记结点。
            if((len-1)==i){//创建最后1个节点，
                ln->next=NULL;//保证最后1个节点的next是空。
            }
        }
    }

return lt;
};


struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){
    int w,c,num1,num2,t=0;//w-两数与进位相加之和  c-当前为的计算结果  t-进位。
    struct ListNode *node1,*cnode,*n1,*n2;//node1-结果链表的第一个1个节点。    cnode用来标记结果链表当前最后1个结点。

    node1 = (struct ListNode*)malloc(sizeof(struct ListNode));//为第一个结点分配存储空间。
    cnode = (struct ListNode*)malloc(sizeof(struct ListNode));//一定要为标记结点分配空间，
    n1=l1;
    n2=l2;
    w = n1->val+n2->val+t;//计算相同位的计算结果。
   // printf("w: %d\n",w);
    if(w<10){ //计算结果小于10
        node1->val = w;//结果位就是计算结果。
        t = 0; //没有进位，进位为0
    }
    else{//结果大于9
        node1->val = w%10;
        t = 1;
    }
    node1->next=NULL;//确保计算结果只有1位时，结点的next是空。
    cnode = node1;
    while((n1->next!=NULL)||(n2->next!=NULL)){//判断条件是“或”，循环一直到2个单链表都走完。
       struct ListNode*Enode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(n1->next!=NULL&&n2->next!=NULL){ //表1，表2都没有循环完。
            num1 = n1->next->val;
            num2 = n2->next->val;
            n1 = n1->next;
            n2 = n2->next;
            //printf("111\n");
        }
        else if(n1->next==NULL&&n2->next!=NULL){ //单链表1循环完了，单链表2还没有循环完。
             num1 = 0;
             num2 = n2->next->val;
             //n1 = n1;//n1保持不变
             n1 = n1; //当循环到1个数的最后1位，即最高位时，next要指向其本身，不能简单的next，否则就陷入死循环，然后输出不了任何结果。
             n2 = n2->next;//指向下一个结点。
             // printf("222\n");
        }
        else{ //if(n1->next!=NULL&&n2->next==NULL){ //计算数1的位数大于计算数2.
             num1 = n1->next->val;
             num2 = 0;
             n1 = n1->next;//n1指向下一个结点
             //n2 = n2;//n2保持不变。
             n2 = n2;
             // printf("333\n");
        }

      w = num1 + num2 + t;//计算相关结果。
     // printf("w:  %d\n",w);
      if(w<10){
        Enode->val = w;//结果位
        t = 0; //进位是0
      }
      else{//计算结果大于9
        Enode->val = w%10;
        t = 1;
      }
     cnode->next = Enode;//将节点连串起来。
     cnode = Enode;//将标记结点指向链表最后1个结点。
     //printf("cnode->val:  %d\n",cnode->val);
     //printf("t: %d\n",t);
    //此时来到最高位的计算，
    }
     //struct ListNode*er = (struct ListNode*)malloc(sizeof(struct ListNode));
//printf("wwwwwww\n");
     if(t==1){ //最后1位的计算结果有进位。要新加一位
            //printf("！！！！！\n");
               struct ListNode*e = (struct ListNode*)malloc(sizeof(struct ListNode));//新加1位结点。
                e->val = 1;//当前位是1。
                e->next = NULL;
                cnode->next = e;//将新增加的节点挂在结果链表的表尾。
               // printf("extra w:  1\n");
     }
//printf("return front!!!!\n");
return node1;
//printf("return aft!!!!\n");
};

int main(){
   /* int t1,t2,t3,t4,t5,t6,t7;
    t1=5;
    t2=2;
    t3=9;
    t4=7;
    t5=4;
    t6=5;
    t7=9;
    struct ListNode*r,*r1,*r2;
    //r=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*c1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*c2=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*c3=(struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode*d1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*d2=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*d3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode*d4=(struct ListNode*)malloc(sizeof(struct ListNode));

    c1->val = t1;
    c2->val = t2;
    c3->val = t3;
    d1->val = t4;
    d2->val = t5;
    d3->val = t6;
    d4->val = t7;

    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;
    d1->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = NULL;

     printf("r front!!!\n");
     r = addTwoNumbers(d1,c1);//计算结果，结果是逆序的。
     printf("r next!!!!\n");
     //r1 = r->next;
    // r2 = r1->next;
    //q = r;
    printf("计算数：\n");
    printf("%d %d %d\n",t1,t2,t3);
    //printf("%d %d %d\n",t4,t5,t6);
     printf("%d %d %d %d\n",t4,t5,t6,t7);

     printf("计算结果： \n");
    while(r!=NULL){
        printf("%d ",r->val);
        r=r->next;
    }
   /*
    printf("%d ",r->val);
      r=r->next;
    printf("%d ",r->val);
      r=r->next;
    printf("%d ",r->val);
       r=r->next;
     printf("%d ",r->val);
            r=r->next;
     printf("%d\n",r->val);
*/

  int m[1]={0};
  int n[1]={0};
  struct ListNode* k,*j,*g;
  k = CreatList(m,1);//创建单链表
  j = CreatList(n,1);
  Prit(k,1);
  Prit(j,1);
  g = addTwoNumbers(k,j);
  Prit(g,0);

return 0;
}
//#endif // 两数之和_C_INCLUDED
