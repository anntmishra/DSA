#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int myVariable;
pid_t pid;
std::cout << "Enter a value for myVariable: ";
std::cin >> myVariable;
printf("hello world (pid:%d)\n", (int)getpid());
pid = fork();
if (pid < 0) {
fprintf(stderr, "Fork failed!\n");
return 1;
}
else if (pid == 0) {
printf("hello, I am child (pid:%d)\n", (int)getpid());
printf("Value of myVariable from child before modification: %d\n", myVariable);
printf("Changing the value of myVariable in child (myVariable + 10)\n");
myVariable += 10;
printf("The changed value of myVariable in child is %d\n", myVariable);
}
else {
printf("hello, I am parent of %d (pid:%d)\n", (int)pid, (int)getpid());
printf("Value of myVariable from parent before modification: %d\n", myVariable);
printf("Changing the value of myVariable in parent (myVariable + 20)\n");
myVariable += 20;
printf("The changed value of myVariable in parent is %d\n", myVariable);
wait(NULL);
}
return 0;
}
