// ����ϵر�֤��  
 
// ���Լ��������������������ӷ�������Ƶ���������й�����
 
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ�����ҵ������
 
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��
 
// �ڴˣ��Ҹ�л XXX, ��, XXX���ҵ������Ͱ���������ı����У��һ��������ᵽ
 
// �����ڸ����������ҵİ�����
 
// �ҵĳ������з������õ�����������ĵ�֮����
 
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
 
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����
 
 
 
// �Ҵ�δ��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
 
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��
 
// ����ǿ        2011202484 
 
 





#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int end;                        //������ʶ 
int canput;                    //�Ƿ��ܷ������ֱ�ʶ 
bool finish=false;            //��������ʶ 
int m,n,su,d=0;
int matrix[9][9];            //�������� 
void solve(int h);          //��������ĵݹ麯�����������ΪԪ�������±� 
void show();                //չʾ�����Ľ�ĺ��� 
int empty[81][2];           //�������Ŀո� 
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
       for(t=1;t<=9;t++)    //��һ����1-9 
       {
           for(k=0;k<9;k++)      
           {
              canput=1;
              su=empty[h][0]*9+empty[h][1];
              m=su/27*27+(su%9/3)*3+k+k/3*6;
              n=m%9;
              m=m/9;                                  //�Ƿ��ܷ� 
                                                                                                     //�������������û�г�ͻ
              if(matrix[empty[h][0]][k]==t)            //�������û�г�ͻ 
              {
                  canput=0;          
                  break;
              }
              else if(matrix[k][empty[h][1]]==t)      //�������û�г�ͻ 
              {
                 canput=0;//printf("contu=[%d][%d]\n",k,j);
                 break;
              }
              else if(matrix[m][n]==t)               //���С������û�г�ͻ
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
               else            //������һ����ʼλ�õݹ� 
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
