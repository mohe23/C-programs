//   移除元素

#include<stdio.h>
#include<stdlib.h>
//  实验一下，数组名能不能当做地址的形参。比如：int a[4]，a能不能做int *k中的形参。


int removeElement(int* nums, int numsSize, int val) {//关键函数
    int i,flag=-1;
    if(0==numsSize)//数组长度为0
        flag = 0;
    else{//数组长度>0
        for(i=0;i<numsSize;i++){// 从头到尾扫描整个数组
            if(nums[i]!=val){//当前扫描元素不是“移除元素”
                flag++;// 找到数组的待赋值位置，数值从0开始。
                nums[flag] = nums[i];
            }
        }
        flag++;//获得最后结果。
    }

return flag;
}

void pri(int *num[],int size1,int size2){ //打印二维数组num。
    int i,j;
    for(i=0;i<size1;i++){
        for(j=0;j<size2;j++)
            printf("%d ",num[i][j]);
        printf("\n");
    }
}

int main(){
    int i,k,a[4]={1,2,3,4};
    int b[3][3]={1,2,3,4,5,6,7,8,9};//我不确定是不是3x3的二维数组
    k = removeElement(a,4,1);
    for(i=0;i<4;i++)
        printf("%d,",a[i]);
    printf("\n\n");
    //pri(b,3,3);
return 0;//我的标准格式。
}
// D:\Code\C\T27.c|36|warning: initialization of 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]|
//D:\Code\C\T27.c|36|warning: excess elements in scalar initializer|
