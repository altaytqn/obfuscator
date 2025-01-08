require_relative 'rb_obf_python'
require_relative 'rb_obf_cpp'
require_relative 'rb_obf_csharp'
require_relative 'rb_utils'

def display_menu
  puts "===================================="
  puts "   RUBY OBFUSCATOR MAIN MENU"
  puts "===================================="
  puts "1) Obfuscate Python"
  puts "2) Obfuscate C++"
  puts "3) Obfuscate C#"
  puts "Enter choice:"
end

def main
  display_menu
  choice = $stdin.gets.to_i
  puts "Paste your code (Ctrl+D or Ctrl+Z to finish):"
  user_code = $stdin.read
  if choice == 1
    out = obf_python(user_code)
    puts "\n----- OBFUSCATED PYTHON CODE -----"
    puts out
  elsif choice == 2
    out = obf_cpp(user_code)
    puts "\n----- OBFUSCATED C++ CODE -----"
    puts out
  elsif choice == 3
    out = obf_csharp(user_code)
    puts "\n----- OBFUSCATED C# CODE -----"
    puts out
  else
    puts "Invalid choice."
  end
end

main
