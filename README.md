# Windows

Using the x64 Cross Tools Command Promt for VS2017

```mkdir build && cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug .. ```
```cmake --build . -- -v ```

Gives:
```
[1/2] "C:\Program Files\CMake\bin\cmake.exe" -E __run_co_compile --tidy="C:/Program Files/LLVM/bin/clang-tidy.exe;-enable-check-profile;-checks=''" --source=..\src\aligned_buffer.cc -- 
C:\PROGRA~2\MIB055~1\2017\PROFES~1\VC\Tools\MSVC\1416~1.270\bin\Hostx64\x86\cl.exe  /nologo /TP  -I..\inc /DWIN32 /D_WINDOWS  /GR /EHsc /MDd /Zi /Ob0 /Od /RTC1   /Od /W4 /Zi /showIncludes 
/FoCMakeFiles\llvm-demo.dir\src\aligned_buffer.cc.obj /FdCMakeFiles\llvm-demo.dir\llvm-demo.pdb /FS -c ..\src\aligned_buffer.cc
..\src\aligned_buffer.cc(5): warning C4100: 'length': unreferenced formal parameter
..\src\aligned_buffer.cc(5): warning C4100: 'from': unreferenced formal parameter
..\src\aligned_buffer.cc(6): warning C4189: 'comp_ptr': local variable is initialized but not referenced
[2/2] cmd.exe /C "cd . && C:\PROGRA~2\MIB055~1\2017\PROFES~1\VC\Tools\MSVC\1416~1.270\bin\Hostx64\x86\link.exe /lib /nologo /machine:X86 /out:llvm-demo.lib CMakeFiles\llvm-demo.dir\src\aligned_buffer.cc.obj  && cd ."
```

# Linux
```mkdir build && cmake -DCMAKE_BUILD_TYPE=Debug ..```
```cmake --build .``` 

Gives:
```
Scanning dependencies of target llvm-demo
[ 50%] Building CXX object CMakeFiles/llvm-demo.dir/src/aligned_buffer.cc.o
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:5:21: warning: unused parameter 'from' [clang-diagnostic-unused-parameter]
bool Compare(size_t from, const void* buf_ptr, size_t length) {
                    ^
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:5:55: warning: unused parameter 'length' [clang-diagnostic-unused-parameter]
bool Compare(size_t from, const void* buf_ptr, size_t length) {
                                                      ^
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:6:9: warning: use auto when initializing with a cast to avoid duplicating the type name [modernize-use-auto]
  const TU8* comp_ptr = static_cast<const TU8*>(buf_ptr);
        ^~~~
        auto
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:6:14: warning: unused variable 'comp_ptr' [clang-diagnostic-unused-variable]
  const TU8* comp_ptr = static_cast<const TU8*>(buf_ptr);
             ^
/tmp/workspace/llvm-demo/src/aligned_buffer.cc: In function ‘bool Compare(size_t, const void*, size_t)’:
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:6:14: warning: unused variable ‘comp_ptr’ [-Wunused-variable]
   const TU8* comp_ptr = static_cast<const TU8*>(buf_ptr);
              ^
/tmp/workspace/llvm-demo/src/aligned_buffer.cc: At global scope:
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:5:21: warning: unused parameter ‘from’ [-Wunused-parameter]
 bool Compare(size_t from, const void* buf_ptr, size_t length) {
                     ^
/tmp/workspace/llvm-demo/src/aligned_buffer.cc:5:55: warning: unused parameter ‘length’ [-Wunused-parameter]
 bool Compare(size_t from, const void* buf_ptr, size_t length) {
                                                       ^
[100%] Linking CXX static library libllvm-demo.a
[100%] Built target llvm-demo
```
