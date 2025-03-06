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
Since we have `Makefile` as launcher, for building single binaries you can just run:
```shell
% make build

# To see help of each target in Makefile:
% make
```

or, of course you can directly invoke `gcc`:
```shell
# gcc
% gcc -Wall -o echo-server.bin ./echo-server.c
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
