require 'securerandom'

def base64_encode(str)
  [[str].pack("m0")].join
end

def shuffle_string(str)
  str.chars.shuffle.join
end

def tokenize_line(line)
  line.split(/\s+/)
end

def inject_rand_symbols(str)
  out = ""
  str.each_char do |c|
    out << c
    out << random_symbol if rand(3).zero?
  end
  out
end

def random_symbol
  ["@", "#", "$", "~"].sample
end

def insert_hashes(s)
  arr = s.split("")
  arr.map! { |c| rand(2).zero? ? "#{c}##" : c }
  arr.join
end
