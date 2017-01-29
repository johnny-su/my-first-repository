// 我真诚地保证：  
 
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
 
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在作业报告中
 
// 详细地列举我所遇到的问题，以及别人给我的提示。
 
// 在此，我感谢 XXX, …, XXX对我的启发和帮助。下面的报告中，我还会具体地提到
 
// 他们在各个方法对我的帮助。
 
// 我的程序里中凡是引用到其他程序或文档之处，
 
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
 
// 我都已经在程序的注释里很清楚地注明了引用的出处。
 
 
 
// 我从未抄袭过别人的程序，也没有盗用别人的程序，
 
// 不管是修改式的抄袭还是原封不动的抄袭。
 
// 苏晓强        2011202484 
 
 





#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int end;                        //结束标识 
int canput;                    //是否能放入数字标识 
bool finish=false;            //求解结束标识 
int m,n,su,d=0;
int matrix[9][9];            //数独矩阵 
void solve(int h);          //解决数独的递归函数，传入参数为元素行列下标 
void show();                //展示数独的解的函数 
int empty[81][2];           //计入待填的空格 
int main()
{
   
   
    
    char input[9][9];
    memset(input,'\0',81);
    
    int j,i=0;
    while(i!=9)
    {
        scanf("%s",&input[i][0]);
        i++;
    }
    
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)   
        {
             matrix[i][j]=input[i][j]-48;
        }
    
   
   for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        if(matrix[i][j]==0)
        { 
            empty[d][0]=i;
            empty[d][1]=j;
            d++;
        }
        end=d-1;
        d=0;
    
  solve(d);
  getchar();  
  
return 0;
}

void solve(int h)
{
       int k,t;
       if(finish){return;}
       for(t=1;t<=9;t++)    //逐一尝试1-9 
       {
           for(k=0;k<9;k++)      
           {
              canput=1;
              su=empty[h][0]*9+empty[h][1];
              m=su/27*27+(su%9/3)*3+k+k/3*6;
              n=m%9;
              m=m/9;                                  //是否能放 
                                                                                                     //检查三个方面有没有冲突
              if(matrix[empty[h][0]][k]==t)            //检查行有没有冲突 
              {
                  canput=0;          
                  break;
              }
              else if(matrix[k][empty[h][1]]==t)      //检查列有没有冲突 
              {
                 canput=0;//printf("contu=[%d][%d]\n",k,j);
                 break;
              }
              else if(matrix[m][n]==t)               //检查小矩阵有没有冲突
              {
                 canput=0;    
                 break;
              }else;
           }
           if(canput)
           {
               matrix[empty[h][0]][empty[h][1]]=t;
               if(h==end)
               {
                        finish=true;
                         show();
                         return;
               }
               else            //跳到下一行起始位置递归 
               {
                    solve(h+1);
               }
                                                
           }
                                 
       }matrix[empty[h][0]][empty[h][1]]=0;
                           
}
void show()
{
      int u,w;
      
      if (finish)
 
      {
                 for(u=0;u<9;u++)
                 {                         
                     for(w=0;w<9;w++)   
                     {
                        printf("%d",matrix[u][w]);
                     }
                  printf("\n");
                 }
      }
 
}              
