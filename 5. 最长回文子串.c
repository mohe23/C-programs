#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

char * longestPalindrome(char * s){
    int i,j, first,end,len,lf,le, ler, leng,la;// first end len��ǰ��������Ӵ���β�ַ��±꣬����
   //lf,le, ler�Ǵ��������Ӵ�����β�ַ��±꣬�Ӵ�����
   //char *t;//����ֵ��
    //leng = sizeof(s)/ sizeof(s[0]);//�����ַ������ȡ�
    leng = strlen(s);
    printf("ԭ�ַ�������leng:%d\n",leng);
    lf = le =0;//һ��ʼ������Ӵ��ǵ����ַ�
    ler = 1;//�ַ�������1��
    first =0; end=1; len=0;
    if(1 == leng)//���ַ�����Ϊ1
       return s;
       //printf("%c",s[0]);

    else{//�ַ������ȣ�1
         while(first < (leng-1)){//firstһֱѭ����������2���ַ���
             end = first+ler;//end��ֵ�����ݵ�ǰ���л����Ӵ����ȣ���֤�µĻ����Ӵ����ȴ������еĳ��ȡ�
             while(end < leng){
                    la = 1;//ÿ���ж��Ӵ��ǻ��Ĵ�ʱ���ͽ�la��ʼ��Ϊ1���ô˱���ж��Ӵ��Ƿ��ǻ��Ĵ���
                    len = end-first+1;//���㵱ǰ�������Ӵ����ȡ�

                 for(i=first; i < (len/2+first); i++){
                      if(s[i] != s[first+end-i]){
                            la = 0;//��ǰ�Ӵ����ǻ��Ĵ���
                            break;//ֱ������forѭ����
                      }

                 }//()&&(len > ler)
                 if(1 == la){//��ǰ�Ӵ��ǻ��Ĵ���
                     if(leng == len){
                         return s;
                         break;//����ѭ����
                     }
                     ler = len;//���»����Ӵ�������ݡ�
                     lf = first;
                     le = end;

                 }
                end++;//��endֵ��1��first���䣬�жϸ������Ӵ��Ƿ��ǻ��Ĵ���
             }

             first++;//��firstΪ�׵����г��ȵ��ַ��Ӵ��Ѿ��ж���ϣ���ô�ͽ�first��1��
            //len = len+1;
            //end++;
         }
     printf("lf: %d, le: %d, ler: %d\n",lf,le,ler);//��bug.
     int lew=0;
     lew = ler;
     char*t = (char*)malloc((lew+1)*sizeof(char));//Ϊ�����Ӵ�����洢�ռ䡣lew*
     t[lew] = '\0';
     printf("lew:  %d\n",lew);
     printf("length: %d\n",strlen(t));

     for(i=0,j=lf;i<lew,j<=le;i++,j++){
        printf("j: %d s[j]: %c  ",j,s[j]);
         t[i] = s[j];//��ȡ�����Ӵ���
         printf("t length: %d\n",strlen(t));
     }//sizeof(t)/sizeof(t[0])   strlen(t)
 printf("t.length: %d\n",strlen(t));

     return t;//����t  1 2 3 4 5
    }

}

int main(){
    char a[5]="dadac";//һ���ַ����鸳ֵ��ʽ��
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

    printf("���Ĵ�����le:%d   b[0]:%c\n",lw,b[0]);
    for(i=0;i<lw;i++)
        printf("%d-%c\n",i,b[i]);

return 0;
}
