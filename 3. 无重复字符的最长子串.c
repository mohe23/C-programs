#include<stdio.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char*s){
      int i,len1=0,len2=0,length=0,la=0,lb;//length-���鳤��  len1-ѭ����ʼԪ���±�  len2-��ǰɨ���Ԫ���±�  la-,lb=0

     /*//lb=sizeof(s)/sizeof(char);//�ж������Ƿ���0����
      //printf("lb:  %d\n",lb);

       //length = strlen(s);
      //for(int j=0;j<lb;j++)
       // printf("5%c  j=%d\n",s[j],j);*/
        if(s==NULL)
            la=0;

        else{
              length = strlen(s);///������s����
               // printf("else!!!\n");
             if(1==length)//�ַ���ֻ��1���ַ���
                la = 1;
             else{//�ַ�����2���������ַ���
                  for(len2=1;len2<length;len2++){
                       printf("len2:  %d\n",len2);
                      for(i=len1;i<len2;i++){
                        printf("i:  %d\n",i);
                         if(s[i]==s[len2]){//��ǰɨ�赽���ַ�s[len2]����֮ǰ���ַ����������ظ��ַ���
                           //lb=i;//����ַ����Ƿ����ظ�Ԫ��
                            if((len2-len1)>la)//��ǰ���ظ��ַ��Ӵ����ȴ���֮ǰ���ַ����ȣ���ô�͸���������ظ��ַ��Ӵ��ĳ��ȡ�
                               la = len2-len1;
                 //����ȷ��ѭ����ʼԪ�ء�
                 //lm=0;
                           len1=i+1;
                           break;//�����ظ�Ԫ�أ�ֱ������ѭ����
                        }//��len2=length-1ʱ���������1����ǣ���ôÿѭ��1�Σ�����ִ���������䣬��ô�ͻ�����Ρ�

                       if((length-1==len2)&&(i==len2-1))//��ɨ�赽�ַ��������1���ַ�ʱ��û����֮ǰ���ַ���ͬ��������ش���
                          la = length-len1;    //lm������ǣ������������ͬ�ַ�����ô�Ͳ�ִ����ؼ�����
                //printf("wer$444   %d\n",la);
                     }

                 }
             }

           if(0==len1)//�ַ���������ظ�Ԫ���Ӵ����䱾��
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
