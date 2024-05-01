//  加一


#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){// 主功能函数。第3个参数-通过该种方式“标记”返回数组的长度。
                                                     // 该函数最后返回的是1个数组名，是指针，不是第3个参数。
    int i,result,flag=0;//flag-进位，初始值为0；
    int *d = (int*)malloc(sizeof(int)*(digitsSize+1));// d就是返回值。
    for(i=(digitsSize-1);i>-1;i--){// 从数组末尾开始向前计算
        if((digitsSize-1)==i){// 整数末位结果的计算
            result = digits[i]+1;
        }
        else//除了末位，其他位结果计算
            result = digits[i]+flag;
        if(result>9){// 某一位计算结果>9
            result = result%10;
            flag = 1;//进位是1。
        }
        else{// 某一位运算结果result < 10
            flag = 0;//向上一位进位=0。
        }
        digits[i] = result;
    }
    if(1==flag){// 最高位计算之后，仍然有进位
       (*returnSize) = digitsSize+1;
       d[0] = 1;//
       for(i=0;i<digitsSize;i++)
           d[i+1] = digits[i];
    }
    else{// 最高位计算后，没有进位
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
