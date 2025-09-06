use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input = input.trim().to_string();

    if input.len() < 7 {
        println!("NO")
    } else {
        let mut danger = false;
        let mut ones = 0;
        let mut zeroes = 0;

        for c in input.chars() {
            if c == '0' {
                zeroes += 1;
                ones = 0
            } else {
                ones += 1;
                zeroes = 0
            }

            if ones == 7 || zeroes == 7 {
                danger = true
            }
        }

        if danger {
            println!("YES")
        } else {
            println!("NO")
        }
    }
}
