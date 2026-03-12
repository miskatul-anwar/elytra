pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
    let mut lsd = digits.len() - 1;

    loop {
        if digits[lsd] < 9 {
            digits[lsd] += 1;
            break digits;
        } else {
            digits[lsd] = 0;
            if lsd == 0 {
                digits.insert(0, 1);
                break digits;
            }
            lsd -= 1;
        }
    }
}
fn main() {
    let digits = vec![1, 2, 9];
    println!("{:?}", plus_one(digits));
}
