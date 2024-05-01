//  x的平方根

#include<stdio.h>
#include<stdlib.h>
#include<string.h>// 调用计算字符数组长度的函数


int mySqrt(int x){ // 主功能函数。
    int i,ret;
    for(i=0;i<46341;i++){
        if(i*i==x){// x正好能够开出平方根。
            ret = i;
            break;
        }
        else if(i*i < x){// i的平方 < x
            ret = i;
        }
        else{// i的平方 > x
            break;// 跳出循环。
        }
        printf("ret: %d\n",ret);
    }

return ret;
}


int main(){
    int k,t;
    t = 600;
    k = mySqrt(t);
    printf("%d \n",24);
return 0;
}
