//   �Ƴ�Ԫ��

#include<stdio.h>
#include<stdlib.h>
//  ʵ��һ�£��������ܲ��ܵ�����ַ���βΡ����磺int a[4]��a�ܲ�����int *k�е��βΡ�


int removeElement(int* nums, int numsSize, int val) {//�ؼ�����
    int i,flag=-1;
    if(0==numsSize)//���鳤��Ϊ0
        flag = 0;
    else{//���鳤��>0
        for(i=0;i<numsSize;i++){// ��ͷ��βɨ����������
            if(nums[i]!=val){//��ǰɨ��Ԫ�ز��ǡ��Ƴ�Ԫ�ء�
                flag++;// �ҵ�����Ĵ���ֵλ�ã���ֵ��0��ʼ��
                nums[flag] = nums[i];
            }
        }
        flag++;//����������
    }

return flag;
}

void pri(int *num[],int size1,int size2){ //��ӡ��ά����num��
    int i,j;
    for(i=0;i<size1;i++){
        for(j=0;j<size2;j++)
            printf("%d ",num[i][j]);
        printf("\n");
    }
}

int main(){
    int i,k,a[4]={1,2,3,4};
    int b[3][3]={1,2,3,4,5,6,7,8,9};//�Ҳ�ȷ���ǲ���3x3�Ķ�ά����
    k = removeElement(a,4,1);
    for(i=0;i<4;i++)
        printf("%d,",a[i]);
    printf("\n\n");
    //pri(b,3,3);
return 0;//�ҵı�׼��ʽ��
}
// D:\Code\C\T27.c|36|warning: initialization of 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]|
//D:\Code\C\T27.c|36|warning: excess elements in scalar initializer|
