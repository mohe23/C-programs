#include<stdio.h>
#include<stdlib.h>
//#define df 1000001//为1000001取1个名字。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){//使用--size判断数组是否有元素。
     int i,j,k=0,count=0,la=0,n[2],n1,n2,df;
     double sg;
     df = 1000001;//
     n[0]=n[1]=0;
    // if(nums1==NULL&&nums2==NULL)//若2个数组是空数组。
      //  return 0;
     if(nums2==0){//数组1不空，数组2空。
        la = nums1Size%2;//判断数组1长度是奇数还是偶数。
        if(0==la)//数组1长度是偶数
            sg = ((double)nums1[nums1Size/2-1]+(double)nums1[nums1Size/2])/2;
        else//长度是奇数
            sg = nums1[nums1Size/2];
     }
        //sg = nums1[0];
     else if(nums1==0){//数组1空，数组2不空
            la = nums2Size%2;//判断数组2长度是奇数还是偶数。
            if(1==la)//数组2长度是奇数
                sg = nums2[nums2Size/2];
            else//数组2长度是偶数
                sg = ((double)nums2[nums2Size/2-1]+(double)nums2[nums2Size/2])/2;
     }
     else if(nums1Size==1&&nums2Size==1)
        sg = ((double)nums1[0]+(double)nums2[0])/2;//对了，
     else{
           la = (nums1Size+nums2Size)%2;//判断合并数组个数是是否是偶数，若是偶数，la=0;若是奇数，la=1。
           n1 = nums1[0];//使用n1,n2来表示比较的2个数。
           n2 = nums2[0];
           for(i=0,j=0;i<nums1Size||j<nums2Size;){
                if(n1<=n2){//nums1数组当前元素较小，
                    n[0] = n[1];//保持数组n中存有当前比较得到的较小元素以及前1个较小元素。
                    n[1] = n1;//将较小数保存，
                    i++;//继续扫描nums1数组接下来的元素
                    j = j;//保持
                    if(i>=nums1Size)//此时数组1已经循环结束了。
                       n1 = df;//让n1取到了1个最大值。
                    else//数组还没有循环结束。
                       n1 = nums1[i];//扫描下一个元素。

                    n2 = n2;//数组2此时扫描到的元素保持不变。
                    count++;
                }    //  1,3,6,9   2
                else{//nums2数组当前元素较小。
                    n[0] = n[1];
                    n[1] = n2;//较小数保存
                    i = i; //i保持不变
                    j++; //继续扫描nums2数组下一个元素。
                    if(j>=nums2Size)//此时数组2已经扫描完毕。
                        n2 = df;//要赋给n2一个最大值，那么比较时
                    else//数组2中元素还没有扫描完毕。
                        n2 = nums2[j];

                    n1 = n1;//保持数组1当前元素不变，继续与下1个
                    count++;
                }
                printf("n[0]:  %d, n[1]: %d, count:   %d\n",n[0],n[1],count);
              if(((nums1Size+nums2Size)/2+1)==count){//找到了位于总数组中间的2个数。
                  la = (nums1Size+nums2Size)%2;//判断合并数组个数是是否是偶数，若是偶数，la=0;若是奇数，la=1。
                  printf("11222333\n");
                  if(0==la){//总元素个数是偶数，取中间2个数的平均值。假如总共有6个数，6/2=3 中位数：第3个数加第4个数取平均
                    sg = ((double)n[0]+(double)n[1])/2;
                  }
                  else{//总元素个数是奇数，取1个数即可。总计7个数，7/2=3  中位数：第4个数
                    sg = n[1];
                  }
                 break;//已经找到了所求，此时跳出循环。
              }

           }
     }

return sg;
}


int main(){
    int l1,l2;
    double c;
    l1 = 0;
    l2 = 1;
  //int a[5]={1,3,6,8,9};
  //int b[1]={2};
  int *a=NULL;
  int b[1]={1};
  //int *b=NULL;

  c = findMedianSortedArrays(a,l1,b,l2);
  //c = findMedianSortedArrays(b,l2,a,l1);
  printf("输出值： %lf\n",c);

return 0;
}
