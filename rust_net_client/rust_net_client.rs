use std::io::{Read, Write};
use std::net::TcpStream;
use serde::{Serialize, Deserialize};
use serde_json;

#[derive(Serialize, Deserialize, Debug)]
struct Message {
    command: String,
    content: String,
}

fn send_message(host: &str, port: u16, msg: &Message) -> Result<String, Box<dyn std::error::Error>> {
    let mut stream = TcpStream::connect((host, port))?;
    let serialized = serde_json::to_string(msg)?;
    stream.write_all(serialized.as_bytes())?;
    stream.shutdown(std::net::Shutdown::Write)?;

    let mut buffer = Vec::new();
    stream.read_to_end(&mut buffer)?;
    Ok(String::from_utf8_lossy(&buffer).into())
}

fn main() {
    println!("== Rust Network Client ==");
    let msg = Message {
        command: "ping".to_string(),
        content: "Hello from Rust".to_string(),
    };
    match send_message("127.0.0.1", 8080, &msg) {
        Ok(response) => println!("Server response: {}", response),
        Err(e) => eprintln!("Error: {}", e),
    }
}
