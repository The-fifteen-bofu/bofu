#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void Cc(char File[])  //�ַ�������
 {
         int count=0;            
         char mychar=' ';
         FILE *f=fopen(File,"r");
         if(f==NULL){
                 printf("�ļ�������\n");
                 return ;
         }
         while((mychar=fgetc(f))!=EOF)
         {
                 if(isspace(mychar)==0)
                 count++;
         }
         fclose(f);
         printf("���ļ����ַ���Ϊ%d\n",count);
 }
 
 void Cw(char File[]){
   FILE *pf=NULL;
    int wcount=0;
    pf=fopen(File,"r");
    if(pf==NULL){
        printf("Ѱ���ļ�ʧ��\n");
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
        printf("�ļ��ĵ�����Ϊ%d\n",wcount);
}
void Cl(char File[]) //��ѯ�ļ�����
{
  FILE *fp;
  int row = 0, count = 0;
  char buffer[150];
  if((fp = fopen(File, "r")) == NULL)
   {printf("��ѯ�ļ�������\n");
    return ;
  }
  while(fgets(buffer,150,fp)!=NULL)
  {
      count++;
  }
  row = count;
  printf("�ļ�������Ϊ%d\n", row);
  fclose(fp);
  return ;
}
 
int main(int argc, char *argv[])//������
{
    if(argc<2)
    {
        printf("���������");
        return 0;
    }//�û��޲�������
 
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
  else{printf("������������");
  }
    return 0;    
    }
