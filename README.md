# Conan CMakeConfigDeps

Build:

```sh
conan export library
conan install . -s build_type=Debug -pr:h clang -pr:b clang --build=missing
(source build/Debug/generators/conanbuild.sh ; cmake --preset conan-debug -G "Ninja" && cmake --build --preset conan-debug)
```

Error:

```
CMake Error at CMakeLists.txt:8 (find_package):
  By not providing "FindMyLib.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "MyLib", but
  CMake did not find one.

  Could not find a package configuration file provided by "MyLib" with any of
  the following names:

    MyLib.cps
    mylib.cps
    MyLibConfig.cmake
    mylib-config.cmake

  Add the installation prefix of "MyLib" to CMAKE_PREFIX_PATH or set
  "MyLib_DIR" to a directory containing one of the above files.  If "MyLib"
  provides a separate development package or SDK, be sure it has been
  installed.
```

But edit conanfile.py::generate to switch to `CMakeDeps`, and it works.

## Environment

* Linux
* clang version 22.1.1
* Conan version 2.31.1
* Python 3.14.5
* CMake versions 4.3.0 and 4.4.20260625-gcdcc758
* Ninja version 1.13.1