use std::io;

fn main() {
    println!("hello, world!");
    let mut nums: Vec<i32> = Vec::new();

    loop {
        let mut inp: String = String::new();
        io::stdin().read_line(&mut inp).expect("failed to read line");
        let inp = inp.trim();

        if inp == "/" {
            break;
        }

        match inp.parse::<i32>() {
            Ok(n) => nums.push(n),
            Err(_) => println!("invalid input"),
        }
    }
    println!("{:?}", nums);

    sort(&mut nums);

    println!("{:?}", nums);
}

fn sort(nums: &mut Vec<i32>) {
    let mut i = 0;
    let mut temp: i32;

    println!("{:?}", nums.len());

    while i < nums.len() {
        let mut j = i + 1;
        let mut key = nums[i];
        let mut temp_index = i;
        while j < nums.len() {
            if key > nums[j] {
                key = nums[j];
                temp_index = j;
            }
            j += 1;
        }

        if nums[i] != key {
            temp = nums[temp_index];
            nums[temp_index] = nums[i];
            nums[i] = temp;
        }

        i += 1;
    }

}
