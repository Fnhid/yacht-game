# CMakeList.txt : CMake project for yacht, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (yacht "main.cpp" "main.h" "game.h" "game.cpp" "interface.h" "interface.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET yacht PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
