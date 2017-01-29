#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define wordnumber_of_eachline 120
#define linenumber_of_eachpage 20 
FILE* turnup(int a,FILE* f)
{
    fseek(f,a*wordnumber_of_eachline*linenumber_of_eachpage,0);
    return f;
}

int main(int argc,char**argv)
{
    FILE* fp;
    char filename[]="G\:\\";
    char c;
    char save[1000];
    //memset(save,'\0',1000);
    int j,i=0;
    int n=0;
    int ln;
    int page,fline,lline;
    //open the file
    strcat(filename,argv[1]);
    if((fp=fopen(filename,"r+"))==NULL)printf("can not open the file");
    
    //show the first page//
    page=1;
    fline=1;
    lline=20;
    printf("page:%d line:%dto%d\n",page,fline,lline);
    
    for(i=0;i<linenumber_of_eachpage;i++)
           if(!feof(fp))        
                    {
                          printf("%d ",i+1);
                          for(j=0;j<wordnumber_of_eachline;j++)
                          {
                                     if((c=fgetc(fp))=='\n')
                                     {
                                                      j--;
                                                      c=fgetc(fp);
                                                      printf("%c",c);
                                     }
                                     else printf("%c",c);
                          }     
                          printf("\n");
                    }
                 

            
  printf("<:翻到上页 >：翻到下页");
 
 
 char botton;
while(1)
 {
        scanf("%c",&c);
 
        if(c=='<')
                  {page--;
                  if(page==0){printf("已是第一页");}continue;}
                  else 
                  {
                       fline=fline-linenumber_of_eachpage;
                       lline=lline-linenumber_of_eachpage;
                       turnup(page,fp);
                       for(i=0;i<linenumber_of_eachpage;i++)
                            {for(j=0;j<wordnumber_of_eachline;j++)
                               printf("%c",fgetc(fp));
                               printf("\n");
                            }
                  }
        //else if(c==">");
        //else printf("wrong enter");
                 }
 

return 0;
}




