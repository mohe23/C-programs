#include<stdio.h>
#include<stdlib.h>
//#define df 1000001//Ϊ1000001ȡ1�����֡�
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){//ʹ��--size�ж������Ƿ���Ԫ�ء�
     int i,j,k=0,count=0,la=0,n[2],n1,n2,df;
     double sg;
     df = 1000001;//
     n[0]=n[1]=0;
    // if(nums1==NULL&&nums2==NULL)//��2�������ǿ����顣
      //  return 0;
     if(nums2==0){//����1���գ�����2�ա�
        la = nums1Size%2;//�ж�����1��������������ż����
        if(0==la)//����1������ż��
            sg = ((double)nums1[nums1Size/2-1]+(double)nums1[nums1Size/2])/2;
        else//����������
            sg = nums1[nums1Size/2];
     }
        //sg = nums1[0];
     else if(nums1==0){//����1�գ�����2����
            la = nums2Size%2;//�ж�����2��������������ż����
            if(1==la)//����2����������
                sg = nums2[nums2Size/2];
            else//����2������ż��
                sg = ((double)nums2[nums2Size/2-1]+(double)nums2[nums2Size/2])/2;
     }
     else if(nums1Size==1&&nums2Size==1)
        sg = ((double)nums1[0]+(double)nums2[0])/2;//���ˣ�
     else{
           la = (nums1Size+nums2Size)%2;//�жϺϲ�����������Ƿ���ż��������ż����la=0;����������la=1��
           n1 = nums1[0];//ʹ��n1,n2����ʾ�Ƚϵ�2������
           n2 = nums2[0];
           for(i=0,j=0;i<nums1Size||j<nums2Size;){
                if(n1<=n2){//nums1���鵱ǰԪ�ؽ�С��
                    n[0] = n[1];//��������n�д��е�ǰ�Ƚϵõ��Ľ�СԪ���Լ�ǰ1����СԪ�ء�
                    n[1] = n1;//����С�����棬
                    i++;//����ɨ��nums1�����������Ԫ��
                    j = j;//����
                    if(i>=nums1Size)//��ʱ����1�Ѿ�ѭ�������ˡ�
                       n1 = df;//��n1ȡ����1�����ֵ��
                    else//���黹û��ѭ��������
                       n1 = nums1[i];//ɨ����һ��Ԫ�ء�

                    n2 = n2;//����2��ʱɨ�赽��Ԫ�ر��ֲ��䡣
                    count++;
                }    //  1,3,6,9   2
                else{//nums2���鵱ǰԪ�ؽ�С��
                    n[0] = n[1];
                    n[1] = n2;//��С������
                    i = i; //i���ֲ���
                    j++; //����ɨ��nums2������һ��Ԫ�ء�
                    if(j>=nums2Size)//��ʱ����2�Ѿ�ɨ����ϡ�
                        n2 = df;//Ҫ����n2һ�����ֵ����ô�Ƚ�ʱ
                    else//����2��Ԫ�ػ�û��ɨ����ϡ�
                        n2 = nums2[j];

                    n1 = n1;//��������1��ǰԪ�ز��䣬��������1��
                    count++;
                }
                printf("n[0]:  %d, n[1]: %d, count:   %d\n",n[0],n[1],count);
              if(((nums1Size+nums2Size)/2+1)==count){//�ҵ���λ���������м��2������
                  la = (nums1Size+nums2Size)%2;//�жϺϲ�����������Ƿ���ż��������ż����la=0;����������la=1��
                  printf("11222333\n");
                  if(0==la){//��Ԫ�ظ�����ż����ȡ�м�2������ƽ��ֵ�������ܹ���6������6/2=3 ��λ������3�����ӵ�4����ȡƽ��
                    sg = ((double)n[0]+(double)n[1])/2;
                  }
                  else{//��Ԫ�ظ�����������ȡ1�������ɡ��ܼ�7������7/2=3  ��λ������4����
                    sg = n[1];
                  }
                 break;//�Ѿ��ҵ������󣬴�ʱ����ѭ����
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
  printf("���ֵ�� %lf\n",c);

return 0;
}
