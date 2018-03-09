#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>

#define SIZE 1024

int main()
{
    int shmid ;
    char *shmaddr ;
    struct shmid_ds buf ;
    int flag = 0 ;
    int pid ;

    //0(IPC_PRIVATE)£º»ὨbÐ¹²ÏÄ´æÏ,IPC_CREATÓIPC¶Ôó¡ȨÏ£¨È0600£©½øËãȷ¶¨ÐºÅ¿¼¯µĴæȨÏ
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0600 ) ;   
    if ( shmid < 0 )
    {
        perror("get shm  ipc_id error") ;
        return -1 ;
    }

    pid = fork() ;
    if ( pid == 0 )
    {
	printf("child progress\n");

        shmaddr = (char *)shmat( shmid, NULL, 0 ) ;      //ֱ½Ó¸¶¨ΪNULLÈÄºËԼº¾ö»¸öʵĵØ·λÖ
        if ( (int)shmaddr == -1 )
        {
            perror("shmat addr error") ;
            return -1 ;
        }
        strcpy( shmaddr, "Hi, I am child process!\n") ;

        //Óshmatº¯ÊÏ·´£¬shmdtÊÓ4¶ϿªÓ¹²ÏÄ´渽¼ӵãµØ·£¬½û½øÎ´Ë¬¹²ÏÄ´æ       shmdt( shmaddr ) ;                               
	
	printf("child end\n");

        return  0;
    } else if ( pid > 0) {
        sleep(3 ) ;
	
	printf("parent progress\n");

        //Í³ɶԹ²ÏÄ´æ¿ØÆµõ½¹²ÏÄ´æ״̬£¬°ѹ²ÏÄ´æshmid_ds½ṹ¸´Öµ½bufÖ
        flag = shmctl( shmid, IPC_STAT, &buf) ;      
        if ( flag == -1 )
        {
            perror("shmctl shm error") ;
            return -1 ;
        }
        printf("shm_segsz =%d bytes\n", buf.shm_segsz ) ;
        printf("parent pid=%d, shm_cpid = %d \n", getpid(), buf.shm_cpid ) ;
        printf("chlid pid=%d, shm_lpid = %d \n",pid , buf.shm_lpid ) ;

        shmaddr = (char *) shmat(shmid, NULL, 0 ) ;
        if ( (int)shmaddr == -1 )
        {
            perror("shmat addr error") ;
            return -1 ;
        }

        printf("%s", shmaddr) ;
        shmdt( shmaddr ) ;
        shmctl(shmid, IPC_RMID, NULL) ;
	printf("parent end\n");
    }
    else if (pid < 0)
    {
        perror("fork error") ;
        shmctl(shmid, IPC_RMID, NULL) ;
    }

    return 0 ;
}
