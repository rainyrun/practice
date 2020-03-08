#include <stdio.h>
/*类似上一节中的函数minprintf，编写scanf函数的一个简化版本*/
void minscanf(char *fmt, ...){
    va_list ap;
    char *p, *sval;
    char temp[3];
    
    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        if(*p != '%' && (c = getchar()) == *p)
            continue;
        switch(*++p){
            case 'd':
                scanf("%d", va_arg(ap, int *));
                break;
            case 'f':
                scanf("%f", va_arg(ap, double *));
                break;
            case 's':
                sval = va_arg(ap, char *);
                do{
                    scanf("%c", sval);
                }while(*sval++);
                break;
            default:
                break;
        }
    }
    va_end(ap);
}
