use std::io;

fn main() {
    println!("Enter the numbers");

    let mut numbers: Vec<i32> = Vec::new();

    loop {
        let mut string_input = String::new();
        io::stdin().read_line(&mut string_input).expect("Failed to read line");
        let trimmed_string_input = string_input.trim();
        if trimmed_string_input == "/" {
            break;
        }
        match trimmed_string_input.parse::<i32>() {
            Ok(num) => numbers.push(num),
            Err(_) => println!("Invalid input. Please enter a number or /. ")
        }
    }
    println!("{:?}", numbers);

    let mut search_number = String::new();
    println!("Enter the number to be searched");
    io::stdin().read_line(&mut search_number).expect("Failed to read line");
    let search_number: i32 = search_number.trim().parse().expect("Failed while parsing into an integer");

    let mut index: i16= -1;
    let mut count: i16 = 0;
    for num in numbers {
        index += 1;
        if num == search_number {
            count += 1;
            println!("The number was found at index {}", index);
            break;
        }
    }
    if count == 0 {
        println!("The number was not found in the Array");
    }

}
