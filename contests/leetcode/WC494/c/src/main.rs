
pub fn min_removals(nums: Vec<i32>, target: i32) -> i32 {
    // 10^4 is less than 2^14 (16384), so the XOR sum will never exceed 16383.
    let max_val = 16384;

    // dp[x] stores the maximum number of elements we can keep to get an XOR sum of x
    let mut dp = vec![-1; max_val];
    dp[0] = 0; // Keeping 0 elements gives an XOR sum of 0

    for &num in &nums {
        let mut next_dp = dp.clone();
        let n = num as usize;

        for x in 0..max_val {
            if dp[x] != -1 {
                let new_xor = x ^ n;
                // If picking this number creates a larger subset for 'new_xor', update it
                if dp[x] + 1 > next_dp[new_xor] {
                    next_dp[new_xor] = dp[x] + 1;
                }
            }
        }
        dp = next_dp;
    }

    let t = target as usize;

    // If the target is unreachable or out of bounds
    if t >= max_val || dp[t] == -1 {
        -1
    } else {
        // Min removals = Total elements - Max elements kept
        nums.len() as i32 - dp[t]
    }
}
fn main() {
    println!("Hello, world!");
}
