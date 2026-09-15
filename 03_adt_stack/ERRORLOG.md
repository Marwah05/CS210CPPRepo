Error 1:
[ 33%] Building CXX object CMakeFiles/03_adt_stack.dir/03_adt_stack/main.cpp.obj
[ 66%] Building CXX object CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj
C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\main.cpp: In function 'int main()':
C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\main.cpp:18:31: error: 'class Stack' has no member named 'top'; did you mean 'pop'?
18 |     std::cout << "Top: " << s.top() << std::endl;
|                               ^~~
|                               pop
mingw32-make[3]: *** [CMakeFiles\03_adt_stack.dir\build.make:78: CMakeFiles/03_adt_stack.dir/03_adt_stack/main.cpp.obj] Error 1
mingw32-make[3]: *** Waiting for unfinished jobs....
mingw32-make[2]: *** [CMakeFiles\Makefile2:180: CMakeFiles/03_adt_stack.dir/all] Error 2
mingw32-make[1]: *** [CMakeFiles\Makefile2:187: CMakeFiles/03_adt_stack.dir/rule] Error 2
mingw32-make: *** [Makefile:149: 03_adt_stack] Error 2

Description and solution: This error was caused because my Stack class (in Stack.h) declared a function called peek(), not top(). main.cpp was trying to call that s.top() while there was no top() because I had commented it. The solution was to go back to main.cpp and use s.peek() instead of top due to the fact that i commented it (can't be used anymore). 


Error 2:
"C:\Program Files\JetBrains\CLion 2026.2.1\bin\cmake\win\x64\bin\cmake.exe" --build C:\Users\marwa\Downloads\CS210\CS210CPPRepo\cmake-build-debug --target 03_adt_stack -- -j 14
[ 33%] Building CXX object CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj
C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\Stack.cpp:53:5: error: no declaration matches 'int Stack::isFull() const'
53 | int Stack::isFull() const {
|     ^~~~~
In file included from C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\Stack.cpp:9:
C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\Stack.h:24:10: note: candidate is: 'bool Stack::isFull() const'
24 |     bool isFull() const;
|          ^~~~~~
C:\Users\marwa\Downloads\CS210\CS210CPPRepo\03_adt_stack\Stack.h:16:7: note: 'class Stack' defined here
16 | class Stack {
|       ^~~~~
mingw32-make[3]: *** [CMakeFiles\03_adt_stack.dir\build.make:92: CMakeFiles/03_adt_stack.dir/03_adt_stack/Stack.cpp.obj] Error 1
mingw32-make[2]: *** [CMakeFiles\Makefile2:180: CMakeFiles/03_adt_stack.dir/all] Error 2
mingw32-make[1]: *** [CMakeFiles\Makefile2:187: CMakeFiles/03_adt_stack.dir/rule] Error 2
mingw32-make: *** [Makefile:149: 03_adt_stack] Error 2

Description and solution: This error was caused by the fact that my header and implementation didn't have the same return type. In my Stack.h file isFull() was set as a bool, while in Stack.cpp it was set as an int, which caused a declaration mismatch. The solution was just to go back to Stack.cpp and fix the return type from int to bool.