# Terminal Wordle

Terminal adaptation of the popular game Wordle.

<p align="center">
  <img src="https://github.com/csierrad/terminal_wordle/blob/main/images/demo_wordle.gif" alt="Wordle demo"/>
</p>



## How to play?

Once downloaded the code, you only have to compile it with the instruction:

```makefile
make
```

Once compiled, it automatically creates a build folder with an executable file called final_program.

To execute it just type in terminal: 

```makefile
./build/final_program
```

## Dictionary

Currently it’s only available the spanish dictionary but in a near future more languages will be included.

The words used are provided by a list of 2000 of the most common words in spanish which are filtered to keep only the ones with 5 letters (about 600).

[Link to the original list](https://github.com/bitcoin/bips/blob/master/bip-0039/spanish.txt)

## Discalimer

The code of this program wont probably be the most correct and clean code of the world so be carefull when using it because it could be full of bad habits and errors. (like non freeing the dinamically allocated variables, in process of being fixed).

Any kind of feedback is appreciated to keep learning. Thanks :)
