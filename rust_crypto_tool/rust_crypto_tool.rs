use rand::Rng;
use std::collections::HashSet;
use sha2::{Digest, Sha256};

fn random_key(len: usize) -> Vec<u8> {
    let mut rng = rand::thread_rng();
    let mut key = vec![0u8; len];
    for i in 0..len {
        key[i] = rng.gen();
    }
    key
}

fn xor_encrypt(data: &[u8], key: &[u8]) -> Vec<u8> {
    data.iter().zip(key.iter().cycle()).map(|(d, k)| d ^ k).collect()
}

fn find_duplicates(strings: &[String]) -> HashSet<String> {
    let mut seen = HashSet::new();
    let mut dups = HashSet::new();
    for s in strings {
        if !seen.insert(s.clone()) {
            dups.insert(s.clone());
        }
    }
    dups
}

fn hash_sha256(s: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(s);
    format!("{:x}", hasher.finalize())
}

fn main() {
    println!("== Rust Crypto Tool ==");
    let original = b"some secret data here";
    let key = random_key(16);
    let enc = xor_encrypt(original, &key);
    println!("Encrypted: {:?}", enc);

    let dec = xor_encrypt(&enc, &key);
    println!("Decrypted: {:?}", String::from_utf8_lossy(&dec));

    let vec_of_strings = vec!["apple".into(), "banana".into(), "apple".into()];
    let dups = find_duplicates(&vec_of_strings);
    println!("Duplicates found: {:?}", dups);

    let hashed = hash_sha256("rust is awesome");
    println!("SHA256: {}", hashed);
}
