#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
int i, pid;
pid = fork();
if (pid == -1)
{
perror("fork failed");
exit(1);
}
else if (pid == 0)
{
printf("\nChild process starts");
for (i = 0; i < 5; i++)
{
printf("\nChild process %d is called", i);
}{
printf("\nChild process ends\n");
}
wait(NULL);
printf("\nParent process ends\n");
}
return 0;
}
