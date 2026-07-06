use std::collections::{BinaryHeap, HashMap};

struct EventManager {
    heap: BinaryHeap<(i32, i32)>,
    map: HashMap<i32, i32>,
}

impl EventManager {
    fn new(events: Vec<Vec<i32>>) -> Self {
        let mut heap = BinaryHeap::new();
        let mut map = HashMap::new();

        for e in events {
            let id = e[0];
            let pr = e[1];
            heap.push((pr, -id));
            map.insert(id, pr);
        }

        Self { heap, map }
    }

    fn update_priority(&mut self, event_id: i32, new_priority: i32) {
        self.map.insert(event_id, new_priority);

        self.heap.push((new_priority, -event_id));
    }

    fn poll_highest(&mut self) -> i32 {
        while let Some((pr, neg_id)) = self.heap.pop() {
            let id = -neg_id;

            if let Some(&current_pr) = self.map.get(&id) {
                if current_pr == pr {
                    self.map.remove(&id);
                    return id;
                }
            }
        }

        -1
    }
}
fn main() {
    println!("Hello, world!");
}
