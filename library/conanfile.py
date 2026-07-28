from conan import ConanFile
from conan.tools.build import check_min_cppstd
from conan.tools.cmake import CMake, CMakeConfigDeps, CMakeToolchain, cmake_layout
from conan.errors import ConanInvalidConfiguration

class MyLib(ConanFile):
    name = "mylib"
    version = "0.1.0"
    settings = "os", "arch", "compiler", "build_type"

    exports_sources = ['*']

    def requirements(self):
        self.requires("spdlog/[*]")

    def generate(self):
        tc = CMakeToolchain(self)
        dep = CMakeConfigDeps(self)
        tc.generate()
        dep.generate()

    def validate(self):
        check_min_cppstd(self, "20")
        if self.settings.compiler == "apple-clang":
            raise ConanInvalidConfiguration("Apple Clang isn't supported; use upstream LLVM on Apple platforms")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ['MyLib']
        self.cpp_info.set_property("cmake_find_mode", "none")
        self.cpp_info.set_property("cmake_file_name_variants", ["mylib", "MyLib"])
        self.cpp_info.builddirs = ["."]