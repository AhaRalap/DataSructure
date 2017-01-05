typedef struct
{
    datatype data[MAXSIZE];
    int top;
}SeqStack;

void Init_SeqStack(SeqStack **s)
{
    *s=(SeqStack*)malloc(sizeof(SeqStack));
    (*s)->top = -1;  //置栈空标志
}

int Empty_SeqStack(SeqStack *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void Push_SeqStack(SeqStack *s,datatype x)
{
    if(s->top == MAXSIZE -1)
        printf("Stack is full!\n");
    else
    {
        s->top++;
        s->data[s->top] = x;
    }
}

void Pop_SeqStack(SeqStack *s,datatype *x)
{
    if(s->top == -1)
        printf("Stack is empty!\n");
    else
    {
        *x=s->data[s->top];
        s->top--;
    }
}

void Top_SeqStack(SeqStack *s,datatype *x)
{
    if(s->top == -1)
        printf("Stack is empty!\n");
    else
        *x=s->data[s->top];

}
