#include <stdio.h>
#include <windows.h>
// #define FALSE = 0;
int main(VOID)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    // allocate memory
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    // create child process
    if (!CreateProcess(NULL, "C:\\WINDOWS\\system32\\fib.exe",
                       NULL, NULL, 0, 0, NULL,
                       NULL, &si, &pi))
    {
        fprintf(stderr, "Create Process Failed");
        return -1;
    }
    else
    {
        int a = 0, b = 1, n = a + b, i, ii;
        printf("Enter the number of a Fibonacci Sequence:\n");
        scanf("%d", &ii);
        if (ii < 0)
            printf("Please enter a non-negative integer!\n");
        else
        {
            printf("%d %d", a, b);
            for (i = 2; i < ii; i++)
            {
                n = a + b;
                printf("%d ", n);
                a = b;
                b = n;
            }
            printf("Parent is waiting for child to complete...\n");
            printf("Child ends\n");
            printf("Parent ends\n");
        }
    }
    // parent will wait for the child to complete
    WaitForSingleObject(pi.hProcess, 5000);
    printf("Child Complete");
    // close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
