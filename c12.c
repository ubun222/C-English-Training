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
/***#include<conio.h>***/
/***#include<curses.h>***/
#define BOOL int
#define TRUE 1
#define FALSE 0

#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |S_IWOTH)

int fd1;
struct termios init_setting;
void my_exit(void)
{
	printf("\033[?25h\nbefore exit () !\n");
    tcgetattr(0,&init_setting);
    /*system("stty -icanon");*/
}


#define   RD_EOF   -1
#define   RD_EIO   -2





/* Return a new file descriptor to the current TTY.
*/
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

static inline int rd(const int Fd)
{
    unsigned char   buffer[4];
    ssize_t         n;

    while (1) {
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
struct itimerval value, value0;
int cursor_position(int *const Row ,int *const Col)
{
    
    value.it_value.tv_sec=0;
    value.it_value.tv_usec=100000;
    value.it_interval.tv_sec=0;
    value.it_interval.tv_usec=100000;

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
printf("\033[6n");
//fflush(stdout);
//f=ftell(stdout);
//printf("%d",f);
    //printf("%d",lf);
    //printf("%d",f);
    fflush(stdout);

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
while(((result = rd(fd1))!='R'))
{
    //ualarm(0,0);
    setitimer(ITIMER_REAL,&value0,NULL);
    //if(result==-1 || result==-2)
    //return 2;
if((int)result>=48 && (int)result<=57 || (int)result==59){
    if ((int)result==59){
    retry++;
    continue;
    }
    if(retry==0){
if (result >= '0' && result <= '9') {
    a = 10 * a + result - '0';
        }
    }
    if(retry==1){
    //strncat(b,&result,1);
if (result >= '0' && result <= '9') {
    b = 10 * b + result - '0';
        }    
    }
}
}
//ualarm(0,0);
setitimer(ITIMER_REAL,&value0,NULL);
//printf("22222");
//printf("s:%s",receives);
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

int ifre(int a1[4],int  b ){
    int l;
    BOOL F;
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

char ysv1;
int getlines(char * string){
    int i;
    int n=strlen(string);
    int l=1;
    int ni[50];
    char strings[999999];
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
    
    i=0;
    while(i<=3){
    if (l<4){
        for(m=0;m<4;m++){
            if(aline[m][0]!='\0')
        printf("%c  %s",aline[m][0],&aline[m][1]);
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
    printf("%c  %s",aline[ran][0],&aline[ran][1]);
    i++;
    }
    else{
        
        continue;
    }
    }
    }

    return l;
}
BOOL CORRECT;
char * en;
char * zh;
char ez;
//char xbuffer[200];
FILE * fp;
FILE * rfp;
FILE * rfpa;
//FILE rfpc;
char EN[200];
int max;
BOOL NL;
char * xtxt;
//xtxt=(char *)malloc(3000010);
char *  alltxt;
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

if (ifrw==FALSE && rw==FALSE && ysv1!='s' && ysv1!='S' ){
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

FILE * rfpr;
FILE * Fp;
char path[200];

int row;
int col;

int ysv(char flag,char * bword,char ze){
char eline[]="\033[32m○\033[0m";
char rbuffer[4000];
char rtxt[299999];
char btxt[299999];
int nrtxt;
int alocate=0;
int locate;
int zlocate=0;
int clocate=0;
char En[200];
char a[200];
char tbuffer[399];
char theline[4000];
char bbuffer[4001];
//char * del;
BOOL vflag=FALSE;
BOOL aflag=FALSE;
BOOL llocate=FALSE;
FILE * yFp;
FILE * wfpn;
char word1[101];
char Buffer[2048];
FILE * rrpp;
int i;
rw=FALSE;
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
    Fp=fopen(path,"r");
    //strcat(EN,"");
   // printf("\n\n222");
    while (fgets(rbuffer,3999,Fp)){
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
            strcpy(bbuffer,rbuffer);
            strncat(rtxt,rbuffer,3999);
            nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(EN,En)==0 && checkstr(bbuffer,"|",1,1)){
                strcpy(theline,bbuffer);
                locate=nrtxt;
                vflag=TRUE;
            }
            strcpy(bbuffer,"");
           //  printf("\nEn:%s",En);
           //  printf("\nEN:%s",EN);
        }
    }
    if(vflag==TRUE){
    if(rtxt[0]!='\0')
    //printf("\n%s",&rtxt[locate]);
    theline[strlen(theline)-1]='\0';
    getlines(&rtxt[locate]);
    if(theline[0]!='\0')
    printf("\n%s",theline);
    fflush(stdout);
    }
    if (flag!=TRUE){
    printf("\n%s",bword);
    fflush(stdout);
    }
    fseek(fp,max , SEEK_SET);
    NL=TRUE;
    strcpy(rtxt,"");
    strcpy(theline,"");
    vflag=FALSE;
}

else if (ysv1=='y' || ysv1=='Y'){
    Fp=fopen(path,"r");
   // printf("\n\n222");
    while (fgets(rbuffer,3999,Fp)){
        if (strcmp(rbuffer,"\n")!=0 && zlocate!=0){
            strcpy(bbuffer,rbuffer);
            
            nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(EN,En)==0 && checkstr(bbuffer,"|",1,1)){
                locate=nrtxt;
                clocate=locate-alocate;
                vflag=TRUE;
                strcpy(theline,bbuffer);
                break;

        } 
            strncat(rtxt,bbuffer,999);
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
           //  printf("\nEN:%s",EN);
    }
    if(vflag==TRUE)
    theline[strlen(theline)-1]='\0';
    if(rtxt[0]!='\0'){
    getlines(rtxt);
    }
    if(theline[0]!='\0')
    printf("\n%s",theline);
    fflush(stdout);
    NL=TRUE;
    if (flag!=TRUE){
    printf("\n%s",bword);
    fflush(stdout);
    }
    fseek(fp,max , SEEK_SET);
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
printf("\033[%dC%s\r",col,eline);

if(flag==FALSE){
    printf("\n%s",bword);
    fflush(stdout);
}
}
strcpy(alltxt,"");
strcpy(word1,"");
if (CORRECT==TRUE){
    rrpp = fopen("CORRECT.txt", "r");
    
    strcpy(word1,EN);
    strcat(word1,"\t\t");
    //printf("\n\n%s\n",word1);
    while (fgets(Buffer,2047,rrpp)){ 
            strncat(alltxt,Buffer,2047);
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
    while (fgets(rbuffer,3999,rfpr)  ){
        if ( checkstr(rbuffer,"\t",0,1)==TRUE  ){
            //printf("\n222");
            strncpy(tbuffer,rbuffer,398);
            strcpy(a,strtok(tbuffer,"\t"));

            //strcpy(b,strtok(NULL,"\t"));
            if(strcmp(a,EN)==0){
                strcpy(tbuffer,"");
                strcpy(rbuffer,"");
                continue;
            }
                strncat(xtxt,rbuffer,399);
            //printf("%s222",btxt);
        }
        else{
            if(rbuffer[0]=='\\'){
            strncat(xtxt,rbuffer,399);
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
            if(strcmp(EN,En)==0 && checkstr(bbuffer,"|",1,1)){
               // locate=nrtxt;
               // clocate=locate-alocate;
                vflag=TRUE;
                //if(vflag==TRUE)
                //printf("%s",bbuffer);
                //strcpy(theline,bbuffer);
        } 
            //strncat(rtxt,bbuffer,999);
            strncat(btxt,bbuffer,3999);
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
    fseek(fp,max , SEEK_SET); 
    //fclose(rfpr); 
   // fseek(Fp,max , SEEK_SET);  
}




else if (rw==FALSE && CORRECT==TRUE && flag!=TRUE && ysv1!='s' && ysv1!='S'){
yFp=fopen(path,"r");
    while (fgets(rbuffer,3998,yFp)){
        if (strcmp(rbuffer,"\n")!=0 ){
            strcpy(bbuffer,rbuffer);
            
            //nrtxt=strlen(rtxt);
            strcpy(En,strtok(rbuffer," "));
            if(strcmp(EN,En)==0 && checkstr(bbuffer,"|",1,1)==TRUE){
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
}
return 0;
}

//return;
int ci=0;
char astrs[100];
BOOL bk=FALSE;

BOOL now=FALSE;
BOOL now1=FALSE;
BOOL now2=FALSE;
BOOL now3;
BOOL now4=FALSE;
BOOL now5=FALSE;
BOOL nown=FALSE;
BOOL ascii;
char lword[4];
char asc[3]="”";
BOOL iszh=FALSE;
//int asci=14844061;
//int fd1;
int prt(char str)
{
    int         rown, coln, rowm, colm;
    char        buffer[64];
    char *const tail = buffer + sizeof(buffer);
    char       *head = buffer + sizeof(buffer);
    now=FALSE;
    now1=FALSE;
    rown = 0;
    coln = 0;
    rowm = 0;
    colm = 0;
 /*  if(ez=='1' && bk==TRUE){
        
    //fd = current_tty();
cursor_position(&rown,&coln);
        str='\0';
        if(coln==1){
            //printf("111");
            printf("\033[1A\033[%dC",col);
            now1=TRUE;
            nown=TRUE;
            fflush(stdout);
            }
    
    //printf("%c",str);
    return 0;
    }
*/
    iszh=FALSE;
    if (ez=='1' && bk!=TRUE){
        
        while (TRUE){
            cursor_position(&rown,&coln);
            printf("%c",str);
            //        printf("%c",str);
            fflush(stdout);
            cursor_position(&rowm,&colm);
            if(colm!=coln)
                break;
            if(colm==col && colm==coln){
                break;
            }
        }
//        now=FALSE;
        if(colm==col && coln==col){
            //printf("111");
            //printf("\033[1A\033[%dC ",col);
            now=TRUE;
            //fflush(stdout);
            }
        return 0;
    }

    if  (ez=='2' && bk==TRUE){
        if (ascii==TRUE){
cursor_position(&rown,&coln);
        if(coln==1){
        //ci=0;
        printf("\033[1A\033[%dC",col+1);
        nown=TRUE;
        fflush(stdout);
        now1=TRUE;
        }
        }
        //printf("222")
//        if (fd == -1)
//           return 1;
cursor_position(&rown,&coln);
        if(coln==1){
        //printf("222");
        if(now3==TRUE){
        printf("\033[1A\033[%dC",col-1);
        nown=TRUE;
        fflush(stdout);
        ci=0;
        now3=FALSE;
        }
        else if(now3==FALSE){
        ci=0;
        printf("\033[1A\033[%dC",col+1);
        nown=TRUE;
        fflush(stdout);
        now4=TRUE;
        }
        //now2=TRUE;
        }
        return 0;
     } 



    if  (ez=='2'  && bk!=TRUE){

    if (str=='.' || str==',' || str==' ' ){
cursor_position(&rown,&coln);
       // printf("%c",str);
        printf("%c",str);
        fflush(stdout);
cursor_position(&rowm,&colm);
        if(colm==col && coln==col){
            //printf("111");
            //printf("\033[1A\033[%dC ",col);
            now=TRUE;
            //fflush(stdout);
            }
        return 0;
    }
    else if(!isascii(str) ){
        
        ci++;
        strncat(astrs,&str,1);
        if(ci==3){
            if ((int)*astrs>(int)*asc){
                iszh=TRUE;
                //fd = current_tty();
            while(TRUE){
                cursor_position(&rown,&coln);
                //printf("%d",coln);
                printf("%s",astrs);
                fflush(stdout);
                //rowm=0;
                //colm=0;
                cursor_position(&rowm,&colm);
                if(colm!=coln)
                    break;
            }
            ci=0;
            //strcpy(astrs,"");
        now2=FALSE;
        if(colm==col && coln==col-2){
            printf(" ");
            //strcpy(lword,astrs);
            now2=TRUE;
            now3=TRUE;
            ci=0;
            fflush(stdout);
            strcpy(astrs,"");
            iszh=FALSE;
            return 0;
            }
            now5=FALSE;
        if(colm==col && coln==col-1){
            now5=TRUE;
            }
                return 0;
        }
            else
                iszh=FALSE;
        }
    }
    else{
        ci=0;
        iszh=FALSE;
        strcpy(astrs,"");
    }

        }
    return 0;
}

void  handler()
{
//printf("rxit");
//  return 2;
printf("\033[6n");
}
//BOOL re;
int main(int argc, char *argv[])
{
int si;
int growm;
int gcolm;
int grown;
int gcoln;
    //asci=printf("%d",asc);
alltxt=(char *)malloc(2999999); 
xtxt=(char *)malloc(3000010);
	if(signal(SIGALRM,handler) == SIG_ERR){  //信号注册函数
    perror("signal");

    exit(-1);

      }
    int arga;
    BOOL ish=FALSE;
    int args;
fd1 = current_tty();

	while ((arga = getopt(argc, argv, ":ir")) != -1) {
		switch (arga) {
			case 'r': printf("错题集模式\n");fflush(stdout);CORRECT=TRUE; break;
			case 'i': printf("优化ish\n");fflush(stdout);ish=TRUE; break;
			
		}
	}
    struct winsize Max;
    ioctl(0, TIOCGWINSZ , &Max);
    row=Max.ws_row;
    col=Max.ws_col;
    char strs[9999];
    int cc;
    strcpy(strs,"");
    for (cc=0;cc<col;cc++){
        strcat(strs,"\xe2");
        strcat(strs,"\x94");
        strcat(strs,"\x80");
    }
        printf("%s",strs);
    char Path;
    /*Path=malloc(200);fgets */ 
    printf("C-English-Training");
    fflush(stdout);
    char aaword;
    char aword[150];
    char atxt;
    char txt[99999];
    char buffer[200];
    int lines=0;
    int pleng;
    atexit (my_exit);
	float time_use=0;
	struct timeval start;
	struct timeval end;//struct timezone tz; 

    fflush(stdout);
    /*system("stty -icanon");*/
    struct termios new_setting;
    tcgetattr(0,&init_setting);
    new_setting=init_setting;
    //new_setting.c_cflag&=~CREAD;
    new_setting.c_lflag&=~ECHO; 
    new_setting.c_lflag&=~ICANON; 
    tcsetattr(0,TCSANOW,&new_setting);
    /*scanf("%s",Path);*/
    //printf("\033[?25l");
    int mi;
    while(TRUE){
           strcpy(path,"");
           strcpy(&Path,"");
           pleng=0;
           printf("\n输入txt文件路径:");
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
            
            //del_char(path,'\01');
            //del_char(path,'\0');
            //printf("%s",path);
            //return 0;
            fp=fopen(path,"r");
            if(fp==NULL){
                continue;
                printf("\n");
            }
            break;

}
//printf("\n%d\n",CORRECT);
if (CORRECT==TRUE){
//printf("@22");
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
    //rfp = fopen("CORRECT.txt", "r+");
    printf("\n使用./CORRECT.txt");
    rfpa = fopen("CORRECT.txt", "a+");
   // Fp=fopen(path,"r");
}

fflush(stdout);
fclose(rfp);
//rfpc=*rfp;
//sleep(10);
//fgets(xbuffer,150,rfp);
//printf("\n%s\n",xbuffer);
    //fpc=*fp;
}
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
    strcat(txt,"\n");
printf("已加载%d组单词\n",lines);
//del_char(txt,EOF);
//strcat(txt,"\n");
    char word[200];

    char ii[200];
    int i;
    char order;
    int max;
    int addmax;
    int ifright;
    char bword[100];
    char zword;
    char zwords[199];
    int xword;
    int rx=0;
    int ab=0;
    char azh[10][100];
    char bzh[10][100];
    int aii=0;
    int iii=0;
    char ch[200];
    int n;
    BOOL flag = FALSE;
    BOOL iez;
    int times = (unsigned int)time(NULL);
    int leng;
    int tleng;
    int zhleng;
    int m=0;
    int mm=0;
    int mmm=0;
    int cmmm=0;
    int acount;
    int z;
    char * dzh;
    char temp[200];
    char ltemp[200];
    BOOL getin=FALSE;
    char tline[]="\033[32m●\033[0m";
    char fline[]="\033[31m●\033[0m";
    //char eline[]="\033[32m○\033[0m";
    char nline[]="\033[33m○\033[0m";
    max=strlen(txt);
    /*system("stty -icanon");*/
    char block;
    printf("1,中译英\033[%dC2,英译中\033[%dC3,混合:",col/2-12,col/2-12);
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
        int num=-1;
        int nend[9999];
        
	    i=-1;
        while (i++,i<max){
	/*printf("%d",i);*/
        /***printf("%c",txt[i]);***/

        if(i==0 | txt[i]=='\n'){
            num++;
            nend[num]=i;
            /*printf("%d\n",i);*/
            
            
        }
            
        }
        int ran;


    srand((unsigned)time(NULL));
	while (TRUE){
        
        now2=FALSE;
        now3=FALSE;
        now4=FALSE;
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
                strncat(word,&txt[n],1);
            }
        
            puts("");
	    zh="\0";
	    en="\0";
        printf("\033[2m%s\n\033[0m",strs);
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
            strcpy(EN,zh);
            strcpy(ch,en);
            }

        else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(ch,zh);
            strcpy(EN,en);
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

            /*printf("\n%s\n",azh[0]);
            printf("\n%s\n",azh[1]);
            printf("\n%s\n",azh[2]);*/

            }
            printf("\r\033[1m%s\033[0m\033[2m——————:\033[0m",en);
            /***puts(en);***/


            bword[0]='\0'; 
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
            
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
            //strcmp(ltemp,"\0");
            //strcmp(ch,"\0");
            //strcmp(astrs,"\0");
            //strcmp(zwords,"\0");
            aii=0;
            //backed=FALSE;

            if(ez=='1'){
                strcpy(zwords,"");
                zwords[0]='\0';
                //printf("%s\n",EN);
            for(si=0;si<strlen(EN);si++){
                zwords[si]='-';
                zwords[si+strlen(EN)]='\x7f';
                zwords[si+strlen(EN)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            leng=0;
            
            while(TRUE){
                //printf("2\n");
                //now1=FALSE;
                if(getin==FALSE){
                    zword=getchar();

                /**    gettimeofday(&start,NULL);
                    while((zword=getchar())){
                        gettimeofday(&end,NULL);
                        time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);

		                    if(time_use>=60000)
		                    {
			                    strcpy(temp,"");
                                
                                
                                break;
                                
		                    }   
                            else
                            {
                                break;
                            }
                                                    
                    }**/

                }
                else if(getin==TRUE){
                   // if(strlen(words)>1){
                        //strcpy(words,zwords);
                        
                        if(iii<strlen(zwords)){
                            zword=zwords[iii];
                            iii++;
                        }
                        else{
                        ci=0;
                        getin=FALSE;
                        strcpy(zwords,"");
                        iii=0;
                        continue;
                        }
                  //  }

                }
                

                bk=FALSE;
                if(zword == '\x7f'){  
                    ascii=FALSE;
                    if(nown==TRUE){
                    nown=FALSE;
                    }
                    if(isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-1]='\0';
                        tleng=tleng-1;
                        
                        fflush(stdout);
                    }
                    else if(!isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-3]='\0';
                        temp[tleng-2]='\0';
                        temp[tleng-1]='\0';
                        
                        fflush(stdout);
                        tleng=tleng-3;
                    }
                    //      
                    if(ez=='1' && isascii(aword[leng-1])  && leng > 0){
                            
                        //now=FALSE;
                        //now1=FALSE;
                        if(leng<=strlen(EN))
                        block='-';
                        else
                        block=' ';
                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1;
                        if(now1==TRUE){
                        printf("%c\b\033[1C",block);
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C%c\b\033[1C",block);
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        while (TRUE){
                        if(ish==TRUE && getin==TRUE)
                        cursor_position(&grown,&gcoln);
                        printf("\b%c\b",block);
                        fflush(stdout);
                        if(ish==TRUE)
                        cursor_position(&growm,&gcolm);
                        if(ish==TRUE && getin==TRUE){
                        if(gcoln==gcolm && gcoln!=1)
                        continue;
                        }
                        break;

                        }
                        }
                        if(ish==TRUE)
                            if(gcolm==1){
            //printf("111");
                            printf("\033[1A\033[%dC",col);
                            now1=TRUE;
                            nown=TRUE;
                            fflush(stdout);
                            }
                        continue;
                        
                    }
                    if(ez=='2' && !isascii(aword[leng-1]) && leng > 0){
                        
                        bk=TRUE;  
                        aword[leng-3]='\0';
                        aword[leng-2]='\0';
                        aword[leng-1]='\0';
                        if(now4==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now4=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        if(now5==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now5=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        printf("\b\b  \b\b");
                        //if(now2==TRUE){
                        //printf("\033[1C");
                        //now2=FALSE;
                        //}
                        fflush(stdout);
                        leng=leng-3;
                        if(ish==TRUE)
                        prt(zword);

                        continue;
                        
                    }
                    if(ez=='2' && isascii(aword[leng-1]) && leng > 0)
                    {
                        //printf("3333");
                        ascii=TRUE;
                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1; 
                        if(now1==TRUE){
                        printf(" \b\033[1C");
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C \b\033[1C");
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        printf("\b \b");
                        fflush(stdout);
                        }
                        if(ish==TRUE)
                        prt(zword);
                        continue;
                    }
                    
                    continue;       
                
                }
                if(zword == '\r' || zword == '\n' || zword == '\0'){
                    /*printf("%s",zh);*/
		    /*printf("%s",zh);*/
		    break;
                }
            
                    /***zword=getchar();***/
                    /*printf("aword:%c",zword);*/
if(ez == '1'  &&  isascii(zword) && (int)zword >= 65 && (int)zword <=122 || ez == '1' && zword=='-' || zword==' ' )
{

                leng++;
                strncat(aword,&zword,1);
                if(getin==FALSE){
                    tleng++;
                    strncat(temp,&zword,1);
                }
                
                if(ish==TRUE){
                    now=FALSE;
                    now1=FALSE;
                    if(nown==TRUE ){
                    now2=FALSE;
                    now4=FALSE;
                    printf("\n");
                    fflush(stdout);
                    nown=FALSE;
                }
                    prt(zword);
                }
                else
                    printf("%c",zword);
                    fflush(stdout);
}
else if (ez=='2' && !isascii(zword) || zword==' ' || zword==',' || zword=='.' || bk==TRUE )
{
    
    
    if(ish==TRUE){
        now=FALSE;
        now1=FALSE;
       if(nown==TRUE ){
        now2=FALSE;
        now4=FALSE;
        printf("\n");
        fflush(stdout);
        nown=FALSE;
    }
        prt(zword);
        if(now2==TRUE)
        {
            strcpy(zwords,astrs);
            //printf("zwords:%s",zwords);
            iii=0;
            
            strcpy(astrs,"");
            getin=TRUE;
            now2=FALSE;
            //continue;
        }
    }
    else{
        mi++;
    strncat(astrs,&zword,1);
    if(mi==3){
        if ((int)*astrs>(int)*asc){
            printf("%s",astrs);
            fflush(stdout);
            //fd = current_tty();
            iszh=TRUE;
            mi=0;
        }
        else{
            mi=0;
            strcpy(astrs,"");
        //printf("%c",zword);
        }
    }
    else
        iszh=FALSE;
    }
    if(isascii(zword)){
        leng++;
        strncat(aword,&zword,1);
        if(getin==FALSE){
            tleng++;
            strncat(temp,&zword,1);
        }
    }
    if(iszh){
                leng=leng+3;
                strncat(aword,astrs,3);
                if(getin==FALSE){
                    tleng=tleng+3;
                    strncat(temp,astrs,3);
                }
        
        iszh=FALSE;
        strcpy(astrs,"");
    }                //getin=FALSE;
}
 else
continue;
//strcpy(&zword,"");
                /*if ((aword==zh))*/
		   /* printf("答对了");*/
                if ((ifright = strcmp(aword,zh)) == 0 && ez=='1'){
                    printf("\033[%dC%s\r",col,tline);
                    getin=FALSE;
                    fflush(stdin);
                    fflush(stdout);
                    flag=TRUE;
                    break;
                 }  
                if (ez=='2'){
                    
                    /*printf("\n%s\n",temp);*/
                    aii=0;
                    /*printf("l:%s",ltemp);*/
                    for(i=0;i<=n;i++){
                        if(strcmp(temp,azh[i])==0 && strcmp(temp,ltemp)!=0 ){
                            strcpy(zwords,"，");
                            getin=TRUE;
                            strcpy(bzh[i],azh[i]);
                            /*strcpy(azh[i],"\1");*/
                            strcpy(ltemp,""); 
                            strcpy(ltemp,temp); 
                            strcpy(temp,"");
                            tleng=0;
                        } 
                        if(strcmp(bzh[i],azh[i])==0){
                            aii++;
                    }  
                    }

                        if(aii==n+1){
                           printf("\033[%dC%s\r",col,tline);
                           fflush(stdout);
                           //getin=FALSE;
                            fflush(stdin);
                            //fflush(stdout);
                            strcpy(ltemp,""); 
                            getin=FALSE;
                            flag = TRUE;
                            break;
                    }
                    if (getin==TRUE)
                    
                    continue;
                     
                }  

                
                    //fflush(stdout);
                    
                 
                    /***printf("%d",xword);***/ 
                
                
                }

                if (flag != TRUE ){
                if(strcmp(aword,"")==0){
                    printf("\033[%dC%s\r",col,nline);
                    fflush(stdout);
                    ysv(flag,bword,ez);
                }
                else{
                //fflush(stdin);
                printf("\033[%dC%s\r",col,fline);
                fflush(stdout);
                ysv(flag,bword,ez); 
                //printf("\n%s",bword);
                //fflush(stdout);
                } 
                }
                else{
                    ysv(flag,bword,ez);
                } 
                fflush(stdin);
                if(CORRECT==TRUE)
                rwfp(EN,ch,ez,flag);
                fflush(stdin);  


            }
        }
    



    else if(order=='2'){
        
	i=max-1;
     srand((unsigned)time(NULL));
        while (i=i-1,i>=0){
	/*printf("%d",i);*/
        /***printf("%c",txt[i]);***/
        if(txt[i] != '\n'){
            
            strcpy(ii,word);
            
            strcpy(word,"");
	/*printf("word:%s",word);*/ 
 /*strncat(word,&txt[i],2);*/
	    strncat(word,&txt[i],1);
            /*printf("%s",word);*/

            strncat(word,ii,strlen(ii));
	    /*printf("%s",word); */     
            strcpy(ii,"");

        }

        if(i==0 | txt[i]=='\n'){
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
            strcpy(EN,zh);
            strcpy(ch,en);
            }

            else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(EN,en);
            strcpy(ch,zh);
            }
            acount=0;
            m=-1;
            mm=0;
            mmm=0;
            zhleng=0;
            zhleng=strlen(zh);
            strcpy(azh[1],"");
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
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
            /*printf("%s\n",azh[0]);*/
            printf("\r\033[1m%s\033[0m\033[2m——————:\033[0m",en);
            /***puts(en);***/

            bword[0]='\0'; 
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
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
            /***if (fgets(aword,2,stdin) != '\0'){*///

               /*** if ((xword = getchar()) != '\n') { ***/
                  /***   strncat(aword,&xword,1); ***/
            strcpy(temp,"\0");
            aii=0;
            strcpy(temp,"");
            strcpy(ltemp,"");
            if(ez=='1'){
                strcpy(zwords,"");
                zwords[0]='\0';
                //printf("%s\n",EN);
            for(si=0;si<strlen(EN);si++){
                zwords[si]='-';
                zwords[si+strlen(EN)]='\x7f';
                zwords[si+strlen(EN)*2]='\x7f';
            }
            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                getin=TRUE;
                //continue;
            }
            //strcmp(ltemp,"\0");
            //strcmp(ch,"\0");
            //strcmp(astrs,"\0");
            //strcmp(zwords,"\0");
            while(TRUE){
                if(getin==FALSE){
                    zword=getchar();
                /**    gettimeofday(&start,NULL);
                    while((zword=getchar())){
                        gettimeofday(&end,NULL);
                        time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);

		                    if(time_use>=60000)
		                    {
			                    strcpy(temp,"");
                                
                                
                                break;
                                
		                    }   
                            else
                            {
                                break;
                            }
                                                    
                    }**/

                }
                else if(getin==TRUE){
                   // if(strlen(words)>1){
                        //strcpy(words,zwords);
                        
                        if(iii<strlen(zwords)){
                            zword=zwords[iii];
                            iii++;
                        }
                        else{
                        getin=FALSE;
                        ci=0;
                        strcpy(zwords,"");
                        iii=0;
                        continue;
                        }
                  //  }

                }                
                bk=FALSE;
                if(zword == '\x7f'){  
                    ascii=FALSE;
                    if(nown==TRUE){
                    nown=FALSE;
                    }
                    if(isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-1]='\0';
                        tleng=tleng-1;
                        
                        fflush(stdout);
                    }
                    else if(!isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-3]='\0';
                        temp[tleng-2]='\0';
                        temp[tleng-1]='\0';
                        
                        fflush(stdout);
                        tleng=tleng-3;
                    }
                    //      
                    if(ez=='1' && isascii(aword[leng-1]) && leng > 0){

                        //now=FALSE;
                        //now1=FALSE;
                        if(leng<=strlen(EN))
                        block='-';
                        else
                        block=' ';

                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1;
                        if(now1==TRUE){
                        printf("%c\b\033[1C",block);
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C%c\b\033[1C",block);
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        while (TRUE){
                        if(ish==TRUE && getin==TRUE)
                        cursor_position(&grown,&gcoln);
                        printf("\b%c\b",block);
                        fflush(stdout);
                        if(ish==TRUE)
                        cursor_position(&growm,&gcolm);
                        if(ish==TRUE && getin==TRUE){
                        if(gcoln==gcolm && gcoln!=1)
                        continue;
                        }
                        break;
                        }
                        }
                        if(ish==TRUE)
                            if(gcolm==1){
            //printf("111");
                            printf("\033[1A\033[%dC",col);
                            now1=TRUE;
                            nown=TRUE;
                            fflush(stdout);
                            }
                        continue;
                        
                    }
                    if(ez=='2' && !isascii(aword[leng-1]) && leng > 0){
                        
                        bk=TRUE;  
                        aword[leng-3]='\0';
                        aword[leng-2]='\0';
                        aword[leng-1]='\0';
                        if(now4==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now4=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        if(now5==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now5=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        printf("\b\b  \b\b");
                        //if(now2==TRUE){
                        //printf("\033[1C");
                        //now2=FALSE;
                        //}
                        fflush(stdout);
                        leng=leng-3;
                        if(ish==TRUE)
                        prt(zword);

                        continue;
                        
                    }
                    if(ez=='2' && isascii(aword[leng-1]) && leng > 0)
                    {
                        //printf("3333");
                        ascii=TRUE;
                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1; 
                        if(now1==TRUE){
                        printf(" \b\033[1C");
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C \b\033[1C");
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        printf("\b \b");
                        fflush(stdout);
                        }
                        if(ish==TRUE)
                        prt(zword);
                        continue;
                    }
                    
                    continue;       
                
                }
                if(zword == '\r' || zword == '\n' || zword == '\0'){
                    /*printf("%s",zh);*/
		    /*printf("%s",zh);*/
		    break;
                }
            
                    /***zword=getchar();***/
                    /*printf("aword:%c",zword);*/
if(ez == '1'  &&  isascii(zword) && (int)zword >= 65 && (int)zword <=122 || ez == '1' && zword=='-' || zword==' ' )
{

                leng++;
                strncat(aword,&zword,1);
                if(getin==FALSE){
                    tleng++;
                    strncat(temp,&zword,1);
                }
                
                if(ish==TRUE){
                    now=FALSE;
                    now1=FALSE;
                    if(nown==TRUE ){
                    now2=FALSE;
                    now4=FALSE;
                    printf("\n");
                    fflush(stdout);
                    nown=FALSE;
                }
                    prt(zword);
                }
                else
                    printf("%c",zword);
                    fflush(stdout);
}
else if (ez=='2' && !isascii(zword) || zword==' ' || zword==',' || zword=='.' || bk==TRUE )
{
    if(ish==TRUE){
        now=FALSE;
        now1=FALSE;
       if(nown==TRUE ){
        now2=FALSE;
        now4=FALSE;
        printf("\n");
        fflush(stdout);
        nown=FALSE;
    }
        prt(zword);
        if(now2==TRUE)
        {
            strcpy(zwords,astrs);
            //printf("zwords:%s",zwords);
            iii=0;
            
            strcpy(astrs,"");
            getin=TRUE;
            now2=FALSE;
            //continue;
        }
    }
    else{
        mi++;
    strncat(astrs,&zword,1);
    if(mi==3){
        if ((int)*astrs>(int)*asc){
            printf("%s",astrs);
            fflush(stdout);
            //fd = current_tty();
            iszh=TRUE;
            mi=0;
        }
        else{
            mi=0;
            strcpy(astrs,"");
        //printf("%c",zword);
        }
    }
    else
        iszh=FALSE;
    }
    if(isascii(zword)){
        leng++;
        strncat(aword,&zword,1);
        if(getin==FALSE){
            tleng++;
            strncat(temp,&zword,1);
        }
    }
    if(iszh){
                leng=leng+3;
                strncat(aword,astrs,3);
                if(getin==FALSE){
                    tleng=tleng+3;
                    strncat(temp,astrs,3);
                }
        
        iszh=FALSE;
        strcpy(astrs,"");
    }                //getin=FALSE;
}

else
continue;
//strcpy(&zword,"");
                /*if ((aword==zh))*/
		   /* printf("答对了");*/
                if ((ifright = strcmp(aword,EN)) == 0 && ez=='1'){
                    printf("\033[%dC%s\r",col,tline);
                    fflush(stdout);
                    fflush(stdin);
                    flag=TRUE;
                    break;
                 }  

                if (ez=='2'){
                    
                    /*printf("\n%d\n",n);*/
                    aii=0;
                    for(z=0;z<=n;z++){
                        if(strcmp(temp,azh[z])==0 && strcmp(temp,ltemp)!=0){
                            strcpy(zwords,"，");
                            getin=TRUE;
                            strcpy(bzh[z],azh[z]);
                            /*strcpy(azh[i],"\1");*/
                            strcpy(ltemp,""); 
                            strcpy(ltemp,temp); 
                            strcpy(temp,"");
                            acount++;   
                            tleng=0;
                        } 
                        if(strcmp(bzh[z],azh[z])==0){
                            aii++;
                    }  
                    }
                    if(aii==n+1){
                        printf("\033[%dC%s\r",col,tline);
                        fflush(stdout);
                        getin=FALSE;
                        flag = TRUE;
                        break;
                        }
                    if (getin==TRUE)
                    continue;
                    
                 }  


                    fflush(stdout);
                    flag = FALSE;
                 
                    /***printf("%d",xword);***/
                
                
                }


    
                if (flag != TRUE ){
                if(strcmp(aword,"")==0){
                    printf("\033[%dC%s\r",col,nline);
                    fflush(stdout);
                    ysv(flag,bword,ez);
                }
                else{
                fflush(stdin);
                printf("\033[%dC%s\r",col,fline);
                fflush(stdout);
                ysv(flag,bword,ez);
                //printf("\n%s",bword);
                //fflush(stdout);
                } 
                }
                else{
                    ysv(flag,bword,ez);
                }  
                fflush(stdin);    
                if(CORRECT==TRUE)
                rwfp(EN,ch,ez,flag);  
                fflush(stdin);     
        }
        }

    

}


    else if(order == '1'){
        fflush(stdin);
        i=-1;
        n=-1;
         srand((unsigned)time(NULL));
    while (i++,i<max){
        /***printf("%c",txt[i]);***/
        if(txt[i] != '\n'){
            strncat(word,&txt[i],1);
        }
        else{
            puts("");
	    zh="\0";
	    en="\0";
            now2=FALSE;
            now3=FALSE;
            now4=FALSE;
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
	    if(ez=='1'){
            zh=strtok(word,"\t");
            /*del_char(zh,'\01');*/
	    /*del_char(zh,'\0');*/
	        en=strtok(NULL,"\t");
            strcpy(EN,zh);
            strcpy(ch,en);
            }

            else if(ez=='2'){
            en=strtok(word,"\t");
            zh=strtok(NULL,"\t");
            strcpy(EN,en);
            strcpy(ch,zh);
            }
            m=-1;
            mm=0;
            mmm=0;
            zhleng=0;
            zhleng=strlen(zh);
            for(n=0;n<10;n=n+1){
                strcpy(bzh[n],"");
                strcpy(azh[n],"");
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
            /*printf("%s\n",azh[0]);*/
            printf("\033[2m%s\n\033[0m",strs);
            printf("\r\033[1m%s\033[0m\033[2m——————:\033[0m",en);
            /***puts(en);***/

            bword[0]='\0'; 
            strcat(bword,en);
            strcat(bword," ");
            strcat(bword,zh);
            
            fflush(stdout);
            /***fgets(aword,2,stdin);***/
            
            strcpy(word,"");
            aword[0]='\0';
            zword='\0';
            /*system("stty -icanon");*/
            /***if (fgets(aword,2,stdin) != '\0'){*///
            leng=0;
            tleng=0;
               /*** if ((xword = getchar()) != '\n') { ***/
                  /***   strncat(aword,&xword,1); ***/
            strcpy(temp,"");
            aii=0;
            strcpy(temp,"");
            strcpy(ltemp,"");
            if(ez=='1'){
                strcpy(zwords,"");
                zwords[0]='\0';
                //printf("%s\n",EN);
            for(si=0;si<strlen(EN);si++){
                zwords[si]='-';
                zwords[si+strlen(EN)]='\x7f';
                zwords[si+strlen(EN)*2]='\x7f';
            }

            //printf("\n%lu\n",strlen(zwords));
                //strcpy(zwords,backs);
                getin=TRUE;
                //backed=TRUE;
                //continue;
            }
            while(TRUE){
                iszh=FALSE;
                if(getin==FALSE){
                    zword=getchar();
                /**    gettimeofday(&start,NULL);
                    while((zword=getchar())){
                        gettimeofday(&end,NULL);
                        time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);

		                    if(time_use>=60000)
		                    {
			                    strcpy(temp,"");
                                
                                
                                break;
                                
		                    }   
                            else
                            {
                                break;
                            }
                                                    
                    }**/

                }
                else if(getin==TRUE){
                   // if(strlen(words)>1){
                        //strcpy(words,zwords);
                        
                        if(iii<strlen(zwords)){
                            zword=zwords[iii];
                            iii++;
                        }
                        else{
                        ci=0;
                        getin=FALSE;
                        strcpy(zwords,"");
                        iii=0;
                        continue;
                        }
                  //  }

                }
                
                bk=FALSE;
                if(zword == '\x7f'){  
                    ascii=FALSE;
                    if(nown==TRUE){
                    nown=FALSE;
                    }
                    if(isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-1]='\0';
                        tleng=tleng-1;
                        
                        fflush(stdout);
                    }
                    else if(!isascii(temp[tleng-1]) && tleng > 0){
                        temp[tleng-3]='\0';
                        temp[tleng-2]='\0';
                        temp[tleng-1]='\0';
                        
                        fflush(stdout);
                        tleng=tleng-3;
                    }
                    //      
                    if(ez=='1' && isascii(aword[leng-1]) && leng > 0){
                        if(leng<=strlen(EN))
                        block='-';
                        else
                        block=' ';
                        //now=FALSE;
                        //now1=FALSE;

                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1;
                        if(now1==TRUE){
                        printf("%c\b\033[1C",block);
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C%c\b\033[1C",block);
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        while (TRUE){
                        if(ish==TRUE && getin==TRUE)
                        cursor_position(&grown,&gcoln);
                        printf("\b%c\b",block);
                        fflush(stdout);
                        if(ish==TRUE)
                        cursor_position(&growm,&gcolm);
                        if(ish==TRUE && getin==TRUE){
                        if(gcoln==gcolm && gcoln!=1)
                        continue;
                        }
                        break;
                        }
                        }
                        if(ish==TRUE)
                            if(gcolm==1){
            //printf("111");
                            printf("\033[1A\033[%dC",col);
                            now1=TRUE;
                            nown=TRUE;
                            fflush(stdout);
                            }
                        continue;
                        
                    }
                    if(ez=='2' && !isascii(aword[leng-1]) && leng > 0){
                        
                        bk=TRUE;  
                        aword[leng-3]='\0';
                        aword[leng-2]='\0';
                        aword[leng-1]='\0';
                        if(now4==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now4=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        if(now5==TRUE){
                            //printf("2222");
                            printf("\b  \b");
                            fflush(stdout);
                            now5=FALSE;
                            leng=leng-3;
                            continue;
                        }
                        printf("\b\b  \b\b");
                        //if(now2==TRUE){
                        //printf("\033[1C");
                        //now2=FALSE;
                        //}
                        fflush(stdout);
                        leng=leng-3;
                        if(ish==TRUE)
                        prt(zword);

                        continue;
                        
                    }
                    if(ez=='2' && isascii(aword[leng-1]) && leng > 0)
                    {
                        //printf("3333");
                        ascii=TRUE;
                        bk=TRUE; 
                        aword[leng-1]='\0';
                        leng=leng-1; 
                        if(now1==TRUE){
                        printf(" \b\033[1C");
                        fflush(stdout);
                        now1=FALSE;
                        continue;
                        }
                        else if(now==TRUE){
                        printf("\033[1D\033[1C \b\033[1C");
                        fflush(stdout);
                        now=FALSE;
                        continue;
                        }
                        else{
                        printf("\b \b");
                        fflush(stdout);
                        }
                        if(ish==TRUE)
                        prt(zword);
                        continue;
                    }
                    
                    continue;       
                
                }
                if(zword == '\r' || zword == '\n' || zword == '\0'){
                    /*printf("%s",zh);*/
		    /*printf("%s",zh);*/
		    break;
                }
            
                    /***zword=getchar();***/
                    /*printf("aword:%c",zword);*/
if(ez == '1'  &&  isascii(zword) && (int)zword >= 65 && (int)zword <=122 || ez == '1' && zword=='-'|| zword==' ' )
{

                leng++;
                strncat(aword,&zword,1);
                if(getin==FALSE){
                    tleng++;
                    strncat(temp,&zword,1);
                }
                
                if(ish==TRUE){
                    now=FALSE;
                    now1=FALSE;
                    if(nown==TRUE ){
                    now2=FALSE;
                    now4=FALSE;
                    printf("\n");
                    fflush(stdout);
                    nown=FALSE;
                }
                    prt(zword);
                }
                else
                    printf("%c",zword);
                    fflush(stdout);
}
else if (ez=='2' && !isascii(zword) || zword==' ' || zword==',' || zword=='.' || bk==TRUE )
{
    if(ish==TRUE){
        now=FALSE;
        now1=FALSE;
       if(nown==TRUE ){
        now2=FALSE;
        now4=FALSE;
        printf("\n");
        fflush(stdout);
        nown=FALSE;
    }
        prt(zword);
        if(now2==TRUE)
        {
            strcpy(zwords,astrs);
            //printf("zwords:%s",zwords);
            iii=0;
            
            strcpy(astrs,"");
            getin=TRUE;
            now2=FALSE;
            //continue;
        }
    }
    else{
        mi++;
    strncat(astrs,&zword,1);
    if(mi==3){
        if ((int)*astrs>(int)*asc){
            printf("%s",astrs);
            fflush(stdout);
            //fd = current_tty();
            iszh=TRUE;
            mi=0;
        }
        else{
            mi=0;
            strcpy(astrs,"");
        //printf("%c",zword);
        }
    }
    else
        iszh=FALSE;
    }
    if(isascii(zword)){
        leng++;
        strncat(aword,&zword,1);
        if(getin==FALSE){
            tleng++;
            strncat(temp,&zword,1);
        }
    }
    if(iszh){
                leng=leng+3;
                strncat(aword,astrs,3);
                if(getin==FALSE){
                    tleng=tleng+3;
                    strncat(temp,astrs,3);
                }
        
        iszh=FALSE;
        strcpy(astrs,"");
    }                //getin=FALSE;
}
else
continue;
//strcpy(&zword,"");
                /*if ((aword==zh))*/
		   /* printf("答对了");*/
                if ((ifright = strcmp(aword,EN)) == 0 && ez=='1'){
                    printf("\033[%dC%s\r",col,tline);
                    fflush(stdout);
                    fflush(stdin);
                    flag=TRUE;
                    break;
                 }  


                else if (ez=='2'){
                    
                    /*printf("\n%d\n",n);*/
                    aii=0;
                    for(z=0;z<=n;z++){
                        if(strcmp(temp,azh[z])==0 && strcmp(temp,ltemp)!=0){
                            strcpy(zwords,"，");
                            getin=TRUE;
                            strcpy(bzh[z],azh[z]);
                            /*strcpy(azh[i],"\1");*/
                            strcpy(ltemp,""); 
                            strcpy(ltemp,temp); 
                            strcpy(temp,"");
                            acount++;   
                            tleng=0;
                        } 
                        if(strcmp(bzh[z],azh[z])==0){
                            aii++;
                    }  
                    }
                    if(aii==n+1){
                        printf("\033[%dC%s\r",col,tline);
                        fflush(stdout);
                        getin=FALSE;
                        flag = TRUE;

                        break;
                        }
                    if (getin==TRUE)
                    continue;
                    
                 }  

                    fflush(stdout);
                    flag = FALSE;
                 
                    /***printf("%d",xword);***/
            }
                if (flag != TRUE ){
                if(strcmp(aword,"")==0){
                    printf("\033[%dC%s\r",col,nline);
                    fflush(stdout);
                    ysv(flag,bword,ez);
                }
                else{
                fflush(stdin);
                printf("\033[%dC%s\r",col,fline);
                fflush(stdout);
                ysv(flag,bword,ez);
                //printf("\n%s",bword);
                //fflush(stdout);
                } 
                }
                else{
                    ysv(flag,bword,ez);
                }  
                fflush(stdin); 
                if(CORRECT==TRUE)
                rwfp(EN,ch,ez,flag);  
                fflush(stdin);               
            /***scanf("%s",aword);***/
            /***aaword=getchar();***/
            /*printf("aword:%s",aword);*/
            }  
        }
    
   /*system("stty icanon");*/ 
}    /***printf("%s",word);***/
 //tcsetattr(0,TCSANOW,&init_setting);
    return 0;
} 
