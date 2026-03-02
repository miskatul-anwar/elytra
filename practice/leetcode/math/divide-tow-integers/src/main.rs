pub fn divide(dividend: i32, divisor: i32) -> i32 {
    if dividend == i32::MIN && divisor == -1 {
        return i32::MAX;
    }

    let sign = (dividend < 0) ^ (divisor < 0);

    let mut dvd = (dividend as i64).abs();
    let dvs = (divisor as i64).abs();
    let mut res: i64 = 0;

    while dvd >= dvs {
        let mut temp = dvs;
        let mut multiple = 1;

        while dvd >= (temp << 1) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        res += multiple;
    }

    if sign { -(res as i32) } else { res as i32 }
}
fn main() {
    println!("Hello, world!");
}
