//  搜索插入位置

#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target){//遇到给出数组长度的，循环要用for循环。
    int first,mid,end,flag;
    first =0;end=(numsSize-1);flag=0;//标记是否查找成功。1-查找成功；0-查找失败
    while(first<=end){// 循环条件：first<=end
        /*if(target<=nums[0]){
            mid = 0;//返回值为-1，直接跳出循环
        }*/
        mid = (first + end)/2;
        if(nums[mid]==target){// 直接跳出循环
            flag = 1;// 标记，查找成功。
            break;
        }
        else if(nums[mid]>target)//要向前找待查找值
            end = mid-1;
        else// mid代表的值 < target， 向后查找待查找值
            first = mid+1;
    }
    if(0==flag){// 查找不成功，找到插入位置
        if(target>=nums[mid])// 只要target >= nums[mid]，就使得mid++。
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
    printf("a： %d\n",a);*/
return 0;
}
