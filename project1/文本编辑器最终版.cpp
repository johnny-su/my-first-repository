#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define wordnumber_of_eachline 80


//*******use list struct to record everyline********//
typedef struct everyline{
        int line;
        char context[wordnumber_of_eachline+1];
        everyline *next;
        everyline *last;
        }oneline,*oneline_arr;
//*************************************************//

oneline_arr p,h,mid;        
FILE* fp;
int   sum_line=0;
char  botton;
char  acmd[20]={"displ"};
char  bcmd[20]={"addl"};
char  ccmd[20]={"dell"};
char  dcmd[20]={"find"};
void  add();
void  dele();
void  search();
void  modify();
void  show();

int main(int argc,char**argv)
{
    
    char filename[]="G\:\\";
    char c;
    int j,i=0;
    int n=0;
    
    
    //**********open the file**********//
    strcat(filename,argv[1]);
    if((fp=fopen(filename,"r+"))==NULL)printf("can not open the file");
    //********************************//
    
    
    //**********put the file into different line*********//
    if((h=(oneline_arr)malloc(sizeof(oneline)))==NULL)printf("space is full\n");
    memset(h->context,'\0',sizeof(h->context));
    for(j=0;j<wordnumber_of_eachline;j++)
    {
       if(((c=fgetc(fp))!='\n')&&(c!='#')){h->context[j]=c;}
      
       else break;
    }    
    h->line=0;
    h->last=NULL;
    h->next=NULL;
    mid=h;
    while(c!='#')
    {
                   //write one line//
                   if((p=(oneline_arr)malloc(sizeof(oneline)))==NULL){printf("space is full\n");break;}
                   memset(p->context,'\0',sizeof(h->context));
                      
                   for(j=0;j<wordnumber_of_eachline;j++)
                   {
                       if(((c=fgetc(fp))!='\n')&&(c!='#'))p->context[j]=c;
                       
                       else break;
                   }    
                   if(c=='#'){free(p);break;}
                   else
                   {
                   p->last=NULL;
                   mid->next=p;
                   mid=p;  
                   sum_line++;
                   p->line=sum_line;
                   }
    }            
    p=h;
    for(i=0;i<sum_line;i++)p=p->next;
    p->next=h;
    p=h;
    for(i=sum_line;i>=0;i--)
           {
                    p->next->last=p;
                    p=p->next;
           }
    //******************************************************//
p=h;for(i=0;i<=3;i++){printf("%s\n",p->context);p=p->next;}
    //*********read the cmd*********//
    
    int N;
    char num_cmd[20];
    char rcmd[20];
    
   
    memset(rcmd,'\0',20);
    memset(num_cmd,'\0',20);
    
    fscanf(fp,"%s",num_cmd);
    N=atoi(num_cmd);
    //**************************//
    
    
    //************carry out the cmd//
    for(i=0;i<N;i++)
    {
                    
                    fscanf(fp,"%s",rcmd);
                    if(strcmp(rcmd,acmd)==0)show();
                    else if(strcmp(rcmd,bcmd)==0)add();
                    else if(strcmp(rcmd,ccmd)==0)dele();
                    else search();
    }
    //********************************//
    
    
    
 fclose(fp);
  
 for(i=sum_line;i>=0;i--)
 {
                        free(p);
                        p=h->next;
                        h=h->next;
 }
 return 0;
}

void     add()
{
         oneline_arr g;
         int  i,w;
         char u,num;
         u='y';
         
         
         if((g=(oneline_arr)malloc(sizeof(oneline)))==NULL)printf("the space is full");
         else 
         {
            memset(g->context,'\0',sizeof(g->context));
            scanf("%s",g->context);
         }      
         printf("是否指定新增加内容的行号位置？y/n");
         scanf("%c",&u);
         if(u=='y')
         {
            while(1)         
            {       
                    printf("请输入插入新内容的行号位置(此设置为可重复输入设置，输入空格号退出):");
                    scanf("%c",&num);
                    printf("\n");
                    if(num==' '){break;}
                    else 
                    {
                         w=atoi(&num); 
                         if(w<(sum_line/2))
                         {
                                             p=h;
                                             for(i=0;i<w;i++)p=p->next;
                                             mid=p;
                                             for(i=0;i<sum_line-w;i++)//依次向后推// 
                                             {
                                                      mid->line++;
                                                      mid=mid->next;
                                             }
                                             p->last->next=g;
                                             g->last=p->last;
                                             p->last=g;
                                             g->next=p;
                         }
                         else 
                         {
                                             p=h->last;
                                             for(i=w;i<sum_line;i++)p=p->last;
                                             mid=p;
                                             for(i=0;i<sum_line-w;i++)//依次向后推// 
                                             {
                                                      mid->line++;
                                                      mid=mid->next;
                                             }
                                             p->last->next=g;
                                             g->last=p->last;
                                             p->last=g;
                                             g->next=p;     
                         }
                    }
            }
         printf("插入新内容结束，刷新请输入s：");
         } 
         else 
         {
              p=h->last;
              p->next->last=g;
              g->next=p->next;
              g->last=p;
              p->next=g;
              sum_line++;
              g->line=sum_line;
              printf("插入新内容结束，刷新请输入s：");
         }
         //printf("插入新内容结束，刷新请输入s：");
}

void   dele()
{
         oneline_arr g;
         int  u,i;
         char num;
         while(1)         
            {       
                    printf("你好，请输入欲删除内容的行号(此设置为可重复输入设置，输入空格号退出):");
                    scanf("%c",&num);
                    printf("\n");
                    if(num==' '){break;}
                    else 
                    {
                                 u=atoi(&num);
                                 if(u<(sum_line/2))
                         {            
                                             p=h;
                                             for(i=0;i<u;i++)p=p->next;
                                             mid=p;
                                             for(i=0;i<sum_line-u;i++)//依次向前推// 
                                             {
                                                      mid->line--;
                                                      mid=mid->next;
                                             }
                                             p->last->next=p->next;
                                             p->next->last=p->last;
                                             free(p);
                         }
                         else 
                         {
                                             p=h->last;
                                             for(i=u;i<sum_line;i++)p=p->last;
                                             mid=p;
                                             for(i=0;i<sum_line-u;i++)//依次向后推// 
                                             {
                                                      mid->line--;
                                                      mid=mid->next;
                                             }
                                             p->last->next=p->next;
                                             p->next->last=p->last;
                                             free(p);   
                         }
                    }
            } 
        
         printf("删除指定内容结束，刷新请输入s：");
}

void    modify()
{
        int u,i;
        char num;
        char mod[wordnumber_of_eachline];
        printf("请输入欲更新的新内容(不超过%d字数，并按回车键结束输入)：",wordnumber_of_eachline);
        scanf("%s",mod);
        while(1)
        {
                printf("请输入欲更新内容的行号(此设置为可重复输入设置，输入空格号退出)：");
                scanf("%c",&num);
                if(num=' ')break;
                else 
                {
                     u=atoi(&num);
                     p=h;
                     for(i=0;i<u;i++)
                     {
                                  p=p->next;
                     }
                     strcpy(p->context,mod);
                }
        }
        printf("更新指定内容结束，刷新请输入s：");                                                 
}

void     search()
{
         int i,j,find=0;
         char num;
         oneline_arr ss,ssh,sm;
         char sear[100];
         memset(sear,'\0',100);
         char space[100];
         memset(space,'\0',100);
         space[0]=' ';
         
         while(1)
         {
                 printf("请输入欲查找的内容(输入空格号退出查找模式)：");        
                 scanf("%s",sear);
                 if(strcmp(sear,space)==0)break;
                 else
                 {
                     p=h;
                     ssh=(oneline_arr)malloc(sizeof(oneline));
                     sm=ssh;
                     for(i=0;i<sum_line;i++)
                     {
                                            
                                            
                                            if(strstr(p->context,sear)!=NULL)
                                            {
                                                                 
                                                    ss=(oneline_arr)malloc(sizeof(oneline));
                                                    ss->line=p->line;
                                                    strcpy(ssh->context,p->context);
                                                    find++;
                                                    sm->next=ss;
                                                    sm=sm->next;
                                            }
                                            p=p->next;
                     } 
                      ss=ssh->next;
                 while(i<find)
                    {
                      i=0;
                      for(;;i++)
                      {
                                      //if(j<linenumber_of_eachpage)
                                      //{
                                      printf("%d %s",ss->line,ss->context);
                                      printf("\n");
                                      ss=ss->next;
                                      j++;
                                      //}
                                      //else{j=0;break;}
                      }
                      printf("显示下一页查找到的内容请输入e,重新查找请输入其他任意键：");
                      scanf("%c",num);
                      if(num=='e')continue;
                      else {find=0;break;}                      
                    }
                    for(i=0;i<find;i++)
                    {
                                       
                                       free(ssh);
                                       ssh=ss->next;
                                       ss=ss->next;
                    }
                 }
         }
}

void  show()
{
    int i;
    char r;
    int n,x,y;
    p=h;
    r=fgetc(fp);
    r=fgetc(fp);
    n=r-'0';
    if((r=fgetc(fp))!='\n')
    {
                      x=r-'0';
                      r=fgetc(fp);
                      y=r-'0';
                      for(i=0;i<n;i++)
                      p=p->next;
                      for(i=x;i<y;i++)
                      printf("%c",p->context[i]);
                      printf("\n");
    }     
    
    else
    {
        if(n<(sum_line/2))
                  {
                          for(i=0;i<n;i++)
                          p=p->next;
                          printf("%s\n",p->context);
                  }
        else
                  {
                          for(i=0;i<n;i++)
                          p=p->last;
                          printf("%s\n",p->context);
                  }
    }
                          
}
