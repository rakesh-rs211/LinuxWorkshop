# Introduction to Linux Workshop - Winter 2024
This readme file is complimentary to slides for the workshop to make it ease for the user to follow through and copy the commands as required. 

## **Table of content** 
- [**Getting started**](#getting-started): Accessing a Linux Machine
- [**Linux shell**](#linux-shell)
- [**Navigating the filesystem**](#navigating-the-filesystem)
- **Creating and Modifying files**
- **Moving the files within the** *local* **filesystem**
- **View the file content**
- **Examing the content of the file**
- **Piping**
- **Search for files**
- **Copying and downloading files**
- **Redirecting input and output**
- **Environment variables**
- **Useful commands**

## Getting started
To begin with let's connect to a remote server, Frontenac, to access a *Linux Shell*

> ssh -Y sa130XXX@login.cac.queensu.ca

Note: Replace '*sa130XXX*' with the username you received earlier to your registered email. The *-Y* flag in the ssh command is for enable X11 forwarding for graphical interface. 

### *Exercise 0* 
1. Download a MobaXterm or any other terminal emulator and installing on your computer. For Mac user, you can open the '*Terminal*' application.
2. Connect to the Frontenac cluster using ssh-client. Instructions to access the cluster were provided in the email.
3. *Optional: If you are using **Windows** you can use powershell, instead.*

Take ~15 minutes to complete this exercise and give us a thumbs-up in the chat once you are logged in.

## Linux shell
Shell is a program that acts a interface between the user and the operating system(Linux kernel) through CLI. On most GNU based system, bash(Bourne-Again-Shell) is the default shell. Almost all operating system including *Windows* have a shell program. On *Windows*, we have *Powershell*. 

## Navigating the filesystem

Once you are logged to a Linux machine(Frontenac), let explore the filesystem with few basic commands.

 - **pwd**   :      Present Working Directory
 - **cd**    :      Change Directory
 - **ls**    :      list files and sub-directories in the directory

> $ pwd \
> */global/home/sa130000* \
> $ cd /global/project/Workshop2023/IntroLinux \
> $ cd .. &emsp;&emsp;      # Go to parent directory \
> $ cd ../..  &emsp;   # Moves two directories up \
> $ cd -  &emsp;&emsp;     # Goes to previous directory \
> */global/project/Workshop2023* \
> $ ls \
> *CourseMaterial.tar.gz  IntroBioInfo  IntroHPC  IntroLinux  IntroMPI_Python  IntroPython  sausers* \
> cd ./IntroLinux/CourseMaterial/  &emsp; # Relative path \
> $ cd ~  &emsp;&emsp;     # Go to user's home directory \
> $ pwd \
> */global/home/sa130000* 
>
> $ man ls ## Manual pages for the command *ls* \
> *Note: enter ':q' to exit the manual page*
