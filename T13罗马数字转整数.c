#include<stdio.h>

//enum Rnum{I=1,V=5,X=10,L=50,C=100,D=500,M=1000};//��enum��������ʾ6����������������ʮ������ֵ��

int Clength(char*c){ // �������鳤�ȡ�
    int j=0,len=0;
    while(c[j]!='\0'){
        len++;
        j++;
    }

return len;
}

int Rtoi(char ch){ // �����������֣����ʮ��������
    int r=0;
    switch(ch){
         case 'I':
             r = 1;
             break;
         case 'V':
              r = 5;
              break;
         case 'X':
              r = 10;
              break;
         case 'L':
              r = 50;
              break;
         case 'C':
              r = 100;
              break;
         case 'D':
              r = 500;
              break;
         case 'M':
              r = 1000;
              break;

    }
return r;
}

int Stonums(char a,char b){// 6���������,������������Ϊ-1
    int num;
    if('I'==a&&'V'==b)
        num = 4;
    else if('I'==a&&'X'==b)
        num = 9;
    else if('X'==a&&'L'==b)
        num = 40;
    else if('X'==a&&'C'==b)
        num = 90;
    else if('C'==a&&'D'==b)
        num = 400;
    else if('C'==a&&'M'==b)
        num = 900;
    else
        num = -1; //�����Ϊ��ȷ������6�����֮���������ϡ�
    return num;
}

int romanToInt(char* s) {//��������ת������s-����������ֵ�char������
    int i,le,rt,twos,si,sm;//le-s���鳤�ȣ�rt-�ж�����s�Ƿ�ɨ���꣬sm-�������ִ����ʮ����������twos-2���������ִ��������
    sm = 0;//��ʼֵΪ0
    le = Clength(s);// �����ַ�����s�ĳ��ȡ�
    printf("le = %d\n",le);
    for(i=0;i<le;){
        rt = Rtoi(s[i]);
        if(0==rt)
            break;//�����е���Ч��ĸ�Ѿ�ɨ����ϣ�����ѭ����
        twos = Stonums(s[i],s[i+1]);
        if(-1==twos){// ��ǰ��ϲ���6���������
           sm = sm + rt;//����ǰ������ĸ����ֵ�ӵ�sm�У�ͬʱi++
           i++;
        }
        else{// ���������6���������
            sm = sm + twos;//����ǰ��ϴ������ֵ�ӵ�sum�У�Ȼ��2��i++
            i += 2;
        }

     printf("i=%d,sum: %d\n",i,sm);
    }
    if(0 == sm)
        printf("�����������г���");

    return sm;// ���������������д�������֡�
}


int main(){
   int i,leng;
   char a[]={'M','D','C','C','C','L','X','X','X','I','V'};
   //char a[]={'M','D','C','C','C','L'};
   leng = romanToInt(a);
   printf("sum: %d ",leng);
   //printf("d:%d\n",Rtoi('Q'));
   //leng = sizeof(a)/sizeof(a[0]);
   // printf("lr: %d\n",leng);
    //char  ch = /0;
    //printf("c:%c\n",ch);
  // for(i =0;i<6;i++){
    //  if(a[i]=='\0')
      //     printf("10\n");
      //else
        //   printf("%c\n",a[i]);
  // }
    //i = 0;
  //  while(a[i]!= '0'){
    //    printf("%c\n",a[i]);
      //  i++;
   // }

    //printf("%d,%d,%d,%d,%d,%d,%d\n",I,V,X,L,C,D,M);
    //printf("%d",I+V);
return 0;
}
