// �ϲ�2����������(����)��

#include<stdio.h>
#include<stdlib.h>

 struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    //
    struct ListNode *Node1,*Node2,*rear,*re;//3���ֱ��Ǳ�һָ�룬���ָ�룬�Լ��ϲ���������βָ�롣
    int f=0;// �������Ϊ��ǣ��ж��ǲ��ǵ�1�αȽϡ�
    Node1 = list1; Node2=list2; //rear=list1;//��list1��Ϊ�ϲ��������ͷָ�롣
    // ������Ŀ�е�����û��ͷ��㣬��1�����������ݽ�㡣
    if(NULL==Node1)//����2�֣�Node2�ջ�Node2���ա�
        re = list2;
    else if(NULL!=Node1&&NULL==Node2)//����գ���һ���ա�
        re = list1;
    else{// ��һ���������ա�
        //Node1=Node1->next; Node2=Node2->next;//��ʱ��ָ��ָ��2�������е����ݽ�㡣
        while(Node1&&Node2){// ѭ��������2������û��ɨ�����
            if(Node2->val > Node1->val){//list1��ǰ����ֵС��
                if(0==f){// ͨ����1���жϣ���һ�ĵ�1��������ֵС�����Խ�����ֵ��Ϊlist1.
                    re = list1;// ���ر�һ��ָ�롣
                    rear = list1;
                    f++;
                }
                else{//��2�μ��Ժ�ıȽ�
                    rear->next = Node1;
                    rear = Node1;
                }

                Node1 = Node1->next;//

            }
            else{// list2��ǰ����ֵС��
                if(0==f){
                    re = list2;//���ص��Ǳ����ָ�롣
                    rear = list2;
                    f++;
                }
                else{
                     rear->next = Node2;
                     rear = Node2;
                }

                Node2 = Node2->next;//����С����ָ�����Ҽ�1��
            }
        }
        if(NULL!=Node1){//��ʱ���ɨ����ϣ�����һδɨ����ϡ�
            rear->next = Node1;//ֱ�ӽ���һʣ�ಿ�ֲ��뵽�ϲ���λ�á���Ϊ�Ǻϲ�ǰ��ϲ���������Ҫ�Ǻϲ�ǰ��ϲ���
                               //��λ�෴����Ҫ���һ��һ���Ĳ��뵽�ϲ������С�
        }
        else{// ��һɨ����ϣ����δɨ����ϡ�

             rear->next = Node2;
        }
    }


return re;
}

