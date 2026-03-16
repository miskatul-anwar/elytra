struct MyHashSet {
    data: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashSet {
    fn new() -> Self {
        MyHashSet { data: Vec::new() }
    }

    fn add(&mut self, key: i32) {
        if !self.data.contains(&key) {
            self.data.push(key);
        }
    }

    fn remove(&mut self, key: i32) {
        self.data.retain(|&x| x != key);
    }

    fn contains(&self, key: i32) -> bool {
        self.data.contains(&key)
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * let obj = MyHashSet::new();
 * obj.add(key);
 * obj.remove(key);
 * let ret_3: bool = obj.contains(key);
 */
fn main() {
    let mut obj = MyHashSet::new();
    obj.add(1);
    obj.add(2);
    if obj.contains(1) {
        obj.remove(1);
    }
}
