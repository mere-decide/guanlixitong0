#include "2.h"
_LinkPoint *LinkHead = NULL;

void Infor_CreateLinkHead(void) {
	LinkHead = (_LinkPoint*)malloc(sizeof(_LinkPoint));
	memset(LinkHead, 0, sizeof(_LinkPoint));
	LinkHead->pNext = NULL;
}
char* BufPerson[2] = { "职工","学生" };
void Infor_delete() {
_LinkPoint* p = LinkHead; //让p=头  第一行定义了一个指针变量p，并把它初始化为LinkHead，这是一个指向链表头节点的指针,是后置节点
	_LinkPoint *pre = NULL;   //中间变量 第二行定义了一个指针变量pre，并把它初始化为NULL，这是一个用来记录前驱节点的指针。
	char named[20];           //第三行定义了一个字符数组named，用来存储要删除的名字。
	printf("请输入需要删除的名字：\n");  //第四行打印出一句提示，让用户输入要删除的名字。
	scanf("%s", named);
	printf("要删除的名字为：%s\n", named); //第六行打印出一句确认，显示要删除的名字是什么。
	while (p->pNext != NULL) {     //表示是不是到了尾部  第七行开始一个循环，用来遍历链表，寻找要删除的节点。
		pre = p;                   //第八行把前驱指针（指向当前节点的上一个节点）pre赋值为 后继指针p ，
		                           //这样就把前驱节点更新为当前节点。
		p = LinkHead->pNext;       //把p赋值为LinkHead->pNext，这样就把当前节点更新为下一个节点。
		if (strcmp(p->data.base.name, named) == 0) {
			_LinkPoint* delete = p;  //定义了一个指针变量delete，并把它赋值为p，这样就把要删除的节点保存在了delete中。
			pre->pNext = delete->pNext;  //把前驱节点的后继指针赋值为要删除节点的后继指针，这样就把要删除节点从链表中断开了。
			free(delete);
			printf("^_^-删除成功^_^ -\n");
		}

	}
}
/*
\033[32m 绿色\033[30m：黑色
\033[31m：红色
\033[32m：绿色
\033[33m：黄色
\033[34m：蓝色
\033[35m：洋红色    printf("\033[30m黑色文本\033[0m\n");
\033[36m：青色 \033[5m：闪烁
\033[37m：白色  */ 


void System_Menu(void)
{

	print_text(COLOR(33) "\033[1m ♥ ♥ ♥ ♥ ♥ ♥   欢迎来到教务管理系统  ♥ ♥ ♥ ♥ ♥ ♥ \033[0m"); // 打印欢迎语，使用粗体字

	print_text(COLOR(32) "♥  输入1表示要添加数据 ♥ "); // 打印选项1

	print_text(COLOR(34) " ♥  输入2表示要删除数据  ♥ "); // 打印选项2

	print_text(COLOR(35) " ♥  输入3表示要改变数据  ♥ "); // 打印选项3

	print_text(COLOR(36) " ♥  输入4表示要查找数据  ♥ "); // 打印选项4

	print_text(COLOR(37) " ♥ 输入5表示要退出系统 ♥ "); // 打印选项5

	print_text(COLOR(33) "  ♥  请输入你的选择 ♥ ："); // 打印输入提示

}

void Infor_AddPerson()
{
	_LinkPoint* LinkTemp = LinkHead;
	_LinkPoint* LinkNew = NULL;
	LinkNew = (_LinkPoint*)malloc(sizeof(_LinkPoint));
	memset(LinkNew, 0, sizeof(_LinkPoint));
//memset是C语言中的一个函数，用来将一段内存空间的值都设置为给定的值。
//void* memset(void* ptr, int value, size_t num);
//其中，ptr是指向要设置的内存空间的指针，value是要设置的值，num是要设置的内存空间的大小。例如：
	LinkNew->pNext = NULL;
	int Count = 0;
	while (LinkTemp->pNext != NULL)
		LinkTemp = LinkTemp->pNext;
	LinkTemp->pNext = LinkNew;
pp_person:;
	printf("\033[33m");
	printf("请输入添加人员身份(1:职工 2:学生)：");
	Count = scanf("%d", &LinkNew->data.flag);
	if ((Count == 0) || ((LinkNew->data.flag != 1) && (LinkNew->data.flag != 2)))
	{
		getchar();
		printf("格式错误,");
goto pp_person;
	}
	printf("\033[31m");
	printf("请输入%s姓名：", BufPerson[LinkNew->data.flag - 1]);
	scanf("%s", LinkNew->data.base.name);
	printf("\033[33m");
	printf("请输入%s年龄：", BufPerson[LinkNew->data.flag - 1]);
	scanf("%d", &LinkNew->data.base.age);
	printf("\033[34m");
	printf("请输入%s性别：", BufPerson[LinkNew->data.flag - 1]);
	scanf("%s", LinkNew->data.base.sex);
	printf("\033[31m");
	printf("请输入%s身份证号：\n", BufPerson[LinkNew->data.flag - 1]);
	scanf("%s", LinkNew->data.school.id.StudentID);
	printf("\033[35m");
	system("clear");
	print_text(COLOR(36) "\033[1m           ♥ 返回到系统菜单 ♥ \n \033[0m"); 
}
/*void Infor_find() 
{
	_LinkPoint* LinkTemp = LinkHead;
	char str[64] = "\0 ";
	printf("身份\t姓名\t性别\t学号\n");
	while (LinkTemp->pNext != NULL)
	{
		LinkTemp = LinkTemp->pNext;
		if (LinkTemp->data.flag != 0)
		printf("%s\t", BufPerson[LinkTemp->data.flag - 1]);
		printf("%s\t", LinkTemp->data.base.name);
		printf("%s\t", LinkTemp->data.base.sex);
		printf("%s\n", LinkTemp->data.school.id.StudentID);
	}
}*/
int quitt()
{
    char str[20] = "";
    printf("输入quit退出此界面或者输入remake回到菜单！！！\n");
    do
    {
        scanf("%s", str);
        if (strcmp(str, "remake") == 0)
        {
            printf("返回主界面\n");
            return 1;
        }
    } while (strcmp(str, "quit") != 0);

    return 0;
}

void Infor_find() {
	_LinkPoint* p = LinkHead;
	_LinkPoint* pre = NULL;
	char named[20];
	printf("请输入需要查找的名字:");
	scanf("%s", named);
	printf("要查找的名字为:%s\n", named);
	while (p->pNext != NULL) {        //表示是不是到了尾部  第七行开始一个循环，用来遍历链表，寻找要删除的节点。
		pre = p;                       //第八行把前驱指针（指向当前节点的上一个节点）pre赋值为 后继指针p ，
		//这样就把前驱节点更新为当前节点。
		p = LinkHead->pNext;          //把p赋值为LinkHead->pNext，这样就把当前节点更新为下一个节点。
		if (strcmp(p->data.base.name, named) == 0) {
			if (p->data.flag == 1)
				printf("%s是职工\t年龄:%d\t性别:%s\t身份证号:%s\n", p->data.base.name, p->data.base.age, p->data.base.sex,p->data.school.id.StudentID);
			else if (p->data.flag == 2)
				printf("%s是学生\t年龄:%d\t性别:%s\t身份证号:%s\n", p->data.base.name, p->data.base.age, p->data.base.sex,p->data.school.id.StudentID);
		}

	}
}
     void  Infor_changePerson() {
		 _LinkPoint *p = LinkHead;
		 _LinkPoint *prt = NULL;
		 printf("请输入需要更改的名字");
		 char name[20] = { 0 }; 
		 scanf("%s", name);
		 while(p->pNext != NULL){
			 prt = p ;
		      p = p->pNext;
			  if (strcmp(name, p->data.base.name) == 0)
			  {
				  _LinkPoint * delete = p;
				  prt->pNext = p->pNext;
				  free(p);
				  printf("接下来请输入要添加的名字");
				  Infor_AddPerson();
		 }
		 }
	
} 
// 定义一个函数，用来打印一行文字
void print_text(char* text) {
	int len = strlen(text); // 计算文字的长度
	int space = (66 - len) / 2; // 计算居中对齐所需的空格数
	for (int i = 0; i < space; i++) {
		printf(" "); // 打印左边的空格
	}
	printf("%s", text); // 打印文字
	for (int i = 0; i < space; i++) {
		printf(" "); // 打印右边的空格
	}
	printf("\n");
}
