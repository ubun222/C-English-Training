#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h> 
#include <sys/stat.h>
#include <pwd.h>
#include <libgen.h>
#include <sys/types.h>
#include <grp.h>
#include <stdarg.h>
/***#include<conio.h>***/
/***#include<curses.h>***/
#define BOOL int
#define TRUE 1
#define FALSE 0
int fd1;
struct termios init_setting;

#define   RD_EOF   -1
#define   RD_EIO   -2

struct itimerval value, value0;
struct itimerval evalue, evalue0;

    char tline[]="\033[32m●\033[0m";
    char fline[]="\033[31m●\033[0m";
    char eline[]="\033[32m○\033[0m";
    char nline[]="\033[33m○\033[0m";

FILE * rfpr;
FILE * Fp;
int Max;
char answer1[200];
int ci=0;
char astrs[100];
BOOL bk=FALSE;
//BOOL now=FALSE;
//BOOL now1=FALSE;
//BOOL now2=FALSE;
BOOL now3;
//BOOL now4=FALSE;
BOOL now5=FALSE;
BOOL nown=FALSE;
BOOL ascii;
char lword[4];
BOOL iszh=FALSE;
BOOL rw;
BOOL NL;
char aword[200];
char ez;
int growm;
int gcolm;
int grown;
int gcoln;

char * en;
char * zh;

//char aword[150];

int si;

char * xtxt;
char *  alltxt;

char zwords[199];

int b=0;
BOOL p6;
void  handler()
{
//printf("rxit");
//  return 2;
//exit(0);
b=1;

printf("\033[6n");
}


int current_tty(void)
{
    const char *dev;
    int         Fd;

    dev = ttyname(STDIN_FILENO);
    if (!dev)
        dev = ttyname(STDOUT_FILENO);
    if (!dev)
        dev = ttyname(STDERR_FILENO);
    if (!dev) {
        errno = ENOTTY;
        return -1;
    }

    do {
        Fd = open(dev, O_RDWR | O_NOCTTY);
    } while (Fd == -1 && errno == EINTR);
    if (Fd == -1)
        return -1;

    return Fd;
}

    int row;
    int col;
    char strs[9999];
    int add=0;
int calendar(){
//    BOOL ish=FALSE;
fd1 = current_tty();
    struct winsize Max;
    ioctl(0, TIOCGWINSZ , &Max);
    row=Max.ws_row;
    col=Max.ws_col;
char a[]="一";

if ((int)a[1] < 0){
    add=256;
}
else
add=0;
//printf("%d",add);
    int cc;
    strcpy(strs,"");
    for (cc=0;cc<col;cc++){
        strcat(strs,"\xe2");
        strcat(strs,"\x94");
        strcat(strs,"\x80");
    }
        printf("%s",strs);
        printf("C-English-Training\n");
        fflush(stdout);
        char txtlist[99999];
        //strcpy(ls("txt"),txtlist);
        return 0;

}


  void del_char(char a[],char c)
  {
     int i,j;
          for(i=0,j=0; *(a+i)!='\0'; i++)
      {
          if(*(a+i)==c)
             continue;
         else
         {
             *(a+j)=*(a+i);
             j++;
         }
     }
     *(a+j)='\0';
 }

 int checkstr(char *s, char *t, int sflag,int lenstr)
{
    char *q;
    for (; *(s + lenstr); s++)
    {
        if (sflag)  // 不区分大小写
        {
          for (q = t; (*s == *q||*s-32==*q||*s+32==*q) && *q; s++, q++)
            ;

        }else  //区分大小写
        {
            for (q = t; *s == *q && *q; s++, q++)
            ;
        }
        
        if (!*q)
        {
            return 1;
        }
    }

    return 0;
}

 int Checkstr(char *s, char *t, int lenstr)
{
    int n=0;
    int m;
    BOOL same=FALSE;
    for (m=0;m<strlen(s);m++)
    {
            for (n=0;n<lenstr;n++){
            if(s[n+m] == t[n]){
               // printf("%c",s[n+m]);
                same=TRUE;
            }
            else{
                same=FALSE;
                break;
            }
            }

        if (same==TRUE)
        {
            return 1;
        }
    }

    return 0;
}

int ifre(int a1[4],int  b ){
    int l;
    //BOOL F;
    if (a1[0]==-1)
    return TRUE;
    for (l=0;l<5;l++){
        if (a1[l] != -1 && b==a1[l]){
        return FALSE;
        }
    }
    return TRUE;
//    return FALSE;
}

static inline int rd(const int Fd)
{
    unsigned char   buffer[4];
    ssize_t         n;

    while (1) {
        //fflush(stdin);
        fflush(stdout);
        n = read(Fd, buffer, 1);
        if (n > (ssize_t)0)
            return buffer[0];

        else
        if (n == (ssize_t)0)
            return RD_EOF;

        else
        if (n != (ssize_t)-1)
            return RD_EIO;

        else
        if (errno != EINTR && errno != EAGAIN && errno != EWOULDBLOCK)
            return RD_EIO;
    }

   return 0;
}
/* As the tty for current cursor position.
 * This function returns 0 if success, errno code otherwise.
 * Actual errno will be unchanged.
*/
//BOOL re;


char ysv1;


FILE * fp;
FILE * rfp;
FILE * rfpa;

BOOL rw;
int rwfp(char * word1,char * word2,char ze,char ifrw){

//int offset;
//BOOL a;
//BOOL b;
int i;
//rrpp = fopen("CORRECT.txt", "r");
//strcpy(alltxt,"");

//if(ze=='1')
//strcat(word2,"\t\t");
//if(ze=='2')
strcat(word1,"\t\t");
//a=FALSE;

//strcpy(Buffer,"");
//fclose(rrpp);

    //offset=strlen(lists);

      //  strcpy(en1,"");
      //  strcpy(zh1,"");

if (ifrw==FALSE && rw==FALSE && ysv1!='s' && ysv1!='S' && ysv1!='V' && ysv1!='Y' ){
    //printf("\n\n22\n");
    rfpa = fopen("CORRECT.txt", "r+");
    rfp = fopen("CORRECT.txt", "w+");
    if(ze=='1'){
    //    strcpy(en1,word2);
    //    strcpy(zh1,word1);



    fprintf(rfp,"%s\t\t\t\t\t%s\n",word1,word2);
    fflush(stdout);
    fclose(rfp);
    fseek(rfpa,0L,SEEK_END);
    fprintf(rfpa,"%s",alltxt);
    fflush(stdout);
    fprintf(rfpa,"%s",xtxt);
    fflush(stdout);
    fclose(rfpa);
    printf("\n错题+1");
}
    else if(ze=='2'){
   //     strcpy(zh1,word2);
    //    strcpy(en1,word1);


    fprintf(rfp,"%s\t\t\t\t\t%s\n",word1,word2);
    fflush(stdout);
    fclose(rfp);
    fseek(rfpa,0L,SEEK_END);
    fprintf(rfpa,"%s",alltxt);
    fflush(stdout);
    fprintf(rfpa,"%s",xtxt);
    fflush(stdout);
    fclose(rfpa);
printf("\n错题+1");

    }
}

else if ((ifrw==TRUE ||  ysv1=='s' ||  ysv1=='S') && rw==TRUE ){
    //rfpa = fopen("CORRECT.txt", "r+");
    //rfpa = fopen("CORRECT.txt", "r+");
    rfp = fopen("CORRECT.txt", "w+");
    if(ze=='1'){
    fseek(rfp,0L,SEEK_END);
    if (xtxt[0]!='\0'){
    printf("\n错题-1");
    }
    fprintf(rfp,"%s",xtxt);
    fflush(stdout);
    fclose(rfp);
}
    else if(ze=='2'){
    fseek(rfp,0L,SEEK_END);
    if (xtxt[0]!='\0'){
    printf("\n错题-1");
    }
    fprintf(rfp,"%s",xtxt);
    fflush(stdout);
    fclose(rfp);
//printf("2");
    }
}
//strcpy(alltxt,"");
strcpy(xtxt,"");
return 0;
}

int words(char * aword){
    int i;
    char theword[1999];
    char abc[4];
    int lengn=0;
    int n=0;
    int co=col;
    int lasti=0;
    int whereadd;
    strcpy(theword,aword);
    i=0;
        while(i<=strlen(theword)){

        //printf("%c",theline[i]);
        //sleep(1);
       if ((int)theword[i]-12<=128 && (int)theword[i]>12 ){
            lengn=lengn+1;
            i=i+1;   
            n=n+1;
            //printf("%d\n",(int)theword[i]);
           continue;
        }
        if ((int)(theword[i])+256 >=224 && (int)theword[i]+256<227 && (int)theword[i+1]+256>128  && (int)theword[i+1]+256<=191 ){
            lengn=lengn+1;
            i=i+3;
            n=n+1;
           continue;
        }
        if((int)theword[i]+256<224 && (int)theword[i]+256>128 && (int)theword[i+1]+256>128){
                lengn=lengn+1;
                i=i+2;
                n=n+1;
                continue;

        }
        if((int)theword[i+1]+256>=128 && (int)theword[i]+256>=227 && (int)theword[i]+256<=239  ){
                lengn=lengn+2;
                i=i+3;
                n=n+1;
                continue;
        }
        else
        i++;

    }

    if (n>=0)
    return n;
    else
    return 0;
}


int col;
char asc[3]="”";
int fresh(char * aline){
    int i;
    char theline[1999];
    char abc[4];
    int lengn=0;
    int co=col;
    int lasti=0;
    int whereadd;
    strcpy(theline,aline);
    i=0;
    while(i<=strlen(theline)){

        if (i>=co)
        {
            if (lengn%co==0){
                co=co+col;
                lasti=i;
            }
            if(lengn%co==1){
                return lasti;
            }
        }
        //printf("%c",theline[i]);
        //sleep(1);
       if ((int)theline[i]-12<=128 && (int)theline[i]>12 ){
            lengn=lengn+1;
            i=i+1;   
            //printf("%d\n",(int)theline[i]);
           continue;
        }
        if ((int)(theline[i])+256 >=224 && (int)theline[i]+256<227 && (int)theline[i+1]+256>=128  && (int)theline[i+1]+256<=191 ){
            lengn=lengn+1;
            i=i+3;
           continue;
        }
        if((int)theline[i]+256<224 && (int)theline[i]+256>128 && (int)theline[i+1]+256>128){
                lengn=lengn+1;
                i=i+2;
                continue;

        }
        if((int)theline[i+1]+256>=128 && (int)theline[i]+256>=227 && (int)theline[i]+256<=239  ){
                lengn=lengn+2;
                i=i+3;
                continue;
        }
        else
        i++;

    }
    return -1;
}


int cursor_position(int *const Row ,int *const Col)
{
    
    value.it_value.tv_sec=0;
    value.it_value.tv_usec=150000;
    value.it_interval.tv_sec=0;
    value.it_interval.tv_usec=200000;

    value0.it_value.tv_sec=0;
    value0.it_value.tv_usec=0;
    value0.it_interval.tv_sec=0;
    value0.it_interval.tv_usec=0;

//system("stty -echo");
//system("stty -icanon");
   // struct termios  saved, temporary;
   //int             retval, rows, cols, saved_errno;
   //alarm(0);
    int retry=0;
    char result;
    /* Bad tty? */
    char receive;
    char receives[999];
    int a=0;
    int b=0;
    int i;
    int f=0;
    int lf;
char   buffer[4];
//strcpy(a,"");
//strcpy(b,"");
strcpy(receives,"");
//wr(fd1, "\033[6n", 4);
//fflush(stdout);

    //i=write(fd1,"\033[6n",1);
//fseek(stdout,0,SEEK_CUR);
//lf=ftell(stdout);
//setvbuf(stdin, NULL, _IOLBF, 512);
//setvbuf(stdout, NULL, _IOLBF, 512);
printf("\033[6n");
fflush(stdout);
//printf("%d",f);
    //printf("%d",lf);
    //printf("%d",f);
   // fflush(stdout);

//if(re==TRUE){
//re=FALSE;
//return 2;
//}
retry=0;
        /* Request cursor coordinates from the terminal. */
//fseek(stdin,0,SEEK_END);
//printf("\033[6n");
//ualarm(100000,9999999);
    setitimer(ITIMER_REAL,&value,NULL);
//setvbuf(stdin, NULL, _IONBF, 2);
while(((result = rd(fd1)) ))
{
if (result=='R'){
setitimer(ITIMER_REAL,&value0,NULL);
break;
}
    setitimer(ITIMER_REAL,&value,NULL);
    //ualarm(0,0);
    //setitimer(ITIMER_REAL,&value0,NULL);
  //  if ((int)result==-1 || (int)result==-2 ){
      // printf("222");
  //  setitimer(ITIMER_REAL,&value,NULL);
 //   break;
  //  }
    //if(result==-1 || result==-2)
    //return 2;

if((int)result>=48 && (int)result<=57 || (int)result==59){
    if ((int)result==59){
    retry=1;
    continue;
    }
    if(retry==0){
if (result >= '0' && result <= '9') {
    a = 10 * a + result - '0';
        }
    }
    if(retry==1){
       setitimer(ITIMER_REAL,&value0,NULL); 
    //strncat(b,&result,1);
if (result >= '0' && result <= '9') {
    b = 10 * b + result - '0';
    //retry=0;
        }  
        
    }
}
}
//ualarm(0,0);
//setitimer(ITIMER_REAL,&value0,NULL);
//printf("22222");
//printf("a:%db:%d",a,b);
//b=strtok(NULL,"\0");
//if(!b)
//eturn 2;
*Row=a;
*Col=b;
//printf(":%d;%d",*Row,*Col);
    /* Restore saved terminal settings. */
    /* Done. */
   // if( *Row + *Col != 0 )
    return 0;
   // else 
   // return 2;
}

BOOL ish=FALSE;
int findword(char * en, char * en2 , char * txt){
    char Eng[399];
    char Zword;
    char Zword2;
    char Zword3;
    char Zwords[399];
    char En[399];
    char Word[999];
    char ZWords[99999];
    int Lengn=0;
    int I=0;
    int max;
    char * Txt;
    Txt=(char *)malloc(1999999);
    strcpy(Txt,txt);
    //FILE * fp;
    strcpy(Eng,en);
    strcpy(En,answer1);
    while(TRUE){
    printf("\n请输入要查找的单词:\n");
    printf("the word:");
    fflush(stdout);
    strcpy(Zwords,"");
        while (TRUE){
        Zword=getchar();
        //fgets(&Zword, 2, stdin);
        if(Zword == '\x7f'){          
            if(isascii(Zwords[Lengn-1]) && Lengn > 0){
                Zwords[Lengn-1]='\0';
                Lengn=Lengn-1;
                printf("\b \b");
                fflush(stdout);
                continue;
            }
            else if(!isascii(Zwords[Lengn-1]) && Lengn > 0){
                Zwords[Lengn-3]='\0';
                Zwords[Lengn-2]='\0';
                Zwords[Lengn-1]='\0';
                printf("\b\b  \b\b");
                fflush(stdout);
                Lengn=Lengn-3;
                continue;
            }
            else
            continue;
                }
        
        if(Zword == '\r' || Zword == '\n' || Zword == '\0'){
            break;
        }



        else{
        Lengn=Lengn+1;
        strncat(Zwords,&Zword,1);
        printf("%c",Zword);
        fflush(stdout);
        continue;
        }
    }
    if (Zwords[0]=='\0')
    break;
    //printf("%s",Txt);
    // max=strlen(txt);
    max=strlen(Txt);
    strcpy(Word,"");
    while (I++,I<max){
        if(Txt[I] != '\n'){
            if(Txt[I] == '\t'){
            continue;
            }
            strncat(Word,&Txt[I],1);
        }
        else{
            if(Checkstr(Word,Zwords,strlen(Zwords))){
                if(ish==TRUE){
                    if(fresh(Word)!=-1)
                printf("\n~");
                    else
                printf("\n");
            }
                else
                printf("\n");
                
                printf("%s",Word);
                fflush(stdout);
                strcat(ZWords,Word);
                strcat(ZWords,"\n");
                strcpy(Word,"");
            }
            strcpy(Word,"");
        }
    }
    //printf("%s",ZWords);
    if(ZWords[0]=='\0'){
        strcpy(Txt,"");
        strcpy(Word,"");
        strcpy(Txt,txt);
        strcpy(Zwords,"");
        strcpy(ZWords,"");
        Lengn=0;
        I=-1;
        continue;
    }
    else{
        strcpy(Txt,"");
        strcpy(Word,"");
        strcpy(Txt,ZWords);
        strcpy(Zwords,"");
        strcpy(ZWords,"");
        Lengn=0;
        I=-1;
        continue;
    }

    }
    strcpy(answer1,Zwords);
    // ysv(FALSE,Zwords,ez);
    strcpy(Zwords,"");
    strcpy(answer1,En);
    printf("\n");
    printf("\033[2m%s\n\033[0m",strs);
    fflush(stdout);
    printf("\r\033[1m%s\033[0m\033[2m \033[3m<───> \033[0m",en2);
    fflush(stdout);
return 0;
}


BOOL termux=FALSE;

char * aprt(char * aline){
char aaline[2999];
int mi=-1;
int leng;
char valine[999];
char baline[2999];
leng=strlen(answer1);
if(ish==TRUE){
    //printf("%s",answer1);
int whereadd=0;
char vvline[4999];
char alinea[4999];
while (TRUE){
    if((whereadd=fresh(aline))==-1){
        break;
    }
    else{
        strcpy(aaline,"");
strcpy(baline,"");
        strcat(baline,&aline[whereadd]);
        strncat(aaline,aline,whereadd);
        strcat(aaline,"~");
        strcat(aaline,baline);
        strcpy(aline,"");
        strcpy(aline,aaline);
    }
    }


//return aline;
}
//else

    if(ysv1=='v' || ysv1=='V'){
        while(mi=mi+1,mi<=strlen(aline)){
strncpy(valine,&aline[mi],leng);
//printf(":%s:%s:",valine,answer1);
if(strncmp(valine,answer1,leng)==0){
break;
}
    }
    if (mi==1 || mi==0 || mi>=strlen(aline))
    return aline;
        strcpy(aaline,"");
        strcpy(baline,"");
        strncat(aaline,aline,mi);
        strcat(aaline,"\033[1m\033[33m");
        strcat(aaline,answer1);
        strcat(aaline,"\033[0m");
        strcat(aaline,&aline[mi+leng]);
        strcpy(aline,aaline);



    }

return aline;
}





char ysv1;
int getlines(char * string){
    int i;
    int n=strlen(string);
    int l=1;
    int ni[50];
    //char strings[999999];
    char temp[89999];
    int times = (unsigned int)time(NULL);
    ni[0]=0;
    int rx=0;
    int ran;
    int m;
    int rans[5]={-1,-1,-1,-1,-1};
    for(i=0;i<n;i++){
        if(string[i]=='\n'){
            ni[l]=i;
            l++;
        }
    }
    char aline[l-1][999];

    for(i=0;i<l;i++){
            strcpy(aline[i],"\0");
    }
    //if(ysv1=='v' || ysv1=='V')
    strcpy(aline[0],"\n");
    for(i=0;i<l-1;i++){
        strncat(aline[i],&string[ni[i]],ni[i+1]-ni[i]);
    }
    
        for(i=0;i<l-1;i++){
            strcpy(temp,"");
            strcpy(temp,"   ");
            strcat(temp,&aline[i][1]);
            //strncat(aline[i],&string[ni[i]],ni[i+1]-ni[i]);
            strcpy(aline[i],temp);
    }

    i=0;
    while(i<=3){
    if (l<4){
        for(m=0;m<4;m++){
            if(strlen(aline[m])>=5)
        printf("\n%s",aprt(&aline[m][1]));
    }
    break;
    }
    else {
    srand(times * (rx+1));
    rx++;
    ran=rand() % (l+1);

    if(ifre(rans,ran)==TRUE){
    rans[i]=ran;
    if(aline[ran][0]!='\0')
    printf("\n%s",aprt(&aline[ran][1]));
    i++;
    }
    else{
        
        continue;
    }
    }
    }

    return l;
}

char yword[9999];
BOOL flag = FALSE;
char azh[10][100];
int zm=0;
int c;

char w1[10][9999];

int         rown, rowm;
int coln=-1;
int colm=-2;
int ishprt( const char *restrict format, ... ){

char format2[9999];
char * format3;
char * format4;
char result;
    if(ish==TRUE){

    va_list ap;
    va_start(ap, format);
    // ...
    strcpy(format2,format);
    strcat(format2,"\033[6n");
    format3=va_arg(ap,char *);
    format4=va_arg(ap,char *);
while(TRUE){
b=0;
printf(format2,format3,format4);
setitimer(ITIMER_REAL,&value,NULL);
   // b++;
    // ..

while(((result = rd(fd1))))
{
    if (result == 'R' ){
    setitimer(ITIMER_REAL,&value0,NULL);
    //b=0;
    break;
}

    //if(result==-1 || result==-2)
    //return 2;

}
if(b==1){
    b=0;
    continue;
}
setitimer(ITIMER_REAL,&value0,NULL);
break;
}
va_end(ap); 
    }
    else{
    va_list ap;
    va_start(ap, format);
    // ...
    vprintf(format, ap);
    // ...
    va_end(ap); 
    }

return 0;
}

int ififright(char * aword){
    //int ifright;
int i,n;
int cmmm,mmm,m;
char tch[9999];
char * dzh;
    if(ez=='2'){
        //c=0;
        m=-1;
        cmmm=0;
        mmm=0;
        strcpy(tch,"");
    strcpy(tch,aword);
    //char w1[10][9999];
if(strlen(tch) >=2 ){
            for(n=0;n<10;n=n+1){
                //printf("222");
                //strcpy(bzh[n],"");
                strcpy(w1[n],"");
                //strcpy(dzh,"");
                /*printf("%d\n",zhleng);*/
                cmmm=0;
                mmm=m;
                m=m+2+cmmm;
                while(m=m+1,m<=strlen(tch)){
                    //printf("222");
                    //strcpy(w1[n],"");
                    if(tch[m]=='\xef' && tch[m+1]=='\xbc' && tch[m+2]=='\x8c' ||  tch[m]=='\0'  ){
                        cmmm=m-mmm-3;
                        if(n==0){
                        dzh=&tch[mmm+1];
                        cmmm=cmmm+2;
                        }
                        else
                        dzh=&tch[mmm+3];
                        strncat(w1[n],dzh,cmmm);
                        //printf("%s",w1[n]);
                        break;
                    }
                }
                if(tch[m]=='\0' )
                break;
                /*strcpy(azh[n],strtok(ch,"\xbc\xef"));*/
            }
//printf("%s",w1[n]);
//c=0;
//printf("%d",zm);
for(m=0;m<zm+1;m=m+1){

if(strcmp(azh[m],w1[n])==0 && strcmp(w1[n],"")!=0){
c++;
strcpy(azh[m],"");
if (c==zm+1){
    flag=TRUE;
    ishprt("\r\033[%dC%s\r",col-2,tline);
    c=0;
    break;
}
else{
    flag=FALSE;
}
strcpy(yword,"*，");
return(2);
}

}

return(0);
}
return(0);
    }
    if(ez=='1'){
        //printf("%s\n",answer1);
      // printf("%s\n",aword);
       if(strcmp(aword,answer1)==0){
        flag=TRUE;
        ishprt("\r\033[%dC%s\r",col-2,tline);
        return 0;
       }

}
return 0;
}

char bzh[10][200];
int ifRight(){
int i,n,cc,k;
int cmmm,mmm,m;
char tch[9999];
char * dzh;
cc=0;
        //c=0;
        m=-1;
        cmmm=0;
        mmm=0;
        strcpy(tch,"");
    strcpy(tch,aword);
    char w1[10][9999];
    
if(ez=='2'){
            for(n=0;n<10;n=n+1){
                //printf("222");
                //strcpy(bzh[n],"");
                strcpy(w1[n],"");
                //strcpy(dzh,"");
                /*printf("%d\n",zhleng);*/
                cmmm=0;
                mmm=m;
                m=m+2+cmmm;
                while(m=m+1,m<=strlen(aword)){
                    //printf("222");
                    strcpy(w1[n],"");
                    if(aword[m]=='\xef' && aword[m+1]=='\xbc' && aword[m+2]=='\x8c' ||  aword[m]=='\0'  ){
                        cmmm=m-mmm-3;
                        if(n==0){
                        dzh=&aword[mmm+1];
                        cmmm=cmmm+2;
                        }
                        else
                        dzh=&aword[mmm+3];
                        strncat(w1[n],dzh,cmmm);
                        //printf("%s",w1[n]);
                        break;
                    }
                }
                if(aword[m]=='\0' )
                break;
                /*strcpy(azh[n],strtok(ch,"\xbc\xef"));*/
            }
for(k=0;k<n+1;k=k+1){
for(m=0;m<zm+1;m=m+1){

if(strcmp(bzh[m],w1[k])==0 && strcmp(w1[k],"")!=0){
cc++;
}

}
}
if (cc==zm+1){
    flag=TRUE;
return TRUE;
   // break;
}
else{
    flag=FALSE;
    return FALSE;
}
}
return 2;
}

char backs[99];
int leng;
char block;
char llword;
BOOL now1;
BOOL now2;
BOOL now3;
BOOL now4=FALSE;

int ezback(){
   // int         rown, coln, rowm, colm;

   // setvbuf(stdin, NULL, _IONBF, 1);
   if(ez=='1'){
                        while (TRUE){
                        //if(ish==TRUE || termux==TRUE){
                        cursor_position(&rown,&coln);
                        //coln=colm;
                        if(coln==1){
                        ishprt("\033[1A\033[%dC%c\b\033[1C",col,block);
                        cursor_position(&rowm,&colm);
                        break;
                        //backs=
                        //continue;
                        }
                        
                       // }

                        
                        if(now3==TRUE){
                        //printf("2222");
                        if(block=='-'){
                            strcpy(backs,"\b\033[1C-\b\033[1C");
                        }
                        else if(block==' '){
                        strcpy(backs,"\b\033[1C \b\033[1C");
                        }
                        now3=FALSE;
                        ishprt("%s",backs);
                        fflush(stdout);
                        cursor_position(&rowm,&colm);
                        break;
                        }

                        printf("%s",backs);
                        fflush(stdout);
                        //if(ish==TRUE)
                        cursor_position(&rowm,&colm);
                        //coln=colm;
                        if(ish==TRUE){
                        if(coln==colm && coln!=col ){
                        continue;
                        }
                        }
                        break;
                        }

   }

      if(ez=='2'){
        llword=aword[strlen(aword)-1];
//printf("%c",llword);
                        while (TRUE){
                        //if(ish==TRUE || termux==TRUE){
                        cursor_position(&rown,&coln);
                        if(coln==1 && ( llword=='.' || llword=='-' ) ){
                         //printf("2222");
                        if(now1==TRUE){
                           // printf("2222");
                        ishprt("\033[1A\033[%dC\b%c\b",col,' ');
                        now1=FALSE;
                        break;
                        }
                        else if(now1==FALSE){
                            now1=TRUE;
                            now2=FALSE;
                          //  printf("2222");
                        ishprt("\033[1A\033[%dC%c\b\033[1C",col,' ');
                        break;
                        }
                        //backs=
                        //continue;
                        }
                        else if(coln==1  && now1==TRUE){
                           // printf("222");
                            ishprt("\033[1A\033[%dC  \b\b",col-2);
                            break;

                        }
                        else if(coln==1 && now1==FALSE){
                            ishprt("\033[1A\033[%dC\b \b",col);
                            break;
                        }
                    


                    
                        if(now3==TRUE){
                        //printf("2222");
                        strcpy(backs,"\b\033[1C \b\033[1C");
                                                    now1=TRUE;
                            now2=FALSE;
                        now3=FALSE;
                        ishprt("%s",backs);
                        fflush(stdout);
                        break;
                        }
                        else if(now2==TRUE){
                           //printf("2222");
                        strcpy(backs,"\b \b");
                        now2=FALSE;
                        ishprt("%s",backs);
                        fflush(stdout);
                        break;
                        }
                        printf("%s",backs);
                        fflush(stdout);
                        //if(ish==TRUE)
                        cursor_position(&rowm,&colm);
                        if(ish==TRUE){
                        if(coln==colm && coln!=col){
                        continue;
                        }
                        }
                        break;
                        }

   }

                        //fprintf(stdout,"%s",backs);
                        //fflush(stdout);
return 0;
}

char zword;
char cword[4];
BOOL getin=FALSE;
BOOL zd=FALSE;
BOOL waiting=FALSE;
char xword; 
BOOL c1=FALSE;
BOOL c2=FALSE;
BOOL c3=FALSE;
int ezprintf(){
now2='\x00';
now3='\x00';
//now4=FALSE;
if(ez=='2'){
//strcpy(cword,"");
//strncat(cword,&zword,1);
if ( zword==',' || zword==' '  ){
    zword='\x00';
strcpy(cword,"");
strcpy(yword,"*，");
//xword='\x00';
getin=FALSE;
//waiting=TRUE;
return(2);
    //strncat(aword,&zword,2);
}

else if ( zword=='.' || zword=='-'  ){
    strcpy(cword,"");

                        while (TRUE){
                        //if(ish==TRUE)
                        cursor_position(&rown,&coln);
                        printf("%s",&zword);
                        fflush(stdout);
                        //if(ish==TRUE)
                        cursor_position(&rowm,&colm);
                        if(ish==TRUE){
                        if(coln==colm && coln!=col){
                        continue;
                        }
                        }
                        if(coln==colm && colm==col){
                            now1=FALSE;
                            now2='\x00';
                            now3=TRUE;
                            //now4=TRUE;
                            break;
                        }
                        else if(coln==colm-1 && colm==col){
                            now1=TRUE;
                            now2=FALSE;
                        }
                        
                        break;
                        }
                    
                        fflush(stdout);       

    strncat(aword,&zword,1);
    return(0);
}
else if (c3==TRUE) {
                        strncat(cword,&zword,1);
                    c3=FALSE;
                    c2=FALSE;
                        while (TRUE){
                        //if(ish==TRUE)
                        cursor_position(&rown,&coln);
                        fprintf(stdout,"%s",cword);
                        fflush(stdout);
                        //if(ish==TRUE)
                        cursor_position(&rowm,&colm);
                        //if(ish==TRUE){
                            if(coln==col-2 && colm==col){
                                //printf("222");
                                now1=TRUE;
                                now2=FALSE;
                                now3=FALSE;
                            }
                            else if(coln==col-1 && colm==col){
                                now1=FALSE;
                                now2=TRUE;
                                now3=FALSE;
                            }
                            else
                            {
                                //now1='\x00';
                                now2='\x00';
                            }
                        if(ish==TRUE){
                        if(coln==colm){
                        if(colm==col){
                        ishprt("\n");
                        now1=TRUE;
                        now2=FALSE;
                        now3=FALSE;
                        continue;
                        }
                        else
                        continue;
                        }
                        }
                        break;
                        }
strncat(aword,cword,3);
strcpy(cword,"");
//c3=FALSE;
return 0;
}

else
{
if ((int)zword+add>=227  && (int)zword+add<=239 ){
   //strcpy(cword,"");
   // fprintf(stdout,"%s",&zword);
strncat(cword,&zword,1);
    c2=TRUE;
    return 0;
}
else if ( (int)zword+add>=128 && c2==TRUE ){
   //strcpy(cword,"");
   // fprintf(stdout,"%s",&zword);
   c3=TRUE;
   //c2=FALSE;
strncat(cword,&zword,1);
    
    return 0;
}
else{
    c3=FALSE;
    c2=FALSE;
    //printf("222");
    strcpy(cword,"");
    return(0);
}
//strcpy(cword,"");
}
}
if(ez=='1'){
//cursor_position(&grown,&gcoln);
fflush(stdin);
if (((int)zword>=65  && (int)zword<=122) || ((int)zword==32 || (int)zword==46 || (int)zword==45 ) ){
                        while (TRUE){
                        //if(ish==TRUE)
                        coln=colm;
                        //cursor_position(&rown,&coln);
//                        fprintf(stdout,"%c",zword);
//                        if(colm==col){
  //                          printf("%c\n",zword);
    //                        now2=TRUE;
      //                     
                       // fflush(stdout);
//}
if(coln==col){ 
ishprt("%c",zword);
fflush(stdout);
}
else
printf("%c",zword);
fflush(stdout);
//ef(ish==TRUE)
			//
                        cursor_position(&rowm,&colm);
			if(coln==col && colm==col){
			ishprt("\n");
            break;
            }
                        if(ish==TRUE)
                        if(coln==colm)
                        continue;
                        
                       // if(coln==colm && colm==col){
                            //printf("2222");
                         //   now3=TRUE;
                           // break;
                        //}
                        
                        break;
                        }
strncat(aword,&zword,1);
}
return(0);
//cursor_position(&growm,&gcolm);
}
//strcpy(&zword,"");

return 0;
}


//calder birdsey
//cs315
//assignment 01 

void print_long(char *dir_arg, struct dirent *dir_entry); 
void flag_handler(char *dir_arg, struct dirent *dir_entry, int flag_all, int flag_long);
void print_args(char *dir_arg, char *file, int flag_all, int flag_long, int flag_file); 

//main function    
int ls(char *txtpath) {
    //initialize flags
    int flag_long = 0; 
    int flag_all = 0; 
    int flag_file = 0; 

    //get options 
    int opt; 
/***    while((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
        case 'l':   
            flag_long = 1; 
            break;
        case 'a':
            flag_all = 1; 
            break;
        default:
            fprintf(stderr, "myls: supports -l and -a options\n"); 
            exit(EXIT_FAILURE); 
        }
    }
***/
    //check command line args and call print_args with appropriate parameters 

            struct stat argbuf;
            char *arg = txtpath; 
            if((stat(arg, &argbuf)) == -1) {
                printf("myls: cannot access '%s': No such file or directory\n", txtpath);
            }else{
                if(S_ISREG(argbuf.st_mode)) {
                    flag_file = 1;
                    print_args(".", arg, flag_all, flag_long, flag_file); 
                }
                if(S_ISDIR(argbuf.st_mode)) {
                    printf("%s:\n", arg); 
                    print_args(arg, "NULL", flag_all, flag_long, flag_file); 
                }
                flag_file = 0;
                if(flag_long == 0) {
                    printf("\n");
                }
            }
            optind ++; 
        return 0;
        }    


//function to print file/directory data with ls option -l
void print_long(char *dir_arg, struct dirent *dir_entry) {
    struct stat statbuf; 
    char fp[PATH_MAX];
    sprintf(fp, "%s/%s", dir_arg, dir_entry->d_name);
    if(stat(fp, &statbuf) == -1) {
        perror("stat");
        return;   
    }

    //permission data/nlink 
    printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-"); 
    printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
    printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
    printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
    printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
    printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
    printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
    printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
    printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
    printf((statbuf.st_mode & S_IXOTH) ? "x " : "- ");
    printf("%u ", statbuf.st_nlink);

    //group and user data 
    struct passwd *pw; 
    struct group *gid; 
    pw = getpwuid(statbuf.st_uid);  
    if(pw == NULL) {
        perror("getpwuid"); 
        printf("%d ", statbuf.st_uid); 
    }else {
        printf("%s ", pw->pw_name); 
    }
    gid = getgrgid(statbuf.st_gid);
    if(gid == NULL) {
        perror("getpwuid"); 
        printf("%d ", statbuf.st_gid); 
    }else  {
        printf("%s ", gid->gr_name); 
    }

    //file size
    printf("%5lld ", statbuf.st_size);

    //timestamp
    struct tm *tmp;
    char outstr[200];
    time_t t = statbuf.st_mtime;
    tmp = localtime(&t);   
    if(tmp == NULL) {
        perror("localtime"); 
        exit(EXIT_FAILURE);
    } 
    strftime(outstr, sizeof(outstr), "%b %d %R", tmp); 
    printf("%s ", outstr);

    //file name 
    printf("%s\n", dir_entry->d_name); 
}

//function to check flags and print file/directory info accordingly
void flag_handler(char *dir_arg, struct dirent *dir_entry, int flag_all, int flag_long) {
    if(flag_all == 0){
        if((dir_entry->d_name[0] = '.')) { 
            return; 
        } 
    }
    if(flag_long == 0) {
        printf("%s ", dir_entry->d_name);
    }else { 
        print_long(dir_arg, dir_entry);
    }
}

//function to handle cmd-line args
void print_args(char *dir_arg, char *file, int flag_all, int flag_long, int flag_file) {
    //open directory
    DIR *dir = opendir(dir_arg);
    if(dir == NULL) {
        perror("opendir"); 
        exit(EXIT_FAILURE);
    } 

    //read and print directory/file data 
    struct dirent *dir_entry;  
    errno = 0; 
    while((dir_entry = readdir(dir))!= NULL) { 
        if(flag_file == 1) {
            if(strcmp(dir_entry->d_name, file) == 0) {
                flag_handler(dir_arg, dir_entry, flag_all, flag_long);
            }
        }else {
            flag_handler(dir_arg, dir_entry, flag_all, flag_long); 
        }
    }
    if((dir_entry == NULL) && (errno != 0)) {
        perror("readdir");
        exit(EXIT_FAILURE); 
    }
    
    //close directory
    closedir(dir);
}

FILE * rfp;
FILE * rfpa;
BOOL CORRECT;
char * txt;
    int lines;
    //lines=0;
int loadcontent(){
    if (CORRECT==TRUE){
        rfp = fopen("CORRECT.txt", "r");
        if(rfp==NULL){
        printf("\n错题集合不存在，在当前目录自动生成CORRECT.txt");
        rfp = fopen("CORRECT.txt", "w+");
        rfpa = fopen("CORRECT.txt", "a+");
        fprintf(rfp,"%s","\\\\\\\n");
   // Fp=fopen(path,"r");
}
else
{
    printf("\n使用./CORRECT.txt");
    rfpa = fopen("CORRECT.txt", "a+");
}

fflush(stdout);
fclose(rfp);
}

    char buffer[9999];

    printf("\n");
    while (fgets(buffer,150,fp)){ 
        if ( checkstr(buffer,"\t",0,1) && buffer[0]!='\n' ){
            /***printf("%s",buffer);***/
            strncat(txt,buffer,100);
            lines++;
        }
        else if(buffer[1] == '\\' )
        break;
    }
    if(txt[strlen(txt)-1]!='\n')
    strcat(txt,"\n"); //
printf("已加载%d组单词\n",lines);
//printf("%s",txt);
return 0;
}


    char PATH[99999][99];
    char path[39999];
    FILE * fp;
    int p=0;
int getfromread(){
    txt=(char *)malloc(9999999); 
    lines=0;
    char Path;
    //char txt[999999]; //segment error
    char buffer[200];
    int pleng;
    //strcpy(PATH,"");
    while(TRUE){
    strcpy(path,"");
    strcpy(&Path,"");
    pleng=0;
    printf("\r输入txt文件路径，按回车键结束:\033[K");
    fflush(stdout);
           while((Path=getchar())  != '\0'){
                if(Path == '\x7f'){          
                    if(isascii(path[pleng-1]) && pleng > 0){
                        path[pleng-1]='\0';
                        pleng=pleng-1;
                        printf("\b \b");
                        fflush(stdout);
                        continue;
                    }
                    else if(!isascii(path[pleng-1]) && pleng > 0){
                        path[pleng-3]='\0';
                        path[pleng-2]='\0';
                        path[pleng-1]='\0';
                        printf("\b\b  \b\b");
                        fflush(stdout);
                        pleng=pleng-3;
                        continue;
                    }
                continue;
                }

           if(Path == '\r' || Path == '\n' || Path == '\0'){
           break;
        }
            pleng++;
            strncat(path,&Path,1);
            printf("%c",Path);
            fflush(stdout);

    }
            fflush(stdout);
                if(strcmp(path,"")==0 && strcmp(PATH[0],"")!=0){
                    //printf("\n");
            break;
            }
            else{
                        fp=fopen(path,"r");
            if(fp==NULL ){
                strcpy(path,"");
                //strcpy(path,"");
                printf("\n");
                continue;
            }  
            else{  
            strcpy(PATH[p],path);
            //printf("%s",PATH[p]);
            p++;
            loadcontent();
            }
            //strcat(PATH,"\n");
            strcpy(path,"");
            continue;


}
            //else
            
            //printf("\n\n%s",path);
    }

return 0;

}


    //int max;
    //BOOL getin=FALSE;
    int iii=0;
    char zword; //ezprintf
    char temp[200];
    int tleng;
    //int leng; ezback
    char ltemp[200];
    int mi;
    //char block; ezback()
    //char azh[10][100]; //ififright()
    //char bzh[10][100]; //ifRight()
   // BOOL flag = FALSE;
    int ifright;

BOOL PASS1=FALSE;
int nend[39999];
int ran;
int num=-1;
    char order;
int ysv(char * bword,char ze){
//char eline[]="\033[32m○\033[0m";
char * rbuffer;
char * rtxt;
rbuffer=(char *)malloc(9997);
rtxt=(char *)malloc(1999999);
char * btxt;
btxt=(char *)malloc(1999999);
int nrtxt;
int alocate=0;
int locate;
int zlocate=0;
int clocate=0;
char En[200];
char a[200];
char tbuffer[399];
char * theline;
theline=(char *)malloc(9999);
char * bbuffer;
bbuffer=(char *)malloc(9998);
//char * del;
BOOL vflag=FALSE;
BOOL aflag=FALSE;
BOOL llocate=FALSE;
FILE * yFp;
FILE * wfpn;
char word1[201];
char Buffer[4096];
FILE * rrpp;
int i;
rw=FALSE;
int P=0;
//alltxt=(char *)malloc(2999999);
//Fp=fp;
//strcat(rtxt,"");
strcpy(En,"");
strcpy(rtxt,"");
strcpy(xtxt,"");
strcpy(btxt,"");
strcpy(rbuffer,"");
strcpy(bbuffer,"");
//Fp=fopen(path,"r");
//yFp=fopen(path,"r");
BOOL non=FALSE;
while ((ysv1=getchar())!='y' && ysv1!='Y' && ysv1!='v' && ysv1!='V' && ysv1!='s' && ysv1!='S' && ysv1!='\n' && ysv1!='\r')
    continue;
//printf("%c",ysv1);
if (ysv1=='v' || ysv1=='V'){
    if (flag!=TRUE){
    printf("\n%s",bword);
    fflush(stdout);
    }
for(P=0;P<p;P++){
    //P=0;
    if(Fp!=NULL)
    fclose(Fp);
    Fp=fopen(PATH[P],"r");
    //strcat(answer1,"");
   // printf("\n\n222");
    while (fgets(rbuffer,9998,Fp)){
        if (strcmp(rbuffer,"\n")==0){
            if(vflag==TRUE){
                zlocate=strlen(rtxt);
                break;
            }
            alocate=zlocate;
            strcpy(rtxt,"");
            
            nrtxt=0;

        } 
        else{
            strncpy(bbuffer,rbuffer,9996);
            strncat(rtxt,rbuffer,9998);
            nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(answer1,En)==0 && checkstr(bbuffer,"|",0,1)){
                strncpy(theline,bbuffer,9996);
                locate=nrtxt;
                vflag=TRUE;
            }
            strcpy(bbuffer,"");
           //  printf("\nEn:%s",En);
           //  printf("\nEN:%s",answer1);
        }
    }
    if(vflag==TRUE){
    if(rtxt[0]!='\0')
    //printf("\n%s",&rtxt[locate]);
    theline[strlen(theline)-1]='\0';
   /// printf("\n\n222");
    getlines(&rtxt[locate]);
    if(theline[0]!='\0')
    printf("\n%s",aprt(theline));
    //printf("\n%s",theline);
    fflush(stdout);
    }
    if(theline[0]!='\0'){
    break;
    }

}

   // fseek(fp,Max , SEEK_SET);
    NL=TRUE;
    strcpy(rtxt,"");
    strcpy(theline,"");
    vflag=FALSE;

}
else if (ysv1=='y' || ysv1=='Y'){
        if (flag!=TRUE){
    printf("\n%s",bword);
    fflush(stdout);
    }

for(P=0;P<p;P++){
    if(Fp!=NULL )
    fclose(Fp);
    Fp=fopen(PATH[P],"r");
   //printf("\n\n222");
    while (fgets(rbuffer,9998,Fp)){
        if (strcmp(rbuffer,"\n")!=0 && zlocate!=0){
            strncpy(bbuffer,rbuffer,9997);
            
            nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(answer1,En)==0 && checkstr(bbuffer,"|",0,1)){
                locate=nrtxt;
                clocate=locate-alocate;
                vflag=TRUE;
                strncpy(theline,bbuffer,9997);
                break;

        } 
            strncat(rtxt,bbuffer,9998);
            strcpy(bbuffer,"");
        }
        else
            {
                zlocate=1;
                alocate=strlen(rtxt);
                strcpy(rtxt,"");
                nrtxt=0;
            }
           //  printf("\nEn:%s",En);
           //  printf("\nEN:%s",answer1);
    }
    if(vflag==FALSE){
        strcpy(rtxt,"");
       //strcpy(rtxt,"");
    }
    if(vflag==TRUE)
    theline[strlen(theline)-1]='\0';
    if(rtxt[0]!='\0'){
    getlines(rtxt);
    }
    if(theline[0]!='\0')
    printf("\n%s",aprt(theline));
    fflush(stdout);
    NL=TRUE;
    if(theline[0]!='\0'){
    break;
    }
}
   // fseek(fp,Max , SEEK_SET);
       // fseek(Fp,max , SEEK_SET);
    strcpy(rbuffer,"");
    strcpy(bbuffer,"");
    strcpy(rtxt,"");
    strcpy(theline,"");
    vflag=FALSE;
  //  fseek(Fp,+max , SEEK_SET);

}

else if (ysv1=='S' || ysv1=='s' || ysv1=='\n' || ysv1=='\r'){
NL=FALSE;
if (ysv1=='S' || ysv1=='s')
ishprt("\r\033[%dC%s\r",col-2,eline);
if(flag==FALSE){
    printf("\n%s",bword);
    fflush(stdout);
}
}
strcpy(alltxt,"");
strcpy(word1,"");

if(PASS1==TRUE){
    if (ysv1=='S' || ysv1=='s' || ysv1=='V' || ysv1=='Y' ||  flag==TRUE){
        for (i=ran;i<=num;i++){
            nend[i]=nend[i+1];
        }
num--;
    }

        if(ysv1=='v' || ysv1=='V' || ysv1=='y' || ysv1=='Y' )
        printf("\n还有%d题",num);
}


if (CORRECT==TRUE){
    rrpp = fopen("CORRECT.txt", "r");
    
    strcpy(word1,answer1);
    strcat(word1,"\t\t");
    //printf("\n\n%s\n",word1);
    while (fgets(Buffer,4095,rrpp)){ 
            strncat(alltxt,Buffer,4095);
            if (Buffer[0]=='\\')
            non=TRUE;
           if(ze=='1' && non==FALSE){
           // if(checkstr(buffer,zh,1,strlen(zh))){
            //strcat(zh,"\t");
            for(i=0;i<strlen(word1)-1;i++){
            if(Buffer[i]==word1[i])
            continue;
            else {
//printf("%c",zh[i]);
//puts(&buffer[i]);
            //a=FALSE;
            break;
            }
            
            }
            if(i==strlen(word1)-1)
            rw=TRUE;

} 
           else if(ze=='2'  && non==FALSE){
            //strcat(en,"\t");
            for(i=0;i<strlen(word1)-1;i++){
            if(Buffer[i]==word1[i])
            continue;
            else{
            //a=FALSE;
            break;
            } 
            }
            if(i==strlen(word1)-1)
            rw=TRUE;

}
    }
    fclose(rrpp);
}



if (rw==TRUE && CORRECT==TRUE && flag==TRUE || rw==TRUE && CORRECT==TRUE &&  ysv1=='s' || rw==TRUE && CORRECT==TRUE && ysv1=='S' ){
    //printf("\n222\n");

    wfpn = fopen("CORRECT.txt", "a");
    fprintf(wfpn,"%s","\n\n\n\n\n");
    fclose(wfpn);
    rfpr = fopen("CORRECT.txt", "r");
    //strcpy(xtxt,"");
    while (fgets(rbuffer,9998,rfpr)  ){
        if ( checkstr(rbuffer,"\t",0,1)==TRUE  ){
            //printf("\n222");
            strncpy(tbuffer,rbuffer,398);
            strcpy(a,strtok(tbuffer,"\t"));

            //strcpy(b,strtok(NULL,"\t"));
            if(strcmp(a,answer1)==0){
                strcpy(tbuffer,"");
                strcpy(rbuffer,"");
                continue;
            }
                strncat(xtxt,rbuffer,9998);
            //printf("%s222",btxt);
        }
        else{
            if(rbuffer[0]=='\\'){
            strncat(xtxt,rbuffer,9998);
            strcpy(tbuffer,"");
            strcpy(rbuffer,"");
            continue;
            }
            if ( strcmp(rbuffer,"\n")!=0  ){
            strcpy(bbuffer,rbuffer);
            //printf("\n222");
            //printf("%s",bbuffer);
            //nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(answer1,En)==0 && checkstr(bbuffer,"|",1,1)){
               // locate=nrtxt;
               // clocate=locate-alocate;
                vflag=TRUE;
                //if(vflag==TRUE)
                //printf("%s",bbuffer);
                //strcpy(theline,bbuffer);
        } 
            //strncat(rtxt,bbuffer,999);
            strncat(btxt,bbuffer,9998);
            //del=btxt;
            strcpy(tbuffer,"");
            strcpy(rbuffer,"");
            strcpy(bbuffer,"");
        }
        else
            {
                //printf("\n222");
                //zlocate=1;
		if (vflag==TRUE){
                //strcpy(xtxt,"\n");
                strcat(xtxt,"\n");
                //del=NULL;
                //strcat(xtxt,btxt);
                vflag=FALSE;
                strcpy(tbuffer,"");
                strcpy(rbuffer,"");
                strcpy(bbuffer,"");
                strcpy(btxt,"");
		}
        else{
            if (btxt[0]!='\0' && strcmp(btxt,"")!=0){
            //printf("\n222");
            strcat(xtxt,btxt);
            strcat(xtxt,"\n");
            //printf("\n222%s",xtxt);
            //strcpy(btxt,"");
            }
            strcpy(tbuffer,"");
            strcpy(rbuffer,"");
            strcpy(bbuffer,"");
            strcpy(btxt,"");

        }
            //strcpy(del,"");
        }
    }
    }
    fclose(rfpr);
    //if(rtxt[0]!='\0'){
    //getlines(rtxt);
    //}
    //if(theline[0]!='\0')
    //printf("\n%s",rtxt);
    //strcpy(xtxt,"");
    //strcpy(xtxt,rtxt);
    //printf("\n%s",xtxt);
    //strcpy(rtxt,"");
    fflush(stdout);
    NL=TRUE;
    //fclose(rfpa);
    //fseek(fp,max , SEEK_SET);
    fseek(fp,Max , SEEK_SET); 
    //fclose(rfpr); 
   // fseek(Fp,max , SEEK_SET);  
}




else if (rw==FALSE && CORRECT==TRUE && flag!=TRUE && ysv1!='s' && ysv1!='S'){

for(P=0;P<p;P++){
yFp=fopen(PATH[P],"r");
    while (fgets(rbuffer,3998,yFp)){
        if (strcmp(rbuffer,"\n")!=0 ){
            strcpy(bbuffer,rbuffer);
            
            //nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(answer1,En)==0 && checkstr(bbuffer,"|",1,1)==TRUE){
                //locate=nrtxt;
                //clocate=locate-alocate;
                vflag=TRUE;
                //strcpy(theline,bbuffer);
                        } 
            strncat(rtxt,bbuffer,3998);
            strcpy(bbuffer,"");
        }
        else
            {
                //zlocate=1;
		if (vflag==TRUE){
                //strcpy(xtxt,"\n");
                
                strcpy(xtxt,rtxt);
                strcat(xtxt,"\n");
                strcpy(rtxt,"");
                //strcpy(tbuffer,"");
                strcpy(rbuffer,"");
                strcpy(bbuffer,"");
		//printf("%s",xtxt);
		    break;
		}
		else{
                alocate=strlen(rtxt);
                //strcpy(xtxt,rtxt);
		//printf("%s",xtxt);
                //strcpy(tbuffer,"");
                strcpy(rbuffer,"");
                strcpy(bbuffer,"");
                strcpy(rtxt,"");
                //nrtxt=0;
		}
            }
                strcpy(rbuffer,"");
                strcpy(bbuffer,"");
 }
    //if(rtxt[0]!='\0'){
    //getlines(rtxt);
    //}
    //if(theline[0]!='\0')
    //printf("\n%s",theline);
    fflush(stdout);
    NL=TRUE;
    //fseek(yFp,max , SEEK_SET);    
fclose(yFp);
		if (vflag==TRUE){
        break;
        }
}
}
return 0;
}
char bword[100];




  //  BOOL getin=FALSE;
//    int mi;
 //   char block;
//char yword[9999]; #ififiright

//char yword[9999];
//char xword; ezprintf()
char zword;
char backs[99]; //ezback
//BOOL waiting=FALSE; ezprintf()
int yi=-1;
//BOOL zd=FALSE;
BOOL bd=FALSE;
BOOL pd=FALSE;
BOOL ad=FALSE;

BOOL nd=TRUE;
//int si=0;
char a1[10][9999];

char czh[10][200];
int Read(){
int leng3;
int yn=0;
int i;
int M;
    int N;
    int I;
while(TRUE){
    leng3=strlen(aword);
    setitimer(ITIMER_REAL,&value0,NULL);
if( getin==TRUE && bd==FALSE){
    //setitimer(ITIMER_REAL,&value0,NULL);
    //printf("2222");
    //strcpy(yword,"");
//nd=FALSE;
    //continue;
}

//printf("%c",zword);

if (waiting==FALSE){
   // setvbuf(stdout, NULL, _IOLBF, 512);
    //printf("g");
    fflush(stdin);
    if(getin==FALSE){
        zword=rd(fd1);
       // nd=FALSE;
        pd=TRUE;
        //if (zword=='\x00')
        //continue;
            //zword=rd(fd1);
    //printf("p");
   //setitimer(ITIMER_REAL,&evalue,NULL);
    zd=TRUE;
    }
    //waiting=FALSE;
}



    //waiting=FALSE;
//printf("%d %d",yn,yi);
//setitimer(ITIMER_REAL,&evalue,NULL);
if (zd==TRUE){
ad=FALSE;

                if(zword == '\r' || zword == '\n' ){
waiting=FALSE;
strcpy(yword,"");
getin=FALSE;
//strcpy(aword,"");
yi=-1;
zd=FALSE;
pd=FALSE;
xword='\x00';
fflush(stdin);
break;
                }


if( zword=='\x06' && getin==FALSE ){
findword(answer1,en,txt);
            if(ez=='1'){
                strcpy(yword,"");
                yword[0]='\0';
                //printf("%s\n",answer1);
            for(si=0;si<strlen(answer1);si++){
                yword[si]='-';
                yword[si+strlen(answer1)]='\x7f';
                yword[si+strlen(answer1)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                zd=FALSE;
                waiting=TRUE;
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            else{
            //getin=FALSE;

waiting=FALSE;
            }
            leng=-1;
strcpy(cword,"");
strcpy(aword,"");
int yn=0;
//free(yword);
zword='\x00';
yi=-1;
bd=FALSE;
pd=FALSE;
ad=FALSE;
zd=FALSE;
//nd=FALSE;
bk=FALSE;
c=0;
continue;
}

else if (getin!=TRUE && waiting!=TRUE ){
//setitimer(ITIMER_REAL,&evalue,NULL);
strncat(yword,&zword,1);
if(strcmp(yword,"\x7f")==0)

//setitimer(ITIMER_REAL,&evalue,NULL);
zd=FALSE;
//bd=TRUE;
waiting=TRUE;
}
//setitimer(ITIMER_REAL,&evalue,NULL);
//zd=FALSE;
//zword='\x00';

}

if(bd!=TRUE && strcmp(yword,"\x7f")!=0 && strlen(yword)==1 && pd==TRUE ){
   // printf("2222");
setitimer(ITIMER_REAL,&evalue,NULL);
}
else{
    setitimer(ITIMER_REAL,&value0,NULL);

}

//printf("1");
if( strcmp(yword,"")!=0 && getin==FALSE ){
bd=TRUE;
}

while (getin==FALSE && pd==TRUE && zd==TRUE){
if( strcmp(yword,"\t")==0 ){
    //bd=FALSE;
setitimer(ITIMER_REAL,&evalue0,NULL);
//continue;
}
setvbuf(stdout, NULL, _IONBF, 1);
//setitimer(ITIMER_REAL,&evalue,NULL);
//setvbuf(stdout, NULL, _IONBF, 1);
fgets(&xword,2,stdin);
//if(getin==FALSE)
setvbuf(stdout, NULL, _IOLBF, 512);
//xword=readword(fd1);

//setitimer(ITIMER_REAL,&value0,NULL);

    if (xword=='R' && ad==TRUE ){
//waiting=TRUE;
ad=FALSE;
//zd=FALSE;
continue;
//waiting=FALSE;
}
if((int)xword+add<=25)
	continue;
if(ad==TRUE)
	continue;
if( xword=='\x5b' ){
    //waiting=FALSE;
    ad=TRUE;
    continue;
}


if (xword=='\x1b' ){
 //setitimer(ITIMER_REAL,&value0,NULL);
fflush(stdin);

//zd=FALSE;
yn=0;
yi=-1;
//setvbuf(stdout, NULL, _IOLBF, 512);
if (bd==FALSE){
waiting=TRUE;
pd=FALSE;
zd=FALSE;
//ad=TRUE;
//printf("2");
}
else{
    zd=TRUE;
   waiting=TRUE; 
}
//setvbuf(stdin, NULL, _IOLBF, 512);
//zd=FALSE;

//printf("3");
pd=FALSE;
    break;

}

else{

  //  nd=FALSE;
    setitimer(ITIMER_REAL,&value0,NULL);
    bd=TRUE;
   //printf("22222");
    //waiting=TRUE;
    strncat(yword,&xword,1);
//yn=strlen(yword);

if(strlen(yword)==2) {
    nd=FALSE;
    setitimer(ITIMER_REAL,&value0,NULL);

}

    if(nd==FALSE){
       // printf("3");
        
          fprintf(stdout,"%s","\033[6n");
          fflush(stdout);

    nd=TRUE;
    }



    continue;

}

}
//nd=FALSE;
yn=strlen(yword);

//printf("%d\n",yn);

//setitimer(ITIMER_REAL,&value0,NULL);
fflush(stdin);


/*
else if(waiting==TRUE && yn==yi-1){
waiting=FALSE;
strcpy(yword,"");
yi=-1;
zd=FALSE;
xword='\x00';
fflush(stdin);
}*/


//yn=strlen(yword);
//printf("%s",yword);


//printf("%d",yi);
if(waiting==TRUE && ( bd==TRUE || getin==TRUE )  ){
   // printf("%d",yi);
    //waiting=TRUE;
    yi=yi+1;
    zword=yword[yi];
    //yi=yi+1;
    //yword[yi]='\x00';
}
else if(waiting==TRUE && zd==FALSE){
yi=1;
//printf("%c",zword);
}
//else if (bd!=TRUE)
//printf("%d",yi);

if (waiting==TRUE || getin==TRUE){

//printf("%s",yword);
if( strcmp(yword,"\t\t")==0 || strcmp(yword,"\t")==0 ){
//printf("2222");
//strcpy(yword,"");
if (ez=='1'){
    for(i=0;i<=strlen(aword);i++){
        if(answer1[i]==aword[i]){
            continue;
        }
        else if(aword[i]=='\x00' && answer1[i]!=aword[i]){
            zword=answer1[i];
            strncpy(yword,&answer1[i],1);
             nd=TRUE;
                break;
        }
        else
        break;
    }
}
else if (ez=='2'){
    N=0;
    for (I=0;I<10;I++){
        strcpy(czh[I],"");
        if(strcmp(azh[I],"")!=0){
            strcpy(czh[N],azh[I]);
            N++;
        }
    }

    srand((unsigned)time(NULL));
    if(N>0){
    M=rand()%(N);

    strcpy(yword," ");
    strcat(yword,czh[M]);
nd=TRUE;

    }
}
//getin=TRUE;
nd=TRUE;
//pd=FALSE;
//continue;
}


//printf("%d",leng3);
 leng=words(aword);
leng3=strlen(aword);
            if(zword == '\x7f' ){
                    //zword='\x00';
                    bk=TRUE;  
//printf("%d",leng3);
strcpy(backs,"");
                    //printf("%d",leng3);
                    ascii=FALSE;
/*if(leng==0 && getin==TRUE){
    //waiting=FALSE;
    getin=FALSE;
    zd=FALSE;
    //strcpy(yword,"");
    continue;
}*/
                    //      
                    if(isascii(aword[leng3-1])  && leng > 0){
                        if(leng3<=strlen(answer1) && ez=='1'){
                        block='-';
                        strcpy(backs,"\b-\b");
                        }
                        else{
                        strcpy(backs,"\b \b");
                        block=' ';
                        }
                        bk=TRUE; 
                        ezback();
                        aword[leng3-1]='\0';
                        //leng=leng-1;
                        //ezback();
                        //printf("\b%c\b",block);
                        fflush(stdout);
                        continue;
                    }
                  //  printf("%d\n",(int)aword[leng3-3]);

            else if((int)aword[leng3-2]+add>=128 && (int)aword[leng3-3]+add>=227  && (int)aword[leng3-3]+add<=239  && leng3 > 0){
                        
                        bk=TRUE;  
                        strcpy(backs,"\b\b  \b\b");
                        ezback();
                        aword[leng3-3]='\0';
                        aword[leng3-2]='\0';
                        aword[leng3-1]='\0';
                        //fflush(stdout);      
                        //ezback();
                    }
                    else{
    
    //zd=FALSE;
   //waiting=FALSE;
if(leng==0 && bk==TRUE){
    bk=FALSE;
   // zd=FALSE;
    //continue;
}
    //getin=FALSE;    


                    }
                    zword='\x00';
                    //setvbuf(stdout, NULL, _IONBF, 1);
                    //fprintf(stdout,"%s",backs);
                    continue;
                
                
                
                }


else if(zword!='\x1b' && zword!='\x00'  && (int)zword+add>=12 ){
//fprintf(stdout,"%c",zword);
//strncat(aword,&zword,1);
bk=FALSE;
if(ezprintf()==2)
{
    nd=TRUE;
//pd=FALSE;
//bd=TRUE;
//yn=strlen(yword);
//continue;
}
//setvbuf(stdout, NULL, _IONBF, 1);
fflush(stdout);
bk=FALSE;

}
//printf("%d",yn);

        if (yn==yi){
    //setitimer(ITIMER_REAL,&value0,NULL);
          //  printf("2222");
if(getin==FALSE)
bd=FALSE;

            getin=FALSE;
  //  printf("\n%d\n%d",yn,yi);
waiting=FALSE;
//zword='\x00';
//free(yword);
strcpy(yword,"");
yi=-1;
//zd=FALSE;
zd=FALSE;
ad=FALSE;
pd=FALSE;
nd=TRUE;
//bd=FALSE;
//bd=FALSE;
///bk=FALSE;
xword='\x00';
//bd=FALSE;
//pd=FALSE;
fflush(stdin);
if( bk==FALSE && ififright(aword)==2){
    //printf("222");
waiting=TRUE;
//getin=TRUE;
bd=TRUE;
zd=TRUE;
nd=TRUE;
}

bk=FALSE;
if(flag==TRUE)
break;
 //printf("22222");
        }

}   
}
return 0;
}
char ch[200];
int colourp(){
            //colm=-1;
            //coln=-2;
                if(ez=='1'){
                if (flag != TRUE ){
                if(strcmp(aword,"")==0){
                    ishprt("\r\033[%dC%s\r",col-2,nline);
                    fflush(stdout);
                    ysv(bword,ez);
                }
                else if(strcmp(aword,answer1)==0){
                    ishprt("\r\033[%dC%s\r",col-2,tline);
                    fflush(stdout);
                    ysv(bword,ez);
                }
                else{
                //fflush(stdin);
                ishprt("\r\033[%dC%s\r",col-2,fline);
                fflush(stdout);
                ysv(bword,ez); 
                //printf("\n%s",bword);
                //fflush(stdout);
                } 
                }
                else{
                    ysv(bword,ez);
                }
            }
            if(ez=='2'){
                if (flag != TRUE ){
                if(strcmp(aword,"")==0){
                    ishprt("\r\033[%dC%s\r",col-2,nline);
                    fflush(stdout);
                    ysv(bword,ez);
                }
else if (ifRight()==TRUE){
    ishprt("\r\033[%dC%s\r",col-2,tline);
    fflush(stdout);
    ysv(bword,ez);
} 
else{
    ishprt("\r\033[%dC%s\r",col-2,fline);
    fflush(stdout);
    ysv(bword,ez);
}
                 } 
                else
                 ysv(bword,ez);
                
            }

         
                fflush(stdin);
                if(CORRECT==TRUE)
                rwfp(answer1,ch,ez,flag);
                fflush(stdin); 

return 0;
}

void my_exit()
{
    //tcgetattr(0,&init_setting);
    tcsetattr(0,TCSANOW,&init_setting);
printf("\033[?25h\n");
    exit(0);
}

int fun(){
    evalue.it_value.tv_sec=0;
    evalue.it_value.tv_usec=15000;
    evalue.it_interval.tv_sec=0;
    evalue.it_interval.tv_usec=0;

    evalue0.it_value.tv_sec=0;
    evalue0.it_value.tv_usec=300000;
    evalue0.it_interval.tv_sec=0;
    evalue0.it_interval.tv_usec=0;

    int ywordi;
  //  yword=(char *)malloc(9999);
  //  int leng3; Read()
//    struct itimerval evalue, evalue0;

    int max;
    max=strlen(txt);
    //char aword[200];
    char ii[200];
   // int i;
//    char order;
//    int max;
    int addmax;
    //int ifright;
 //   char bword[100]; //ifright()
   // char zword;
    //char zwords[199];
   // int xword;
    int rx=0;
    int ab=0;
//    char azh[10][100];
//    char bzh[10][100];
  //  int aii=0;
//    int iii=0;
 //   char ch[200];
   // int n;
    //BOOL flag = FALSE;
    BOOL iez;

    //int leng;
    //int tleng;
    int zhleng;
    int m=0;
    int mm=0;
    int mmm=0;
    int cmmm=0;
    int acount;
  //  int z;
    char * dzh;
    //char temp[200];
    //char ltemp[200];
    char word[200];



    int aii;
    int i;
    int n;
    int z;
printf("\r\033[K1,中译英\033[%dC2,英译中\033[%dC3,混合:",col/2-12,col/2-12);
    fflush(stdout);
    while ((ez=getchar())!='\n' && ez!='1' && ez!='2' && ez!='3' ){
        continue;
    }	
    printf("%c",ez);
    fflush(stdout); 
    /*fflush(stdout);*/
    printf("\n1,顺序\033[%dC2,倒序\033[%dC3,乱序:",col/2-10,col/2-10);
    fflush(stdout);


    while ((order=getchar())!='\n' && order!='1' && order!='2' && order!='3' ){
        continue;
    }
    printf("%c",order);
    fflush(stdout);

    if(order=='3'){
        int n=-1;
       num=0;
       // int nend[9999];
        
	    i=-1;
        while (i++,i<max){
	/*printf("%d",i);*/
        /***printf("%c",txt[i]);***/

        if(txt[i]=='\n'){
            num++;
            nend[num]=i;
            /*printf("%d\n",i);*/           
        }
            
        }

        nend[0]=-1;
nend[num+1]=max;
      //  int ran;
    srand((unsigned)time(NULL));
	while (TRUE){
        
        if(PASS1==TRUE){
            if(num==0){
                printf("\n过关了！");
                return 0;
            }
        }

        ci=0;
        strcpy(astrs,"");
        //strcpy(word,"");
        //zword='\0';
        iii=0;

        getin=FALSE;
        
        rx++;
        ran=rand() % num;
        n=nend[ran];
        /*printf("%d",nend[ran]);*/    
        strcpy(word,"");
	if(n==0)
            strncat(word,&txt[0],1);
            while (n++,n<nend[ran+1]){
                if(txt[n]=='\n'){
                    break;
                }
                strncat(word,&txt[n],1);
            }
        
            puts("");
	    zh="\0";
	    en="\0";
        printf("\033[2m%s\n\033[0m",strs);
        fflush(stdout);
	    if(ez=='3'||iez==TRUE){
	    iez=TRUE;   
            //srand((unsigned)time(NULL));
            //ab++;
	    ez=rand()%2+49;
	    /*ez=iez+48;*/
	    /*printf("%c",ez);*/ 
		}
        acount=0;
	    if(ez=='1'){
            zh=strtok(word,"\t");
            /*del_char(zh,'\01');*/
	    /*del_char(zh,'\0');*/
	        en=strtok(NULL,"\t");
            strcpy(answer1,zh);
            strcpy(ch,en);
            
            for(n=0;n<10;n=n+1){
            strcpy(bzh[n],"");
            strcpy(azh[n],"");
            }         
            }
    
        else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(ch,zh);
            strcpy(answer1,en);
            m=-1;
            mm=0;
            mmm=0;
            zhleng=0;
            zhleng=strlen(zh);
            /*strcpy(azh[0],"");
            strcpy(azh[1],"");
            strcpy(azh[2],"");
            strcpy(azh[3],"");
            strcpy(azh[4],"");
            strcpy(azh[5],"");
            strcpy(azh[6],"");*/
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
                strcpy(w1[n],"");
                strcpy(czh[n],"");
            }


            for(n=0;n<10;n=n+1){
                /*printf("%d\n",zhleng);*/
                cmmm=0;
                mmm=m;
                m=m+2+cmmm;
                while(m=m+1,m<=zhleng){
                    if(ch[m]=='\xef' && ch[m+1]=='\xbc' && ch[m+2]=='\x8c' ||  ch[m]=='\0'  ){
                        cmmm=m-mmm-3;
                        if(n==0){
                        dzh=&ch[mmm+1];
                        cmmm=cmmm+2;
                        }
                        else
                        dzh=&ch[mmm+3];
                        strncat(azh[n],dzh,cmmm);
                        strncat(bzh[n],dzh,cmmm);
                        break;
                    }
                }
                if(ch[m]=='\0' )
                break;
                /*strcpy(azh[n],strtok(ch,"\xbc\xef"));*/
            }

            /*printf("\n%s\n",azh[0]);
            printf("\n%s\n",azh[1]);
            printf("\n%s\n",azh[2]);*/
            zm=n;
            }
            printf("\r\033[1m%s\033[0m\033[2m \033[3m<───> \033[0m",en);

            //cursor_position(&rown,&coln);
            cursor_position(&rowm,&colm);
            /***puts(en);***/
            strcpy(bword,"");
            if (ish==TRUE){
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
            if(fresh(bword)!=-1)
                strcpy(bword,"~");
            else
                strcpy(bword,"");
            }
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,"\033[1m");
            strcat(bword,zh);
            strcat(bword,"\033[0m");
            
            /*word[0]='\0';*/
            fflush(stdout);
            /***fgets(aword,2,stdin);***/
            aword[0]='\0';
            zword='\0';
            tleng=0;
            leng=0;
            strcpy(temp,"");
            fflush(stdin);
            flag = FALSE;
            iii=0;

            //strcpy(temp,"");
            strcpy(ltemp,"");
            aii=0;
            //backed=FALSE;

            if(ez=='1'){
                strcpy(yword,"");
                yword[0]='\0';
                //printf("%s\n",answer1);
            for(si=0;si<strlen(answer1);si++){
                yword[si]='-';
                yword[si+strlen(answer1)]='\x7f';
                yword[si+strlen(answer1)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                zd=FALSE;
                waiting=TRUE;
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            else{
            //getin=FALSE;

waiting=FALSE;
            }
            leng=-1;
strcpy(cword,"");
int yn=0;
//free(yword);
zword='\x00';
yi=-1;
bd=FALSE;
pd=FALSE;
ad=FALSE;
zd=FALSE;
//nd=FALSE;
bk=FALSE;
c=0;
        
                    //fflush(stdout);
Read() ;                   
colourp();               
                    /***printf("%d",xword);***/ 
    }
            }

    else if(order=='2'){
i=-1;
	//i=-1;
    fflush(stdin);
    strcpy(word,"");
    num=0;
     //srand((unsigned)time(NULL));
        while (i++,i<max-1){
	/*printf("%d",i);*/
       // printf("%c",txt[i]);

        if( txt[i]=='\n'){
            num++;
            nend[num]=i;
            //printf("%d\n",i);      
        }
            
        }
        nend[0]=-1;
        nend[num+1]=max;
ran=num+1;
//strcpy(word,"");
while (TRUE){
//printf("@22");
 ran--;
	if(ran==-1){
        ran=num;
    }

            for (n=nend[ran]+1;n<nend[ran+1];n++){
                if(txt[n]=='\n'){
                    break;
                }
strncat(word,&txt[n],1);
            }
            //printf("%s",word);

                if(PASS1==TRUE){
            if(num==-1){
                printf("\n过关了！");
                return 0;
            }
        }

       // if(i==0 | txt[i]=='\n'){
	    /*printf("%d",i);*/
            puts("");
            /*printf("%s",word);*/
	    zh="\0";
	    en="\0";
        printf("\033[2m%s\n\033[0m",strs);
	    if(ez=='3'||iez==TRUE){
	    iez=TRUE;   
            //srand(times * (ab+1) * (ab+1));
            ab++;
	    ez=rand()%2+49;
	    /*ez=iez+48;*/
	    /*printf("%c",ez);*/ 
		}
        acount=0;
	    if(ez=='1'){
            zh=strtok(word,"\t");
            /*del_char(zh,'\01');*/
	    /*del_char(zh,'\0');*/
	        en=strtok(NULL,"\t");
            strcpy(answer1,zh);
            strcpy(ch,en);
            for(n=0;n<10;n=n+1){
            strcpy(bzh[n],"");
            strcpy(azh[n],"");
            } 
            
            }

            else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(answer1,en);
            strcpy(ch,zh);
            for(n=0;n<10;n=n+1){
            strcpy(bzh[n],"");
            strcpy(azh[n],"");
            } 
            }
            flag=FALSE;
            getin=FALSE;
            acount=0;
            m=-1;
            mm=0;
            mmm=0;
            zhleng=0;
            zhleng=strlen(zh);
            //strcpy(azh[1],"");
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
                strcpy(w1[n],"");
                strcpy(czh[n],"");
            }
            for(n=0;n<10;n=n+1){
                /*printf("%d\n",zhleng);*/
                cmmm=0;
                mmm=m;
                m=m+2+cmmm;
                strcpy(w1[n],"");
                while(m=m+1,m<=zhleng){
                    if(ch[m]=='\xef' && ch[m+1]=='\xbc' && ch[m+2]=='\x8c' ||  ch[m]=='\0'  ){
                        cmmm=m-mmm-3;
                        if(n==0){
                        dzh=&ch[mmm+1];
                        cmmm=cmmm+2;
                        }
                        else
                        dzh=&ch[mmm+3];
                        strncat(azh[n],dzh,cmmm);
                        break;
                    }
                }
                if(ch[m]=='\0' )
                break;
                /*strcpy(azh[n],strtok(ch,"\xbc\xef"));*/
            }
            zm=n;
            /*printf("%s\n",azh[0]);*/
            printf("\r\033[1m%s\033[0m\033[2m \033[3m<───> \033[0m",en);
            /***puts(en);***/

            cursor_position(&rowm,&colm);
            strcpy(bword,"");
            if (ish==TRUE){
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
            if(fresh(bword)!=-1)
                strcpy(bword,"~");
            else
                strcpy(bword,"");
            }
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,"\033[1m");
            strcat(bword,zh);
            strcat(bword,"\033[0m");
            /*word[0]='\0'; */
            /*memset(word,0,sizeof word); */
            /*printf("%s",word);*/
            fflush(stdout);
            /***fgets(aword,2,stdin);***/
            aword[0]='\0';
            strcpy(word,"");
            zword='\0';
            strcpy(ii,"");
            tleng=0;
            leng=0; 
        acount=0;       
            /***if (fgets(aword,2,stdin) != '\0'){*///

             aii=0;  /*** if ((xword = getchar()) != '\n') { ***/
                  /***   strncat(aword,&xword,1); ***/
            if(ez=='1'){
                strcpy(yword,"");
                yword[0]='\0';
                //printf("%s\n",answer1);
            for(si=0;si<strlen(answer1);si++){
                yword[si]='-';
                yword[si+strlen(answer1)]='\x7f';
                yword[si+strlen(answer1)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                zd=FALSE;
                waiting=TRUE;
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            else{
            //getin=FALSE;

waiting=FALSE;
            }
            leng=-1;
strcpy(cword,"");
int yn=0;
//free(yword);
zword='\x00';
yi=-1;
bd=FALSE;
pd=FALSE;
ad=FALSE;
zd=FALSE;
//nd=FALSE;
bk=FALSE;
c=0;

Read();
colourp(); 
}

    
    }
    //return(0);
        

    else if(order=='1'){
        //flag=FALSE;
        //int n=-1;
        strcpy(word,"");
        fflush(stdin);
        i=-1;
        num=0;
        //n=-1;
         srand((unsigned)time(NULL));

        while (i++,i<max-1){
	/*printf("%d",i);*/
      // printf("%c",txt[i]);

        if(txt[i]=='\n'  ){
            num++;
            nend[num]=i;
            //printf("%d\n",i);      
        }
            
        }
nend[0]=-1;
nend[num+1]=max;
ran=-1;
while (TRUE){
if ( ysv1!='S' && ysv1!='s'  && flag==FALSE ){
    ran++;
}
	if(ran==num+1){
        ran=0;
    } 
          
            for (n=nend[ran]+1;n<nend[ran+1];n++){
                if(txt[n]=='\n'){
                    break;
                }
strncat(word,&txt[n],1);
            }
            //printf("%s",word);
  
                if(PASS1==TRUE){
            if(num==-1){
                printf("\n过关了！");
                return 0;
            }
        }
           // puts("");
   // if(i==0 | txt[i]=='\n'){
	    zh="\0";
	    en="\0";
            ci=0;
            //strcpy(astrs,"");
            iii=0;
            
            //getin=FALSE;
	    if(ez=='3'||iez==TRUE){
	    iez=TRUE;   
            //srand(times * (ab+1) * (ab+1));
            //ab++;
	    ez=rand()%2+49;
	    /*ez=iez+48;*/
	    /*printf("%c",ez);*/ 
		}
        acount=0;
        flag=FALSE;
        getin=FALSE;
	    if(ez=='1'){
            zh=strtok(word,"\t");
            /*del_char(zh,'\01');*/
	    /*del_char(zh,'\0');*/
	        en=strtok(NULL,"\t");
            strcpy(answer1,zh);
            strcpy(ch,en);


            }

            else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(answer1,en);
            strcpy(ch,zh);
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
            } 
            }
            m=-1;
            mm=0;
            mmm=0;
            zhleng=0;
            zhleng=strlen(zh);
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
                strcpy(w1[n],"");
                strcpy(czh[n],"");
            }
            for(n=0;n<10;n=n+1){
                /*printf("%d\n",zhleng);*/
                cmmm=0;
                mmm=m;
                m=m+2+cmmm;
                while(m=m+1,m<=zhleng){
                    if(ch[m]=='\xef' && ch[m+1]=='\xbc' && ch[m+2]=='\x8c' ||  ch[m]=='\0'  ){
                        cmmm=m-mmm-3;
                        if(n==0){
                        dzh=&ch[mmm+1];
                        cmmm=cmmm+2;
                        }
                        else
                        dzh=&ch[mmm+3];
                        strncat(azh[n],dzh,cmmm);
                        break;
                    }
                }

                if(ch[m]=='\0' )
                break;
                /*strcpy(azh[n],strtok(ch,"\xbc\xef"));*/
            }
            zm=n;
            /*printf("%s\n",azh[0]);*/
            printf("\n\033[2m%s\n\033[0m",strs);
            printf("\r\033[1m%s\033[0m\033[2m \033[3m<───> \033[0m",en);
            /***puts(en);***/
            cursor_position(&rowm,&colm);
            strcpy(bword,"");
            if (ish==TRUE){
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
            if(fresh(bword)!=-1)
                strcpy(bword,"~");
            else
                strcpy(bword,"");
            }
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,"\033[1m");
            strcat(bword,zh);
            strcat(bword,"\033[0m");
            
            fflush(stdout);
            /***fgets(aword,2,stdin);***/
            
            strcpy(word,"");
            aword[0]='\0';
            zword='\0';
            /*system("stty -icanon");*/
            /***if (fgets(aword,2,stdin) != '\0'){*///
            leng=0;
            tleng=0;
            aii=0;   /*** if ((xword = getchar()) != '\n') { ***/
                  /***   strncat(aword,&xword,1); ***/
            tleng=0;
            leng=0;        
            /***if (fgets(aword,2,stdin) != '\0'){*///

             aii=0;  /*** if ((xword = getchar()) != '\n') { ***/
                  /***   strncat(aword,&xword,1); ***/
            if(ez=='1'){
                strcpy(yword,"");
                yword[0]='\0';
                //printf("%s\n",answer1);
            for(si=0;si<strlen(answer1);si++){
                yword[si]='-';
                yword[si+strlen(answer1)]='\x7f';
                yword[si+strlen(answer1)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                zd=FALSE;
                waiting=TRUE;
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            else{
            //getin=FALSE;

waiting=FALSE;
            }
            leng=-1;
strcpy(cword,"");
int yn=0;
//free(yword);
zword='\x00';
yi=-1;
bd=FALSE;
pd=FALSE;
ad=FALSE;
zd=FALSE;
//nd=FALSE;
bk=FALSE;
c=0;
Read();
colourp();
}

    
    }
return 0;
    }
int main(int argc, char *argv[]){
int arga;
	while ((arga = getopt(argc, argv, ":irp")) != -1) {
		switch (arga) {
			case 'r': printf("错题集模式\n");fflush(stdout);CORRECT=TRUE; break;
			case 'i': printf("优化ish\n");fflush(stdout);ish=TRUE;termux=TRUE; break;
            case 'p': printf("通关模式\n");fflush(stdout);PASS1=TRUE; break;			
		}
	}

	if(signal(SIGALRM,handler) == SIG_ERR){  //信号注册函数
    perror("signal");

    exit(-1);

      }

	if(signal(SIGINT,my_exit) == SIG_ERR){  //信号注册函数
    perror("signal");
    exit(-1);
      }

atexit(my_exit);
xtxt=(char *)malloc(8999999);
alltxt=(char *)malloc(8999999); 

    struct termios new_setting;
    struct termios new_settingback;
    tcgetattr(0,&init_setting);
    //tcgetattr(0,&new_settingback);
    new_setting=init_setting;
    new_setting.c_cflag&=~CREAD;
    new_setting.c_lflag&=~ECHO; 
    new_setting.c_lflag&=~ICANON; 
    tcsetattr(0,TCSANOW,&new_setting);

    calendar();
    getfromread();
   // loadcontent();
   printf("\033[?25l");
    fun();
    return 0;
}
