
#include<stdio.h>
#include<stdlib.h>

int* Getxb(int*nums,int numsSize,int target,int *returnSize){
   int i,j,*b;
   b = (int*)malloc(sizeof(int)*2);//给b数组申请了2个int数据的存储空间。
   for(i=0;i<numsSize-1;i++){
      for(j=i+1;j<numsSize;j++){
            if(target==(nums[i]+nums[j])){
                b[0]=i;
                b[1]=j;
                *returnSize = 2;
            }
     }
   }

return b;
}


int main(){
   int a[4]={1,4,6,3};
   int *w;
   w = Getxb(a,4,7,w);
   for(int i=0;i<2;i++)
    printf("%d  ",w[i]);

return 0;
}


