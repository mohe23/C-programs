//  ���һ�����ʵĳ���

#include<stdio.h>
#include<stdlib.h>

int lengthOfLastWord(char*s){
    int i,cal,ucal;// cal-����ÿһ�����ʳ��ȣ� ucal- ͳ�Ƶ�ǰ��ɨ��ĵ����е�����ʳ��ȡ�
    i=cal=0;//��ʼ����
    while(s[i]!='\0'){//ɨ���ַ���s
        if(' '!=s[i]){//ɨ�赽Ӣ���ַ�ʱ����ʼ���㵱ǰ���ʳ��ȡ�
            cal++;//��ǰ���ʳ���+1
        }
        else{// ɨ�赽�հ��ַ�
            if(0!=cal)//ֻ���浥�ʳ���>0�ĵ��ʡ�
                ucal = cal;//���һ����1�����ʳ���
            cal = 0;//��cal��Ϊ0��
        }
        i++;//ע�ⲻҪ���Ǹ���䣬�����������ѭ���ˡ�
    }
    if(0==cal)// ����ַ����ԡ��ո��ַ���β��
        cal =ucal;// �ͽ�ucalֵ��ֵ��cal;


return cal;
}

int main(){
    int k;
    char a[]="luffy is still joyboy";
    k = lengthOfLastWord(a);
    printf("k: %d\n",k);

return 0;
}
