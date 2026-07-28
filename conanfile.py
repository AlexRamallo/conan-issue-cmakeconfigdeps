from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeConfigDeps, CMakeDeps, CMake, cmake_layout

class Consumer(ConanFile):
    name = "consumer"
    version = '0.1.0'
    settings = 'os', 'build_type', 'arch', 'compiler'

    def requirements(self):
        self.tool_requires('cmake/4.3.0')
        self.requires('mylib/0.1.0')

    def layout(self):
        cmake_layout(self)

    def generate(self):
        CMakeToolchain(self).generate()
        
        # works:
        CMakeDeps(self).generate()

        # doesn't work:
        # CMakeConfigDeps(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
