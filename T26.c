// 删除有序数组中的有序重复项

#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int* nums, int numsSize) {//移除数组中的重复项。
    int i,flag,num,ret;     // ****最后测试，数组nums改变了没有！！！ ***解答：数组实际存储元素确实发生改变，即使返回值不是数组名nums。
    i=0;flag=-1;//赋初始值。
    if(1==numsSize)//数组长度==1
        ret = 1;//返回1，并且不需要对数组做任何处理。
    else{// 数组长度>1。
        for(i=0;i<numsSize;i++){//扫描数组，直到最后。
            //printf("i: %d\n",i);
            if(0==i){
                num = nums[0];//给num赋初始值。
                //times++;//当前num出现次数加1。
            }
            if(0!=i&&num!=nums[i]){//当前扫描元素与num中元素不一样
                flag++;//找到num在数组的存放位置。
                nums[flag]= num;//将num放在该放的位置。
                num = nums[i];//更新num值。
            }


            //i++;//继续扫描下一个元素。
        }
        flag++;
        if(flag!=(numsSize-1))//原数组中有重复元素。
            nums[flag]= nums[numsSize-1];//将数组最后1个元素赋值到num[flag]。
        ret = (flag+1);

    }

return ret;
}


int main(){
    int i,len,k, *a;
    a = (int*)malloc(sizeof(int)*4);//创建1个长度为4的数组。
    //scanf("xx: %d\n",&len);//练习一下scanf语句。
    a[0]= 1;a[1]=1;a[2]=2;a[3]=3;
    printf("处理前：\n");
    for(i=0;i<4;i++)
        printf("%d-",a[i]);
    k = removeDuplicates(a,4);
    printf("k: %d\n",k);
     printf("处理后：\n");
    for(i=0;i<4;i++)
        printf("%d-",a[i]);

return 0;//以后，return语句一定要在某1行顶格写。
}
