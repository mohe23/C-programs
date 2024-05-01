// 最长公共前缀
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Compare2str(char *c1,char *c2){//针对2个字符串，返回公共前缀长度。取值范围包括0。
    int i=0;
    //if(c1[0]=='\0'||c2[0]=='\0')//一旦2个字符串有1个长度=0，则返回公共前缀长度为0。
      //  return 0;
    while(c1[i]!='\0'&&c2[i]!='\0'){
        if(c1[i]==c2[i])
            i++;
        else//一旦待比较的2个字符不同，则跳出循环。
            break;
    }
    //if(i>0)//如果i>0，说明2个字符串有公共前缀，若i==0，则说明2个字符串没有公共前缀。
      //  i++;
    return i;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    char*c = (char*)malloc(sizeof(char)*300);//创建1个长度为200的字符数组。
    int i,f,l,flag;//i为序号，f作为标记，flag标记公共前缀长度。

    if(1==strsSize){ // 只有1个字符串，那最长公共前缀就是该字符串。无论该字符串是不是空串。
        //l = strlen()
      if((*strs)==NULL)//1个字符串，该字符串为空。
          c[0]='\0';
      else{//存在1个非空的字符串
           l = strlen(*strs);
           for(i=0;i<l;i++)
               c[i]=strs[0][i];
           c[i] = '\0';//保证字符串c以'\0'结尾。
      }
    }
    else{ // 字符串长度 > 1。
        for(i=1;i<strsSize;i++){
            f = Compare2str(strs[0],strs[i]);//比较第1个字符串与第（i+1）个字符串。

            if(0==f){//第1个字符串与第（i+1）个字符串没有公共前缀，直接跳出循环。
                flag = 0;//标记公共前缀是空串。
                break;
            }
            else{// f>0，即当前待比较的2个字符串有公共前缀。
                if(1==i)
                    flag = f;//标记第1个字符串与第2个字符串的公共前缀长度。
                if(f < flag)// 最新比较得出的公共前缀长度 < 之前的公共前缀长度，更新公共前缀长度。
                    flag = f;
            }
        }
        if(0==flag){//在比较第1个字符串与第k(k>2)个字符串过程中，发现没有公共前缀。
            //c = (char*)malloc(sizeof(char));//创建长度为flag的一维字符数组。
            c[0]='\0';
        }
        else{//存在公共前缀。
           // c = (char*)malloc(sizeof(char)*flag);//创建长度为flag的一维字符数组。
            for(i=0;i<flag;i++)
                c[i]= strs[0][i];//得到存放“公共前缀”的数组。
            c[i] = '\0';//保证字符串以‘\0’结尾。
        }

    }
return c;//返回存放“公共前缀”的数组名
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
