# echo-server
Implementation of socket connection with C Language for personal workouts.

<!-- *** -->
## Usage

```shell
% ./echo-server.bin 8088
Serving HTTP on 0.0.0.0 port 8088 (http://0.0.0.0:8088/) ...
Quit the server with CONTROL-C.
```

In other terminal window:

```shell
% curl --http0.9 -X GET localhost:8088/ -d 'hello!' ; echo
GET / HTTP/1.1
Host: localhost:8088
User-Agent: curl/8.7.1
Accept: */*
Content-Length: 6
Content-Type: application/x-www-form-urlencoded

hello!
```

<!-- *** -->
## Configurations
Environmental Variables...etc

<!-- *** -->
## Build from source
As there are several ways to build echo-server application on your machine. \
In this project, we will expect to use [bazel](https://bazel.build) as build tools.

```shell
% git clone git@github.com:hwakabh/echo-server.git

# Run all targets at the same time
% bazel build //...

# If you would like to build single binaries on your machine
% bazel build //src:bin -- 8088

# (Optional) Clean up build artifacts on your machine
% bazel clean
```

or, of course you can directly invoke `gcc` for application compiles/linkings, \
once you clone the sources from repository:

```shell
# Create object files
% gcc -Wall -c src/echo-server.c
% gcc -Wall -c src/helpers.c

# Link object files
% gcc -Wall *.o -o echo-server.bin

# Run app with printing help
% ./echo-server.bin --help

# (Optional) Clean up object files & binary on your machine
% rm ./echo-server.bin ./echo-server.o ./helpers.o
```

<!-- *** -->
## Distributions
We have prepared echo-server application with following form-factors, so in case just you would like to play with application, \
you can available with the following distributions.

### GitHub Release
In release pipeline, we are preparing the single binaries for each platform with several CPU architectures, and this will be publised as GitHub Releases. \
You can see all of the releases via [Release page](https://github.com/hwakabh/echo-server/releases) of this repo, and all of them are available with downloading directly.

```shell
% export RELEASE_VERSION='v0.3.11'
% curl -L -o echo-server.bin https://github.com/hwakabh/echo-server/releases/download/${RELEASE_VERSION}/echo-server_darwin-aarch64-${RELEASE_VERSION}
% chmod 744 ./echo-server.bin
```

### GitHub Packages
Same as general container image registries, such as Docker Hub, you can pull the image from [GitHub Container Registry (ghcr.io)](https://docs.github.com/en/packages/working-with-a-github-packages-registry/working-with-the-container-registry). \
The images have been stored in ghcr.io as GitHub Packages, so you can all revisions with accessing [Packages page](https://github.com/hwakabh/echo-server/pkgs/container/echo-server) of this repo.

```shell
% docker image pull ghcr.io/hwakabh/echo-server:latest
% docker run -d -p 8088:8088 ghcr.io/hwakabh/echo-server:latest
```

### load OCI container images from sources
As we have bundled Bazel rules [`rules_oci`](https://github.com/bazel-contrib/rules_oci) for managing [OCI images](https://github.com/opencontainers/image-spec) with code bases, \
you can build the images from sources with `bazel` commands:

```shell
# If you would like to load application OCI image onto your docker
% bazel run //src:load
INFO: Analyzed target //src:load (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //src:load up-to-date:
  bazel-bin/src/load.sh
INFO: Elapsed time: 0.108s, Critical Path: 0.00s
INFO: 1 process: 4 action cache hit, 1 internal.
INFO: Build completed successfully, 1 total action
INFO: Running command line: bazel-bin/src/load.sh
Loaded image: ghcr.io/hwakabh/echo-server:local

% docker images ghcr.io/hwakabh/echo-server
REPOSITORY                    TAG       IMAGE ID       CREATED   SIZE
ghcr.io/hwakabh/echo-server   local     9582b4a2d316   N/A       6.17MB
```

<!-- *** -->
## Credits
Implementation references on:
