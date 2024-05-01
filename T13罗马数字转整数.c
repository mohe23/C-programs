#include<stdio.h>

//enum Rnum{I=1,V=5,X=10,L=50,C=100,D=500,M=1000};//用enum类型来表示6个罗马数字所代表十进制数值。

int Clength(char*c){ // 计算数组长度。
    int j=0,len=0;
    while(c[j]!='\0'){
        len++;
        j++;
    }

return len;
}

int Rtoi(char ch){ // 输入罗马数字，输出十进制整数
    int r=0;
    switch(ch){
         case 'I':
             r = 1;
             break;
         case 'V':
              r = 5;
              break;
         case 'X':
              r = 10;
              break;
         case 'L':
              r = 50;
              break;
         case 'C':
              r = 100;
              break;
         case 'D':
              r = 500;
              break;
         case 'M':
              r = 1000;
              break;

    }
return r;
}

int Stonums(char a,char b){// 6种特殊情况,其他情况，输出为-1
    int num;
    if('I'==a&&'V'==b)
        num = 4;
    else if('I'==a&&'X'==b)
        num = 9;
    else if('X'==a&&'L'==b)
        num = 40;
    else if('X'==a&&'C'==b)
        num = 90;
    else if('C'==a&&'D'==b)
        num = 400;
    else if('C'==a&&'M'==b)
        num = 900;
    else
        num = -1; //这个是为了确保出现6种情况之外的其他组合。
    return num;
}

int romanToInt(char* s) {//罗马数字转整数。s-存放罗马数字的char型数组
    int i,le,rt,twos,si,sm;//le-s数组长度，rt-判断数组s是否扫描完，sm-罗马数字代表的十进制整数。twos-2个罗马数字代表的数字
    sm = 0;//初始值为0
    le = Clength(s);// 计算字符数组s的长度。
    printf("le = %d\n",le);
    for(i=0;i<le;){
        rt = Rtoi(s[i]);
        if(0==rt)
            break;//数组中的有效字母已经扫描完毕，跳出循环。
        twos = Stonums(s[i],s[i+1]);
        if(-1==twos){// 当前组合不是6种特殊情况
           sm = sm + rt;//将当前罗马字母的数值加到sm中，同时i++
           i++;
        }
        else{// 数字组合是6种特殊组合
            sm = sm + twos;//将当前组合代表的数值加到sum中，然后2次i++
            i += 2;
        }

     printf("i=%d,sum: %d\n",i,sm);
    }
    if(0 == sm)
        printf("罗马数字序列出错！");

    return sm;// 返回罗马数字序列代表的数字。
}


int main(){
   int i,leng;
   char a[]={'M','D','C','C','C','L','X','X','X','I','V'};
   //char a[]={'M','D','C','C','C','L'};
   leng = romanToInt(a);
   printf("sum: %d ",leng);
   //printf("d:%d\n",Rtoi('Q'));
   //leng = sizeof(a)/sizeof(a[0]);
   // printf("lr: %d\n",leng);
    //char  ch = /0;
    //printf("c:%c\n",ch);
  // for(i =0;i<6;i++){
    //  if(a[i]=='\0')
      //     printf("10\n");
      //else
        //   printf("%c\n",a[i]);
  // }
    //i = 0;
  //  while(a[i]!= '0'){
    //    printf("%c\n",a[i]);
      //  i++;
   // }

    //printf("%d,%d,%d,%d,%d,%d,%d\n",I,V,X,L,C,D,M);
    //printf("%d",I+V);
return 0;
}
