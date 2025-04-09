MAKEFLAGS += --warn-undefined-variables
SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
.DEFAULT_GOAL := help

# all targets are phony
.PHONY: $(shell egrep -o ^[a-zA-Z_-]+: $(MAKEFILE_LIST) | sed 's/://')

--check-docker:
	@echo ">>> Checking docker engine exists ..."
	@echo "Server: `docker version --format '{{.Server.Version}}'`"
	@echo "Client: `docker version --format '{{.Client.Version}}'`"
	@echo ''

--check-gcc:
	@gcc --version


build: --check-gcc ## Start all componentes of echo-server app
	@echo
	@gcc -Wall -o echo-server.bin ./echo-server.c

image: --check-docker ## Build Docker image of echo-server app
	@docker build -t echo-server:dev .

help: ## Print this help
	@echo 'Usage: make [target]'
	@echo ''
	@echo 'Targets:'
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
