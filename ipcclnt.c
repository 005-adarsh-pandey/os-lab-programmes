//it is a client side code 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHSZ 27
int main()
{
int shmid;
key_t key;
char *shm ,*s;
key=5549;
if((shmid=shmget(key,SHSZ, IPC_CREAT|0666))<0)

{
        perror("Shmget Problem\n");
        exit(1);
}
if ((shm=shmat(shmid, NULL, 0))==(char*)-1)
        {
        perror ("Shmget Error\n");
        exit (1);
        }
for(s=shm;*s!='\0';s++)
        putchar(*s);
         putchar('\n');
        *shm='*';

exit(0);
return 0;
}
