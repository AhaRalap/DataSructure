typedef struct
{
    datatype data[MAXSIZE];
    int len;
}SeqList;

SeqList *Init_SeqList()
{
    SeqList *L;
    L=(SeqList*)malloc(sizeof(SeqList));
    L->len = 0;
    return L;
}

void CreatList(SeqList **L)
{
    int i,n;
    printf("Input length of List:");
    scanf("%d",&n);
    printf("Input elements of List:\n");
    for(i = 1;i <= n;i++)
        scanf("%d",&(*L)->data[i]);
    (*L)->len = n;
}

void Insert_seqList(SeqList *L,int i,datatype x)
{
    int j;
    if(L->len == MAXSIZE-1)
        printf("The List is full!\n");
    else
        if(i < 1 || i > L->len + 1)
            printf("The position is invalid\n\n");
        else
        {
            for(j = L->len;j >= i;j--)
                L->data[j+1] = L->data[j];
            L->data[i] = x;
            L->len++;
        }
}

void Delete_SeqList(SeqList *L,datatype i)
{
    int j;
    if(L->len == 0)
        printf("The list is empt!\n");
    else
        if(i < 1 || i > L->len)
            printf("The posttion is invalid!\n");
        else
           {
            for(j = i+1;j <= L->len;j++)
                L->data[j-1] = L->data[j];
            L->Len--;
           }
}

int Location_SeqList(SeqList *L,datatype x)
{
    int i = 1;
    while(i < L-len && L->data[i]!=x)
        i++
    if(L->data[i] == x)
        return i;
    else
        return 0;
}

int Location_SeqList1(SeqList *L,datatype x)
{
    i = L->len;
    L->data[0] =x;
    while(L->data[i] != x)
        i--;
    return i;
}
