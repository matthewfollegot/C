/* strcopy: copies t to s */
void strcopy(char *s, char *t)
{
    while (*s++=*t++);
}

/* strcompare: return -1 if s<t, 0 if s==t, 1 if s>t */
int strcompare(char *s, char *t)
{
    const unsigned char *us = (const unsigned char *) s;
    const unsigned char *ut = (const unsigned char *) t;
    for (; *us==*ut && *us; us++, ut++)
        ;
    return (*us > *ut) - (*us < *ut);
}
char *alloc(int n);
