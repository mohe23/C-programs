//#ifndef ����֮��_C_INCLUDED
//#define ����֮��_C_INCLUDED
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void Prit(struct ListNode* l1,int la){//��ӡ���������������ݡ�
    if(1==la)
        printf("��������\n");
    else
        printf("�������� \n");

    while(l1!=NULL){
        printf("%d ",l1->val);
        l1 = l1->next;
    }
  printf("\n");
}

struct ListNode* CreatList(int*a,int len){//����������
    int i;
    struct ListNode* l=(struct ListNode*)malloc(sizeof(struct ListNode));//��Ϊ��ǵ�ǰ����������1���ڵ㡣����洢�ռ䡣*
    struct ListNode* lt=(struct ListNode*)malloc(sizeof(struct ListNode));
    lt->next=NULL;                                                                       //***�����������������ռ������***
    for(i=0;i<len;i++){
        if(0==i){
            lt->val = a[i];//������ĵ�һ���ڵ㡣
            l = lt;//����ǽ��ָ������ǰ���1����㡣
        }
        else{
            //ln->val = a[i];
            struct ListNode* ln=(struct ListNode*)malloc(sizeof(struct ListNode));//�����ڵ㣬������洢�ռ䡣
            ln->val = a[i];
            l->next = ln;//�������ڵ���ڱ�β��
            l = ln;//���±�ǽ�㡣
            if((len-1)==i){//�������1���ڵ㣬
                ln->next=NULL;//��֤���1���ڵ��next�ǿա�
            }
        }
    }

return lt;
};


struct ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2){
    int w,c,num1,num2,t=0;//w-�������λ���֮��  c-��ǰΪ�ļ�����  t-��λ��
    struct ListNode *node1,*cnode,*n1,*n2;//node1-�������ĵ�һ��1���ڵ㡣    cnode������ǽ������ǰ���1����㡣

    node1 = (struct ListNode*)malloc(sizeof(struct ListNode));//Ϊ��һ��������洢�ռ䡣
    cnode = (struct ListNode*)malloc(sizeof(struct ListNode));//һ��ҪΪ��ǽ�����ռ䣬
    n1=l1;
    n2=l2;
    w = n1->val+n2->val+t;//������ͬλ�ļ�������
   // printf("w: %d\n",w);
    if(w<10){ //������С��10
        node1->val = w;//���λ���Ǽ�������
        t = 0; //û�н�λ����λΪ0
    }
    else{//�������9
        node1->val = w%10;
        t = 1;
    }
    node1->next=NULL;//ȷ��������ֻ��1λʱ������next�ǿա�
    cnode = node1;
    while((n1->next!=NULL)||(n2->next!=NULL)){//�ж������ǡ��򡱣�ѭ��һֱ��2�����������ꡣ
       struct ListNode*Enode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(n1->next!=NULL&&n2->next!=NULL){ //��1����2��û��ѭ���ꡣ
            num1 = n1->next->val;
            num2 = n2->next->val;
            n1 = n1->next;
            n2 = n2->next;
            //printf("111\n");
        }
        else if(n1->next==NULL&&n2->next!=NULL){ //������1ѭ�����ˣ�������2��û��ѭ���ꡣ
             num1 = 0;
             num2 = n2->next->val;
             //n1 = n1;//n1���ֲ���
             n1 = n1; //��ѭ����1���������1λ�������λʱ��nextҪָ���䱾�����ܼ򵥵�next�������������ѭ����Ȼ����������κν����
             n2 = n2->next;//ָ����һ����㡣
             // printf("222\n");
        }
        else{ //if(n1->next!=NULL&&n2->next==NULL){ //������1��λ�����ڼ�����2.
             num1 = n1->next->val;
             num2 = 0;
             n1 = n1->next;//n1ָ����һ�����
             //n2 = n2;//n2���ֲ��䡣
             n2 = n2;
             // printf("333\n");
        }

      w = num1 + num2 + t;//������ؽ����
     // printf("w:  %d\n",w);
      if(w<10){
        Enode->val = w;//���λ
        t = 0; //��λ��0
      }
      else{//����������9
        Enode->val = w%10;
        t = 1;
      }
     cnode->next = Enode;//���ڵ�����������
     cnode = Enode;//����ǽ��ָ���������1����㡣
     //printf("cnode->val:  %d\n",cnode->val);
     //printf("t: %d\n",t);
    //��ʱ�������λ�ļ��㣬
    }
     //struct ListNode*er = (struct ListNode*)malloc(sizeof(struct ListNode));
//printf("wwwwwww\n");
     if(t==1){ //���1λ�ļ������н�λ��Ҫ�¼�һλ
            //printf("����������\n");
               struct ListNode*e = (struct ListNode*)malloc(sizeof(struct ListNode));//�¼�1λ��㡣
                e->val = 1;//��ǰλ��1��
                e->next = NULL;
                cnode->next = e;//�������ӵĽڵ���ڽ������ı�β��
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
     r = addTwoNumbers(d1,c1);//�����������������ġ�
     printf("r next!!!!\n");
     //r1 = r->next;
    // r2 = r1->next;
    //q = r;
    printf("��������\n");
    printf("%d %d %d\n",t1,t2,t3);
    //printf("%d %d %d\n",t4,t5,t6);
     printf("%d %d %d %d\n",t4,t5,t6,t7);

     printf("�������� \n");
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
  k = CreatList(m,1);//����������
  j = CreatList(n,1);
  Prit(k,1);
  Prit(j,1);
  g = addTwoNumbers(k,j);
  Prit(g,0);

return 0;
}
//#endif // ����֮��_C_INCLUDED
