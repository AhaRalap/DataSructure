void CreatelLinkList(LNode **head)
{ //将主调函数中指向待生成单链表的指针地址(如&p)传给**head
    char x;
    LNode *p;
    *head = (LNode *)malloc(sizeof(LNode));
    (*head)->next = NULL;
    printf("Input any char string :\n");
    scanf("%c",&x);
    while(x != '\n')
    {
        p=(LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = (*head)->next;
        (*head)->next = p;
        scanf("%c",&x);
    }
}

LNode *CreateLinkList()
{
    LNode *head,*p;
    char x;
    head = (LNode *)malloc(sizeof(LNode);
    head->next = NULL;
    printf("Input any char string: \n");
    scanf("%c",&x);
    while(x != '\n')
    {
        p =(LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = head->next;
        head->next = p;
        scanf("%c",&x);
    }
    return head;
}

LNode *CreateLinkList()
{
    LNode *head,*p,*q;
    char x;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    p = head;
    q = p;
    printf("Input any char string:\n");
    scanf("%c",&x);
    while(x != '\n')
    {
        p =(LNode *)malloc(sizeof(LNode));
        p->data = x;
        p-next = NULL;
        q = p;
        scanf("%c",&x);
    }
    return head;
}

int Length_LinkList(LNode *head)
{
    LNode *p = head;
    int i = 0;
    while(p->next != NULL)
    {
        p = p->next;
        i++
    }
    return i;
}

LNode *Get_LinkList(LNode *head,int i)
{
    LNode *p = head;
    int j = 0;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *Locate_LinkList(LNode *head,char x)
{
    LNode *p = head->next;
    while(p != NULL && p->data != x)
        p = p->next;
    return p;
}

void Inset_LinkList(LNode *head,int i,batatype x)
{
    LNode *p,*q;
    p = Get_LinkList(head,i-1);
    if(p == NULL)
        printf("Error!\n");
    else
    {
        q=(LNode *)malloc(sizeof(LNode));
        q->data = x;
        q->next = p->next;
        p->next = q;
    } 
}

void Del_LinkList(LNode *head,int i)
{
    LNode *p,*q;
    p = Get_LinkList(head,i-1);
    if(p== NULL)
        printf("第i-1个结点不存在\n"); 
    else
        if(p->next == NULL)
            printf("第i个结点不存在");
        else
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
}

DLNode *CreateDlinkList()
{
    DLNode *head,*s;
    char x;
    head = (DLNode *)malloc(sizeof(DLNode));
    head->prior = head;
    head->next = head;
    printf("Input any char string: \n");
    scanf("%c",&x);
    while(x != '\n')
    {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = x;
        s->prior = head;
        s->next = head->next;
        head->next->prior = s;
        head->next = s;
        scanf("%c",&x);
    }
    return head;
}

void InsertList(SNode L[],int i,datatype x)  //静态链表（数组模拟）
{
    int j,j1,j2,k;
    j = L[0].curor;
    if(i == 1)
    {
        if(j == 0)
        {
            L[1].data = x;
            L[0].cursor = 1;
            L[1].cursor = 0;
        }
        else
        {
            k = j+1;
            while(k != j)
                if(L[k].cursor == -1)
                    break;
                else
                    k = (k+1)%MAXSIZE;
            if(k != j)
            {
                L[k].data = x;
                L[k].cursor = L[0].cursor;
                L[0].cursor = k;
            }
            else
                printf("List overflow!\n");
        }
    }
    else
    {
        k = 0;
        while(k < i-2&&j != 0)
        {
            k++;
            j = L[j].cursor;
        }
        if(j == 0)
            printf("Insert error\n");
        else
        {
            j1 = j;
            j2 = L[j].cursor;
            k = j + 1;
            while(K != j)
                if(L[k].cursor == -1)
                    break;
                else
                    k = (k+1)%MAXSIZE;
            if(K != j)
            {
                L[k].data = x;
                L[j1].cursor = k;
                L[k].cursor = j2;
            }
            else
                printf("List overflow\n");
        }
    }
}

void Convert(LNode *H)  //逆置单链表
{
    LNode *p,*q;
    p = H->next;
    H->next = NULL;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
}

void Merge(LNode *A,LNode *B,LNode **C) //将增序链表A，B合并成降序链表*c
{
    LNode *p,*q,*s;
    p = A->next;
    q = B->next;
    *C = A;
    (*C)->next = NULL;
    free(B);
    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            s = p;
            p = p->next;
        }
        else
        {
            s = q;
            q = q->next;
        }
        s->next = (*C)->next;
        (*C)->next = s;
    }
    if(p == NULL)
        p = q;
    while(p != NULL)
    {
        s = p;
        p = p->next;
        s->next = (*C)->next;
        (*C)->next = s;
    }
    
}

void Josephus(int n,int m,int k) //约翰夫问题：设有N个人围成一圈并顺序编号为1～N。由编号为K的人进行1到M的报数，数到M的的人出圈。循环直到所有人出去
{
    LNode *p,*q;
    int i;
    p=(LNode*)malloc(sizeof(LNode));
    q=p;
    for(i=1;i<n;i++)  //从编号K开始建立一个单链表
    {
        q->data=k;
        K=k%n+1;
        q->next=(LNode*)malloc(sizeof(LNode));
        q=q->next;
    }
    q->data=k;
    q->next=p;
    while(p->next!=p)
    {
        for(i=1;i<m;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        printf("%4d",p->data);
        free(p);
        p=q->next;
    }
    printf("%4d",p->data);
}
