use std::io;

fn main() {
    let mut numbers: Vec<i32> = Vec::new();
    let mut highest_numbers: Vec<i32> = Vec::new();
    println!("Input the numbers of the array");
    loop {
        let mut string_input = String::new();
        io::stdin().read_line(&mut string_input).expect("Failed to read line");
        let trimmed_input = string_input.trim();

        if trimmed_input == "/" {
            break;
        }

        match trimmed_input.parse::<i32>() {
            Ok(num) => numbers.push(num),
            Err(_) => println!("Invalid input. Please enter a number or /"),
        }
    }

    println!("{:?}", numbers);
    let mut highest: i32 = 0;
    let mut second_highest: i32 = 0;
    for element in numbers {
        if element>highest {
            second_highest = highest;
            highest = element;
        }
    }
    println!("{highest}");
    println!("{second_highest}");
}
