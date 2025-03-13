fn main() {
    let mut arr: [u32; 500000] = {
        let mut tmp = [0u32; 500000];
        for i in 0..500000 {
            tmp[i] = (500000 - i as u32) % 251;
        }
        tmp
    };

    arr.sort();
}
