#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int end=8;                //������ʶ 
int canput;                    //�Ƿ��ܷ������ֱ�ʶ 
bool finish=false;            //��������ʶ 
int m,n,su;
int matrix[9][9];             //�������� 
void solve(int i,int j);     //��������ĵݹ麯�����������ΪԪ�������±� 
void show();                 //չʾ�����Ľ�ĺ��� 


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
                     for(t=1;t<=9;t++)                //��һ����1-9 
                       {
                            for(k=0;k<9;k++)      
                            {
                                su=i*9+j;
                                m=su/27*27+(su%9/3)*3+k+k/3*6;
                                n=m%9;
                                m=m/9;                       
                                canput=1;                     //�������������û�г�ͻ
                                        
                                if(matrix[i][k]==t)          //�������û�г�ͻ 
                                {
                                    canput=0;   
                                    break;
                                }
                                else if(matrix[k][j]==t)      //�������û�г�ͻ 
                                {
                                     canput=0;
                                     break;
                                }
                                else if(matrix[m][n]==t)  //���С������û�г�ͻ
                                {
                                     canput=0;    
                                     break;
                                }else;
                            }
                            if(canput)                  //����ܷ� 
                            {
                                matrix[i][j]=t;
                                if(i==end&&j==end)
                                {
                                   finish=true;
                                   show();
                                   return;
                                }
                                if((i<end)&&(j==end))    //������һ����ʼλ�õݹ� 
                                {
                                    solve(i+1,0);
                                }
                                    else solve(i,j+1);
                            }
                                 
                       }
                       matrix[i][j]=0;           //���� 
             }
            else 
            {
                  if((i==end)&&(j==end))
                  {
                         finish=true;
                         show();
                         return;
                  }
                  
                  if((i<end)&&(j==end))            //������һ����ʼλ�õݹ� 
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
      
      
      
      

      
      
      
      
      
      
      
      
      
      
      
      
