use std::io;

fn main() {
    let mut numbers: Vec<i32> = Vec::new();
    println!("Enter the numbers");
    loop {
        let mut string_input = String::new();
        io::stdin().read_line(&mut string_input).expect("Failed to read line");
        let trimmed_string_input = string_input.trim();

        if trimmed_string_input == "/" {
            break;
        }

        match trimmed_string_input.parse::<i32>() {
            Ok(num) => numbers.push(num),
            Err(_) => println!("Invalid input. Please enter a number or /.")
        }
    }
    println!("{:?}", numbers);

    let mut search_number = String::new();
    println!("Enter the number to be searched");
    io::stdin().read_line(&mut search_number).expect("Failed to read line");
    let search_number: i32 = search_number.trim().parse().expect("Failed to parse the number");

    let index: i32 = binary_search(&numbers, search_number);

    if index == -1 {
        println!("The number does not exist in the Arrays");
    } else {
        println!("The number was found at index {}", index);
    }

}

fn binary_search(vec: &Vec<i32> , x: i32) -> i32 {
    let mut first_index: usize = 0;
    let mut last_index: usize = vec.len();

    while first_index < last_index {
        let middle_index: usize = (first_index + last_index)/2;
        if vec[middle_index] == x {
            return middle_index.try_into().expect("Failed to convert into i32")
        }
        else if vec[middle_index] > x {
            last_index= middle_index - 1;
        } else {
            first_index= middle_index + 1;
        }
    }
    return -1
}
