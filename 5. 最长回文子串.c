#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

char * longestPalindrome(char * s){
    int i,j, first,end,len,lf,le, ler, leng,la;// first end len当前待处理的子串首尾字符下标，长度
   //lf,le, ler是存放最长回文子串的首尾字符下标，子串长度
   //char *t;//返回值。
    //leng = sizeof(s)/ sizeof(s[0]);//计算字符串长度。
    leng = strlen(s);
    printf("原字符串长度leng:%d\n",leng);
    lf = le =0;//一开始最长回文子串是单个字符
    ler = 1;//字符长度是1。
    first =0; end=1; len=0;
    if(1 == leng)//总字符长度为1
       return s;
       //printf("%c",s[0]);

    else{//字符串长度＞1
         while(first < (leng-1)){//first一直循环到倒数第2个字符。
             end = first+ler;//end初值。根据当前已有回文子串长度，保证新的回文子串长度大于已有的长度。
             while(end < leng){
                    la = 1;//每次判断子串是回文串时，就将la初始化为1，用此标记判断子串是否是回文串。
                    len = end-first+1;//计算当前待处理子串长度。

                 for(i=first; i < (len/2+first); i++){
                      if(s[i] != s[first+end-i]){
                            la = 0;//当前子串不是回文串。
                            break;//直接跳出for循环。
                      }

                 }//()&&(len > ler)
                 if(1 == la){//当前子串是回文串。
                     if(leng == len){
                         return s;
                         break;//跳出循环。
                     }
                     ler = len;//更新回文子串相关数据。
                     lf = first;
                     le = end;

                 }
                end++;//将end值加1，first不变，判断更长的子串是否是回文串。
             }

             first++;//以first为首的所有长度的字符子串已经判断完毕，那么就将first加1。
            //len = len+1;
            //end++;
         }
     printf("lf: %d, le: %d, ler: %d\n",lf,le,ler);//找bug.
     int lew=0;
     lew = ler;
     char*t = (char*)malloc((lew+1)*sizeof(char));//为回文子串分配存储空间。lew*
     t[lew] = '\0';
     printf("lew:  %d\n",lew);
     printf("length: %d\n",strlen(t));

     for(i=0,j=lf;i<lew,j<=le;i++,j++){
        printf("j: %d s[j]: %c  ",j,s[j]);
         t[i] = s[j];//提取回文子串。
         printf("t length: %d\n",strlen(t));
     }//sizeof(t)/sizeof(t[0])   strlen(t)
 printf("t.length: %d\n",strlen(t));

     return t;//返回t  1 2 3 4 5
    }

}

int main(){
    char a[5]="dadac";//一种字符数组赋值方式。
     //char a[]="obbt";
    // char a[]="abbbd";
    //char a[]="abbaabba";
    char *b;//=NULL;
    int i,lw;
    //lw = sizeof(a)/sizeof(a[0]);
    //printf("lw: %d\n",lw);
    b = longestPalindrome(a);
    //lw = sizeof(b)/sizeof(b[0]);
    lw = strlen(b);

    printf("回文串长度le:%d   b[0]:%c\n",lw,b[0]);
    for(i=0;i<lw;i++)
        printf("%d-%c\n",i,b[i]);

return 0;
}
