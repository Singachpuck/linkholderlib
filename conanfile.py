from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class LinkHolderRecipe(ConanFile):
    name = "linkholderlib"
    version = "1.0"

    # Optional metadata
    license = "GNU General Public License"
    author = "Dmytro Ochkas ochkasdmytro@gmail.com"
    url = "https://github.com/Singachpuck/linkholderlib"
    description = "Library for managing URLs."
    topics = ("CMake", "managing", "boost")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    # Private fields
    _boost_package_name = "boost"
    _boost_version = "1.85.0"

    @property
    def _boost_package(self): return "{}/{}".format(self._boost_package_name, self._boost_version)

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def configure(self):
        if self.settings.compiler == "gcc":
            self.options[self._boost_package_name].without_url = True

    def requirements(self):
        self.requires(self._boost_package)

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["linkholderlib"]