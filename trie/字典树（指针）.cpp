#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Tree
{
    Tree *next[2];
    int v, mk;
}Tree;

Tree root;

void Buid_Tree(char *str)
{
    int len = strlen(str);
    Tree *p = &root, *q;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (p->next[id] == NULL)
        {
            q = (Tree *)malloc(sizeof(root));
            q->v = 1;
            q->mk = 0;
            for (int j = 0; j < 2; j++)q->next[j] = NULL;
            p->next[id] = q;
            p = p->next[id];
        }
        else
        {
            p = p->next[id];
            p->v++;
        }
    }
    p->mk = 1;
}

int Find(char *str)
{
    int len = strlen(str);
    Tree *p = &root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        p = p->next[id];
        if (p == NULL) return 0;
        if (p->mk == 1) return 2;
    }
}


int main()
{
    char str[10000];
    int cas = 1;
    while (~scanf("%s", str))
    {
        if (!strcmp(str, "9"))
        {
            printf("Set %d is immediately decodable\n", cas++);
            continue;
        }
        root.next[0] = root.next[1] = NULL;
        Buid_Tree(str);
        int mk = 0;
        while (scanf("%s", str) && strcmp(str, "9"))
        {
            mk=Find(str);
            Buid_Tree(str);
        }
        if (!mk) printf("Set %d is immediately decodable\n", cas++);
        else printf("Set %d is not immediately decodable\n", cas++);
    }
    return 0;
}



