pub fn longest_palindrome(s: String) -> String {
    let chars: Vec<char> = s.chars().collect();
    let n = chars.len();

    if n == 0 {
        return String::new();
    }

    let mut start = 0;
    let mut max_len = 1;

    fn expand(chars: &[char], mut l: i32, mut r: i32) -> (i32, i32) {
        let n = chars.len() as i32;

        while l >= 0 && r < n && chars[l as usize] == chars[r as usize] {
            l -= 1;
            r += 1;
        }

        (l + 1, r - 1)
    }

    for i in 0..n {
        // Odd length palindrome
        let (l1, r1) = expand(&chars, i as i32, i as i32);
        if (r1 - l1 + 1) as usize > max_len {
            start = l1 as usize;
            max_len = (r1 - l1 + 1) as usize;
        }

        // Even length palindrome
        let (l2, r2) = expand(&chars, i as i32, i as i32 + 1);
        if (r2 - l2 + 1) as usize > max_len {
            start = l2 as usize;
            max_len = (r2 - l2 + 1) as usize;
        }
    }

    chars[start..start + max_len].iter().collect()
}

fn main() {}

#[cfg(test)]
mod leetcode_tests {
    use super::*;

    #[test]
    fn string_sample_bb() {
        assert_eq!(longest_palindrome("bb".to_string()), "bb".to_string());
    }

    #[test]
    fn string_sample_bbb() {
        assert_eq!(longest_palindrome("bbb".to_string()), "bbb".to_string());
    }

    #[test]
    fn string_sample_babad() {
        assert_eq!(longest_palindrome("babad".to_string()), "bab".to_string());
    }

    #[test]
    fn string_sample_cbbd() {
        assert_eq!(longest_palindrome("cbbd".to_string()), "bb".to_string());
    }
}

#[cfg(test)]
mod personal_assesment {
    use super::*;

    #[test]
    fn len1_strings() {
        assert_eq!(longest_palindrome("a".to_string()), "a".to_string());
    }
}
