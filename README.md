# Playground Games Submission

This repository is the submission for the engineering test given by Playground Game and is also hosted on [GitHub](https://github.com/abdullaahi140/Run-length-Encoding). The project compresses and decompresses files using Run-length Encoding. 

## Compiling the project

On Ubuntu, you will need to have CMake and G++. They can be installed using the following commands respectively:

```
sudo apt-get install cmake
sudo apt-get install g++
```

Then in the project repository, run the two following two commands:

```
cmake .
cmake --build .
```

This will create an executable inside the newly created `bin` folder. To execute this file, make sure you are in the root directory of the project and type `bin/main` in the terminal. 

To run the unit tests in the project, make sure you are in the root directory of the project and type `bin/test_compress` in the terminal.