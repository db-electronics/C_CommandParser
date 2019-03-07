# C_CommandParser
An C library to tokenize and parse commands received in a string most likely over serial/USB

# VSCode Setup
To build and debug in VSCode on a Linux platform two files, *tasks.json* and *launch.json* must be created inside a *.vscode* directory. You will also need gcc and gdb obviously.

The debug launch command first builds the C code using the *-ggdb* switch to *debug.out*. The default build commands simply outputs an executable *release.out*.

Copy the following contents into the respective files.

## tasks.json
```
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "gcc -o release.out ${workspaceFolder}/*.c",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "label": "debugbuild",
            "type": "shell",
            "command": "gcc -ggdb -o debug.out ${workspaceFolder}/*.c",
            "options": {
                "cwd": "${workspaceFolder}"
            },
        }
    ]
}
```

## launch.json
```
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/debug.out",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "debugbuild"
        }
    ]
}
```