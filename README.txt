How to run tests
-----------------------------
Run the below 3 cmake commands:

PS C:\Users\Steven\Desktop\OOP\GroupProject1> cmake -S . -B build
-- Selecting Windows SDK version 10.0.19041.0 to target Windows 10.0.19045.
...
-- Configuring done (1.6s)
-- Generating done (0.5s)
-- Build files have been written to: C:/Users/Steven/Desktop/OOP/GroupProject1/build


PS C:\Users\Steven\Desktop\OOP\GroupProject1> cmake --build build
Microsoft (R) Build Engine version 17.0.0+c9eb9dd64 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  1>Checking Build System
 ...
  Building Custom Rule C:/Users/Steven/Desktop/OOP/GroupProject1/CMakeLists.txt


PS C:\Users\Steven\Desktop\OOP\GroupProject1> cd build
PS C:\Users\Steven\Desktop\OOP\GroupProject1\build> ctest
Test project C:/Users/Steven/Desktop/OOP/GroupProject1/build
    Start 1: HelloTest.BasicAssertions
1/1 Test #1: HelloTest.BasicAssertions ........   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec