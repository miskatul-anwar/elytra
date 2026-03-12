pub fn minimum_index(capacity: Vec<i32>, item_size: i32) -> i32 {
    let mut min = i32::MAX;
    let mut min_index = -1;

    for i in 0..capacity.len() {
        if capacity[i] >= item_size {
            if capacity[i] < min {
                min = capacity[i];
                min_index = i as i32;
            }
        }
    }
    min_index
}
fn main() {
    println!("Hello, world!");
}
