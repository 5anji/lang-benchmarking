rm ./build/*

mkdir -p ./build

rustc -O main.rs -o build/rust.out
go build -o build/go.out main.go
g++ -O3 main.cpp -o build/cpp.out -lboost_graph

echo "C++ results:"
perf stat ./build/cpp.out

echo "Golang results:"
perf stat ./build/go.out

echo "Rust results:"
perf stat ./build/rust.out
