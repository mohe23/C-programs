// 有效的括号。

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {// 定义1个顺序栈。
     char *ch;//
     int top;//初始值为-1。但结构体声明中不能赋初值。
}OrderStack;

bool isValid(char* s){ //判断字符串s是否有效。
    int i=0;//k-代表当前扫描字符的值。
    bool flag = true;//返回值。
    OrderStack Sta;// 栈。
    Sta.top = -1;//初始化该变量。
    Sta.ch = (char*)malloc(sizeof(char)*5000);//为数组ch分配存储空间。
    while(s[i]!='\0'){//只要没扫描完字符串，就一直扫描。
        //k = Chtoi(s[i]);
        if(s[i]=='('||s[i]=='['||s[i]=='{'){//当前扫描的字符是“左括号”
            Sta.top++;//栈顶指针加1
            Sta.ch[Sta.top] = s[i];//将左括号入栈，栈顶指针始终指向栈顶元素。
        }
        else if(')'==s[i]){// 此时扫描到的字符是')'。
            if(-1==Sta.top){// 栈已空，但此时进栈元素是右括号
                flag = false;//判断“无效”。
                break;
            }
            if('('==Sta.ch[Sta.top]){//此时栈顶元素是‘（’
                Sta.ch[Sta.top] = '\0';//将栈顶元素“出栈”
                Sta.top--;
               }
            else{//此时栈顶元素不为'('
                flag = false;//返回值为“false”
                break;//直接跳出循环。
            }
        }
        else if(']'==s[i]){// 此时扫描到的字符是']'
             if(-1==Sta.top){// 栈已空，但此时进栈元素是右括号
                flag = false;//判断“无效”。
                break;
            }
            if('['==Sta.ch[Sta.top]){//此时栈顶元素是‘[’
                Sta.ch[Sta.top] = '\0';//将栈顶元素“出栈”
                Sta.top--;
               }
            else{//此时栈顶元素不为'['
                flag = false;//返回值为“false”
                break;//直接跳出循环。
            }
        }
        else{//此时扫描到的字符是'}'
             if(-1==Sta.top){// 栈已空，但此时进栈元素是右括号
                flag = false;//判断“无效”。
                break;
            }
             if('{'==Sta.ch[Sta.top]){//此时栈顶元素是‘{’
                Sta.ch[Sta.top] = '\0';//将栈顶元素“出栈”
                Sta.top--;
               }
            else{//此时栈顶元素不为'{'
                flag = false;//返回值为“false”
                break;//直接跳出循环。
            }
        }
       i++;//此时i加1。
    }
    if(true==flag&&(-1)!=Sta.top)//这个是字符串s只有1个元素的情况。
        flag = false;

return flag;
}

/*int Chtoi(char ch){// st是1个长度为4的数组,初始值全为0。初始化将“括号”字符转换为相应的数字。
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
        printf("扫描到非括号字符！！\n");


return num;
}
*/

/*int *Chtoi(char ch){// st是1个长度为4的数组,初始值全为0。初始化将“括号”字符转换为相应的数字。
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
        printf("扫描到非括号字符！！\n");


return num;
}
*/
/*bool isValid(char* s) {
    bool flag = true;
    int i=0,j,k;//flag = 1; //flag=1,表示括号有效，flag=0，表示括号无效。
    int *a = (int*)malloc(sizeof(int)*4);//创建一个长度为3的数组。
    for(j=0;j<4;j++)
        a[j]=0;//将数组初始化，初始值全为0。

    while(s[i]!='\0'){//扫描字符数组,直到扫描结束。
        a = Chtoi(s[i],a);
        //k = a[0];
        if(i==0)
            k = a[0];
        else{ //i > 0
            if((a[0]==2)||(a[0]==4)||(a[0]==6)){
                if(((a[0]-1)!=k)||((a[0]%2)!=0)){
                    flag = false;
                    break;//直接跳出循环
                }
            }
            k = a[0];
        }
        i++;
    }
    for(i=1;i<4;i++){
        if((true==flag)&&(a[i]!=0)){// 只要a[1],a[2],a[3]只要有1个不为0，那么就令
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
