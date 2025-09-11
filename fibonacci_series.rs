use std::io;

fn main() {
    println!("Input the rank of the number of Fibonacci Series");
    let mut number= String::new();
    io::stdin().read_line(&mut number).expect("Failed to read line");

    let number: u32 = number.trim().parse().expect("Failed to parse into number");
    println!("The rank input by the user is: {number}");

    let mut num1: u32 = 0;
    let mut num2: u32 = 1;
    let mut counter: u32 = 3;
    let mut temp: u32;

    loop {
        if number == 1 {
            println!("The number with the rank {number} is: {num1}");
            break;
        }
        else if number == 2 {
            println!("the number with the rank {number} is: {num2}");
            break;
        }
        else {
            temp = num2;
            num2 = num2+ num1;
            num1 = temp;
            if counter == number {
                println!("The number with the rank {counter} is: {num2}");
                break;
            }
            counter = counter + 1;
        }
    }
}
