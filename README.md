<div align="center">
  <h1>Simple Shell <img src="https://cdn-icons-png.flaticon.com/128/6821/6821173.png" width=60 align=center> </h1>
  <h6>
    <a href="#">Man Page</a>
    ·
    <a href="#">Compilation</a>
    ·
    <a href="#">Commands</a>
    ·
    <a href="#">Usage</a>
  </h6>
  <img src="#">
</div>

## Description <img src="https://cdn-icons-png.flaticon.com/128/1903/1903496.png" width=45 align=center>

Simple Shell is a command line interpreter developed in C language that emulates the most basic functionality of `sh`.

## Man page <img src="https://cdn-icons-png.flaticon.com/128/781/781103.png" width=50 align=center>

The man page is a file wich explains in detail how Simple Shell works. If you want see a full explanation of this function you can run our man page this way:
```
$ man ./man_1_simple_shell
```

## Flowchart

## Compilation <img src="https://cdn-icons-png.flaticon.com/128/8084/8084300.png" width=50 align=center>

To compile the program this command has to be executed:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
To run the shell is like this:
```
$ ./hsh
```
## List of Files

| Function Name | Description |
|---------------- | -----------|


## Modes
The user can have the experience in an interactive and non-interactive way.

To use the **interactive mode** use . Immediately the user will see a warning $ indicating that our shell is ready to read the command.
And to exit the program, use the word  ```exit```.
Example:
```
$ ./hsh
$ /bin/ls
```

En **non-interactive mode** the user will enter command line arguments,In non-interactive mode, you can pipe commands to the program using echo or cat:

Example:
```
$ echo "/bin/ls" | ./hsh
$ cat file_name | ./hsh
```

## Bugs
No known bugs.


## Authors <img src="https://cdn-icons-png.flaticon.com/128/2463/2463510.png" width=50 align=center>

* Ishay Junnco <a href="#" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Oscar J Alfaro M <a href="#" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
<br>

> Project developed during the [Holberton School](https://www.holbertonschool.com/) program.
