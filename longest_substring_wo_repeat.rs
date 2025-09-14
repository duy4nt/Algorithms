use std::io;

fn main() {
    let mut string_input= String::new();
    println!("Input the string");
    io::stdin().read_line(&mut string_input).expect("Failed to read line");
    let mut char_vec: Vec<char> = string_input.chars().collect();
    char_vec.pop();
    println!("{:?}", char_vec);

    let mut char_vec_output: Vec<char>= vec![];
    for element in char_vec {
        if char_vec_output.contains(&element) {
            continue;
        }
        char_vec_output.push(element);
    }

    let string_output: String = char_vec_output.into_iter().collect();
    println!("{:?}", string_output);
}
