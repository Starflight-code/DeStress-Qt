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

As soon as you're finished, just restart De-Stress Qt. Your file will be automatically loaded in and the number of program cycles (how many time to run your exercise per minute) will
be automatically determined. 
