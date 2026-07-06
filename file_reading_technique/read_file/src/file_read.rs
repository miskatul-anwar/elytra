use std::{fs::File, io::Read, path::Path};

fn read_file(pstr: &str) -> String {
    let path = Path::new(pstr);
    let mut file = File::open(path).expect("Cannot Open the File!");

    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .expect("Unable to convert to string");
    contents
}

pub fn print_pretty(pstr: &str) {
    let contents = read_file(pstr);
    println!("The Text: \n{}", contents)
}
