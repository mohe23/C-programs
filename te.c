#ifndef TE_C_INCLUDED
#define TE_C_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//stdio.h stdlib.h

void rt(char*u){
   int h;
   h=sizeof(u)/sizeof(char);//计算存储空间长度
   printf("rt 存储空间长度：%d\n",h);
}

void rt1(int*u){
   int h;
   h=sizeof(u)/sizeof(int);//计算存储空间长度
   printf("rt1 存储空间长度：%d\n",h);
}

int main(){

   int a,b,c,f;
   char e[0];
   int w[0];
   f = sizeof(e);
   printf("f=%d\n",f);
   printf("存储空间  %d\n",sizeof(e));
   rt(e);
   rt1(w);
   char d[4]={'4','5','6','7'};
   d[0]='a';
   for(a=0;a<4;a++)
    printf("%d--%c\n",d[a],d[a]);
   //b = atoi(&d[1]);
  // b = atoi(d+1);
    b = d[1] - '0';
    printf("b: %d\n",b);


    int wq=0;
    for(int i=wq;i<1;i++){
        printf("ssssss1\n");
        wq=1;
        printf("sssssss2\n");
    }
    char fe[]="qwe345dfg!";
    //char fe[10]="qwe345dfg!";
    //char fe[50]="qwe345dfg!";
    wq = strlen(fe);
    int we = sizeof(fe)/sizeof(fe[0]);
    printf("wq= %d  we= %d\n",wq,we);
   /*printf("请输入a: ");
   scanf("%d",&a); //scanf中变量名前要加上“&”！！！
   printf("输入b: ");
   scanf("%d", &b);

   c = a + b;

   printf("运算结果c: %d\n",c);*/
   int i,j;
   //printf("1111i:  %d  j:  %d\n",i,j);
   for(i=0,j=0;i<1,j<4;i++,j++)
   printf("i= %d, j= %d\n",i,j);
    printf("qwee11!!!\n\n\n");

    char*qw=(char*)malloc(sizeof(char));
    printf("length: %d\n",strlen(qw));

return 0;
}



#endif // TE_C_INCLUDED
