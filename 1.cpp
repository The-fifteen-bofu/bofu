#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void Cc(char File[])  //字符数计算
 {
         int count=0;            
         char mychar=' ';
         FILE *f=fopen(File,"r");
         if(f==NULL){
                 printf("文件不存在\n");
                 return ;
         }
         while((mychar=fgetc(f))!=EOF)
         {
                 if(isspace(mychar)==0)
                 count++;
         }
         fclose(f);
         printf("该文件的字符数为%d\n",count);
 }
 
 void Cw(char File[]){
   FILE *pf=NULL;
    int wcount=0;
    pf=fopen(File,"r");
    if(pf==NULL){
        printf("寻找文件失败\n");
        exit(-1);
    }
      char mychar;
    mychar = fgetc(pf);
    while(mychar!=EOF){
        if(mychar>='a'&&mychar<='z'||mychar>='A'&&mychar<='Z'||mychar>='0'&&mychar<='9'){
            while(mychar>='a'&&mychar<='z'||mychar>='A'&&mychar<='Z'||mychar>='0'&&mychar<='9'||mychar=='_'){
                mychar=fgetc(pf);
            }
            wcount++;
            mychar=fgetc(pf);
        }
        mychar=fgetc(pf);
    }
        fclose(pf);
        printf("文件的单词数为%d\n",wcount);
}
void Cl(char File[]) //查询文件行数
{
  FILE *fp;
  int row = 0, count = 0;
  char buffer[150];
  if((fp = fopen(File, "r")) == NULL)
   {printf("查询文件不存在\n");
    return ;
  }
  while(fgets(buffer,150,fp)!=NULL)
  {
      count++;
  }
  row = count;
  printf("文件的行数为%d\n", row);
  fclose(fp);
  return ;
}
 
int main(int argc, char *argv[])//主函数
{
    if(argc<2)
    {
        printf("请输入参数");
        return 0;
    }//用户无参数输入
 
    else if(strcmp(argv[1],"-c")==0)
   {
    Cc(argv[2]);
  }
     else if(strcmp(argv[1],"-w")==0)
   {
    Cw(argv[2]);
  }
     else if(strcmp(argv[1],"-l")==0)
   {
    Cl(argv[2]);
  }
  else{printf("参数输入有误");
  }
    return 0;    
    }
