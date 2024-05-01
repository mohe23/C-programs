//   爬楼梯


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int climbStairs(int n){
    /*int ret;// 递归方法
    if(1==n)// 爬1层楼梯
        return 1;
        //ret = 1;
    else if(2==n)// 爬2层楼梯
        return 2;
        //ret = 2;
    else //if(3==n)
        return climbStairs(n-1)+climbStairs(n-2);
*/
//return ret;
   int i,p,q,k;//使用for循环解决问题
   p=1;q=2;
   if(1==n)
       k = 1;
   else if(2==n)
       k = 2;
   else{ //n>=3
       for(i=3;i<=n;i++){
           k = p+q;
           p = q;
           q = k;
       }
   }

return k;
}

int main(){
    int k,t;
    k = 5;
    t = climbStairs(k);
    printf("t: %d\n",t);


return 0;
}
