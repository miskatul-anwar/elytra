pub fn construct_rectangle(area: i32) -> Vec<i32> {
    let mut width = (area as f32).sqrt() as i32;

    while area % width != 0 {
        width -= 1;
    }

    let length = area / width;
    vec![length, width]
}
fn main() {
    println!("{:?}", construct_rectangle(4));
}
