#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>


int main(int argc,char**argv)
{
    FILE* fp;
    if(argc!=1)printf("parameters wrong");
    else if(fp=fopen(argv[0],"r")==NULL)printf("wrong file name,can not open the file");
    else;
    
    //将数据文件处理成每行固定字数的新文件// 
    FILE*f;
    f=fopen("E:\new.txt","w");
    while(!feof(fp))
    for(i=0;i<250;i++)
    {
                               
                               c=fgetc(fp);
                               fputc(f,c);
                               if(c=='\n'){jud=1;break;}
                               else jud=0;
    }
    if(!jud)
    n//the number of line
    
    //对新文件进行处理//
     
    int lnumb=20;
    FILE* arr;
    (FILE*)realloc(sizeof(arr)*n);
    
    //lock the line number //
    arr[0]=f;
    for(i=1;i<n;i++)
    {
                    for(m=0;c!='\n';m++)
                    c=fgetc(f);
    fseek(arr[i],m,a[i-1]);
    m=0;
    }
    
    
    //output//
    for(i=0;i<lnumb;i++)
    {
                        fgets(arr[i],260,save);
                        printf("%s",save);       
                        for(i=1;i<=lnumb;i++)
    }
    
    
    //翻页设置 
    printf("<:pageup  >:pagedown\n");
    fscanf("%c",&p);
    if(c=='<')
    for()
    
    else if(c=='>')
    for()
    else {printf("wrong input");break;}
    
    fprintf("%d %s",i,save);
           
           
           
           
           
           
           
           
           
           
           
           
           
           
           
