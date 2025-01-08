use std::collections::HashMap;
use std::fs::File;
use std::io::{BufRead, BufReader, Write};
use std::time::{SystemTime, UNIX_EPOCH};
use rand::{thread_rng, Rng};

pub fn convert_to_map(lines: Vec<String>) -> HashMap<String, String> {
    let mut map = HashMap::new();
    for line in lines {
        let parts: Vec<&str> = line.split("=").collect();
        if parts.len() == 2 {
            map.insert(parts[0].trim().to_string(), parts[1].trim().to_string());
        }
    }
    map
}

pub fn scramble_values(map: &mut HashMap<String, String>) {
    let mut rng = thread_rng();
    for val in map.values_mut() {
        let mut chars: Vec<char> = val.chars().collect();
        for i in 0..chars.len() {
            let j = rng.gen_range(0..chars.len());
            chars.swap(i, j);
        }
        *val = chars.into_iter().collect();
    }
}

pub fn load_file_to_vec(path: &str) -> Vec<String> {
    let file = File::open(path).expect("Could not open file");
    let reader = BufReader::new(file);
    reader.lines().map(|l| l.unwrap()).collect()
}

pub fn save_map_to_file(map: &HashMap<String, String>, path: &str) {
    let mut file = File::create(path).expect("Could not create output file");
    for (k, v) in map {
        let line = format!("{}={}\n", k, v);
        file.write_all(line.as_bytes()).unwrap();
    }
}

pub fn generate_timestamp() -> u128 {
    let start = SystemTime::now().duration_since(UNIX_EPOCH).unwrap();
    start.as_millis()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert_to_map() {
        let lines = vec!["foo=bar".to_string(), "baz=123".to_string()];
        let map = convert_to_map(lines);
        assert_eq!(map.get("foo").unwrap(), "bar");
        assert_eq!(map.get("baz").unwrap(), "123");
    }

    #[test]
    fn test_scramble_values() {
        let mut map = HashMap::new();
        map.insert("test".to_string(), "abcd".to_string());
        scramble_values(&mut map);
        assert_eq!(map.len(), 1);
        let scrambled = map.get("test").unwrap().clone();
        assert_eq!(scrambled.len(), 4);
    }

    #[test]
    fn test_timestamp() {
        let t = generate_timestamp();
        assert!(t > 0);
    }
}

fn main() {
    println!("== Rust Data Processor ==");
    let input_path = "data_input.txt";
    let output_path = "data_output.txt";
    let lines = load_file_to_vec(input_path);
    let mut map = convert_to_map(lines);
    scramble_values(&mut map);
    save_map_to_file(&map, output_path);
    println!("Data processed and saved with timestamp: {}", generate_timestamp());
}
