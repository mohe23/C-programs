// ��Ч�����š�

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {// ����1��˳��ջ��
     char *ch;//
     int top;//��ʼֵΪ-1�����ṹ�������в��ܸ���ֵ��
}OrderStack;

bool isValid(char* s){ //�ж��ַ���s�Ƿ���Ч��
    int i=0;//k-����ǰɨ���ַ���ֵ��
    bool flag = true;//����ֵ��
    OrderStack Sta;// ջ��
    Sta.top = -1;//��ʼ���ñ�����
    Sta.ch = (char*)malloc(sizeof(char)*5000);//Ϊ����ch����洢�ռ䡣
    while(s[i]!='\0'){//ֻҪûɨ�����ַ�������һֱɨ�衣
        //k = Chtoi(s[i]);
        if(s[i]=='('||s[i]=='['||s[i]=='{'){//��ǰɨ����ַ��ǡ������š�
            Sta.top++;//ջ��ָ���1
            Sta.ch[Sta.top] = s[i];//����������ջ��ջ��ָ��ʼ��ָ��ջ��Ԫ�ء�
        }
        else if(')'==s[i]){// ��ʱɨ�赽���ַ���')'��
            if(-1==Sta.top){// ջ�ѿգ�����ʱ��ջԪ����������
                flag = false;//�жϡ���Ч����
                break;
            }
            if('('==Sta.ch[Sta.top]){//��ʱջ��Ԫ���ǡ�����
                Sta.ch[Sta.top] = '\0';//��ջ��Ԫ�ء���ջ��
                Sta.top--;
               }
            else{//��ʱջ��Ԫ�ز�Ϊ'('
                flag = false;//����ֵΪ��false��
                break;//ֱ������ѭ����
            }
        }
        else if(']'==s[i]){// ��ʱɨ�赽���ַ���']'
             if(-1==Sta.top){// ջ�ѿգ�����ʱ��ջԪ����������
                flag = false;//�жϡ���Ч����
                break;
            }
            if('['==Sta.ch[Sta.top]){//��ʱջ��Ԫ���ǡ�[��
                Sta.ch[Sta.top] = '\0';//��ջ��Ԫ�ء���ջ��
                Sta.top--;
               }
            else{//��ʱջ��Ԫ�ز�Ϊ'['
                flag = false;//����ֵΪ��false��
                break;//ֱ������ѭ����
            }
        }
        else{//��ʱɨ�赽���ַ���'}'
             if(-1==Sta.top){// ջ�ѿգ�����ʱ��ջԪ����������
                flag = false;//�жϡ���Ч����
                break;
            }
             if('{'==Sta.ch[Sta.top]){//��ʱջ��Ԫ���ǡ�{��
                Sta.ch[Sta.top] = '\0';//��ջ��Ԫ�ء���ջ��
                Sta.top--;
               }
            else{//��ʱջ��Ԫ�ز�Ϊ'{'
                flag = false;//����ֵΪ��false��
                break;//ֱ������ѭ����
            }
        }
       i++;//��ʱi��1��
    }
    if(true==flag&&(-1)!=Sta.top)//������ַ���sֻ��1��Ԫ�ص������
        flag = false;

return flag;
}

/*int Chtoi(char ch){// st��1������Ϊ4������,��ʼֵȫΪ0����ʼ���������š��ַ�ת��Ϊ��Ӧ�����֡�
    int num =0;
    switch(ch){
        case '(':
            num = 1;
            break;
        case ')':
            num = 2;
            break;
        case '[':
            num = 3;
            break;
        case ']':
            num = 4;
            break;
        case '{':
            num = 5;
            break;
        case '}':
            num = 6;
            break;
    }
    if(0==num)
        printf("ɨ�赽�������ַ�����\n");


return num;
}
*/

/*int *Chtoi(char ch){// st��1������Ϊ4������,��ʼֵȫΪ0����ʼ���������š��ַ�ת��Ϊ��Ӧ�����֡�
    int num =0;
    switch(ch){
        case '(':
            num = 1;
            break;
        case ')':
            num = 2;
            break;
        case '[':
            num = 3;
            break;
        case ']':
            num = 4;
            break;
        case '{':
            num = 5;
            break;
        case '}':
            num = 6;
            break;
    }
    if(0==num)
        printf("ɨ�赽�������ַ�����\n");


return num;
}
*/
/*bool isValid(char* s) {
    bool flag = true;
    int i=0,j,k;//flag = 1; //flag=1,��ʾ������Ч��flag=0����ʾ������Ч��
    int *a = (int*)malloc(sizeof(int)*4);//����һ������Ϊ3�����顣
    for(j=0;j<4;j++)
        a[j]=0;//�������ʼ������ʼֵȫΪ0��

    while(s[i]!='\0'){//ɨ���ַ�����,ֱ��ɨ�������
        a = Chtoi(s[i],a);
        //k = a[0];
        if(i==0)
            k = a[0];
        else{ //i > 0
            if((a[0]==2)||(a[0]==4)||(a[0]==6)){
                if(((a[0]-1)!=k)||((a[0]%2)!=0)){
                    flag = false;
                    break;//ֱ������ѭ��
                }
            }
            k = a[0];
        }
        i++;
    }
    for(i=1;i<4;i++){
        if((true==flag)&&(a[i]!=0)){// ֻҪa[1],a[2],a[3]ֻҪ��1����Ϊ0����ô����
            flag = false;
            break;
        }
    }

return flag;
}
*/
int main(){
    int i,*a;
    bool ste;
    //char b[4] = {'(','[',']',') '};//,'{','}'
    char b[2] = {'(','('};
    ste = isValid(b);
    printf("%d\n",ste);
    /*a = (int*)malloc(sizeof(int)*4);
    for(i=0;i<3;i++)
        a[i]=0;
    for(i=0;i<6;i++)
        a = Chtoi(b[i],a);
    for(i=0;i<3;i++)
        printf("%d\n",a[i]);*/
return 0;
}
