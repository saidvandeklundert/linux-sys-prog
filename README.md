# linux-sys-prog

System programming in Linux

Learning abour C and Linux, following the book and https://github.com/stewartweiss/intro-linux-sys-prog.git




## Notes 1

In Unix systems, some resources are protected from access by ordinary programs and are accessible only by the operating system. These protected resources are called system resources. System resources include hardware, such as the CPU, physical memory, screen displays, storage devices, and network connections. They also include objects that aren’t hardware, such as system data structures and files. These are sometimes called soft resources.

There are APIs to access system resources. The functions these APIs offer are called 'system calls'.


We’ve now set the stage to make a distinction between ordinary programs and system programs. A program that’s not a system program is designed as if it has exclusive access to all of the resources it uses. It doesn’t deal with the complexity of connecting to monitors and keyboards and isn’t cognizant of the fact that the operating system must manage these resources. In contrast, a program that makes direct requests for the services exposed in an operating system’s API is called a system program, and when we write this kind of program we are system programming.

System programs make requests for resources and services directly from the operating system.

From its beginning, Unix was designed around a small set of clever ideas, as its authors, Dennis Ritchie and Ken Thompson, put it: “The success of UNIX lies not so much in new inventions but rather in the full exploitation of a carefully selected set of fertile ideas, and especially in showing that they can be keys to the implementation of a small yet powerful operating system”. Those “fertile ideas” included the concepts of a programmable shell, users and groups, privileged and unprivileged instructions, environments, files and the directory hierarchy, device-independent input and output, and most important, processes.

The kernel is a program, or a collection of interacting programs, depending on the particular implementation of Unix, with many entry points.

### What does the Kernel do?

When a Unix system boots, a combination of firmware and software loads the kernel into the portion of memory called _system space_ or _kernel space_, where it stays until the machine is shut down. User programs are not allowed to access system space. If they try, the kernel terminates them.

The kernel has full access to all the hardware that is attached to the computer. The Unix kernal manages and protects system resources like input/output (I/O), memory, device usage and more. 

When a program writes to disk for instance, it does not access the hardware itself. Instead, it asks the Kernel to do this.

Because access to all these resources happens through the kernel, it enables the kernel to protect users from each other and against themselves while giving all users the impression that they have the computer entirely to themselves.

In order to ensure the kernal can achieve this, the inventors of Unix incorporated several key principles into its design:
- there are 2 levels of privilege: user privilege and kernel privilege
- every user has a unique identity. A priviliged user can create groups of users and those groups have unique identities as well. Users and group identifiers are assigne privileges and protections for all user resources such as disk storage, running programs and so on.
- the system of files support creation, modification, retrieval, and removal of persisted data and programs as well as privacy, protection and the ability to share software and data
- physical memory is divided into two regions: user space where ordinary programs run and system space where the operating system itself is stored
- the kernal has exclusive control of the use of the processor and it decides at any given time what runs next
- the kernel has the exclusive ability to load programs into memory, run them and terminate them. A running program cannot even terminate itself; it can only ask the kernal to terminate it.
- the kernel has complete and exclusive control of all computer hardware

Several kernel services:
- Process scheduling and management
- I/O handling
- Physical and virtual memory management
- Device management
- Filesystem management
- Signaling and interprocess communication
- Multithreading
- Protection and security
- Networking services

__kernel role image __

The first and oldest shell was the Bourne shell. The C- and Korn-shell were developped after that. The GNU project extended the Bourne shell taking some features from the Korn shell and the C shell.

In Unix systems, a user is an entity that can run programs and own files.

A group is a set of persons.

Users have a user ID and groups have a groupd ID.

Users and files can be associated with groups.

Root is a 'special' user whose UID is 0. It has absolute power over the system.

The kernels makes a distinction between privileged mode and unprivileged mode aka supervisor mode and user mode. Privileged instructions are instructions that can alter system resources, directly or indirectly. _Only the klernals is allowed to execute privileged instructions_.

When a program is run in Unix, one of the steps that the kernel takes prior to running the program is to make available to it an array of name-value pairs called the environment list, or simply the environment. Each name-value pair in this list is a string of the form name=value, where value is a NULL-terminated C string and there are no spaces around the = character. The name is called an environment variable and name=value is called an environment string.


Unix creators argued that the most important role of the operating system is to provide a file system and they went as far as to state that 'everything in UNIX is a file'.

### Files

From the kernels point of view, a file is just an object that contains a linear sequence of bytes. 

We can distinguish the following file types:
- directories
- device files
- pipes
- sockets
- symbolic links

### File attributes, permissions and content

All files have attributes that include all the important information about the file and collectively, they are called 'file status' or 'metadata'. This is different from the content or data of the file.

Some 'special' files have no content or data, they are interfaces that the kernel uses to implement device-independent intput and output.

File content and status are not stored together. The status is stored in a data structure called _inode_ whereas the contents may be spread out in multiple blocks on the same storage device as the inode.

Filenames are not port of the status of the file. A non-directory file can have multiple names and those names aren't an inherent property of the file itself.

A directory is a file that contains a table of directory entries, called _links_. A link is an object that associates a filename to an actual file. It has 2 components: a filename and a reference to a file's inode.

Files can have names in different directories. If a files has names in different directories, all the links will be pointing to the same inode.

Top level directories:
- `bin`: all essential binary executables, including shell commands that must be available when the computer is running in single-user mode
- `boot`: static files of the bootloader
- `dev`: essential device files
- `etc`: almost all configuration files, roughly like the registry file of Windows
- `home`: all user' home directories
- `lib`: essential shared libraries and kernel modules
- `media`: mount point for removable media
- `mnt`: mount point for mounting a filesystem temporarily
- `opt`: add-on application software packages
- `sbin`: essential system binaries
- `srv`: data for services provided by this system
- `tmp`: temporary files created by applications
- `usr`: originally, this was the top hierarchy of user data files, but now it's the top of a hierarchy containing nonessential binaries, libraries and sources. Typical subdirectories are /usr/bin and /usr/sbin, which contain binaries; /usr/lib, containing library files; and /usr/local, the top of a third level of local programs and data.
- `var`: variable files, meaning files whose content can change

`Symbolic` link is a file whose contents are just the name of another file. It is like a shortcut in Windows. Symbolic links are sometimes called soft links.

A process is an instance of a running program. Each separate instance of the same program is a different process, although each and every one of them is executing the exact same executable file.

By default, a program/process will have a single thread of control. This is a single sequence of instructions that is executed one instruction at a time, one af the other. Originally, all programs had 1 single thread of control.

To utilize modern hardware, programming lanugages and libraries were created that would allow a program to contain more then one thread of control, each of which could run on separate processors simultaneously.

The definiation of a thread is a single flow of control through a process together with the required system resources to support a flow of control.

Linux treats all threads as standard processes. There is no special scheduling or data structures for threads. To the Linx kernal, processes and threads are both called 'Tasks' and internally, both are represented by the `task_struct`.

One big difference between threads and processes is that in Linux, threads can share resources, such as their addresse space. Processes do not do this.

_ Linux man pages organization picture _

Linux comes with some documentation:
- man pages describes everything from Linux commands, APIs, system calls and more (`man ls`)
- info (usually) provides more elaborate information on commands (`info ls`)
- application documentation in /usr/share/doc, where individual Linux applications can provide their documentation (`ls --help`)
- Bash `help` lists everything available in the shell

Another extremely important source of information is the docs for the C std:
https://sourceware.org/glibc/manual/


## Notes 2

An object library is a file that bundles together, in a structured way, the compiled object code from multiple functions so that programs can call them easily. Libraries aren't stand-alone executables; they do not have a `main` function and you cannot run them.


Using a library requires that the library’s header file be included in the code with the appropriate #include directive (for example, `#include <termios.h>`) and, sometimes, that the library be linked explicitly because it isn’t in a standard place.

Unix supports 2 kinds of libraries:
- static: a library whose code can be linked to the program statically after the program is compiled. Here, the linker copies the library functions that are referenced into the executable. In Unix, static libs are suffixed with `.a` (archives).
- shared: not copied into the executable, but lined to the program at runtime. Because they are linked at runtime, they are also called `dynamic libraries` or `dynamically linked libraries`. Ends with `.so` (shared object).

Reason for statically linking is so that the executable is self-contained.

Shared library advantages:
- program has a smaller footprint and is loaded into memory faster
- more efficient memory usage. Instead of multiple copies in the systems memory, there is 1 memory-resident copy of the library that is linked to each program
- when the shared library is updated, programs linking to it do not need to be updated
- with dynamically linked executables, the kernel has the ability to load the libraries at arbitrary addresses, independent of each other, so that library code can have different addresses in each run, which makes such attacks much harder.

### System call execution

When a system call is made:
1. The user program makes a normal function call to the wrapper function in the library
2. The wrapper function copies the arguments of the call off of the stack and puts them into the registers where the kernel expects them
3. The wrapper executes the trap, passing the number of the system call as its argument. This causes the mode switch to supervisor mode and the jump to the kernel's system call handler.
4. The kernel's system call handler uses the number passed to it to access the system call vector at that offset. The vector contains the address in system space of the actual kernel code for that call.
5. The actual call code is executed, and it passes the return value back to the system call handler.
6. The handler passes the return value to the wrapper; the return instruction executed by the handler causes the switch back to user mode. If an error occured, the wrapper function makes the error code available to the program.

_usermode kernal mode pic_


In case there are no wrappers available, the users have to resort to `syscall` and pass in the call's number and argument.

In summary, there are multiple ways to the kernel services:
- calling a library function that does not need to make a system call
- calling a library that does make a system call
- making a system call through a wrapper function
- in rare cases, using `syscall` to make the system call

_paths to kernel pic_

System call errors are signalled through their return value. When a system call returns a negative number, it is stored in a static variable named `errno` and it returns -1 to the calling program. By incuding errno.h in your program, you can read the value that is stored in errno.