#include <unistd.h>     // fork()
#include <stdio.h>      // printf(), fflush()
#include <stdlib.h>     // exit()
#include <sys/wait.h>   // wait()
#include <sys/types.h>  // pid_t

int main() {
    int i;
    int batas = 5;      // jumlah perulangan
    pid_t pid;

    printf("Program dimulai\n");
    pid = fork();       // membuat proses baru

    if (pid < 0) {
        // fork gagal
        printf("Gagal membuat proses child\n");
        exit(1);
    }
    else if (pid == 0) {
        // proses child
        for (i = 1; i <= batas; i++) {
            printf("Child process ke-%d\n", i);
            fflush(stdout);
            sleep(1);   // jeda 1 detik (opsional, agar output terlihat jelas)
        }
        printf("Child selesai\n");
        exit(0);
    }
    else {
        // proses parent
        wait(NULL);     // menunggu child selesai
        for (i = 1; i <= batas; i++) {
            printf("Parent process ke-%d\n", i);
            fflush(stdout);
            sleep(1);
        }
        printf("Parent selesai\n");
        exit(0);
    }
}
