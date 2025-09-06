fn main() {
    let a = vec![1, 2, 3, 4]; // The array needs to be sorted !
    let n = a.len();
    let target = 3;

    let mut b = n / 2;
    let mut k = 0;
    loop {
        if b < 1 {
            break;
        }

        while k + b < n && a[k + b] <= target {
            k += b
        }

        b /= 2;
    }

    if a[k] == target {
        println!("YES")
    } else {
        println!("NO")
    }
}
