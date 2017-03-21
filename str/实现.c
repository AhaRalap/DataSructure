void StrAssingn(LiString **s,char str[])
{
	LiString *p,*r;
	int i;
	*s = (LiString*)malloc(sizeof(LiString));
	r = *s;
	for(i=0;str[i] != '\0';i++)
	{
		p = (LiString*)malloc(sizeof(LiString));
		p->data = str[i];
		r->next = p;
		r = p;
	}
	r->next = NULL:
}

int StrLength(LiString *s)
{
	int i = 0;
	LiString *p = s->next;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void StrCat(LiString *s,LiString *t)
{
	LiString *p,*q,*r,*str;
	str = (LiString *)malloc(sizeof(LiString));
	r = str;
	p = t->next;
	while(p != NULL)
	{
		q =(LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	p = s;
	while(p->next != NULL)
		p = p->next;
	p->next = str->next;
	free(str);
}

void SubStr(LiString *s,LiString **str,int i,int len)
{
	LiString *p,*q,*r;
	int k;
	p = s->next;
	*str = (LiString *)malloc(sizeof(LiString));
	(*str)->next  = NULL;
	r = *str;
	if(i<1 || i>StrLength(s) || len < 0 || i+len-1>StrLength(s))
		goto L1;
	for(k=0;k<i-1;k++)
		p = p->next;
	for(k=0;k<len;k++)
	{
		q = (LiString *)malloc(sizeof(LiString));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL:
	L1: ;
}