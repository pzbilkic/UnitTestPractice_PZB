#!/bin/bash
# Build and run the unit tests inside the cpp-container Docker image.
# Runs as your own user so build outputs aren't owned by root.
#
#   ./docker_test.sh          build + run tests (test_runner.sh)
#   ./docker_test.sh bash     open a shell inside the container
#   ./docker_test.sh <cmd>    run any command in the container, e.g. "pmccabe Password.cpp"

IMAGE="${IMAGE:-cpp-container}"
cd "$(dirname "$0")"

if ! docker image inspect "$IMAGE" >/dev/null 2>&1; then
  echo "Image '$IMAGE' not found. Build it first:"
  echo "  git clone https://github.com/ChicoState/cpp-container && cd cpp-container && docker build -t cpp-container ."
  echo "or pull the prebuilt one:  docker pull kbuffardi/cpp-container && IMAGE=kbuffardi/cpp-container ./docker_test.sh"
  exit 1
fi

TTY_FLAGS=""
[ -t 0 ] && [ -t 1 ] && TTY_FLAGS="-it"

docker run --rm $TTY_FLAGS --user "$(id -u):$(id -g)" -v "$(pwd)":/usr/src "$IMAGE" "$@"
