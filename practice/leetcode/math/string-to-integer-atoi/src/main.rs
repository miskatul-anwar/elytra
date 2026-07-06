#[allow(unused)]

pub fn my_atoi(s: String) -> i32 {
    let chars: Vec<char> = s.trim().chars().collect();
    let mut num: i32 = 0;
    let mut sign: i32 = 1;

    if let Some(&first) = chars.get(0) {
        if first == '-' {
            sign = -1;
        } else if first == '+' {
            sign = 1;
        }
    }

    let start_index = if let Some(&first) = chars.get(0) {
        if first == '-' || first == '+' { 1 } else { 0 }
    } else {
        0
    };

    for &c in chars.iter().skip(start_index) {
        match c {
            '0'..='9' => {
                let digit = (c as i32 - '0' as i32) as i32;

                if num > i32::MAX / 10 || (num == i32::MAX / 10 && digit > 7) {
                    return if sign > 0 { i32::MAX } else { i32::MIN };
                }

                num = num * 10 + digit;
            }
            _ => break,
        }
    }

    if sign < 0 {
        num = -num;
    }

    num
}
fn main() {
    let s = "   42".to_string();
    let result = my_atoi(s);
    println!("{}", result); // Output: -42
}
