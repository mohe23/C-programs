//  最后一个单词的长度

#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char*s){
    int i,cal,ucal;// cal-计算每一个单词长度； ucal- 统计当前已扫描的单词中的最长单词长度。
    i=cal=0;//初始化。
    while(s[i]!='\0'){//扫描字符串s
        if(' '!=s[i]){//扫描到英文字符时，开始计算当前单词长度。
            cal++;//当前单词长度+1
        }
        else{// 扫描到空白字符
            if(0!=cal)//只保存单词长度>0的单词。
                ucal = cal;//标记一下上1个单词长度
            cal = 0;//将cal置为0。
        }
        i++;//注意不要忘记该语句，否则就陷入死循环了。
    }
    if(0==cal)// 如果字符串以“空格”字符结尾。
        cal =ucal;// 就将ucal值赋值给cal;


return cal;
}

int main(){
    int k;
    char a[]="luffy is still joyboy";
    k = lengthOfLastWord(a);
    printf("k: %d\n",k);

return 0;
}
