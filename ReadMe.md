# Introduction to Linux Workshop - Winter 2024
This readme file is complimentary to slides for the workshop to make it easier to follow through and copy the commands, as required. 

## **Table of content** 
[**Getting started**](#getting-started)\
[**Linux shell**](#linux-shell)\
[**Navigating the filesystem**](#navigating-the-filesystem)\
[**Creating and Modifying files**](#creating-files)\
[**Moving the files within the** ***local*** **filesystem**](#copying-and-moving-files)\
[**View the file content**](#view-file-content)\
[**Examing the content of the file**](#examine-the-file-content)
[**Piping**](#piping) \
[**Searching for files**](#searching-for-files) \
[**Copying and downloading files**](#copying-and-downloading-files) \
[**Redirecting input and output**](#redirecting-input-and-output) \
[**File permissions**](#file-permissions) \
[**Environment variables**](#environment-variables) \
[**List of Exercises**](#list-of-exercises)

## Getting started
To begin with let's connect to a remote server, Frontenac, to access a *Linux Shell*

> ssh -Y sa130XXX@login.cac.queensu.ca

Note: Replace '*sa130XXX*' with the username you received earlier to your registered email. The *-Y* flag in the ssh command is for enable X11 forwarding for graphical interface. 

### *Exercise 0* 
1. Download a MobaXterm or any other terminal emulator and installing on your computer. For Mac user, you can open the '*Terminal*' application.
2. Connect to the Frontenac cluster using ssh-client. Instructions to access the cluster were provided in the email.
3. *Optional: If you are using **Windows** you can use powershell, instead.*

Take ~15 minutes to complete this exercise and give us a thumbs-up in the chat once you are logged in.

**Note(Optional)**: Course material for this workshop are located at '/global/project/Workshop2023/IntroLinux/CourseMaterial.tar.gz'. You have read permission to copy the 'tar' file. We have created a folder '/global/project/Workshop2023/sausers' with read/write access to all the student accounts. You can create a new sub-directory with your username,'sa130xxx', in this path and copy the file 'CourseMaterial.tar.gz' here.

After copying 'tar' to a folder, you can use the following command to untar or decompress the file
```console
tar xvfz CourseMaterial.tar.gz
```
## Linux shell
Shell is a program that acts a interface between the user and the operating system(Linux kernel) through CLI. On most GNU based system, bash(Bourne-Again-Shell) is the default shell. Almost all operating system including *Windows* have a shell program. On *Windows*, we have *Powershell*. 

## Navigating the filesystem

Once you are logged to a Linux machine(Frontenac), let explore the filesystem with few basic commands.

 - **pwd**   :&emsp;      Present Working Directory
 - **cd**    :&emsp;&emsp;      Change Directory
 - **ls**    :&emsp;&emsp;      List files and sub-directories in the directory
```console
$ pwd 
/global/home/sa130000 
$ cd /global/project/Workshop2023/IntroLinux 
$ cd ..              # Go to parent directory 
$ cd ../..           # Moves two directories up
$ cd -               # Goes to previous directory 
/global/project/Workshop2023
$ ls 
CourseMaterial.tar.gz  IntroBioInfo  IntroHPC  IntroLinux  IntroMPI_Python  IntroPython  sausers
$ cd ./IntroLinux/CourseMaterial/   # Relative path 
$ cd ~               # Go to user's home directory 
$ pwd 
/global/home/sa130000
```
```console
$ man ls # Manual pages for the command 'ls' 
Note: enter ':q' to exit the manual page*
```

### Excerise 1
Take 10 minutes for this exercise to explore the filesytem.

1. Open a terminal on your local computer(or on Frontenac) and change present working directory to $HOME and identify all the files in the folder 
2. (Optional) Explore various flags for ‘ls’ command using ‘man’ or ‘- -help’ and find the option to print all the files including hidden file(has a ‘.’ prefix in the file name)
3. Change the directory to '/global/project/Workshop2023/IntroLinux' and list all the sub-folders

## Creating files

Now, lets create a few files and learn how to read and write to these files. Note, in linux everything is a file, including directories

### List of commands
- **mkdir** : Creates a new sub-directory
- **touch** : Create an empty file
- **echo**  : Display the text to screen or *stdout*
- **nano**  : Text editor; other editors: vim, emacs
- **cat**   : Display the content of the file

```console
$ cd /global/project/Workshop2023/sauser
$ mkdir sa130XXX    # Replace with your username
$ cd sa130XXX
$ mkdir Example01 & cd Example01 # Create a subfolder and change directory

$ touch file01.txt
$ ls
file01.txt
$ echo "First line of the file" # print to screen(stdout)
First line of the file
$ echo "First line of the file" > file01.txt # Redirect output to the file instead of the screen
$ cat file01.txt    # Output the content of the file
First line of the file
$ nano file01.txt ## Open the file in a text editor
```

## Copying and moving files 

Here, we will learn how to move, copy, delete files

### List of commands

- **mv** : Move or rename a file or files
- **cp** : Copy file or files
- **rm** : delete/remove file or files
- **ln** : Create a link to a file(equivalent to shortcut in 'Windows')

```console
[Example01]$ ls
file01.txt
[Example01]$ cp file01.txt file01.bak.txt
[Example01]$ ls
file01.bak.txt  file01.txt
[Example01]$ rm file01.bak.txt
[Example01]$ mv file01.txt file01_renamed.txt
[Example01]$ mkdir backup_dir
[Example01]$ cp file01_renamed.txt file01.txt
[Example01]$ mv file01.txt ./backup_dir/
[Example01]$ ls
backup_dir  file01_renamed.txt
[Example01]$ ls backup_dir/
file01.txt
```

### Exercise 02: Creating files

Take 15 minutes to complete this exercise

1. Change directory to ‘/global/project/Workshop2023/sausers’ and create a folder with your username ‘sa130xxx’
2. Create a file in this folder and enter your first line(‘This is the first line’) into this file 
3. Now copy the file to a new file
4. And add a second line to the folder ‘This is a second line’
5. *Optional*: Examine the difference between the first file and second file using ‘diff’. Use ‘man’ command to find the syntax for 'diff' command.

## View file content

### List of commands
- **more** : View file content
- **less** : View file content
- **head** : First few lines of the file
- **tail** : Last few lines of the file

```console
[IntroLinux]$ cd grep_Tut
[grep_Tut]$ more NameList_200.txt
…
[grepTut]$ head -n 6 NameList_200.txt
FNAME, LNAME, City, Province
Arwen, Kirk, Ottawa, ON
Thor, Lannister, Kingston, ON
Trinity, Smith, Waterloo, ON
Athena, Gandalf, Winnepeg, MB
Juliet, Smith, Halifax, NS

[grepTut]$ tail -n 5 NameList_200.txt
Bilbo, Gandalf, Vancouver, BC
Trinity, Smith, Vancouver, BC
Shrek, Baratheon, Calgary, AB
Bruce, Loki, Halifax, NS
Athena, Bane, Toronto, ON
```
Commands to copy course material
```
cd /global/project/Workshop2023/sausers/
cp CourseMaterial.tar.gz sa130244/
cd sa130244
tar xvfz CourseMaterial.tar.gz
cd CourseMaterial/
```
Just the commands
```
cd grep_Tut
more NameList_200.txt
head -n 6 NameList_200.txt
tail -n 5 NameList_200.txt
```

## Examine the file content

### List of commands
- **grep** : Search for a keyword/s
- **wc**   : Word, line count

### Regular expressions(regex) 
 &emsp; **\.** &emsp;&emsp; Match any single character \
 &emsp; **\*** &emsp;&emsp; Any character must appear zero or more times \
 &emsp; **\?** &emsp;&emsp; Preceding character must appear once \
 &emsp; **\^** &emsp;&emsp; Match pattern at the begin of line \
 &emsp; **\$** &emsp;&emsp; Match pattern at the end of line \
 &emsp; **\\** &emsp;&emsp; Escape the special character \
 &emsp; **\[\]** &emsp;&emsp; Should contain any of the characters within the '[]' \
 &emsp; **\|** &emsp;&emsp; Can be use to match one or more patterns

 ```console
[IntroLinux]$ cd grep_Tut
[grep_Tut]$ grep ‘Toronto’  NameList_200.txt
[grep_Tut]$ wc NameList_200.txt
[test0]$ wc -l example3.fastq
400 example3.fastq
[grep_Tut]$ ls ./Nek5000/bin/nekb*
nekb  nekbb  nekbmpi
[grep_Tut]$ ls ./Nek5000/bin/nek[1-9]*
nekb  nekbb  nekbmpi
[grep_Tut]$ grep ‘[tT]oronto’  NameList.txt
[grep_Tut]$ grep ‘Toronto|Ottawa’  NameList.txt
 ```
Just the commands
 ```
 grep ‘Toronto’  NameList_200.txt
 wc NameList_200.txt
 wc -l example3.fastq
 ls ./Nek5000/bin/nekb*
 ls ./Nek5000/bin/nek[1-9]*
 grep ‘[tT]oronto’  NameList.txt
 grep ‘Toronto|Ottawa’  NameList.txt
 ```
## Piping
We can redirect(or pipe) output from command to the other using '|' key. You can find this key('|'), just above the 'Enter' key on most keyboards.

```console
[IntroLinux]$ cd grep_Tut
[grep_Tut]$  cat NameList_200.txt |grep ON| wc –l
89
[grep_Tut]$ grep 'ON' NameList_200.txt | grep -v 'Toronto' |wc –l
76
```

### Exercise 03
 Examing the content of the files using regex and pipes

1. Copy ‘1_control_trnL_2019_minq7.fastq’ from ‘IntroLinux/CourseMaterial/grepTut’ to your folder in ‘IntroLinux /sausers/’
2. And count the number of lines in the file
3. (Optional) Find the number of lines with the sequence A,C,T,G; with atleast 10 characters in each sequence.
4. (Optional) Download NEK5000 tar file from github and untar the file. You can find the commands in ‘IntroLinux/CourseMaterial/grepTut DownloadCommands’

## Searching for files

- **find** : Find the files and directories in specified directories and sub-directories

```console
$ module load nixpkgs/16.09
$ module load qt/5.9.6
$ cd $EBROOTQT5
[5.9.6]$ find $EBROOTQT5 -type d -name "Qt*"
…
[5.9.6]$ find $EBROOTQT5 -type f -name "qt*"
…
```
 
 ## Copying and Downloading files
We can use the following set of commands to download file from remote server/internet

- **wget**: Download files using http/ftp protocol from the internet
- **git clone**: To download files from GitHub
- **scp/sftp** : To copy files to and from remote servers

When you are downloading multiple file from elsewhere, they are usually shared in a compressed format such as tar or zip files

- **tar/gunzip**: To compress/decompress files

```console
scp -R ./myfile.txt sa130000@login.cac.queensu.ca:~
```

### Download Commands
```console
wget ftp://ftp.ensembl.org/pub/release-77/gtf/drosophila_melanogaster/Drosophila_melanogaster.BDGP5.77.gtf.gz
gunzip Drosophila_melanogaster.BDGP5.77.gtf.gz

wget https://github.com/Nek5000/Nek5000/archive/refs/tags/v19.0.tar.gz
tar xvfz v19.0.tar.gz

git clone https://github.com/Nek5000/Nek5000.git
wget https://zenodo.org/records/3736457/files/1_control_trnL_2019_minq7.fastq?download=1 -o 1_control_trnL_2019_minq7.fastq
```
### Exercise 4

1. Create a file called ‘Local_file.txt’ on your local terminal(not Frontenac). Add a few lines to this file and upload it to your $HOME directory Frontenac cluster.

## Redirecting Input and Output

On the shell, the input is taken from keyboard and the output is printed to the terminal or the screen. Linux shell offers the flexibility to redirect the input and output, elsewhere. For example, we can print the output to a file instead of the screen.

We can redirect standard out(***stdout***), standard error(***stderr***) and standard input (***stdin***) using '***>***' and '***<***'.

```console
[04_CalcPi]$ ./calcPi
No arguments were entered defaulting to N=10000
The value of PI is: 3.1416

[04_CalcPi]$ ./calcPi > out.txt
[04_CalcPi]$ cat out.txt
The value of PI is: 3.1416

[04_CalcPi]$ ./calcPi 1>out.txt 2>/dev/null
[04_CalcPi]$ cat out.txt
The value of PI is: 3.1416

[04_CalcPi]$ ./calcPi 1>out.txt 2>&1
[04_CalcPi]$ cat out.txt
The value of PI is: 3.1416

[04_CalcPi]$ wc –l < calcPi.c
23
```
## File permissions

### Exercise 5
1. Copy the folder from '*/global/project/Workshop2023/IntroLinux/CourseMaterial/Example01*' and troubleshoot if you face any issue
Note: All sa130XXX accounts are part of sg130000  group

## Environment variables
```console
$ env
$ var="This is a new variable"
$ echo $var
$ myWorkDir="~/.local/workdir'
$ mkdir -P $myWorkDir
$ cd $myWorkDir
$ pwd
/global/home/sa130000/.local/workdir
```
### Exercise 6
1. Load a module called dealii using the following commands and check how the path variable changes with each command
   ```console
	module --force purge
	module load StdEnv/2020 gcc/9.3.0
	module load dealii
   ```

2. On Frontenac we use Slurm as our job scheduler. Running the following to ask for interactive node through scheduler.
    ```
    salloc --nodes=1 --ntasks=1 --mem=1g --time=15:00 
    ```
    Once the job is allocated find all the environment variable that start with ‘SLURM’. Use ‘grep’ command to search for the variables.
   
## List of exercises
0. [**Accessing a cluster**](#exercise-0)
1. [**Exploring the filesystem**](#excerise-1)
2. [**Creating files**](#exercise-02-creating-files)
3. [**Examine file content**](#exercise-03)
4. [**Upload files**](#exercise-4)
5. [**File permissions**](#exercise-5)
6. [**Environment variable**](#exercise-6)
