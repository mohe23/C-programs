//  ��������λ��

#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target){//�����������鳤�ȵģ�ѭ��Ҫ��forѭ����
    int first,mid,end,flag;
    first =0;end=(numsSize-1);flag=0;//����Ƿ���ҳɹ���1-���ҳɹ���0-����ʧ��
    while(first<=end){// ѭ��������first<=end
        /*if(target<=nums[0]){
            mid = 0;//����ֵΪ-1��ֱ������ѭ��
        }*/
        mid = (first + end)/2;
        if(nums[mid]==target){// ֱ������ѭ��
            flag = 1;// ��ǣ����ҳɹ���
            break;
        }
        else if(nums[mid]>target)//Ҫ��ǰ�Ҵ�����ֵ
            end = mid-1;
        else// mid�����ֵ < target�� �����Ҵ�����ֵ
            first = mid+1;
    }
    if(0==flag){// ���Ҳ��ɹ����ҵ�����λ��
        if(target>=nums[mid])// ֻҪtarget >= nums[mid]����ʹ��mid++��
           mid++;
    }
return mid;
}

// (mid==numsSize-1)||(0==mid&&target>=nums[0])


int main(){
    int a[7]={1,3,5,6,9,11,13};
    int b,c,d;
    b = 2;d =4;
    c = searchInsert(a,d,b);
    printf("c: %d\n",c);
    /*int a,b,c;
    a = 2;b=5;c=7;
    a = b-c;
    printf("a�� %d\n",a);*/
return 0;
}
