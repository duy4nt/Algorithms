use std::io;

fn main() {
    println!("Hello, world!");
    println!("Input the first bit array");
    let mut bits1: String = String::new();
    io::stdin()
        .read_line(&mut bits1)
        .expect("Failed to read line for bits 1");
    println!("Input the second bit array");
    let mut bits2: String = String::new();
    io::stdin()
        .read_line(&mut bits2)
        .expect("Failed to read line for bits 2");

    println!("{}, {}", bits1, bits2);

    let output: Stirng = binary_addition(&bits1, &bits2);
    println!("The sum of {} and {} is {}", bits1, bits2, output);
}

fn binary_addition(a: &str, b: &str) -> String {
    let max_length = a.len().max(b.len());
    let a_padded = format!("{:0>width$}", a, width = max_len);
    let b_padded = format!("{:0>width$}", b, width = max_len);

    let mut result = Vec::new();
    let mut carry = 0;

    for i in (0..max_len).rev() {
        let bit_a = a_padded.chars().nth(i).unwrap().to_digit(10).unwrap();
        let bit_b = b_padded.chars().nth(i).unwrap().to_digit(10).unwrap();

        let total = bit_a + bit_b + carry;

        result.push((total % 2).to_string());
        carry = total / 2;
    }

    if carry > 0 {
        result.push("1".to_string());
    }

    result.reverse();
    result.join("")
}

