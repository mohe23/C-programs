//  ���������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {// �����ܺ�����
    int i,j,numa,numb,num,la,lb,k,flag=0;
    char *c=(char*)malloc(sizeof(char)*(10001)); //��a��b�����ַ������ȳ����׵�ַ��ֵ��c��
    la = strlen(a);lb = strlen(b);//�����2���ַ����ĳ��ȡ�
    if(la > lb){// �����ȸ����ֵ
        //c = a;
        k = 0; // ��ʾ�ַ���a�ĳ��ȴ�
    }
    else{
        //c = b;
        k = 1;// ��ʾ�ַ���b�ĳ��ȴ�
    }
    i = la-1; j = lb-1;
    while(i>=0||j>=0){// ѭ���������Ӻ���ǰ��û��ɨ�����
        if(i>=0)
            numa = a[i]-'0';
        else
            numa = 0;
        if(j>=0)
            numb = b[j]-'0';//��char��ת��Ϊint�͡�
        else
            numb = 0;
        num = numa + numb + flag;//�����ӽ����
        flag = num/2;// ���ڴ˴�����2������1��������flag������num����ֵ��2����һ��ʼ����flag = flag/2��ʵ���� flag = num/2��
        num = num%2;

        printf("num: %d, flag: %d\n",num,flag);
        if(0==k)// �ַ���a�ĳ��ȴ�
            a[i] = (num + '0');
        else// �ַ���b�ĳ��ȴ�
            b[j] = (num + '0');

        if(i>=0)
            i--;
        if(j>=0)
            j--;

    }
    if(1==flag){// ����������λ�� > ��ַ����ĳ��ȣ��������Ӧ����1��
        if(0==k){// ��ַ�����a��
            //c = (char*)malloc(sizeof(char)*(la+1));
            c[0] = '1';
            for(i=0;i<la;i++)
                 c[i+1] = a[i];
        }
        else{// ��ַ���Ϊb
            //c = (char*)malloc(sizeof(char)*(lb+1));
            c[0] = '1';
            for(i=0;i<lb;i++)
                c[i+1] = b[i];
        }
        c[i+1] = '\0';
    }
    else{// ��������λ�� == ��ַ�������
        if(0==k){// �ַ���a�ĳ����
            for(i=0;i<la;i++)
                c[i] = a[i];
        }
        else{// �ַ���b�ĳ����
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
