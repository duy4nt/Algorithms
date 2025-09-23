use std::io;

fn main() {
    let mut string_input = String::new();
    const RADIX: u32 = 10;
    println!("Input the string");
    io::stdin().read_line(&mut string_input).expect("Failed to read line");
    let trimmed_input = string_input.trim();
    let mut vec_input: Vec<char> = trimmed_input.chars().collect();
    println!("{:?}", vec_input);

    loop {
        if vec_input[0] == '0' {
            vec_input.remove(0);
        }
        else {
            break;
        }
    }

    println!("{:?}", vec_input);

    let vec_output: Vec<i32> = vec_input.iter().filter_map(|&c| c.to_digit(RADIX)).map(|d| d as i32).collect();
    println!("{:?}", vec_output);

}
