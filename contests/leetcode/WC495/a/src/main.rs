pub fn first_matching_index(s: String) -> i32 {
    let sv: Vec<char> = s.chars().collect();
    let n = sv.len();

    let mut i = 0;

    loop {
        if i > n / 2 {
            break -1;
        }

        if sv[i] == sv[n - i - 1] {
            break i as i32;
        }
        i += 1
    }
}

fn main() {
    let s = "abcdab".to_string();
    println!("{}", first_matching_index(s))
}
