//  �ҳ��ַ����е�һ��ƥ������±�

#include<stdio.h>
#include<stdlib.h>

int strStr(char*haystack,char*needle){
    int i,j,usedi,ret;//ret-����ֵ��
    i = j = 0; ret=usedi= -1;
    while(haystack[i]&&needle[j]){// ѭ�����������ַ�����ǰ�Ƚ��ַ������ǿա�
        if(haystack[i]==needle[j]){// ��ǰ2�Ƚ��ַ���ͬ
            if(needle[0]==haystack[i]&&(-1)==usedi)//ֻҪhaystack��ǰ�ַ�==needle[0]���ͱ�������ַ���haystack�е��±�
                usedi = i;
            i++;j++;//�±��1�������Ƚϡ�
            printf("i: %d,j: %d\n",i,j);
        }
        else{//2���ַ���ͬ����2���ַ�����û��ɨ�����
            if((-1)!=usedi){// ˵���Ѿ����ַ���haystack���ҵ�needle[0]
                if((i-j)==usedi)// ����һ��ƥ���ڼ䣬���˵�1��ƥ��ʱ������needle[0]�������ط�û������needle[0]
                    i = (usedi+1);
                else// ����һ��ƥ���ڼ䣬���˵�1��ƥ��ʱ������needle[0]��hastack�ַ����ֳ���needle[0]
                    i = usedi;// �������ڼ���ƥ����̡�
                usedi = -1;//����ƥ��ʱ��ʹ��һ��usedi�󣬾ͽ���usedi��ֵΪ-1����ֹ������ѭ����
            }
            else{// ˵����û�����ַ���haystack���ҵ�needle[0]
                i++;
            }

            j = 0; //needle�ַ���ֱ�ӻص���1���ַ����Ƚϡ�
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

// "aabaaabaaac"��"aabaaac"�����ڣ�����ÿ��ɨ��a�ַ���ʱ����Ҫ�жϴ�ʱa���ַ��Ƿ����b[0]��Ҫ��=���ͽ���ʱ��uesdi= i����
// ����������������þ����������㣬�ͽ����ò��ҳɹ��ģ����Ҳ��ɹ��ˡ�
return 0;
}
