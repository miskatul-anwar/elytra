use std::f32::INFINITY;

fn selection_sort(vecr: &mut Vec<i32>, n: usize) {
    for i in 0..n {
        let mut smalst = INFINITY as i32;
        let mut idx: usize = 0;

        for j in i..n {
            if vecr[j] < smalst {
                smalst = vecr[j];
                idx = j;
            }
        }

        vecr.swap(i, idx);
    }
}

fn main() {
    let mut vecr: Vec<i32> = vec![3, 2, 1, 4, 2, 1, 11, 21, 5, 4, 6, 7, 8, 9, 10];
    let n = vecr.len();

    selection_sort(&mut vecr, n);

    for i in 0..vecr.len() {
        print!("{} ", vecr.get(i).expect("Invalid Index ERROR!"))
    }

    println!()
}
