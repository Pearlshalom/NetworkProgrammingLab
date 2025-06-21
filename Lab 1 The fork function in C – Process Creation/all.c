#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num_clients = 3; // Simulate 3 client connections
    for (int i = 0; i < num_clients; i++) {
        pid_t child_pid = fork(); // Create a new child process
        if (child_pid < 0) {
            perror("fork failed");
            return 1;
        } else if (child_pid == 0) {
            // Child process
            printf("This is the client. I am handling the request. My PID = %d, 
            My parent’s PID = %d.\n", getpid(), getppid());
            exit(0); // Exit child process
        } else {
            // Parent process
            printf("This is the server. I have created a child process to handle a client. 
            Parent PID = %d, Child PID = %d.\n", getpid(), child_pid);
        }
    }
    // Parent waits for all children to finish
    while (wait(NULL) > 0);
    printf("All child processes have finished. Server exiting.\n");
    return 0;
}
