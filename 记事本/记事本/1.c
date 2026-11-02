#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void roll(int n,char a[1000][1000]) {
	int i;
	int c = 0;
	for (i = 0 ;i <= n;i++) {
		c++;
		printf("%d.%s\n",c, a[i]);
	}
}
int main(){
	int q,n=-1;
	int x,k;
	char a[1000][1000];
	while (1) {
		printf("------功能表------\n");
		printf("输入1记录信息\n");
		printf("输入2查询记事本\n");
		printf("输入3查看所有记事\n");
		printf("输入0关闭记事本\n");
		printf("输入4删除或插入文本\n");
		printf("------------------\n");
		scanf("%d", &q);
		if (q > 4|| q< 0) {
			printf("请按规定输入！\n");
			break;
		}
		int c = 0;
		if (q == 1) {
			char temp[1000];
			printf("请输入文本并在最后输入日期,输入end结束\n");
			while (1) {
				scanf("%s", temp);
				if (strcmp(temp, "end") == 0) {
					break;
				}
				n++;
				strcpy(a[n], temp);
			}
		}
		else if (q == 2) {
			if (n == -1) {
				printf("未添加任何记事\n");
			}
			else {
				printf("日期查询请按1\n");
				printf("关键词查询请按2\n");
				scanf("%d", &x);
				if (x == 1) {
					char w[1000];
					printf("请输入查询的日期\n");
					scanf("%s", w);
					int count;
					for (count = 0;count <= n;count++) {
						char* p = strstr(a[count], w);
						c++;
						if (p != NULL) {
							printf("查询到的记事本\n");
							printf("%d.%s", c, a[count]);
						}
					}
				}
				else if (x == 2) {
					printf("请输入查询关键词\n");
					char o;
					scanf(" %c", &o);
					for (int y = 0;y <= n;y++) {
						char* b = strchr(a[y], o);
						if (b != NULL) {
							printf("%s\n", a[y]);
						}
						else {
							printf("未查询到相关文本");
						}
					}
				}
			}
		}
		else if (q == 3) {
				roll(n, a);
				if (n == -1) {
					printf("无任何文本\n");
				}
		}
		else if (q == 4) {
			printf("删除请按1，插入请按2\n");
			int sp;
			scanf("%d", &sp);
			if (sp == 1) {
				roll(n, a);
				printf("请输入想要删除的文本\n");
				scanf("%d", &k);
				for (int i = k-1;i <= n;i++) {
					strcpy(a[i], a[i + 1]);
				}
				printf("删除成功!\n");
				n--;
			}
			else if (sp == 2) {
				char enter[1000];
				if (n < 999) {
					roll(n, a);
					printf("请输入要插入到几号文本\n");
					scanf("%d", &k);
					for (int i = n;i >= k-1;i--) {
						strcpy(a[i + 1], a[i]);
					}
					printf("请输入要插入的文本\n");
					scanf(" %s", enter);
					strcpy(a[k-1], enter);
					printf("添加成功!\n");
					n++;
				}
				else {
					printf("内存已满请删除部分文本\n");
				}
			}
		}
		else if (q == 0) {
			printf("已关闭记事本\n");
			break;
		}
	}
	return 0;
}