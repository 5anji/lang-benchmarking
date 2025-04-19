# rm ./build/*

# mkdir -p ./build

# rustc -O main.rs -o build/rust.out
# go build -o build/go.out main.go
# g++ -O3 -std=c++23 main.cpp -o build/cpp.out

# echo "C++ results:"
# perf stat ./build/cpp.out

# echo "Golang results:"
# perf stat ./build/go.out

# echo "Rust results:"
# perf stat ./build/rust.out

#!/bin/bash

set -e

rm -rf ./build/*
mkdir -p ./build

rustc -O main.rs -o build/rust.out
go build -o build/go.out main.go
g++ -O3 -std=c++23 main.cpp -o build/cpp.out

progress_bar() {
  local current=$1
  local total=$2
  local width=50
  local progress=$((current * width / total))
  local remaining=$((width - progress))

  printf "\r["
  for ((i = 0; i < progress; i++)); do printf "#"; done
  for ((i = 0; i < remaining; i++)); do printf "."; done
  printf "] %d%%" $((current * 100 / total))
}

run_time() {
  local label=$1
  local bin_path=$2
  local log_file="build/${label}_times.log"

  echo "Running $label..."
  > "$log_file"

  for i in {1..100}; do
    perf stat -x, -e task-clock "$bin_path" 2>&1 | grep task-clock | cut -d',' -f1 >> "$log_file"
    progress_bar "$i" 100
  done
  echo

  local avg=$(awk '{sum+=$1} END {if (NR>0) print sum/NR}' "$log_file")
  echo "$label average task-clock time: $avg ms"
  echo ""
}

run_time "C++" ./build/cpp.out
run_time "Golang" ./build/go.out
run_time "Rust" ./build/rust.out
