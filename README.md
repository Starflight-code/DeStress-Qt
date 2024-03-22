# DeStress-Qt
DeStress yourself with some guided breathing exercises. This project is similar to the original DeStress project but with Qt as a GUI library, hense it's name. 

## Extending De-Stress
Build your own exercises using DeStress by placing an addon file in the assets folder (automatically generated on first run).
An example file is included, 4 4 4 breathing. Your text should be on the first line and the duration in seconds can be on the next.
The file name (without the .txt) will be used as the exercise name in the main menu.

> 4-4-4 breathing.txt
```
Breathe In
4
Hold
4
Breathe Out
4
Hold
4
```

> A more abstract example
```
<Text for Step 1>
<Duration In Seconds (for Step 1)>
<Text for Step 2>
<Duration In Seconds (for Step 2)>
```
> This program contains only 2 steps, you can have an infinite number in your own files.

As soon as you're finished, just restart De-Stress Qt. Your file will be automatically loaded in and the number of program cycles (how many time to run your exercise per minute) will
be automatically determined. 

## Build Instructions
Officially Supported/Tested Dependencies (Requirements):
- Qt (5.15.13)
- CMake

Officially Supported/Tested Compilers:
- GCC

Officially Supported Operating Systems:
- Linux (x86-64)

> Note: DeStress Qt may work on unsupported platforms/Qt versions/compilers but functionality has not been verified. If you would like to help expand official support, pull requests are welcome.

Instructions
- `cmake -s . -b build` (Generate the Build Files)
- `cd build` (Navigate to the Build Directory)
- `cmake --build .` (Build the Program)
- `./DeStress-QT` (Run The Executable)
> If these instructions do not work on your system, open a ticket and reach out on Discord/Matrix for a speedier response.  
