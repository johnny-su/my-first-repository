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
        if(botton[1]!='\0'){printf("�������룬���������룺");continue;}
        switch(botton[0])
   {
        case '<':
        {
                  if(cur_page==1){printf("���ǵ�һҳ");break;}
                  else 
                  {
                       cur_page--;
                       turnup(cur_page);
                       break;
                  }
        }
        case '>':
        {
                   if(cur_page==sum_page){printf("�������һҳ");break;}
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
            printf("��������,�����������룺 ");
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
                       printf("< >����ҳ\n");
                       printf("a : ������һ������\n"); 
                       printf("b : ɾ��ĳһ������\n");            
                       printf("c : ��������\n");   
                       printf("d : �޸�����\n");   
                       printf("x : ����\n");   
                       printf("s : ˢ��\n");   
                       printf("���룺");
                            
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
                       printf("< >����ҳ\n");
                       printf("a : ������һ������\n"); 
                       printf("b : ɾ��ĳһ������\n");            
                       printf("c : ��������\n");   
                       printf("d : �޸�����\n");   
                       printf("x : ����\n");   
                       printf("s : ˢ��\n");   
                       printf("���룺");
                            
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
    printf("< >����ҳ\n");
    printf("a : ������һ������\n"); 
    printf("b : ɾ��ĳһ������\n");            
    printf("c : ��������\n");   
    printf("d : �޸�����\n");   
    printf("x : ����\n");   
    printf("s : ˢ��\n");   
    printf("���룺");
        
}
void     add()
{
         oneline_arr g;
         int  i,w;
         
         printf("��ã������������ӵ�����(������%d�����������س�����������)��",wordnumber_of_eachline);
         if((g=(oneline_arr)malloc(sizeof(oneline)))==NULL)printf("the space is full");
         else 
         {
            memset(g->context,'\0',sizeof(g->context));
            scanf("%s",g->context);
         }      
         printf("�Ƿ�ָ�����������ݵ��к�λ�ã�y/n\n");
         printf("���룺"); 
         while(1){memset(input,'\0',100);scanf("%s",input);if(input[1]!='\0')printf("��������,�����������룺 ");else break;}
         if(input[0]=='y')
         {
            while(1)         
            {       
                    printf("��������������ݵ��к�λ��(������Ϊ���ظ��������ã�����#���˳�):");
                    while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("��������,�����������룺 ");else break;}
                    
                    if(num[0]=='#'){break;}
                    else 
                    {
                         w=atoi(num); 
                          p=h;
                                             for(i=1;i<w;i++)p=p->next;
                                             mid=p;
                                             for(i=1;i<sum_line-w;i++)//���������// 
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
         printf("���������ݽ�����ˢ��������s��");
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
              printf("���������ݽ�����ˢ��������s��");
         }
       
}

void   dele()
{
         oneline_arr g;
         int  v,i;
        
         while(1)         
            {       
                    printf("��ã���������ɾ�����ݵ��к�(������Ϊ���ظ��������ã�����#���˳�):");
                    while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("��������,�����������룺 ");else break;}
                    
                    if(num[0]=='#'){break;}
                    else 
                    {
                                 v=atoi(num);
                        
                                             p=h;
                                             for(i=1;i<v;i++)p=p->next;
                                             mid=p;
                                             for(i=0;i<sum_line-v;i++)//������ǰ��// 
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
         printf("ɾ��ָ�����ݽ�����ˢ��������s��");
}

void    modify()
{
        int v,i;
        
        char mod[wordnumber_of_eachline];
        printf("�����������µ�������(������%d�����������س�����������)��",wordnumber_of_eachline);
        scanf("%s",mod);
        while(1)
        {
                printf("���������������ݵ��к�(������Ϊ���ظ��������ã�����#���˳�)��");
                while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("��������,�����������룺 ");else break;}
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
        printf("����ָ�����ݽ�����ˢ��������s��");                                                 
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
                 printf("�����������ҵ�����(����#���˳�����ģʽ)��");        
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
        
        printf("ȷ��Ҫ����֮ǰ�����в��������?(y/n):");
        while(1){memset(num,'\0',100);scanf("%s",num);if(num[1]!='\0')printf("��������,�����������룺 ");else break;}
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
        else printf("ˢ��������s��") ;
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
   
    printf("< >����ҳ\n");
    printf("a : ������һ������\n"); 
    printf("b : ɾ��ĳһ������\n");            
    printf("c : ��������\n");   
    printf("d : �޸�����\n");   
    printf("x : ����\n");   
    printf("s : ˢ��\n");   
    printf("���룺");
}     
int manage(char* a)
{
    int i,sum=0;
    for(i=0;(a[i]!='\0')&&(i<wordnumber_of_eachline);i++)
    sum++;
    return sum;
}
