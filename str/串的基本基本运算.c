typedef struct 
{
	char data[MAXSIZE];
	int len;	
}SeqString;
SeqString s;


int StyLength(char *s)
{
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

int StrCat(char s[],char s2[])
{
	int i,j,len1,len2;
	len1 = StrLength(s1);
	len2 = StrLength(s2);
	if(len1 + len2 = MAXSIZE-1)
		return 0;
	i = 0; j = 0;
	while(s1[i] != '\0')
		i++;
	while(s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return 1;
}

int SubStr(char *s,char t[],int i,int len)
{
	int j,slen;
	slen = StrLength(s);
	if(i<1 || i>slen || len<0 || len>slen-i+1)
		return 0;
	for(j=0;j<len;j++)
		t[j] = s[i+j-1];
	t[j] = '\0';
	return 1;
}

int StrCmp(char *s1,char *s2)
{
	int i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return(s1[i] - s2[i]);
}

int StrInsert(char *s,int i,char *t)
{
	char str[MAXSIZE];
	int j,k,len1,len2;
	len1 = StrLength(s);
	len2 = StrLength(t);
	if(i<0 || i>len1 || len1+len2>MAXSIZE-1)
		return 0;
	k = i;
	for(j=0;s[k]!='\0';j++)
		str[j] =s[k++];
	str[j] = '\0';
	j = 0;
	while(t[j] != '\0')
		s[i++] = t[k++];
	j = 0;
	while(str[j] != "\0")
		s[i++] = str[j++];
	s[i] = '\0';
	return 1;
}

