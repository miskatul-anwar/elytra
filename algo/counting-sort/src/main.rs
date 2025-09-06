fn main() {
    let a = vec![3, 2, 1, 3, 4];
    let max = *a.iter().max().unwrap();
    let mut count_array = vec![0; max + 1];

    let mut i = 0;
    loop {
        if i == a.len() {
            break;
        }

        count_array[a[i]] += 1;
        i += 1
    }

    let mut j = 0;
    let mut sorted = Vec::new();
    loop {
        if j == count_array.len() {
            break;
        }

        while count_array[j] > 0 {
            sorted.push(j);
            count_array[j] -= 1
        }

        j += 1
    }

    println!("{:?}", sorted)
}
