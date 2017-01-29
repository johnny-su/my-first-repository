#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int end=8;                //结束标识 
int canput;                    //是否能放入数字标识 
bool finish=false;            //求解结束标识 
int m,n,su;
int matrix[9][9];             //数独矩阵 
void solve(int i,int j);     //解决数独的递归函数，传入参数为元素行列下标 
void show();                 //展示数独的解的函数 


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
   
    
     solve(0,0);
     return 0;
}

void solve(int i,int j)
{
       int k,t;
       if(finish){return;}
       else 
       {
            if(matrix[i][j]==0)
             {      
                     for(t=1;t<=9;t++)                //逐一尝试1-9 
                       {
                            for(k=0;k<9;k++)      
                            {
                                su=i*9+j;
                                m=su/27*27+(su%9/3)*3+k+k/3*6;
                                n=m%9;
                                m=m/9;                       
                                canput=1;                     //检查三个方面有没有冲突
                                        
                                if(matrix[i][k]==t)          //检查行有没有冲突 
                                {
                                    canput=0;   
                                    break;
                                }
                                else if(matrix[k][j]==t)      //检查列有没有冲突 
                                {
                                     canput=0;
                                     break;
                                }
                                else if(matrix[m][n]==t)  //检查小矩阵有没有冲突
                                {
                                     canput=0;    
                                     break;
                                }else;
                            }
                            if(canput)                  //如果能放 
                            {
                                matrix[i][j]=t;
                                if(i==end&&j==end)
                                {
                                   finish=true;
                                   show();
                                   return;
                                }
                                if((i<end)&&(j==end))    //跳到下一行起始位置递归 
                                {
                                    solve(i+1,0);
                                }
                                    else solve(i,j+1);
                            }
                                 
                       }
                       matrix[i][j]=0;           //回溯 
             }
            else 
            {
                  if((i==end)&&(j==end))
                  {
                         finish=true;
                         show();
                         return;
                  }
                  
                  if((i<end)&&(j==end))            //跳到下一行起始位置递归 
                  {
                     solve(i+1,0);
                  }
                  else solve(i,j+1);
            }
      }    
                 
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
      
      
      
      

      
      
      
      
      
      
      
      
      
      
      
      
