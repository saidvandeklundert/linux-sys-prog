# linux-sys-prog

System programming in Linux

Learning abour C and Linux, following the book and https://github.com/stewartweiss/intro-linux-sys-prog.git




## Notes

In Unix systems, some resources are protected from access by ordinary programs and are accessible only by the operating system. These protected resources are called system resources. System resources include hardware, such as the CPU, physical memory, screen displays, storage devices, and network connections. They also include objects that aren’t hardware, such as system data structures and files. These are sometimes called soft resources.

There are APIs to access system resources. The functions these APIs offer are called 'system calls'.


We’ve now set the stage to make a distinction between ordinary programs and system programs. A program that’s not a system program is designed as if it has exclusive access to all of the resources it uses. It doesn’t deal with the complexity of connecting to monitors and keyboards and isn’t cognizant of the fact that the operating system must manage these resources. In contrast, a program that makes direct requests for the services exposed in an operating system’s API is called a system program, and when we write this kind of program we are system programming.

System programs make requests for resources and services directly from the operating system.

From its beginning, Unix was designed around a small set of clever ideas, as its authors, Dennis Ritchie and Ken Thompson, put it: “The success of UNIX lies not so much in new inventions but rather in the full exploitation of a carefully selected set of fertile ideas, and especially in showing that they can be keys to the implementation of a small yet powerful operating system”. Those “fertile ideas” included the concepts of a programmable shell, users and groups, privileged and unprivileged instructions, environments, files and the directory hierarchy, device-independent input and output, and most important, processes.