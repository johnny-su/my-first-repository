#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int end=8; 
int canput;
int answer=0;
int m,n,su;
void solve(int i,int j);
int matrix[9][9];

int main()
{
   
    
    char input[9][9];
    //memset(input,'\0',81);
    
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
    printf("%d",answer);
    
return 0;
}

void solve(int i,int j)
{
       int k,t;
      
            if(matrix[i][j]==0)
             {     
                     for(t=1;t<=9;t++)    //逐一尝试1-9 
                       {
                                      for(k=0;k<9;k++)      
                                 {
                                        canput=1;
                                        su=i*9+j;
                                        m=su/27*27+(su%9/3)*3+k+k/3*6;
                                        n=m%9;
                                        m=m/9;                          //是否能放 
                                                                                                     //检查三个方面有没有冲突
                                        if(matrix[i][k]==t)            //检查行有没有冲突 
                                        {
                                                            canput=0; //printf("contu=[%d][%d]\n",i,k);         
                                                            break;
                                        }
                                        else if(matrix[k][j]==t)      //检查列有没有冲突 
                                        {
                                                            canput=0;//printf("contu=[%d][%d]\n",k,j);
                                                            break;
                                        }
                                        else if(matrix[m][n]==t)  //检查小矩阵有没有冲突
                                        {
                                                            canput=0;    //printf("contu=[%d][%d]\n",i%3+(k+1)/3,j%3+k%3);
                                                            break;
                                        }else;
                                 }
                                        if(canput)
                                        {
                                                  matrix[i][j]=t;
                                                  if(i==end&&j==end){answer++;matrix[i][j]=0;}
                                                  if((i<end)&&(j==end))            //跳到下一行起始位置递归 
                                                  {
                                                                  solve(i+1,0);
                                                  }
                                                  else {solve(i,j+1);}
                                        }
                                 
                       }matrix[i][j]=0;
                           
             }
            else 
            {
                  if((i==end)&&(j==end)){answer++; matrix[i][j]=0;}
                  if((i<end)&&(j==end))                             //跳到下一行起始位置递归 
                  {
                  
                  solve(i+1,0);
                  }
                  else solve(i,j+1);
            }
          
                 
}
                                       
      
      
      
      

      
      
      
      
      
      
      
      
      
      
      
      
