//  x��ƽ����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>// ���ü����ַ����鳤�ȵĺ���


int mySqrt(int x){ // �����ܺ�����
    int i,ret;
    for(i=0;i<46341;i++){
        if(i*i==x){// x�����ܹ�����ƽ������
            ret = i;
            break;
        }
        else if(i*i < x){// i��ƽ�� < x
            ret = i;
        }
        else{// i��ƽ�� > x
            break;// ����ѭ����
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
