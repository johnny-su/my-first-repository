//我真诚地保证：  
 
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
 
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在作业报告中
 
// 详细地列举我所遇到的问题，以及别人给我的提示。
//我的程序里中凡是引用到其他程序或文档之处，
 
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
 
// 我都已经在程序的注释里很清楚地注明了引用的出处。
 


// 我从未抄袭过别人的程序，也没有盗用别人的程序，
 
// 不管是修改式的抄袭还是原封不动的抄袭。

//  苏晓强  2011202484 



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


oneline_arr p,h,mid;        
FILE* fp;
int   sum_line=0;
char  *g;
char  acmd[20]={"displ"};           //记录各种命令 
char  bcmd[20]={"addl"};
char  ccmd[20]={"dell"};
char  dcmd[20]={"adds"};
char  ecmd[20]={"dels"};
char  fcmd[20]={"find"};

void  addl();                     //与命令相对应的各种操作函数 
void  adds();
void  dele();
void  dels();
void  search();
void  modify();
void  show();
void  move(char*a,int n);        //adds操作的递归移行函数 
void  minus(int a,int b);
int   manage(char*a); 

int main(int argc,char**argv)
{
    
    char filename[]="G\:\\";
    char c;
    int j,i=0;
    int n=0;
    
    
    //**********open the file**********//
    strcat(filename,argv[1]);
    if((fp=fopen(filename,"r+"))==NULL)printf("can not open the file");
    
    
    
    //**********put the file context into different line*********//
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
                   if((p=(oneline_arr)malloc(sizeof(oneline)))==NULL)
                   {
                         printf("space is full\n");
                         break;
                   }
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
   
   p=h;
   for(i=0;i<sum_line;i++)
   {
                    if(p->context[0]=='\0')
                    {
                       p->last->next=p->next;
                       p->next->last=p->last;
                       p=p->next;
                       for(j=i;j<sum_line;j++)
                       {
                           p->line--;
                           p=p->next;
                           sum_line--;
                       }
                           p=p->next;
                    }
   } 
         
    
    //*********read the cmd*********//
    
    int N;
    char num_cmd[20];
    char rcmd[20];
    
   
    memset(rcmd,'\0',20);
    memset(num_cmd,'\0',20);
    
    fscanf(fp,"%s",num_cmd);
    N=atoi(num_cmd);
    
    
    
    //************carry out the cmd//
    for(i=0;i<N;i++)
    {
                    fscanf(fp,"%s",rcmd);
                    if(strcmp(rcmd,acmd)==0)show();
                    else if(strcmp(rcmd,bcmd)==0)addl();
                    else if(strcmp(rcmd,ccmd)==0)dele();
                    else if(strcmp(rcmd,dcmd)==0)adds();
                    else if(strcmp(rcmd,ecmd)==0)dels();
                    else search();
    }
    
 
    fclose(fp);
    p=h;
    for(i=sum_line;i>0;i--)
 {
                       free(p->next);
                        p=p->last;
                       
 }
 return 0;
}

void     addl()
{
         int n,i=0;                                          //读取参数// 
         char d;
         char c[8];
         memset(c,'\0',8);
         char read[wordnumber_of_eachline+1];
         memset(read,'\0',sizeof(read));
         oneline_arr z;
         
         fgetc(fp);
         fscanf(fp,"%s",c);
         n=atoi(c);
         fgetc(fp);
         while((d=fgetc(fp))!='\n'){read[i]=d;i++;}
                                                   
         p=h;
         for(i=0;i<n;i++)p=p->next;
         z=(oneline_arr)malloc(sizeof(oneline));              //插入 
         memset(z->context,'\0',sizeof(z->context));
         strcpy(z->context,read);
         z->line=n;
         p->last->next=z;
         z->last=p->last;
         p->last=z;
         z->next=p;
         for(i=n;i<=sum_line;i++){p->line++;p=p->next;}      //以后的依次次向后移动 
         
}

void   adds()
{
       int i,n,x;
       char a[8];
       
       char read[2*wordnumber_of_eachline+1];
       memset(read,'\0',sizeof(read));
       
       memset(a,'\0',8);
       fgetc(fp);                                          //读入参数// 
       fscanf(fp,"%s",a);
       n=atoi(a);
       
       fgetc(fp);
       memset(a,'\0',8);
       fscanf(fp,"%s",a);
       x=atoi(a);
       
       fgetc(fp);
       fgets(read,80,fp);
       read[manage(read)-1]='\0';
      
       
       p=h;
       for(i=0;i<n;i++)p=p->next;                        //指针移动到要插入的那行 
       
       move(read,x);
}

void   dele()
{
         int n,i=0;                                      //读取参数// 
         char d;
         char c[8];
         memset(c,'\0',8);
         
         
         fgetc(fp);
         fscanf(fp,"%s",c);
         n=atoi(c);
         
                                                          //读取参数结束// 
         p=h;
         for(i=0;i<n;i++)p=p->next;
         
         p->last->next=p->next;
         p->next->last=p->last;
         p=p->next;
         for(i=n;i<sum_line;i++){p->line--;p=p->next;}   //以后的依次次向前移动     
}
void   dels()
{
       int i,n,x,y,;
       char a[8];
       
       char read[2*wordnumber_of_eachline+1];
       memset(read,'\0',sizeof(read));
       
       memset(a,'\0',8);
       fgetc(fp);                      //读入参数// 
       fscanf(fp,"%s",a);
       n=atoi(a);
       
       fgetc(fp);
       memset(a,'\0',8);
       fscanf(fp,"%s",a);
       x=atoi(a);
       
       fgetc(fp);
       memset(a,'\0',8);
       fscanf(fp,"%s",a);
       y=atoi(a);
       
        p=h;
        for(i=0;i<n;i++)p=p->next;

        minus(x,y);
}

void     search()
{
         int i,j,t,s,l1,l2,find=0;
         char an[wordnumber_of_eachline];
         char t_save[2*wordnumber_of_eachline];       // save the join place data//
         char save[wordnumber_of_eachline];
         memset(save,'\0',sizeof(save));
         memset(t_save,'\0',sizeof(t_save));
         
         fgetc(fp);
         fgets(save,sizeof(save),fp);
         l1=manage(save);
         save[l1-1]='\0';
         l1=manage(save);
         
         p=h;
        
         for(s=0;s<=sum_line;s++)
         {
               l2=manage(p->context);
               memset(an,'\0',sizeof(an));
               if(strstr(p->context,save)!=NULL)
            {
               for(i=0;i<=l2-l1+1;i++)
               {
                   for(j=i;j<l1+i;j++)
                   an[j-i]=p->context[j];
                   if(strcmp(an,save)==0)find++;
               }
            } 
               p=p->next;
                                
         }
        
         printf("%d\n",find);
}

void  show()
{
    int i;
    char r;
    char a[20];
    memset(a,'\0',sizeof(a));
    int n,x,y;
    p=h;
    fgetc(fp);
    fscanf(fp,"%s",a);
    n=atoi(a);
    if((r=fgetc(fp))!='\n')
    {
                      memset(a,'\0',sizeof(a));
                      fscanf(fp,"%s",a);
                      x=atoi(a);
                      
                      memset(a,'\0',sizeof(a));
                      r=fgetc(fp);
                      fscanf(fp,"%s",a);
                      y=atoi(a);
                      memset(a,'\0',sizeof(a));
                      
                      for(i=0;i<n;i++)
                      p=p->next;
                      for(i=x;i<y;i++)
                      printf("%c",p->context[i]);
                      printf("\n");
    }     
    
    else
    {
                      for(i=0;i<n;i++)
                      p=p->next;
                      if(p->context[wordnumber_of_eachline-1]!='\0')printf("%s",p->context);
                      else printf("%s\n",p->context);
      
    }
                          
}
int manage(char* a)
{
    int i,sum=0;
    for(i=0;(a[i]!='\0')&&(i<wordnumber_of_eachline);i++)
    sum++;
    return sum;
}

void move(char *a,int n)
{
     int o1,o2,s,j,i;
     
     o1=manage(a);
     o2=manage(p->context);
     
     if((o1+o2)>wordnumber_of_eachline)
     {
            
            for(j=o1,i=n;i<o2;j++,i++)
            a[j]=p->context[i];
            for(i=n;i<wordnumber_of_eachline;i++)
            p->context[i]=a[i-n];
            
            s=wordnumber_of_eachline-n;
            for(i=0;i<s;i++)
            a[i]=a[i+s];
            for(i=s;i<manage(a);i++)
            a[i]='\0';
            p=p->next;
            //printf("\n%s\n",a);
            move(a,0);
     }                           
     
     else 
     {
          for(i=wordnumber_of_eachline-1;i>=n+o1;i--)
          p->context[i]=p->context[i-o1];
          for(i=n;i<n+o1;i++)
          p->context[i]=a[i-n];
         
     }
     
}
 
void   minus(int a,int b)
{
     int i,j,t,l;      
     l=manage(p->context);
     for(i=a;i<l-(b-a);i++)
     p->context[i]=p->context[i+b-a];
   
}
 
