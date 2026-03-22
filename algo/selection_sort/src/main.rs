const INFINITY: i32 = f32::INFINITY as i32;

fn selection_sort(vecr: &mut [i32]) {
    let n: usize = vecr.len();

    for i in 0..n {
        let mut smalst = INFINITY;
        let mut idx: usize = 0;

        for (j, item) in vecr.iter().enumerate().skip(i) {
            if *item < smalst {
                smalst = *item;
                idx = j;
            }
        }

        vecr.swap(i, idx);
    }
}

fn main() {
    let mut vecr = [3, 2, 1, 4, 2, 1, 11, 21, 5, 4, 6, 7, 8, 9, 10];

    selection_sort(&mut vecr);

    for i in 0..vecr.len() {
        print!("{} ", vecr.get(i).expect("Invalid Index ERROR!"))
    }

    println!()
}
