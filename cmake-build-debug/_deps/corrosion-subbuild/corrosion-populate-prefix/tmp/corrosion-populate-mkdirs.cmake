# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-src"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-build"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/tmp"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/src/corrosion-populate-stamp"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/src"
  "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/src/corrosion-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/src/corrosion-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/alexchen/Documents/GitHub/Battleship_FinalProject/cmake-build-debug/_deps/corrosion-subbuild/corrosion-populate-prefix/src/corrosion-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
