use crate::file_read::print_pretty;

mod file_read;

fn main() {
    let pstr = "src/storage/file.txt";
    print_pretty(pstr);
}
