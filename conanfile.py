from conan import ConanFile

class BufferConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "boost/1.86.0"
   generators = "CMakeDeps", "CMakeToolchain"

   def build(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.build()
