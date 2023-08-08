#include "file.h"
void File_WriteLink(void)
{
           _LinkPoint * LinkTemp = LinkHead;
           FILE *fp = NULL;
           char buf[64] =  "\0";
           fp = fopen ( "test.txt" ,"w+");//如果没有文件就创建，如果有文件就打开然后关闭
           while (LinkTemp->pNext != NULL)
	{
		   LinkTemp = LinkTemp->pNext;
           fwrite(LinkTemp,sizeof(_LinkPoint),1,fp);
    }
           fclose(fp);
}
void File_ReadLink(void)
{
          _LinkPoint *LinkTemp = LinkHead;
          _LinkPoint *LinkNew = NULL;
          FILE *fp = NULL;
          fp = fopen ( "test.txt" ,"a");//如果没有文件就创建，如果有文件就打开然后关闭
          fclose(fp);
          fp = fopen ( "test.txt" ,"r+");
          fgetc(fp);

          while(feof(fp) == 0 )
{
         fseek (fp,-1,SEEK_CUR);
         _LinkPoint* LinkNew = NULL;
	     LinkNew = (_LinkPoint*)malloc(sizeof(_LinkPoint));
	     memset(LinkNew, 0, sizeof(_LinkPoint));
	     LinkNew->pNext = NULL;
         fread(LinkNew,sizeof(_LinkPoint),1,fp);
         LinkTemp->pNext = LinkNew;
         LinkTemp = LinkTemp -> pNext;
         fgetc(fp);
          }
	fclose(fp);

}
