macro_rules! gcd {
    ($a:expr, $b:expr) => {{
        let (mut a, mut b) = ($a, $b);
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a
    }};
}
macro_rules! lcm {
    ($a:expr, $b:expr) => {
        ($a * $b) / gcd!($a, $b)
    };
}

macro_rules! modpow {
    ($base:expr, $exp:expr, $m:expr) => {{
        let (mut a, mut e, m) = ($base % $m, $exp, $m);
        let mut res = 1 % m;
        while e > 0 {
            if e & 1 == 1 {
                res = (res * a) % m;
            }
            a = (a * a) % m;
            e >>= 1;
        }
        res
    }};
}

fn main() {
    let num1 = 29;
    let num2 = 35;
    let result = gcd!(num1, num2);
    println!("The GCD of {} and {} is {}", num1, num2, result);
    let result = lcm!(num1, num2);
    println!("The LCM of {} and {} is {}", num1, num2, result);
    let result = modpow!(num1, num2, 100);
    println!("The result of {}^{} mod 100 is {}", num1, num2, result);
}
