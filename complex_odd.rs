use std::io;

fn main() {
    let mut integer: i8 = 99;
    let mut number: i8;
    let mut tenths: i8;
    let mut ones: i8;

    println!("Input the number");
    let mut str_inp: String = String::new();
    io::stdin().read_line(&mut str_inp).expect("Failed to read the line");
    number = str_inp.trim().parse::<i8>().expect("Invalid input");


    loop {
        if integer <= 0 || number <= 0 {
            break;
        }

        if integer % 2 != 0 {
            // Integer is odd
            ones = integer % 10;
            tenths = integer / 10;

            if ones != 5 && ones != 9 && tenths != 5 && tenths != 9 {
                println!("{ones}{tenths}");
                number -= 1;
            }

//            println!("{ones}{tenths}");
        } else {
            // Integer is even
        }

        integer -= 1;
    }
}

