# stacktrace


- debug mode
```
c:\users\i066088\source\repos\consoleapplication1\dll1\dll1.cpp(51) : 0x00007FFE46AF73B6 : foo : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\DLL1.dll
 c:\users\i066088\source\repos\consoleapplication1\consoleapplication1\consoleapplication1.cpp(18) : 0x00007FF754B222A1 : main : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe
  d:\agent\_work\2\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl(79) : 0x00007FF754B22DB4 : invoke_main : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe
   d:\agent\_work\2\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl(288) : 0x00007FF754B22C5E : __scrt_common_main_seh : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe
    d:\agent\_work\2\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl(331) : 0x00007FF754B22B1E : __scrt_common_main : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe
     d:\agent\_work\2\s\src\vctools\crt\vcstartup\src\startup\exe_main.cpp(17) : 0x00007FF754B22E49 : mainCRTStartup : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Debug\ConsoleApplication1.exe
       No Source File (0) : 0x00007FFE54847974 : BaseThreadInitThunk : C:\WINDOWS\System32\KERNEL32.DLL
        No Source File (0) : 0x00007FFE56F8A261 : RtlUserThreadStart : C:\WINDOWS\SYSTEM32\ntdll.dll
 ```       
        
- release mode
```
c:\users\i066088\source\repos\consoleapplication1\dll1\dll1.cpp(51) : 0x00007FFE4751115F : foo : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Release\DLL1.dll
 c:\users\i066088\source\repos\consoleapplication1\consoleapplication1\consoleapplication1.cpp(20) : 0x00007FF619A7108F : main : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Release\ConsoleApplication1.exe
  d:\agent\_work\2\s\src\vctools\crt\vcstartup\src\startup\exe_common.inl(288) : 0x00007FF619A712F4 : __scrt_common_main_seh : C:\Users\i066088\source\repos\ConsoleApplication1\x64\Release\ConsoleApplication1.exe
    No Source File (0) : 0x00007FFE54847974 : BaseThreadInitThunk : C:\WINDOWS\System32\KERNEL32.DLL
     No Source File (0) : 0x00007FFE56F8A261 : RtlUserThreadStart : C:\WINDOWS\SYSTEM32\ntdll.dll
 ```
