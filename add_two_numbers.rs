use std::io;

fn main() {
    let mut vec_one: Vec<u32> = Vec::new();
    let mut vec_two: Vec<u32> = Vec::new();
    let mut vec_result: Vec<u32> = Vec::new();

    println!("Enter the first vector");
    loop {
        let mut string_input = String::new();
        io::stdin().read_line(&mut string_input).expect("Failed to read line");
        let trimmed_string_input = string_input.trim();
        if trimmed_string_input == "/" {
            break;
        }
        match trimmed_string_input.parse::<u32>() {
            Ok(num) => vec_one.push(num),
            Err(_) => println!("Invalid input. Please enter a number of /.")
        }

    }

    println!("Input the second vecotr");
    loop {
        let mut string_input = String::new();
        io::stdin().read_line(&mut string_input).expect("Failed to read line");
        let trimmed_string_input = string_input.trim();
        if trimmed_string_input == "/" {
            break;
        }
        match trimmed_string_input.parse::<u32>() {
            Ok(num) => vec_two.push(num),
            Err(_) => println!("INvalid input. Please enter a number or /.")
        }
    }
    println!("{:?}", vec_one);
    println!("{:?}", vec_two);

    let mut vec_one_string: Vec<String> = vec_one.iter().map(|&d| d.to_string()).collect();
    let joined_string_one = vec_one_string.join("");
    let joined_number_one: u32 = joined_string_one.parse::<u32>().expect("Unable to parse the number");

    let mut vec_two_string: Vec<String> = vec_two.iter().map(|&d| d.to_string()).collect();
    let joined_string_two = vec_two_string.join("");
    let joined_number_two: u32 = joined_string_two.parse::<u32>().expect("Unable to parse the number");

    let mut sum_of_vec: u32 = joined_number_one + joined_number_two;

    vec_result = num_to_vec(sum_of_vec);

    vec_result.reverse();
    println!("{:?}", vec_result);
}

fn num_to_vec(n: u32) -> Vec<u32> {
    n.to_string().chars().map(|c| c.to_digit(10).unwrap()).collect()
}
