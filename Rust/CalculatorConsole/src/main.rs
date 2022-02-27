use std::fmt::Error;
use std::io::{stdin};
use std::ptr::null;

fn sum(a:f64, b:f64) -> f64 {
    return a + b;
}

fn difference(a:f64, b:f64) -> f64 {
    return a - b;
}

fn product(a:f64, b:f64) -> f64 {
    return a * b;
}

fn quotient(a:f64, b:f64) -> f64 {
    return a / b;
}

fn input_num<T>(num: &mut T) -> bool {
    let mut input_str= String::new();
    if stdin().read_line(&mut input_str).is_err() {return false}
    match input_str.trim().parse() {
        Ok(val) => { *num = val }
        Err(err) => {return false}
    }
    return true;
}

fn main() {
    let mut first_num: f64 = 0.0;
    let mut second_num: f64 = 0.0;
    let mut option: i8;
    let mut input_str = String::new();
    let mut is_run: bool = true;

    println!("It's calculator");
    while is_run {
        println!("Input first number:");
        if !input_num(&mut first_num) {
            println!("Incorrect input");
            continue;
        }

        println!("[1] +\n[2] -\n[3] *\n[4] /");
        if !input_num(&mut option) {
            println!("Incorrect input");
            continue;
        }
        if option == 0 || option > 4 {
            println!("Option doesn't exist");
        }

        println!("Input second number:");
        if !input_num(&mut second_num) {
            println!("Incorrect input");
            continue;
        }

        match option {
            1 => println!("{}", sum(first_num, second_num)),
            2 => println!("{}", difference(first_num, second_num)),
            3 => println!("{}", product(first_num, second_num)),
            4 => println!("{}", quotient(first_num, second_num)),
            _ => println!("Option doesn't exest")
        }

        println!("[1] exit\n[another number] continue");
        if !input_num(&mut option) {
            println!("Incorrect input");
            continue;
        }
        if option == 1 { is_run = false; }
    }
}