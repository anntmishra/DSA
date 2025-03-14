#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
    int pipe1[2];
    int pipe2[2];
    char buffer[BUFFER_SIZE];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        std::cerr << "Pipe creation failed" << std::endl;
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        write(pipe1[1], message.c_str(), message.length() + 1);

        memset(buffer, 0, BUFFER_SIZE);
        read(pipe2[0], buffer, BUFFER_SIZE);
        std::cout << "Parent received: " << buffer << std::endl;

        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL);
    }
    else {
        close(pipe1[1]);
        close(pipe2[0]);

        memset(buffer, 0, BUFFER_SIZE);
        read(pipe1[0], buffer, BUFFER_SIZE);
        std::cout << "Child received: " << buffer << std::endl;

        std::string response = "• Child: Received your message - '" + std::string(buffer) + "'.";
        write(pipe2[1], response.c_str(), response.length() + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
