# GoogleTest Project
Create a demo examle for gtest usage.

## Prerequisites BUILD

### VSCode

Download VSCode to build this project.

[VSCode](https://code.visualstudio.com/download)

Download VSCode CMake Tools Extension 

[VSCode CMake Tool](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

### Compiler 

This project is supported gcc versions: 

9.3, ..., 12.2

Mainly tests are applied on 12.2.0 version

### CMAKE

Download CMake to build GLFW library

[CMake](https://cmake.org/download/)

(Windows x64 Installer) 

[CMake](https://github.com/Kitware/CMake/releases/download/v3.28.1/cmake-3.28.1-windows-x86_64.msi)

### GoogleTest

Download GoogleTest to implement library functions.

Google Test download

[GTest Github](https://github.com/google/googletest)

Build Google Test Library with CMake

VSCode Extension TestMate C++ download

[VSCode Test Extension](https://marketplace.visualstudio.com/items?itemName=matepek.vscode-catch2-test-adapter)

Create a VSCodeApplication with CMake

Create a test directory, add subdirectory to main CMakeList.txt

Add dependencies, library files, header files, modify CMakeList.txt and build with CMake,

Extension => TestMate C++ is visible after download, write some tests as ExampleTests.cpp and it could be seen if it fails or pass

Open Terminal
  ```
    mkdir build
    cd build
    cmake -g "Unix Makefiles" ..
    make install
  ```
cpy lib files and add to cmakelist.txt

Ctrl+Shift+P > CMake Set Debug Target > GoogleTest \ App
Ctrl+Shift+P > CMake Set Build Target > GoogleTest \ App
 
# PROFILING AN APP PERFORMANCE AND MEMORY ANALYSING

### Valgrind (Memory Analysing)

  ```
    sudo apt-get download valgrind
    sudo dpkg -i /path/to/.deb
  ```

While in executable folder open terminal,

  ```
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./exeFileName
  ```

### Visualize Program Performance(Gprof | Gprof2dot | dot)

CMakeLists.txt 

add_compile_options(-pg)
add_link_options(-pg)

terminal 
  ```
    gprof exeFileName gmon.out > report.txt
  ```

That will give a binary output of grof documentation

## Gprof2dot

  ```
    mkdir build
    cd build

    sudo apt-get download python3
    sudo apt-get download graphviz
    sudo apt-get download python3-pip
    sudo dpkg -i /path/to/python3
    
    mkdir graphviz_dep
    cd grahviz_dep
    sudo apt-rdepends graphviz | grep -v "^ " | xargs -I {} sudo apt-get download {}
    sudo dpkg -i *.deb
    cd..

    mkdir pip_dep
    cd pip_dep
    sudo apt-rdepends python3-pip | grep -v "^ " | xargs -I {} sudo apt-get download {}
    sudo dpkg -i *.deb
    cd..

    sudo dpkg -i /path/to/graph/deb
    sudo dpkg -i /path/to/pip/deb

    sudo apt-get download python3.8-venv
    sudo dpkg -i /path/to/venv/deb

    //Set up python environment before usage of grof2dot
    python3 -m venv myenv
    source myenv/bin/activate

    pip download gprof2dot
    pip install /path/to/gprof2dot.whl
  ```

    after downloads go to application exe file path 
  ```
    gprof ./exeFileName gmon.out | gprof2dot -w | dot -Gdpi=200 -Tpng -o output.png
  ```
    
## Contribute

Contributions are always welcome!
Please reach me [contact-addres](https://www.linkedin.com/in/%C3%A7a%C4%9Fr%C4%B1-d%C3%BCk%C3%BCnl%C3%BC-msc-a47b83131/) first.
