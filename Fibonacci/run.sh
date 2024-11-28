rm rust.out go.out cpp.out

rustc -O main.rs -o rust.out
go build -o go.out main.go
g++ -O3 main.cpp -o cpp.out

echo "C++ results:"
time ./cpp.out

echo "Golang results:"
time ./go.out

echo "Rust results:"
time ./rust.out
