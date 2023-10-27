from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
import re


def get_version():
    try:
        version = ""
        with open("CMakeLists.txt", "r") as file:
            line = [x for x in file.readlines() if "LIBRARY_VERSION" in x]
            line = line[0].strip()
            version = re.search("[0-9]+(\.[0-9]+)+", line)
            version = version.group().strip()
        return version
    except Exception as e:
        return None


class meltrixRecipe(ConanFile):
    name = "meltrix"
    version = get_version()

    # Optional metadata
    license = "GPL 3.0 license "
    author = "Eryk Majoch eryk.majoch13@gmail.com"
    url = "https://github.com/ErykMajoch/Meltrix"
    description = "A Simple Matrix Library Written in C++"
    topics = ("C++", "Matrix", "Math")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*", "unit_tests/*"

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def requirements(self):
        self.test_requires("catch2/3.4.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["meltrix"]
