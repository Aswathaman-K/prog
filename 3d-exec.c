#include<stdio.h> 
#include<unistd.h>
int main( )
{
printf("/n exec system call");
printf("displaying the date"); 
execlp( "/bin/date", "date", NULL);
return 0;
}

