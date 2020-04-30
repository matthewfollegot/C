/* this is merely a mini-illustration on unions */
main () { 
    union u_tag {
        int ival;
        float fval;
        char *sval;
    } utype;
    
    if (utype == INT)
        printf("%d\n", u.ival);
    else if (utype == FLOAT)
        printf("%f\n", u.fval);
    else if (utype == STRING)
        printf("%s\n", utype.sval);
    else
        printf("bad type %d in utype\n", utype);
    

    struct {
        char *name;
        int flags
        int utype;
        union {
            int val;
            float fval;
            char *sval;
        } u;
    } symbtab[10];
    
    /* first character of sval may be referred to by either *symbtab[i].u.sval or symbtab[i].u.sval[0] */
}
