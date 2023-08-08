#ifndef __ACG		
#define __ACG
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "file.h"
// 定义一个宏，用来生成颜色代码
#define COLOR(c) "\033[" #c "m"
// 定义一个宏，用来重置颜色
#define RESET "\033[0m"
typedef enum {
	RED = 31, // 红色
	GREEN = 32, // 绿色
	YELLOW = 33, // 黄色
	BLUE = 34, // 蓝色
	PURPLE = 35, // 紫色
	CYAN = 36, // 青色
	WHITE = 37 // 白色
}Color;

void Infor_find(void);
void Infor_CreateLinkHead(void);
void System_Menu(void);
void Infor_AddPerson(void);
void Infor_changePerson(void);
int quitt();
void Infor_delete(void);
void print_text(char *text);
// 定义一个枚举类型，用来表示不同的颜色
//增删改查
typedef struct {
	char name[20];
	char sex[4];
	int age;
}_Base;
typedef struct {
	float marxist;
	float maogai;
}_StuOther;
typedef struct {
	char title[16];
	float salary;
}_TeaOther;
typedef union {   //定义一个公用体,相比于结构体共用体的空间没有浪费
	_StuOther Student;
	_TeaOther Teacher;
}_InforOther;
typedef struct {
	char StudentID[20];
	char TeacherID[12];
}_ID;
typedef struct {
	_ID id;
	_InforOther other;
}_School;
typedef struct {
	int flag;
	_Base base;
	_School school;
}_StrInformation;
typedef struct point {
	_StrInformation data;
	struct point *pNext;
}_LinkPoint;
typedef enum {
	none = 0,
    add,delete,change,find,quit
}_Choose;
extern _LinkPoint *LinkHead;

#endif
