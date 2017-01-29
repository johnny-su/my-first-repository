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
int   sig=0;
char  botton[100];
char  input[100];
char  num[100];
void  turnup(int a);
void  turndown(int a);
void  add();
void  dele();
void  search();
void  modify();
void  refresh();
void  save(char*a); 
int   manage(char* a);
int main(int argc,char**argv)
{
  
    FILE* fp;
    char filename[]={"G\:\\"};
    char c;
    int j,i=0;
    int n=0;
 
    
    //**********open the file**********//
    strcat(filename,argv[1]);
    if((fp=fopen(filename,"a+"))==NULL)printf("can not open the file");
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
        if(sig)break;
        memset(botton,'\0',100);
        scanf("%s",botton);
        if(botton[1]!='\0'){printf("错误输入，请重新输入：");continue;}
        switch(botton[0])
   {
        case '<':
        {
                  if(cur_page==1){printf("已是第一页");break;}
                  else 
                  {
                       cur_page--;
                       turnup(cur_page);
                       break;
                  }
        }
        case '>':
        {
                   if(cur_page==sum_page){printf("已是最后一页");break;}
                   else 
                  {
                       cur_page++;
                       turndown(cur_page);
                       break;          
                  }
        }
       case 'a':
       {
             add();
             break;
       }
       case 'b':
       {
             dele();
             break;
       }
       case 'c':
       {
             search();
             break;
        }
       case 'd':
       {
             modify();
             break;
       }
       case 's':
       {
            refresh();
            break;
       }
       case 'x':
       {
            save(filename);
            break;
       }
       default:
       { 
            printf("错误输入,，请重新输入： ");
            break;
       } 
   } 
 }
 
 p=h;
    for(i=sum_line;i>0;i--)
 {
                       free(p->next);
                        p=p->last;
                       
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
         
         printf("你好，请输入新增加的内容(不超过%d字数，并按回车键结束输入)：",wordnumber_of_eachline);
         if((g=(oneline_arr)malloc(sizeof(oneline)))==NULL)printf("the space is full");
         else 
         {
            memset(g->context,'\0',sizeof(g->context));
            scanf("%s",g->context);
         }      
         printf("是否指定新增加内容的行号位置？y/n\n");
         printf("输入："); 
         while(1){memset(input,'\0',100);scanf("%s",input);if(input[1]!='\0')printf("错误输入,，请重新输入： ");else break;}
         if(input[0]=='y')
         {
            while(1)         
            {       
                    printf("请输入插入新内容的行号位置(此设置为可重复输入设置，输入#号退出):");
                    while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("错误输入,，请重新输入： ");else break;}
                    
                    if(num[0]=='#'){break;}
                    else 
                    {
                         w=atoi(num); 
                          p=h;
                                             for(i=1;i<w;i++)p=p->next;
                                             mid=p;
                                             for(i=1;i<sum_line-w;i++)//依次向后推// 
                                             {
                                                      mid->line++;
                                                      mid=mid->next;
                                             }
                                             g->line=w;
                                             p->last->next=g;
                                             g->last=p->last;
                                             p->last=g;
                                             g->next=p;
                                             sum_line++;
                        
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
       
}

void   dele()
{
         oneline_arr g;
         int  v,i;
        
         while(1)         
            {       
                    printf("你好，请输入欲删除内容的行号(此设置为可重复输入设置，输入#号退出):");
                    while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("错误输入,，请重新输入： ");else break;}
                    
                    if(num[0]=='#'){break;}
                    else 
                    {
                                 v=atoi(num);
                        
                                             p=h;
                                             for(i=1;i<v;i++)p=p->next;
                                             mid=p;
                                             for(i=0;i<sum_line-v;i++)//依次向前推// 
                                             {
                                                      mid->line--;
                                                      mid=mid->next;
                                             }
                                             p->last->next=p->next;
                                             p->next->last=p->last;
                                             free(p);
                                             sum_line--;
                        
                    }
            } 
         sum_page=sum_line/linenumber_of_eachpage;
         printf("删除指定内容结束，刷新请输入s：");
}

void    modify()
{
        int v,i;
        
        char mod[wordnumber_of_eachline];
        printf("请输入欲更新的新内容(不超过%d字数，并按回车键结束输入)：",wordnumber_of_eachline);
        scanf("%s",mod);
        while(1)
        {
                printf("请输入欲更新内容的行号(此设置为可重复输入设置，输入#号退出)：");
                while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("错误输入,，请重新输入： ");else break;}
                if(num[0]=='#')break;
                else 
                {
                     v=atoi(num);
                     p=h;
                     for(i=1;i<v;i++)
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
         int l1,l2,i,j,s,find=0;
         
         oneline_arr ss,ssh,sm;
         char sear[100];
         char an[100];
         char space[100];
         memset(space,'\0',100);
         space[0]='#';
         
         while(1)
         {
                 printf("请输入欲查找的内容(输入#号退出查找模式)：");        
                 memset(sear,'\0',100);
                 scanf("%s",sear);
                 l1=manage(sear);
                 find=0;
                 if(strcmp(sear,space)==0)break;
                 else
                 {
                     p=h;
                     
                     for(s=0;s<sum_line;s++)
                     {
                                            
                                            
                                            if(strstr(p->context,sear)!=NULL)
                                            {
                                                      l2=manage(p->context);
                                                     for(i=0;i<=l2-l1+1;i++)
                                                                       {
                                                                                       for(j=i;j<l1+i;j++)
                                                                                       an[j-i]=p->context[j];
                                                                                       if(strcmp(an,sear)==0)find++;
                                                                                        memset(an,'\0',100);
                                                                       }
                                            }
                                            p=p->next;
                     } 
                     printf("\tresult: %d\n",find);
                 }
         }
}

void    save(char*a)
{
        FILE*f;
        int i;
        
        printf("确定要储存之前的所有操作结果吗?(y/n):");
        while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("错误输入,，请重新输入： ");else break;}
        if(num[0]=='y')
        {
                    f=fopen(a,"w+");
                    p=h;
                    for(i=0;i<sum_line;i++)
                    {
                            fputs(p->context,f);
                            fputs("\r\n",f);
                            p=p->next;
                    }
                    fclose(f);
                    sig=1;            
        }               
        else printf("刷新请输入s：") ;
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
int manage(char* a)
{
    int i,sum=0;
    for(i=0;(a[i]!='\0')&&(i<wordnumber_of_eachline);i++)
    sum++;
    return sum;
}
