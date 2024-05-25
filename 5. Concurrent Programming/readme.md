# Concurrent Programming with C++

### Processes

**Definition:**
A process is an instance of a program that is being executed. It contains the program code and its current activity. Each process has its own memory space, which includes the code segment, data segment, heap, and stack.

**Characteristics:**

- **Isolation:** Processes are isolated from each other. Each process has its own address space, and one process cannot directly access the memory of another process.
- **Overhead:** Creating and managing processes is more resource-intensive compared to threads. The operating system needs to allocate separate memory space and resources for each process.
- **Communication:** Inter-process communication (IPC) is required for processes to communicate with each other. IPC mechanisms include pipes, message queues, shared memory, and sockets.

**Use Case:**
Processes are suitable for tasks that require strong isolation and independence, such as running different applications or services.

### Threads

**Definition:**
A thread is the smallest unit of execution within a process. Threads share the same memory space within a process but have their own stack, program counter, and registers.

**Characteristics:**

- **Shared Memory:** Threads within the same process can access shared data and resources. This can lead to more efficient communication and data sharing but also requires synchronization mechanisms to avoid data races.
- **Low Overhead:** Creating and managing threads is less resource-intensive than processes because threads share the process's memory and resources.
- **Concurrency:** Threads can run concurrently, allowing for parallel execution of tasks within a single process.

**Use Case:**
Threads are suitable for tasks that require frequent communication and data sharing, such as handling multiple clients in a server or performing background tasks in an application.

### Processes vs. Threads in C++

**1. Creation:**

- **Process Creation:**
  In C++, processes can be created using system-specific calls such as `fork()` on Unix-like systems. Creating a process involves duplicating the calling process.

  ```cpp
  #include <unistd.h>

  int main() {
      pid_t pid = fork();
      if (pid == 0) {
          // Child process
      } else if (pid > 0) {
          // Parent process
      } else {
          // Fork failed
      }
      return 0;
  }
  ```

- **Thread Creation:**
  C++11 introduced the `<thread>` library, making thread creation straightforward and portable across different operating systems.

  ```cpp
  #include <iostream>
  #include <thread>

  void threadFunction() {
      std::cout << "Thread function executing\n";
  }

  int main() {
      std::thread t(threadFunction);
      t.join(); // Wait for the thread to finish
      return 0;
  }
  ```

**2. Communication:**

- **Process Communication:**
  Processes use IPC mechanisms. Here’s an example using a pipe:

  ```cpp
  #include <unistd.h>
  #include <iostream>

  int main() {
      int pipefd[2];
      if (pipe(pipefd) == -1) {
          perror("pipe");
          return 1;
      }

      pid_t pid = fork();
      if (pid == 0) {
          // Child process
          close(pipefd[0]); // Close read end
          const char *msg = "Hello, parent!";
          write(pipefd[1], msg, sizeof(msg));
          close(pipefd[1]);
      } else if (pid > 0) {
          // Parent process
          close(pipefd[1]); // Close write end
          char buffer[128];
          read(pipefd[0], buffer, sizeof(buffer));
          std::cout << "Received from child: " << buffer << "\n";
          close(pipefd[0]);
      }
      return 0;
  }
  ```

- **Thread Communication:**
  Threads use shared memory, so synchronization mechanisms like mutexes, condition variables, and atomic operations are essential to avoid race conditions.

  ```cpp
  #include <iostream>
  #include <thread>
  #include <mutex>

  int counter = 0;
  std::mutex mtx;

  void increment() {
      for (int i = 0; i < 1000; ++i) {
          std::lock_guard<std::mutex> lock(mtx);
          ++counter;
      }
  }

  int main() {
      std::thread t1(increment);
      std::thread t2(increment);

      t1.join();
      t2.join();

      std::cout << "Counter value: " << counter << "\n";
      return 0;
  }
  ```

### Summary

- **Processes** are independent, isolated units of execution with separate memory spaces, suitable for running distinct applications or services.
- **Threads** are lightweight units of execution within a process, sharing memory space and suitable for tasks requiring frequent communication and data sharing.

By understanding these concepts, you can choose the appropriate concurrency mechanism in C++ based on your specific requirements for isolation, communication, and performance.
