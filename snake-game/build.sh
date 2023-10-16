#!/bin/bash
dir=$(dirname "${BASH_SOURCE[0]}")
cmake -S "${dir}" -B cmake-build-debug/ && make -C cmake-build-debug/
