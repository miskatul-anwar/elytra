pub fn uniform_array(nums1: Vec<i32>) -> bool {
    let min = *nums1.iter().min().unwrap();

    if min % 2 == 0 {
        for &x in &nums1 {
            if x % 2 == 1 {
                return false;
            }
        }
    }

    true
}
fn main() {
    println!("Hello, world!");
}
