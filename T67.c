//  二进制求和

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {// 主功能函数。
    int i,j,numa,numb,num,la,lb,k,flag=0;
    char *c=(char*)malloc(sizeof(char)*(10001)); //将a、b两个字符串长度长的首地址赋值给c。
    la = strlen(a);lb = strlen(b);//计算出2个字符串的长度。
    if(la > lb){// 将长度更大的值
        //c = a;
        k = 0; // 表示字符串a的长度大
    }
    else{
        //c = b;
        k = 1;// 表示字符串b的长度大。
    }
    i = la-1; j = lb-1;
    while(i>=0||j>=0){// 循环条件：从后向前，没有扫描完毕
        if(i>=0)
            numa = a[i]-'0';
        else
            numa = 0;
        if(j>=0)
            numb = b[j]-'0';//从char型转化为int型。
        else
            numb = 0;
        num = numa + numb + flag;//获得相加结果。
        flag = num/2;// 我在此处犯了2个错误，1：是先求flag，后求num最终值。2：我一开始，把flag = flag/2，实际上 flag = num/2；
        num = num%2;

        printf("num: %d, flag: %d\n",num,flag);
        if(0==k)// 字符串a的长度大。
            a[i] = (num + '0');
        else// 字符串b的长度大。
            b[j] = (num + '0');

        if(i>=0)
            i--;
        if(j>=0)
            j--;

    }
    if(1==flag){// 最后计算结果的位数 > 最长字符串的长度，两者相差应该是1。
        if(0==k){// 最长字符串是a。
            //c = (char*)malloc(sizeof(char)*(la+1));
            c[0] = '1';
            for(i=0;i<la;i++)
                 c[i+1] = a[i];
        }
        else{// 最长字符串为b
            //c = (char*)malloc(sizeof(char)*(lb+1));
            c[0] = '1';
            for(i=0;i<lb;i++)
                c[i+1] = b[i];
        }
        c[i+1] = '\0';
    }
    else{// 最后计算结果位数 == 最长字符串长度
        if(0==k){// 字符串a的长度最长
            for(i=0;i<la;i++)
                c[i] = a[i];
        }
        else{// 字符串b的长度最长
            for(i=0;i<lb;i++)
                c[i] = b[i];
        }
        c[i] = '\0';
    }


return c;
}


int main(){
   int i,leng;
   char a[10] = "1010",b[]="1011";
   //int b[5] = {1,2,3,4,5};
    char *c;
    c = addBinary(a,b);
    leng = strlen(c);
    printf("leng: %d\n",leng);
    for(i=0;i<leng;i++)
        printf("%c ",c[i]);

return 0;
}
