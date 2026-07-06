pub fn smallest_balanced_index(nums: Vec<i32>) -> i32 {
    let mut left_sum = 0;
    let mut right_product = 1;

    for (i, &num) in nums.iter().enumerate().skip(1) {
        left_sum += num;

        for j in (i + 1)..nums.len() {
            right_product *= nums[j];
        }

        if left_sum == right_product {
            return i as i32;
        }
    }
    -1
}
fn main() {
    println!("Hello, world!");
}
