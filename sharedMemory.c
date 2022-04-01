#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    int segment_id;
    const int SIZE = 4096;
    char *sharedMemory;
    segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
    sharedMemory = (char *)shmat(segment_id, NULL, 0);

    sprintf(sharedMemory, "Hii There ");

    printf(" %s\n", sharedMemory);
    shmdt(sharedMemory);
    shmctl(segment_id, IPCRMID, NULL);
    return 0;
}