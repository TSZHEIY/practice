#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
typedef struct a {
	char name[10];
	int age;
	char number[20];
}write;
void charu(write a[1000], int k) {//插入函数
	printf("姓名:\n");
	scanf("%s", a[k-1].name);
	printf("年龄\n");
	scanf("%d", &a[k-1].age);
	printf("学号\n");
	scanf("%s", a[k-1].number);
}
void shuru(write a[1000],int n) {//录入函数
	for (int i = 0;i < n;i++) {
		printf("请输入第%d个学生的信息\n", i+1);
		printf("姓名:\n");
		scanf("%s", a[i].name);
		printf("年龄\n");
		scanf("%d", &a[i].age);
		printf("学号\n");
		scanf("%s", a[i].number);
	}
}
void print(write a[1000], int n) {//打印学生表
	for (int i = 0;i < n;i++) {
		int c = 0;
		c = i + 1;
		printf("-----------学生表-----------\n");
		printf("%d.姓名:%s 年龄:%d 学号:%s\n", c, a[i].name, a[i].age, a[i].number);
		printf("----------------------------\n");
	}
}
int main() {
	int q, n;
	int number=0;
	write a[1000];
	while (1) {
		printf("---------功能表---------\n");
		printf("关闭请按0\n");
		printf("录入学生按1\n");
		printf("查看学生信息表按2\n");
		printf("删除或插入学生信息按3\n");
		printf("更改学生信息请按4\n");
		printf("------------------------\n");
		scanf("%d", &q);
		if (q == 1) {//录入
			if (number < 999) {
				printf("请输入录入学生人数\n");
				scanf("%d", &n);
				number += n;
				shuru(a, n);
				printf("录入成功！\n");
				print(a, number);
			}
		}
		else if (q == 2) {//打印学生表
			if (number != 0) {
				print(a, number);
			}
			else {
				printf("未添加任何学生信息\n");
				printf("----------------------------\n");
			}
		}
		else if (q == 3) {//插入删除学生信息
			printf("插入信息请按1,删除信息请按2\n");
			int f,c;
			scanf("%d",&f);
			if (f == 1) {
				if (number != 0) {
					printf("请输入要插入到的序号\n");
					scanf("%d", &c);
					printf("请输入插入信息\n");
					for (int i = number-1;i >= c-1;i--) {
						strcpy(a[i + 1].name, a[i].name);
						a[i + 1].age = a[i].age;
						strcpy(a[i + 1].number, a[i].number);
					}
					number++;
					charu(a, c);
					printf("插入成功!\n");
					printf("----------------------------\n");
					print(a, number);
				}
				else {
					printf("未添加任何学生信息\n");
				}
			}
			else if (f == 2) {
				if(number!=0){
					print(a, number);
					printf("请输入要删除的学生序号\n");
					scanf("%d", &c);
					for (int i = c-1;i <= number;i++) {
						strcpy(a[i].name, a[i + 1].name);
						a[i].age = a[i + 1].age;
						strcpy(a[i].number, a[i + 1].number);
					}
					number--;
					printf("删除成功!\n");
					printf("----------------------------\n");
					print(a, number);
				}
				else {
					printf("没有添加任何学生信息\n");
					printf("----------------------------\n");
				}
			}
		}
		else if (q == 4) {//更改学生信息
			if (number != 0) {
				print(a, number);
				printf("请输入要更改的学生序号\n");
				int f;
				char o[10], x[10];
				scanf("%d", &f);
				printf("请输入更改项目\n");
				scanf("%s", o);
				printf("请输入更改的内容\n");
				scanf("%s", x);
				if (strcmp(o, "姓名") == 0) {
					strcpy(a[f - 1].name, x);
				}
				else if (strcmp(o, "年龄") == 0) {
					strcpy(a[f - 1].age, x);
				}
				else if (strcmp(o, "学号") == 0) {
					strcpy(a[f - 1].number, x);
				}
				printf("更改成功！\n");
				printf("----------------------------\n");
				print(a, number);
			}
			else {
				printf("未添加任何学生信息\n");
				printf("----------------------------\n");
			}
		}
		else if (q == 0) {//关闭程序
			printf("程序已关闭");
			printf("----------------------------\n");
			break;
		}
	}
	return 0;
}