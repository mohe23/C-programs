// �����ǰ׺
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Compare2str(char *c1,char *c2){//���2���ַ��������ع���ǰ׺���ȡ�ȡֵ��Χ����0��
    int i=0;
    //if(c1[0]=='\0'||c2[0]=='\0')//һ��2���ַ�����1������=0���򷵻ع���ǰ׺����Ϊ0��
      //  return 0;
    while(c1[i]!='\0'&&c2[i]!='\0'){
        if(c1[i]==c2[i])
            i++;
        else//һ�����Ƚϵ�2���ַ���ͬ��������ѭ����
            break;
    }
    //if(i>0)//���i>0��˵��2���ַ����й���ǰ׺����i==0����˵��2���ַ���û�й���ǰ׺��
      //  i++;
    return i;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char*c = (char*)malloc(sizeof(char)*300);//����1������Ϊ200���ַ����顣
    int i,f,l,flag;//iΪ��ţ�f��Ϊ��ǣ�flag��ǹ���ǰ׺���ȡ�

    if(1==strsSize){ // ֻ��1���ַ������������ǰ׺���Ǹ��ַ��������۸��ַ����ǲ��ǿմ���
        //l = strlen()
      if((*strs)==NULL)//1���ַ��������ַ���Ϊ�ա�
          c[0]='\0';
      else{//����1���ǿյ��ַ���
           l = strlen(*strs);
           for(i=0;i<l;i++)
               c[i]=strs[0][i];
           c[i] = '\0';//��֤�ַ���c��'\0'��β��
      }
    }
    else{ // �ַ������� > 1��
        for(i=1;i<strsSize;i++){
            f = Compare2str(strs[0],strs[i]);//�Ƚϵ�1���ַ�����ڣ�i+1�����ַ�����

            if(0==f){//��1���ַ�����ڣ�i+1�����ַ���û�й���ǰ׺��ֱ������ѭ����
                flag = 0;//��ǹ���ǰ׺�ǿմ���
                break;
            }
            else{// f>0������ǰ���Ƚϵ�2���ַ����й���ǰ׺��
                if(1==i)
                    flag = f;//��ǵ�1���ַ������2���ַ����Ĺ���ǰ׺���ȡ�
                if(f < flag)// ���±Ƚϵó��Ĺ���ǰ׺���� < ֮ǰ�Ĺ���ǰ׺���ȣ����¹���ǰ׺���ȡ�
                    flag = f;
            }
        }
        if(0==flag){//�ڱȽϵ�1���ַ������k(k>2)���ַ��������У�����û�й���ǰ׺��
            //c = (char*)malloc(sizeof(char));//��������Ϊflag��һά�ַ����顣
            c[0]='\0';
        }
        else{//���ڹ���ǰ׺��
           // c = (char*)malloc(sizeof(char)*flag);//��������Ϊflag��һά�ַ����顣
            for(i=0;i<flag;i++)
                c[i]= strs[0][i];//�õ���š�����ǰ׺�������顣
            c[i] = '\0';//��֤�ַ����ԡ�\0����β��
        }

    }
return c;//���ش�š�����ǰ׺����������
}

int main(){
    int i=0,j=0,leng=3;
    char *s[3]={"flower","flow","fly"};
    char *sr =(char*)malloc(sizeof(char)*10);
    char **st = (char**)malloc(sizeof(char*)*leng);
    for(i=0;i<leng;i++)
        st[i] = (char*)malloc(sizeof(char)*10);

      st[0][0]='\0';
     //st[0][0]='f'; st[0][1]='l'; st[0][2]='o'; st[0][3]='w'; st[0][4]='e'; st[0][5]='r';
     //st[1][0]='f'; st[1][1]='l'; st[1][2]='e'; st[1][3]='w';
     //st[2][0]='f'; st[2][1]='l'; st[2][2]='r';
    //st[0]={'f','l','o','w','e','r'};//{'f','l','e','w'},{'f','l','r'}};
    //st[1][]={'f','l','e','w'};
    //st[2][]={'f','l','r'};

    sr = longestCommonPrefix(s,leng);
    while(sr[j]!='\0'){
        printf("%c",sr[j]);
        j++;
    }

return 0;
}
