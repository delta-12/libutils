# libutils

Collection of C utils.

## Table of Contents

- [Getting Started](#getting-started)
- [Documentation](#documentation)
- [Docker](#docker)

## Getting Started

### Include in another CMake project

To include this library in another project that uses CMake, simply include the `libutils.cmake` file in your `CMakeLists.txt`.

`include(<path to libutils.cmake>)`, e.g. `include(libutils/libutils.cmake)`

Then, add `utils` to your target as a dependecy.

`add_dependencies(<your target> utils)`

### Build and Link Externally

The static library can be built by running the following commands:

`cmake -B build -G Ninja`

`cmake --build build -j$(nproc)`

Then, you can link against the static library `libutils-v<version>.a`. For example, `gcc -o <target> <target>.c -I <path to libutils>/include -L <path to libutils>/build -lutils-v<version>`

## Documentation

Documentation for the latest release can be found here: [https://libutils-docs.surge.sh](https://libutils-docs.surge.sh)

## Docker

All of the tooling needed to build and test this project can be found in the Docker container defined by the Dockerfile found in `/tools/docker`.

To get started developing with Docker, navigate to the aforementioned directory and run `docker-compose build && docker-compose up`. This will create a directory called `docker-build` in the root of the project which will serve as the CMake build directory for any CMake commands run in the Docker container and is automatically populated with build files for Ninja.

Then, execute commands as such: `docker-compose run --rm build-and-test sh -c "<command>"`, e.g. `docker-compose run --rm build-and-test sh -c "cmake --build . -j$(nproc)"`.

Alternatively, a shell can be launched in the container with just `docker-compose run --rm build-and-test sh`. The present working directory upon launching the shell will be the `docker-build` directory.
