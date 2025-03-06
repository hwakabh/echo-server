// need to run `export NOMAD_VAR_GHCR_TOKEN="...."` before run jobs
variable "GHCR_TOKEN" {
  type         = string
  description  = "GitHub PAT to pull image from Private GitHub Packages."
}


job "echo-server" {

  group "server" {
    count = 1

    network {
      port "server-api" {
        to = 5001
      }
    }

    task "bin" {
      // To use raw_exec driver, need to enable in nomad.config.hcl first
      // https://developer.hashicorp.com/nomad/docs/drivers/raw_exec
      driver = "raw_exec"

      config {
        // should be absolute path
        command = "/Users/hiro.wakabayashi/git/echo-server/echo-server.bin"
        args    = ["5001"]
      }
    }

    task "web" {
      // https://developer.hashicorp.com/nomad/docs/drivers/docker
      driver = "docker"

      config {
        // TODO: need to fix image builds
        image          = "ghcr.io/hwakabh/echo-server:main"
        args           = ["5001"]
        ports          = ["server-api"]
        auth_soft_fail = true
        auth {
          username = "hwakabh"
          password = var.GHCR_TOKEN
        }
      }

      identity {
        env  = true
        file = true
      }

      resources {
        cpu    = 500
        memory = 256
      }
    }
  }
}
