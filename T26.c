// ɾ�����������е������ظ���

#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int* nums, int numsSize) {//�Ƴ������е��ظ��
    int i,flag,num,ret;     // ****�����ԣ�����nums�ı���û�У����� ***�������ʵ�ʴ洢Ԫ��ȷʵ�����ı䣬��ʹ����ֵ����������nums��
    i=0;flag=-1;//����ʼֵ��
    if(1==numsSize)//���鳤��==1
        ret = 1;//����1�����Ҳ���Ҫ���������κδ���
    else{// ���鳤��>1��
        for(i=0;i<numsSize;i++){//ɨ�����飬ֱ�����
            //printf("i: %d\n",i);
            if(0==i){
                num = nums[0];//��num����ʼֵ��
                //times++;//��ǰnum���ִ�����1��
            }
            if(0!=i&&num!=nums[i]){//��ǰɨ��Ԫ����num��Ԫ�ز�һ��
                flag++;//�ҵ�num������Ĵ��λ�á�
                nums[flag]= num;//��num���ڸ÷ŵ�λ�á�
                num = nums[i];//����numֵ��
            }


            //i++;//����ɨ����һ��Ԫ�ء�
        }
        flag++;
        if(flag!=(numsSize-1))//ԭ���������ظ�Ԫ�ء�
            nums[flag]= nums[numsSize-1];//���������1��Ԫ�ظ�ֵ��num[flag]��
        ret = (flag+1);

    }

return ret;
}


int main(){
    int i,len,k, *a;
    a = (int*)malloc(sizeof(int)*4);//����1������Ϊ4�����顣
    //scanf("xx: %d\n",&len);//��ϰһ��scanf��䡣
    a[0]= 1;a[1]=1;a[2]=2;a[3]=3;
    printf("����ǰ��\n");
    for(i=0;i<4;i++)
        printf("%d-",a[i]);
    k = removeDuplicates(a,4);
    printf("k: %d\n",k);
     printf("�����\n");
    for(i=0;i<4;i++)
        printf("%d-",a[i]);

return 0;//�Ժ�return���һ��Ҫ��ĳ1�ж���д��
}
