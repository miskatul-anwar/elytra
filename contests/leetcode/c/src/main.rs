pub fn min_operations(s: String) -> i32 {
    let bytes = s.as_bytes();
    let n = bytes.len();

    let mut breaks = 0;

    for i in 0..n - 1 {
        if bytes[i] > bytes[i + 1] {
            breaks += 1;
        }
    }

    if n == 2 && breaks == 1 {
        return -1;
    }

    breaks
}
fn main() {
    println!("Hello, world!");
}
