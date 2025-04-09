# echo-server
Implementation of socket connection with C Language for personal workouts.

## Usage

```shell
% ./echo-server.bin 8080
Serving HTTP on 0.0.0.0 port 8080 (http://0.0.0.0:8080/) ...
Quit the server with CONTROL-C.
```

In other terminal window:

```shell
% curl --http0.9 -X GET localhost:8088/
HTTP1.1 200 OK
```

## Configurations
Environmental Variables...etc

## Build
In this project, we will expect to use [bazel](https://bazel.build) as build tools.

```shell
# Run all targets at the same time
% bazel build //...

# If you would like to run single binaries on your machine
% bazel run //src:bin -- --help

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

# (Optional) Clean up build artifacts on your machine
% bazel clean
```

or, of course you can directly invoke `gcc` for application compiles/linkings:
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

## Deployments

```shell
# start Nomad on local
% nomad agent -dev -config=nomad/nomad.config.hcl

# deploy echo-server application
$ export NOMAD_VAR_GHCR_TOKEN="***"
$ nomad job run nomad/echo-server.nomad.hcl
```

## Distributions
- Source code (with `git clone`)
- single binaries (with GitHub Release)
- container images (with ghcr.io)

## Credits
Implementation references on:
