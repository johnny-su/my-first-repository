#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define wordnumber_of_eachline 50
#define linenumber_of_eachpage 20 

//*******use list struct to record everyline********//
typedef struct everyline{
        int line;
        char context[wordnumber_of_eachline+1];
        everyline *next;
        everyline *last;
        }oneline,*oneline_arr;
//*************************************************//

oneline_arr p,h,mid;        
int   cur_page,sum_page,fline,lline,sum_line=1;
int   lastpageline;
char  botton;
void  turnup(int a);
void  turndown(int a);
void  add();
void  dele();
void  search();
void  modify();
void  refresh();
void  save(char* a); 
int main(int argc,char**argv)
{
    FILE* fp;
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
    for(j=0;(j<wordnumber_of_eachline)&&(!feof(fp));j++)
    {
       if((c=fgetc(fp))!='\n'){h->context[j]=c;}
       else j--;
    }    
    h->line=1;
    h->last=NULL;
    h->next=NULL;
    mid=h;
    while(!feof(fp))
    {
                   //write one line//
                   if((p=(oneline_arr)malloc(sizeof(oneline)))==NULL){printf("space is full\n");break;}
                   memset(p->context,'\0',sizeof(h->context));
                      
                   for(j=0;(j<wordnumber_of_eachline)&&(!feof(fp));j++)
                   {
                       if((c=fgetc(fp))!='\n')p->context[j]=c;
                       else j--;
                   }    
                   //h->context[j+1]='\0';
                   p->last=NULL;
                   mid->next=p;
                   mid=p;  
                   sum_line++;
                   p->line=sum_line;
                  
    }            
    sum_page=sum_line/linenumber_of_eachpage+1;
    lastpageline=sum_line%linenumber_of_eachpage;
    p->next=h;
    p=h;
    for(i=sum_line;i>0;i--)
           {
                    p->next->last=p;
                    p=p->next;
           }
    //******************************************************//

    
    //*********show the first page*********//
    refresh();
    //********************************//
 
 
 fclose(fp);
 //***********diferent fuctions*************//
  while(1)
 {
        scanf("%c",&botton);
 
        switch(botton)
   {
        case '<':
        {
                  if(cur_page==1){printf("已是第一页");continue;}
                  else 
                  {
                       cur_page--;
                       turnup(cur_page);
                       continue;
                  }
        }
        case '>':
        {
                   if(cur_page==sum_page){printf("已是最后一页");continue;}
                   else 
                  {
                       cur_page++;
                       turndown(cur_page);
                       continue;          
                  }
        }
       case 'a':
       {
             add();
             continue;
       }
       case 'b':
       {
             dele();
             continue;
       }
       case 'c':
       {
             search();
             continue;
        }
       case 'd':
       {
             modify();
             continue;
       }
       case 's':
       {
            refresh();
            continue;
       }
       case 'x':
       {
            save(filename);
            break;
       }
   }  
 }
 
 for(i=sum_line;i>0;i--)
 {
                        free(p);
                        p=h->next;
                        h=h->next;
 }
 return 0;
}

void  turnup(int a)
{
      int i;
      if(a==sum_page-1)
                  {
                      
                       fline=fline-linenumber_of_eachpage-lastpageline;
                       lline=lline-lastpageline;
                       for(i=0;i<(linenumber_of_eachpage+lastpageline);i++)p=p->last;
                       printf("\tpage: %d  line: %d to %d\n",a,fline,lline);
                       for(i=0;i<linenumber_of_eachpage;i++)
                       {
                                   
                                   printf("%d %s",p->line,p->context);
                                   printf("\n");
                                   p=p->next;
                          
                       }
                       printf("< >：翻页\n");
                       printf("a : 增加新一行内容\n"); 
                       printf("b : 删除某一行内容\n");            
                       printf("c : 查找内容\n");   
                       printf("d : 修改内容\n");   
                       printf("x : 保存\n");   
                       printf("s : 刷新\n");   
                       printf("输入：");
                            
                  }
      else 
                  {
                       
                       fline=fline-linenumber_of_eachpage;
                       lline=lline-linenumber_of_eachpage;
                       for(i=0;i<(linenumber_of_eachpage*2);i++)p=p->last;
                       printf("\tpage: %d  line: %d to %d\n",a,fline,lline);
                       for(i=0;i<linenumber_of_eachpage;i++)
                       {
                                   
                                   printf("%d %s",p->line,p->context);
                                   printf("\n");
                                   p=p->next;
                          
                       }
                       printf("< >：翻页\n");
                       printf("a : 增加新一行内容\n"); 
                       printf("b : 删除某一行内容\n");            
                       printf("c : 查找内容\n");   
                       printf("d : 修改内容\n");   
                       printf("x : 保存\n");   
                       printf("s : 刷新\n");   
                       printf("输入：");
                            
                  }
 
}
void     turndown(int a)
{
         int i;
         fline=fline+linenumber_of_eachpage;
         lline=lline+linenumber_of_eachpage;
         printf("\tpage: %d  line: %d to %d\n",a,fline,lline);
         for(i=0;i<linenumber_of_eachpage;i++)
         {
                            if(p->next->line==sum_line)
                            {
                                 printf("%d %s",p->line,p->context);
                                 printf("\n");
                                 printf("%d %s",p->next->line,p->next->context);
                                 printf("\n");
                                 p=p->next->next;
                                 break;
                            }
                            else 
                            {
                                 printf("%d %s",p->line,p->context);
                                 printf("\n");
                                 p=p->next;
                            }
         }
    printf("< >：翻页\n");
    printf("a : 增加新一行内容\n"); 
    printf("b : 删除某一行内容\n");            
    printf("c : 查找内容\n");   
    printf("d : 修改内容\n");   
    printf("x : 保存\n");   
    printf("s : 刷新\n");   
    printf("输入：");
        
}
void     add()
{
         oneline_arr g;
         int  i,w;
         char u,num;
         u='y';
         
         printf("你好，请输入新增加的内容(不超过%d字数，并按回车键结束输入)：",wordnumber_of_eachline);
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
                                      if(j<linenumber_of_eachpage)
                                      {
                                      printf("%d %s",ss->line,ss->context);
                                      printf("\n");
                                      ss=ss->next;
                                      j++;
                                      }
                                      else{j=0;break;}
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

void    save(char* a)
{
        char num;
        int i;
        FILE* f;
        printf("确定要储存之前的所有操作结果吗?(y/n):");
        scanf("%c",num);
        if(num=='y')
        {
                    f=fopen(a,"w");
                    p=h;
                    for(i=0;i<sum_line;i++)
                    {
                            fputs(p->context,f);
                            fputc('\r\n',f);
                            p=p->next;
                    }
                    fclose(f);
                    
        }               
        else ;
}

void  refresh()
{
    int i;
    p=h;
    cur_page=1;
    fline=1;
    lline=linenumber_of_eachpage;
    printf("\tpage: %d  line: %d to %d\n",cur_page,fline,lline);
    for(i=fline;i<=linenumber_of_eachpage;i++)
    {
                                              printf("%d %s",p->line,p->context);
                                              printf("\n");
                                              p=p->next;
    }
   
    printf("< >：翻页\n");
    printf("a : 增加新一行内容\n"); 
    printf("b : 删除某一行内容\n");            
    printf("c : 查找内容\n");   
    printf("d : 修改内容\n");   
    printf("x : 保存\n");   
    printf("s : 刷新\n");   
    printf("输入：");
}     

