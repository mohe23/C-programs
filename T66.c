//  ��һ


#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){// �����ܺ�������3������-ͨ�����ַ�ʽ����ǡ���������ĳ��ȡ�
                                                     // �ú�����󷵻ص���1������������ָ�룬���ǵ�3��������
    int i,result,flag=0;//flag-��λ����ʼֵΪ0��
    int *d = (int*)malloc(sizeof(int)*(digitsSize+1));// d���Ƿ���ֵ��
    for(i=(digitsSize-1);i>-1;i--){// ������ĩβ��ʼ��ǰ����
        if((digitsSize-1)==i){// ����ĩλ����ļ���
            result = digits[i]+1;
        }
        else//����ĩλ������λ�������
            result = digits[i]+flag;
        if(result>9){// ĳһλ������>9
            result = result%10;
            flag = 1;//��λ��1��
        }
        else{// ĳһλ������result < 10
            flag = 0;//����һλ��λ=0��
        }
        digits[i] = result;
    }
    if(1==flag){// ���λ����֮����Ȼ�н�λ
       (*returnSize) = digitsSize+1;
       d[0] = 1;//
       for(i=0;i<digitsSize;i++)
           d[i+1] = digits[i];
    }
    else{// ���λ�����û�н�λ
        (*returnSize) = digitsSize;
         for(i=0;i<digitsSize;i++)
           d[i] = digits[i];
        d[i] = '\0';
    }
return d;
}

int main(){

   int i,le,*leg,*b;
   int a[3]={1,2,3};
   //b = (int*)malloc(sizeof(int)*10);
   le = 3;
   b = plusOne(a,le,leg);
   for(i=0;i<(*leg);i++)
       printf("%d ",b[i]);

return 0;
}


//  D:\Code\C\T66.c|43|error: assignment to expression with array type|
