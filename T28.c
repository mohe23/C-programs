//  找出字符串中第一个匹配项的下标

#include<stdio.h>
#include<stdlib.h>

int strStr(char*haystack,char*needle){
    int i,j,usedi,ret;//ret-返回值。
    i = j = 0; ret=usedi= -1;
    while(haystack[i]&&needle[j]){// 循环条件是两字符串当前比较字符都不是空。
        if(haystack[i]==needle[j]){// 当前2比较字符相同
            if(needle[0]==haystack[i]&&(-1)==usedi)//只要haystack当前字符==needle[0]，就标记其在字符串haystack中的下标
                usedi = i;
            i++;j++;//下标加1，继续比较。
            printf("i: %d,j: %d\n",i,j);
        }
        else{//2个字符不同，且2个字符串都没有扫描完毕
            if((-1)!=usedi){// 说明已经在字符串haystack中找到needle[0]
                if((i-j)==usedi)// 在上一次匹配期间，除了第1次匹配时遇到了needle[0]，其他地方没有遇到needle[0]
                    i = (usedi+1);
                else// 在上一次匹配期间，除了第1次匹配时遇到了needle[0]，hastack字符串又出现needle[0]
                    i = usedi;// 这样便于加速匹配过程。
                usedi = -1;//当不匹配时，使用一次usedi后，就将该usedi赋值为-1。防止陷入死循环。
            }
            else{// 说明还没有在字符串haystack中找到needle[0]
                i++;
            }

            j = 0; //needle字符串直接回到第1个字符串比较。
            printf("i: %d,j: %d\n",i,j);
        }
    }
    if(needle[j]=='\0')
        ret = (i-j);

return ret;
}


int main(){
    int k;
    char a[]="aabaaabaaac";//"leetcode";
    char b[]="aabaaac";//"leeto";
    k = strStr(a,b);
    printf("k: %d\n",k);

// "aabaaabaaac"，"aabaaac"。由于，我在每次扫描a字符串时，都要判断此时a中字符是否等于b[0]，要是=，就将此时的uesdi= i。而
// 这个测试用例，正好经过上述运算，就将本该查找成功的，查找不成功了。
return 0;
}
