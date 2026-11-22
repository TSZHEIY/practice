#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    long isbn;
    float price;
    char name[20];
    char author[20];
}infor;
typedef struct lnode{
    infor book;
    struct lnode *next;
}lnode,*linklist;
linklist clearlist(linklist L){
    L=(linklist)malloc(sizeof(lnode));
    if(L==NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    L->next=NULL;
    return L;
}
void addbooks(linklist *tail){
    linklist p=(linklist)malloc(sizeof(lnode));
    p->book.isbn=0;
    p->book.price=0;
    printf("请输入书名\n");
    scanf("%s",p->book.name);
    printf("请输入isbn号\n");
    scanf(" %ld",&p->book.isbn);
    printf("请输入作者\n");
    scanf("%s",p->book.author);
    printf("请输入价格\n");
    scanf(" %f",&p->book.price);
    p->next=NULL;
    (*tail)->next=p;
    (*tail)=p;
    printf("添加成功\n");
}
void printbooklist(linklist L){
    int n=1;
    linklist p=L->next;
    if(p==NULL){
        printf("无图书\n");
        return;
    }
    while(p!=NULL){
         printf("%d.书名:%s 作者:%s isbn:%ld 价格:%.2f\n",n,p->book.name,p->book.author,p->book.isbn,p->book.price);
         p=p->next;
         n++;
    }
}
void deletebook(linklist L,linklist *tail){
    printf("请输入要删除的书本编号\n");
    printbooklist(L);
    int x,n=0;
    scanf("%d",&x);
    linklist p=L;
    while(n<x-1&&p!=NULL){
        p=p->next;
        n++;
    }
    if(p==NULL||p->next==NULL){
        printf("要删除的图书不存在\n");
        return;
    }
    linklist q=p->next;
    if(q==(*tail)){
        (*tail)=p;
    }
    p->next=q->next;
    free(q);
    printf("删除成功\n");
    printbooklist(L);
}
void insertbook(linklist L){
    printf("要在哪里插入?\n");
    linklist q=L;
    printbooklist(L);
    int x,n=0;
    scanf("%d",&x);
    while(n<x-1){
        q=q->next;
        n++;
    }
    linklist p=(linklist)malloc(sizeof(lnode));
    printf("请输入要插入的图书信息\n");
    printf("请输入书名\n");
    scanf("%s",p->book.name);
    printf("请输入isbn号\n");
    scanf("%ld",&p->book.isbn);
    printf("请输入作者\n");
    scanf("%s",p->book.author);
    printf("请输入价格\n");
    scanf("%f",&p->book.price);
    p->next=q->next;
    q->next=p;
    printf("插入完成\n");
    printbooklist(L);
}
void changeinformation(linklist L){
    printf("请输入要更改的书本编号\n");
    printbooklist(L);
    int x,n=0;
    scanf("%d",&x);
    linklist p=L->next;
    if(p==NULL){
        printf("无图书\n");
        return;
    }else if(p->next==NULL){
        printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",p->book.name,p->book.author,p->book.isbn,p->book.price);
    }else{
        while(x<n-1){
            p=p->next;
            n++;
        }
        printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",p->book.name,p->book.author,p->book.isbn,p->book.price);
    }
    printf("要更改什么?\n");
    char a[10];
    scanf("%s",a);
    printf("请输入要更改的信息\n");
    if(strcmp("书名",a)==0){
        scanf("%s",p->book.name);
    }else if(strcmp("作者",a)==0){
        scanf("%s",p->book.author);
    }else if(strcmp("isbn",a)==0){
        scanf("%ld",&p->book.isbn);
    }else if(strcmp("价格",a)==0){
        scanf("%f",&p->book.price);
    }else printf("输入错误\n");
    printf("更改成功\n");
    printbooklist(L);
}
void searchbook(linklist L){
    printf("按书名查找请按1,按isbn查找请按2,按作者查找请按3,书名关键字模糊查找请按4\n");
    int x;
    scanf("%d",&x);
    if(x==1){
        printf("请输入书名\n");
        char a[10];
        scanf("%s",a);
        while(L->next!=NULL){
            L=L->next;
            if(strcmp(a,L->book.name)==0){
                printf("查找到以下书籍\n");
                printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",L->book.name,L->book.author,L->book.isbn,L->book.price);
            }
        }
    }else if(x==2){
        printf("请输入isbn\n");
        long a;
        scanf("%d",&a);
        while(L->next!=NULL){
            L=L->next;
            if(a==L->book.isbn){
                printf("查找到以下书籍\n");
                printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",L->book.name,L->book.author,L->book.isbn,L->book.price);
            }
        }
    }else if(x==3){
        printf("请输入作者姓名\n");
        char a[20];
        scanf("%s",a);
        while(L->next!=NULL){
            L=L->next;
            if(strcmp(L->book.author,a)==0){
                printf("查找到以下书籍\n");
                printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",L->book.name,L->book.author,L->book.isbn,L->book.price);
            }
        }
    }else if(x==4){
        printf("请输入书名信息\n");
        char a[20];
        scanf("%s",a);
        while(L->next!=NULL){
            L=L->next;
            if(strstr(L->book.name,a)!=NULL){
                printf("查找到以下书本\n");
                printf("书名:%s 作者:%s isbn:%ld 价格:%.2f\n",L->book.name,L->book.author,L->book.isbn,L->book.price);
            }
        }
    }
}
int main(){
    linklist L;
    L=clearlist(L);
    linklist tail=L;
    int x;
    while(1){
        printf("------菜单栏------\n");
        printf("结束程序按0\n");
        printf("添加书本按1\n");
        printf("删除书本按2\n");
        printf("插入书本按3\n");
        printf("查看书架按4\n");
        printf("修改书本按5\n");
        printf("查找书本按6\n");
        printf("-----------------\n");
        scanf("%d",&x);
        if(x==0){
            break;
        }else if(x==1){
            addbooks(&tail);
        }else if(x==2){
            deletebook(L,&tail);
        }else if(x==4){
            printbooklist(L);
        }else if(x==5){
            changeinformation(L);
        }else if(x==3){
            insertbook(L);
        }else if(x==6){
            searchbook(L);
        }
    }
    return 0;
}