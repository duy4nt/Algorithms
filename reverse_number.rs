use std::io;

fn main() {
    let mut number= String::new();
    println!("Input the number to be reversed");
    io::stdin().read_line(&mut number).expect("Failed to read line");
    let mut number: i32 = match number.trim().parse::<i32>() {
        Ok(num) => num,
        Err(_) => 0
    };
    println!("{number}");

    let mut rev_num: i32= 0;
    while number > 0 {
        let last = number % 10;
        rev_num = rev_num*10 + last;
        number = number /10 as i32;
        println!("{rev_num}")
    }
    println!("{rev_num}");
}
