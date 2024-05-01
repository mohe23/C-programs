#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char*s){
      int i,len1=0,len2=0,length=0,la=0,lb;//length-数组长度  len1-循环开始元素下标  len2-当前扫描的元素下标  la-,lb=0

     /*//lb=sizeof(s)/sizeof(char);//判断数组是否是0数组
      //printf("lb:  %d\n",lb);

       //length = strlen(s);
      //for(int j=0;j<lb;j++)
       // printf("5%c  j=%d\n",s[j],j);*/
        if(s==NULL)
            la=0;

        else{
              length = strlen(s);///求数组s长度
               // printf("else!!!\n");
             if(1==length)//字符串只有1个字符。
                la = 1;
             else{//字符串有2个及以上字符。
                  for(len2=1;len2<length;len2++){
                       printf("len2:  %d\n",len2);
                      for(i=len1;i<len2;i++){
                        printf("i:  %d\n",i);
                         if(s[i]==s[len2]){//当前扫描到的字符s[len2]，在之前的字符序列中有重复字符。
                           //lb=i;//标记字符串是否有重复元素
                            if((len2-len1)>la)//当前无重复字符子串长度大于之前的字符长度，那么就更新最大无重复字符子串的长度。
                               la = len2-len1;
                 //重新确定循环开始元素。
                 //lm=0;
                           len1=i+1;
                           break;//出现重复元素，直接跳出循环。
                        }//当len2=length-1时，如果不加1个标记，那么每循环1次，都会执行下面的语句，那么就会很尴尬。

                       if((length-1==len2)&&(i==len2-1))//当扫描到字符数组最后1个字符时，没有与之前的字符相同，进行相关处理。
                          la = length-len1;    //lm是做标记，如果出现了相同字符，那么就不执行相关计算了
                //printf("wer$444   %d\n",la);
                     }

                 }
             }

           if(0==len1)//字符串最大无重复元素子串是其本身，
             la = length;
      }
return la;
}


int main(){
    //char ch[]={'a','b','c','a','b','c','b','b'};
    //char ch[]={'b','b','b','b','b'};
    //char ch[]={'p','w','w','k','e','w'};
    //char ch[]={'p','p','p','p','h','m','h','r'};
    //char ch[]={'p','p','p','p','p','p','p','p'};
    //char ch[]={'p','p','p','p','h','m','j','h'};
   // char ch[]={'p','w','y','k','e','l','o','o'};
    //char ch[0];
   // char ch[]={'c','f'};
    char ch[]={'c','c'};
    //printf("chr   %c\n",chr[0]);
    int k,m;
    //printf("char  %d\n",sizeof(char));
    //printf("int  %d\n",sizeof(int));
    //m = sizeof(chr)/sizeof(char);
    //printf("m: %d\n",m);
    k = lengthOfLongestSubstring(ch);
    printf("k: %d\n",k);

return 0;
}
